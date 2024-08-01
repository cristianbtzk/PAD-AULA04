#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	const int TAM = 4;
	int m1[TAM][TAM] = {{}};
	int m2[TAM][TAM] = {{}};
	int mprod[TAM][TAM];

	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			m1[i][j] = (i + 1);
			m2[i][j] = (j + 1);
		}
	}

	int metade = TAM / 2;
#pragma omp parallel shared(metade, m1, m2, mprod)
	{

#pragma omp sections
		{
#pragma omp section
			{

				for (int i = 0; i < metade; i++)
				{
					int j = 0;
					int soma = 0;
					for (int k = 0; k < TAM; k++)
					{
						for (int l = 0; l < TAM; l++)
						{
							soma += m1[i][l] * m2[l][j];
						}

						mprod[i][j] = soma;
						j++;
					}
				}
			}
#pragma omp section
			{
				/* int j = 0;

				for (int i = metade; i < TAM; i++)
				{
					int soma = 0;

					for (int l = 0; l < TAM; l++)
					{
						soma += m1[i][l] * m2[l][j];
					}
					mprod[i][j] = soma;
					j++;
				}
 */
				printf("Thread %d - section 2, i = %d\n", omp_get_thread_num());
			}
		}
	}
	printf("Matriz 1:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	printf("Matriz 2:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}
	printf("Matriz Produto:\n");
	for (int i = 0; i < TAM; i++)
	{
		for (int j = 0; j < TAM; j++)
		{
			printf("%d ", mprod[i][j]);
		}
		printf("\n");
	}

	return 0;
}
