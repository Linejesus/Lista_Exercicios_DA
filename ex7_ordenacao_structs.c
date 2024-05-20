#include <stdio.h> 
#include <stdlib.h>
#include "funcoes.h"

typedef struct { 
  char nome[50];
  int idade;      
  char email[30]; 
  long int telefone; 
} Contato;  

int comparaIdade(const void *a, const void *b)
{
  if((*(Contato*)a).idade == (*(Contato*)b).idade)
  {
    return 0;
  }
  else if((*(Contato*)a).idade < (*(Contato*)b).idade)
  {
    return -1;
  }
  else 
  {
    return 1;
  }
}

ERROS ordenacao_structs()
{
  int quantidade;
  int controle = 0;

  printf("\nDigite a quantidade de contatos: ");
  scanf("%d", &quantidade);

  Contato pessoa[quantidade];

  for(int i = 0; i < quantidade; i++)
  {
    clearBuffer(); 
    printf("\nDigite seu nome: ");
    fgets(pessoa[controle].nome, 50, stdin); 
    clearBuffer();

    printf("Digite sua idade: "); 
    scanf("%d", &pessoa[controle].idade); 
    clearBuffer(); 

    printf("Digite seu email: ");
    fgets(pessoa[controle].email, 30, stdin); 
    clearBuffer(); 

    printf("Digite seu telefone: ");
    scanf("%ld", &pessoa[controle].telefone); 
    printf("\n");

    controle = controle + 1;
  }

  qsort(pessoa, controle, sizeof(Contato), comparaIdade);

  printf("\n----------------------------\n");
  printf("Structs Ordenados pela Idade:\n\n");
  for (int i = 0; i < controle; i++)
  {
    printf("Nome: %s", pessoa[i].nome);
    printf("Idade: %d\n", pessoa[i].idade);
    printf("Email: %s", pessoa[i].email);
    printf("Telefone: %ld\n", pessoa[i].telefone);
    printf("----------------------------\n");
  }

  return OK;
}