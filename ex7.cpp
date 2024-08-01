#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	const int TAM = 5;
	int v[TAM];

	for (int i = 0; i <= TAM; i++)
	{
		v[i] = i + 1;
	}
	int soma = 0;
	int produto = 1;
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			{
				for (int i = 0; i < TAM; i++)
				{
					soma += v[i];
					printf("Thread %d - section 1, i = %d\n", omp_get_thread_num(), i);
				}
			}
#pragma omp section
			{
				for (int i = 0; i < TAM; i++)
				{
					produto *= v[i];
					printf("Thread %d - section 2, i = %d\n", omp_get_thread_num(), i);
				}
			}
		}
	}
	printf("Soma = %d, Mult = %d\n", soma, produto);
	return 0;
}
