#include <stdio.h>

// stdout, stdin, stderr


int main(int argc, char** argv)
{
	FILE *entrada;
	int c;
    int letras = 0, palavra = 0, result = 0, letraTotal = 0;

	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"r");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	c = fgetc(entrada);

	while (c != EOF)
     {
        if(('A' <= c && c <='Z') || ('a' <= c && c <='z')){
            letras = letras + 1;
        }
    
        else if (c = ' ') {
            if (letras > 0) {
                palavra = palavra+1;
                letraTotal = letraTotal + letras;
                letras = 0;
            }
        }
        c = fgetc(entrada);
    }

    result = letraTotal/palavra;

     printf("Esse arquivo tem %d letras e %d palavras, portanto em média tem %d por palavra", letraTotal, palavra, result);

	fclose(entrada);
	return 0;
}