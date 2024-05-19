#include <stdio.h> 
#include "funcoes.h"

int inverte(int array[], int pos){
  int novo_array[pos];
  int count = 1;
  for (int i = 0; i < pos; i++){
    novo_array[i] = array[pos-count];
    count++;
  }

  printf("\nArray invertido: [");
  for (int i = 0; i < pos; i++){
    printf(" %d", novo_array[i]);
  }
  
  printf(" ]\n");
}

ERROS manipulacao_ponteiros()
{
  int quantidade;

  printf("\nDigite a quantidade de itens: ");
  scanf("%d", &quantidade);

  int *pos;
  pos = &quantidade;
  int array[*pos];

  for(int i = 0; i < quantidade; i++){
    printf("Digite o %d item: ", (i+1));
    scanf("%d", &array[i]);
  }

  printf("\nArray: [");
  for (int i = 0; i < *pos; i++){
    printf(" %d", array[i]);
  }
  printf(" ]");

  inverte(array, *pos);

  return OK;
}