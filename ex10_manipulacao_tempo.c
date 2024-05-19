#include <stdio.h> 
#include <time.h>
#include "funcoes.h"

ERROS manipulacao_tempo()
{
  clock_t tempo_inicial = clock();

  for (int i = 0; i < 1000000000; ++i)
  {
    printf("");
  }

  clock_t tempo_final = clock();
  float r = tempo_final - tempo_inicial;

  printf("\nTempo de duração do programa: %f s\n", r / CLOCKS_PER_SEC);

  return OK;
}