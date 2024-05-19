#include <stdio.h> 
#include "funcoes.h"

ERROS soma_elementos()
{
  int i;
  int quant;

  printf("\nDigite a quantidade de números a serem somados: ");
  scanf("%d", &quant);

  int array[quant];

  for(int j = 0; j < quant; j++)
  {
    printf("Digite um número: ");
    scanf("%d", &i);
    array[j] = i;
  }

  int soma = 0;
  for (int j = 0; j < quant; j++)
  {
    soma += array[j];
  }

  printf("\nA soma dos números é: %d\n", soma);
  
  return OK;
}