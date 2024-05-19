#include <stdio.h> 
#include <stdlib.h>
#include "funcoes.h"

int comparaCrescente (const void * a, const void * b) {
   if ( *(int*)a == *(int*)b ){
     return 0; // iguais
   }
  else if ( *(int*)a < *(int*)b ){
    return -1; // a menor que b
  }
  else
  {
    return 1; // a maior que b
  }
}

int media(){
  int quantidade;

  printf("\nDigite a quantidade de itens: ");
  scanf("%d", &quantidade);

  int *pos;
  pos = &quantidade;
  int array[*pos];
  float media;

  for(int i = 0; i < quantidade; i++){
    printf("Digite o %d item: ", (i+1));
    scanf("%d", &array[i]);
    media = media + array[i];
  }

  media = media / quantidade;
  printf("\nA média é: %.2f\n", media);

  return 0;
}



int mediana(){
  int quantidade;

  printf("\nDigite a quantidade de itens: ");
  scanf("%d", &quantidade);

  int *pos;
  pos = &quantidade;
  int array[*pos];
  float mediana;

  for(int i = 0; i < quantidade; i++){
    printf("Digite o %d item: ", i+1);
    scanf("%d", &array[i]);
  }

  qsort(array, quantidade, sizeof(int), comparaCrescente);

  if(quantidade % 2 != 0){
    mediana = array[quantidade/2];
  }
  else {
    mediana = (array[quantidade/2] + array[(quantidade/2) - 1]) / 2.0;
  }

  printf("\nA mediana é: %.2f\n", mediana);

  return 0;
}



int moda(){
  int quantidade;

  printf("\nDigite a quantidade de itens: ");
  scanf("%d", &quantidade);

  int *pos;
  pos = &quantidade;
  int array[*pos];
  float moda;
  int max = -99999;
  int count = 0;

  for(int i = 0; i < quantidade; i++){
    printf("Digite o %d item: ", (i+1));
    scanf("%d", &array[i]);
  }

  for(int i = 0; i < quantidade; i++){
    for(int j = 0; j < quantidade; j++){
      if(array[i] == array[j]){
        count = count + 1;
      } 
    }
    if(count > max){
      max = count;
      moda = array[i];
    }
    count = 0;
  }

  printf("\nA moda é: %.2f\n", moda);

  return 0;
}


ERROS calculo_estatisticas()
{
  int opcao; 
  do{ 
      printf("\n---------------------------------\n"); 
      printf("\nMenu principal\n"); 
      printf("1. Média\n"); 
      printf("2. Mediana\n"); 
      printf("3. Moda\n"); 
      printf("0. Sair\n"); 
      printf("Escolha uma opção: "); 
      scanf("%d", &opcao); 

      if(opcao > 3 || opcao < 0) { 
        printf("Opção inválida\n");
      } 
      else if(opcao == 1) {
          media();
      }
      else if(opcao == 2) {
          mediana();
      }
      else if(opcao == 3) {
          moda();
      }
      else {
        printf("Sair...\n"); 
      }

  } while(opcao != 0);

  return OK;
}