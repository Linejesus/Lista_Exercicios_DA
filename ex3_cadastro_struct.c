#include <stdio.h> 
#include <string.h>
#include "funcoes.h"

int criar(Produto produtos[], int *pos){
  printf("\nDigite a quantidade do produto: ");
  scanf("%d", &produtos[*pos].quant);
  clearBuffer();

  printf("Digite o nome do produto: ");
  fgets(produtos[*pos].nome, 50, stdin);
  clearBuffer();

  printf("Digite o preço do produto: ");
  scanf("%f", &produtos[*pos].preco);
  clearBuffer();

  *pos = *pos + 1;
}


int listar(Produto produtos[], int pos){
  for (int i = 0; i < pos; i++) {
    printf("\nPosição: %d\n", i+1);
    printf("Nome: %s\n", produtos[i].nome);
    printf("Preço: R$ %.2f\n", produtos[i].preco);
    printf("Quantidade: %d\n\n", produtos[i].quant);
  }

  return 0;
}

int calcular(Produto produtos[], int pos){
  float total = 0;

  for (int i = 0; i < pos; i++) {

    total += produtos[i].preco * produtos[i].quant;
  }

  printf("\nValor total: R$ %.2f\n", total);

  return 0;
}

ERROS cadastro_struct()
{
  int pos = 0;
  Produto produtos[MAX_PRODUTOS];

  int opcao;
  do{
    printf("\n---------------------------------------\n");
    printf("\nMenu de Opções:\n");
    printf("1. Cadastrar produto\n");
    printf("2. Listar produtos\n");
    printf("3. Calcular o valor total em estoque\n");
    printf("0. Sair\n");
    printf("Entre com uma opção: ");
    int i = scanf("%d", &opcao);

    if(opcao == 1)
    {
      criar(produtos, &pos);
    }
    else if(opcao == 2)
    {
      listar(produtos, pos);
    }
    else if(opcao == 3)
    {
      calcular(produtos, pos);
    }

  } while(opcao != 0);
  
  return OK;
}