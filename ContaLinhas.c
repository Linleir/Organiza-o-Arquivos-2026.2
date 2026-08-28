#include <stdio.h>

int main(int argc, char** argv)
{
	FILE *entrada;
	int c;
	int linhas;

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

	linhas = 0;
	c = fgetc(entrada);
	while(c != EOF)
	{
		if(c == '\n')
			linhas++;
		c = fgetc(entrada);
	}

	printf("Quantidade de linhas: %d\n", linhas);

	fclose(entrada);
	return 0;
}
