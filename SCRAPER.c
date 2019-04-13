#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 80/100
// Falto usar punteros para extraer info -20

void cod_fuente(char codigo_pagina[])
{
	int i = 0, count = 0;
	char next_limhallar_repos[] = "<span class=\"css-truncate css-truncate-target\"";

	while ((i = Encontrarnext_lim(codigo_pagina, next_limhallar_repos, i)))
	{

			printf("\n%d) ", ++count);
			ExtraerInfo(codigo_pagina, i);

	}
}
int Encontrarnext_lim(char codigo_pagina[], char next_lim[], int plus)
{
	while (codigo_pagina[plus] != '\0')
	{
		if (cadena(codigo_pagina, next_lim, plus))
		{
			plus += strlen(next_lim);
			while (codigo_pagina[plus++] != '>');
			return (plus);
		}
		plus++;
	}
	return 0;
}

int repositorio(char codigo_pagina[], char hallar_repos[], int plus);
int cadena(char codigo_pagina[], char array_str[], int plus);
int ExtraerInfo(char codigo_pagina[], int plus)
{
	while (codigo_pagina[plus] != '\0' && codigo_pagina[plus] != '<')
		printf("%c", codigo_pagina[plus++]);

	printf("\n");
	return plus;
}
char * ver_info(char texto[]);

int main()
{
	char * codigo_pagina = ver_info("fuente.txt");

	cod_fuente(codigo_pagina);
	free(codigo_pagina);
	return 0;
}

char * ver_info(char texto[])
{
	int tamanofichero_info_pag;
	FILE * fichero_info_pag;
	char * codigo_pagina;

	fichero_info_pag = fopen(texto, "rt");

	if (fichero_info_pag == NULL)
		return NULL;

	fseek(fichero_info_pag, 0, SEEK_END);
	tamanofichero_info_pag = ftell(fichero_info_pag);
	fseek(fichero_info_pag, 0, SEEK_SET);

	codigo_pagina = malloc((tamanofichero_info_pag + 1) * sizeof(char));

	fread(codigo_pagina, sizeof(char), tamanofichero_info_pag, fichero_info_pag);
	fclose(fichero_info_pag);
	codigo_pagina[tamanofichero_info_pag] = '\0';

	return codigo_pagina;
}

int cadena(char codigo_pagina[], char array_str[], int plus)
{
	int i;

	for (i = 0; codigo_pagina[i + plus] != '\0' && codigo_pagina[i + plus] != '\n'; i++)
		if (array_str[i] != codigo_pagina[i + plus])
			break;

	return (array_str[i] == '\0');
}
