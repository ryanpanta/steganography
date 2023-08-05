# Esteganografia em C: Decodificador de Arquivos Ocultos em Imagens PPM


Bem-vindo ao Decodificador de Arquivos Ocultos em Imagens PPM utilizando Esteganografia em C! Este projeto se dedica a detectar e recuperar arquivos escondidos em imagens no formato PPM. Utilizando a técnica de esteganografia, exploramos as bandas de cores dos pixels para identificar e revelar informações ocultas.  

## Como Usar
**Compilação com Makefile**

Para compilar o projeto de forma simples, você pode utilizar o arquivo makefile fornecido. Certifique-se de que todos os arquivos fonte e o makefile estejam no mesmo diretório. No terminal, execute o seguinte comando:

```
make
```

**Compilação Manual**

Caso prefira compilar manualmente, utilize um compilador C, como o gcc, para compilar o arquivo fonte. No terminal, navegue até a pasta do projeto e execute o seguinte comando de compilação:  
```
gcc -o decode decode.c
```

**Execução**
Após a compilação bem-sucedida, você estará pronto para usar o decodificador. No terminal, execute o seguinte comando:  

`./decode <nome-da-imagem>.ppm`  

Substitua <nome-da-imagem> pelo nome da imagem PPM na qual você deseja detectar arquivos escondidos. O decodificador aplicará a técnica de esteganografia para identificar e recuperar informações ocultas nos pixels da imagem.  

**Detecção de Arquivos Escondidos**  
Este projeto destaca a capacidade de detectar arquivos escondidos por meio da esteganografia. Ao analisar as bandas de cores dos pixels, conseguimos revelar informações ocultas, como nomes de arquivos e tamanhos, que foram codificadas na imagem de maneira imperceptível.  

**Testes e Exploração**    
Para experimentar a detecção de arquivos escondidos, fornecemos três imagens de exemplo (cores-e.ppm, jardim-e.ppm e porto-e.ppm) no repositório. Use essas imagens para explorar a detecção de informações ocultas e para compreender melhor a técnica de esteganografia em ação.  

**Contribuição**   
Este é um projeto de código aberto. Se você tiver sugestões para melhorias, correções de bugs ou novos recursos relacionados à detecção de arquivos escondidos usando esteganografia, não hesite em enviar um pull request.
