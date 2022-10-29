#include <stdio.h>
#include <string.h>
// stdout, stdin, stderr

int main(int argc, char** argv)
{
	FILE *entrada;
	
	int c, CasaNaoPreenchida = 0;
    int Numeroletras[52];
    
	char letra[52];

	//int len = strlen(letra);

	for (int i = 0; i < 52; i++)
	{
		Numeroletras[i] = 0;
		letra[i] = ' ';
	}



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
		if (('A' <= c && c <='Z') || ('a' <= c && c <='z'))
		{
			for (int i = 0; i < 52; i++)
			{
				if (letra[i] == c)
				{
					Numeroletras[i]=Numeroletras[i]+1;
					break;
				}
				
				if (i == 51)
				{
					letra[CasaNaoPreenchida] = c;
					
					Numeroletras[CasaNaoPreenchida] = Numeroletras[CasaNaoPreenchida]+1;
					
					CasaNaoPreenchida = CasaNaoPreenchida+1;
				}	
			}
		}
             
        c = fgetc(entrada);
    }

	printf("Letras do documento com as respectivas vezes que eles aparecem\n");


	for (int j = 0 ; j < 52; j++)
	{
		if (letra[j] != 32)
		{
			printf("%c                  %d\n", letra[j], Numeroletras[j]);
		}
	}

	fclose(entrada);
	return 0;
}