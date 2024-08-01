#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	const int TAM = 5;
	int v[TAM][TAM];

#pragma omp parallel
	{
#pragma omp single
		{
			srand(time(NULL));
		}
		for (int i = 0; i < TAM; i++)
		{
#pragma omp for
			for (int j = 0; j < TAM; j++)
			{
				v[i][j] = rand();
				int id = omp_get_thread_num();
				printf("[%d][%d] - Thread %d - num %d\n", i, j, id, v[i][j]);
			}
		}
	}
	return 0;
}
