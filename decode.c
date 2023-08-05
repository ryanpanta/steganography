/*=============================================================
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTACAO.
* Trabalho . . . . : Esteganografia
* Discplina: . . . : Processamento de Imagens
* Professor: . . . : Luiz Eduardo da Silva
* Aluno . . . . .  : Ryan Rodrigues - 2021.1.08.032
* Data . . . . . . : 29/06/2023
=============================================================*/

/*---------------------------------------------------------
 * Image Processing
 * 
 * Steganography - decode
 *---------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "imagelib.h"
#define DEBUG(x) x


void decode(image In)
{
    FILE *file;
    char name[100] = "";
    int fsize = 0;
    unsigned char byte = 0;
    unsigned char conteudo = 0;
    unsigned char rgb;
    unsigned char RGB;
    int bitCount = 0;
    int parada = 1;
    int m = 2;
    int i = 0;

    // decode the name
    while(parada){

        rgb = (In->px[i] >> 8*m) & 0xFF;
        RGB = rgb & 0x01;
        i++;
        
        if(m > 0)
            m--;
        else 
            m=2;

        byte <<= 1; // Pula uma casa para esquerda
        byte |= RGB; // Faz a concatenação do bit a variavel byte.
        bitCount++;

        if (bitCount % 8 == 0) {  // Verifica se formou um byte completo
            if (byte == '\0') {  // Verifica se o byte é igual ao caractere nulo ('\0')
                parada = 0;  // Define parada como 1 para sair do loop
                if (m == 0) // Padrão que eu descobri após observar o comportamento do m, é feito uma decrementação a mais
                    m = 2;
                else
                    m--;  
            } else {
                strncat(name, (char*)&byte, 1); // Adicione o byte decodificado ao nome do arquivo
            }
            byte = 0;  // Reinicia o byte para armazenar o próximo caractere
        }
    }
    
    
    printf("File name: %s\n", name);
    
    // decode file size

    unsigned int sizeBits = 0; 
    int j = 0;
    for(j = i+1; j < 32+i; j++){ // Indice j vai ser onde o i parou na ultima decodificação + 1, para não pegar a casa do '\0'
                                        // e ele faz 32 iterações, pois no enunciado indica que o tamanho está codificado em 4 bytes
        rgb = (In->px[j] >> 8*m) & 0xFF;
        RGB = rgb & 0x01;
        if(m > 0)
            m--;
        else 
            m=2;

        sizeBits <<= 1;
        sizeBits |= RGB;

    }

    fsize = sizeBits; // Atribuição para a variavel fsize
    printf("File size: %d bytes\n", fsize);
    
    // decode file
    
    file = fopen(name, "wb");
    if (!file)
    {
        printf("Cannot create file %s\n", name);
        exit(10);
    }
    while (fsize)
    {
        for(int i = 0; i < 8; i++){
            rgb = (In->px[j] >> 8*m) & 0xFF;
            RGB = rgb & 0x01;
            j++;
            if(m > 0)
                m--;
            else 
                m=2;
            //printf("%d", RGB);
            conteudo <<= 1;
            conteudo |= RGB;
        }
        fprintf(file, "%c", conteudo); 
        fsize--;
    }
    fclose(file);
}

void msg(char *s)
{
    printf("\nSteganography - decode");
    printf("\n-------------------------------");
    printf("\nUSE.:  %s  <IMG.PPM>", s);
    printf("\nWhere:\n");
    printf("    <IMG.PPM>  Image file in PPM ASCII format\n\n");
    exit(20);
}

/*-----------------------------------------
  Main program
------------------------------------------*/
int main(int argc, char *argv[])
{
    char name[100];
    int nr, nc;
    image In;
    char *p;
    if (argc < 2)
        msg(argv[0]);
    strcpy(name, argv[1]);
    p = strstr(name, ".ppm");
    if (p)
        *p = 0;
    strcat(name, ".ppm");
    In = img_get(name, COLOR);
    decode(In);
    img_free(In);
    return 0;
}
