#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

int main(int argc, char *argv[])
{
	const int TAM = 10;
	int v[TAM];

	for (int i = 0; i < TAM; i++)
	{
		v[i] = i;
	}

	int soma = 0;
#pragma omp parallel for reduction(+:soma)
	for (int i = 0; i < TAM; i++)
	{
		soma += v[i];
	}
	printf("Soma = %d\n", soma);
	return 0;
}
