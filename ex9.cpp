#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  srand(time(NULL));

	const int TAM = 100;
  int numeroBuscado = (rand() % TAM) + 1;
  
	int array[TAM];

	for (int i = 0; i < TAM; i++)
	{
		array[i] = i + 1;
	}

  int posicao = -1;

#pragma omp parallel 
	{

#pragma omp for		
    for (int i = 0; i < TAM; i++)
    { 
      if(array[i] == numeroBuscado) {
        #pragma omp critical
        posicao = i;
      }
    }

    #pragma omp single 
    {
      if(posicao == -1) {
        printf("Número não encontrado\n");
      } else {
        printf("Posição do número %d: %d\n", numeroBuscado, posicao);
      }
    }
  }
	return 0;
}
