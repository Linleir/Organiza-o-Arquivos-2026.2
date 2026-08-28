#include <stdio.h>

int main(int argc, char** argv)
{
	FILE *entrada;
	int c;
	int ocorrencias[256];
	int i;

	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"rb");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	for(i = 0; i < 256; i++)
		ocorrencias[i] = 0;

	c = fgetc(entrada);
	while(c != EOF)
	{
		ocorrencias[c]++;
		c = fgetc(entrada);
	}

	for(i = 0; i < 256; i++)
	{
		if(((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')) && ocorrencias[i] > 0)
			printf("%c %d\n", i, ocorrencias[i]);
	}

	fclose(entrada);
	return 0;
}
