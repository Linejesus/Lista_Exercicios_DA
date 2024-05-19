#include <stdio.h> 
#include "funcoes.h"

int multiplicar_matrizes(){
  int matriz[3][3];

  printf("\nDigite a primeira matriz (3x3): \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       scanf("%d", &matriz[i][j]);
    }
  }

  int matriz2[3][3];

  printf("\nDigite a segunda matriz (3x3): \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       scanf("%d", &matriz2[i][j]);
    }
  }

  printf("\nSua primeira matriz: \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       printf("%d ", matriz[i][j]);
    }  
    printf("\n");
  }

  printf("\nSua segunda matriz: \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       printf("%d ", matriz2[i][j]);
    }  
    printf("\n");
  }

  int matriz3[3][3];
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      matriz3[i][j] = matriz[i][j] * matriz2[i][j];
    }
  }

  printf("\nMultiplicação das Matrizes: \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       printf("%d ", matriz3[i][j]);
    }  
    printf("\n");
  }
}

int transposicao(){
  int matriz[3][3];

  printf("\nDigite a matriz (3x3): \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       scanf("%d", &matriz[i][j]);
    }
  }

  printf("\nSua matriz: \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       printf("%d ", matriz[i][j]);
    }  
    printf("\n");
  }

  int matriz3[3][3];

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      matriz3[i][j] = matriz[j][i];
    }
  }

  printf("\nTransposição da matriz: \n");

  for (int i=0; i < 3; i++)
  {
    for (int j=0; j < 3; j++)
    {
       printf("%d ", matriz3[i][j]);
    }  
    printf("\n");
  }
}

ERROS operacoes_matriciais()
{
  int opcao; 
  do{ 
      printf("\n----------------------------------\n"); 
      printf("\nMenu principal\n"); 
      printf("1. Multiplicar matrizes\n"); 
      printf("2. Transposição da matriz\n"); 
      printf("0. Sair\n"); 
      printf("Escolha uma opção: "); 
      scanf("%d", &opcao); 

      if(opcao > 2 || opcao < 0) { 
        printf("Opção inválida\n");
      } 
      else if(opcao == 1) {
        multiplicar_matrizes();
      } 
      else if(opcao == 2) {
          transposicao();
      }
      else {
        printf("Sair...\n"); 
      }

  } while(opcao != 0);

  return OK;
}