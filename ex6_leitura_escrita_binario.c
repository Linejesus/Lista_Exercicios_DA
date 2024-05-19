#include <stdio.h> 
#include <string.h>
#include "funcoes.h"

ERROS adicionar_funcionario(Funcionario registro[], int *pos){
  if(*pos >= TOTAL_REGISTROS)
      return MAX_FUNCIONARIO;

  clearBuffer();
  printf("Digite o nome do funcionário: ");
  fgets(registro[*pos].nome, 20, stdin);
  clearBuffer();

  printf("Digite a idade do funcionário: ");
  scanf("%d", &registro[*pos].idade);
  clearBuffer();

  printf("Digite o salário do funcionário: ");
  scanf("%f", &registro[*pos].salario);
  clearBuffer();

  *pos = *pos + 1;

  return OK;
}

ERROS listar_funcionario(Funcionario registro[], int *pos){
  if(*pos == 0)
      return SEM_FUNCIONARIO;

  clearBuffer();
  char procura_nome[20];
  printf("Digite o nome do funcionário pelo qual deseja listar: ");
  fgets(procura_nome, 20, stdin);
  clearBuffer();

  if(strcmp(procura_nome, "\n") == 0){
    for(int i=0; i<*pos; i++){
      printf("Pos: %d\t", i+1);
      printf("Nome: %s\t", registro[i].nome);
      printf("Idade: %d\t", registro[i].idade);
      printf("Salário: %f\n\n", registro[i].salario);
    }
  } else{
    int nome_existe = 0;
    for(int i=0; i<*pos; i++){
      if(strcmp(procura_nome, registro[i].nome) == 0){
        nome_existe = nome_existe + 1;
      }
    }
    if (nome_existe == 0){
      printf("Não existe nenhum funcionário com o nome %s\n", procura_nome);
    } else{
      for(int i = 0; i<*pos; i++){
        if(strcmp(procura_nome, registro[i].nome) == 0){
          printf("Pos: %d\t", i+1);
          printf("Nome: %s\t", registro[i].nome);
          printf("Idade: %d\t", registro[i].idade);
          printf("Salário: %f\n", registro[i].salario);
        }
      }
    }
  }

  return OK;
}

ERROS salvar_funcionario(Funcionario registro[], int *pos){
  FILE *f = fopen("registro_funcionarios.bin", "wb");
  if(f == NULL)
      return ABRIR;

  int qtd = fwrite(registro, TOTAL_REGISTROS, sizeof(Funcionario), f);
  if(qtd == 0)
      return ESCREVER;

  qtd = fwrite(pos, 1, sizeof(int), f);
  if(qtd == 0)
      return ESCREVER;

  if(fclose(f))
      return FECHAR;

  return OK;
}

ERROS carregar_funcionario(Funcionario registro[], int *pos){
  FILE *f = fopen("registro_funcionarios.bin", "rb");
  if(f == NULL)
      return ABRIR;

  int qtd = fread(registro, TOTAL_REGISTROS, sizeof(Funcionario), f);
  if(qtd == 0)
      return LER;

  qtd = fread(pos, 1, sizeof(int), f);
  if(qtd == 0)
      return LER;

  if(fclose(f))
      return FECHAR;

  return OK;

}

ERROS leitura_escrita_binario()
{
  funcao_colaborador funcoes[] = {adicionar_funcionario, listar_funcionario, salvar_funcionario, carregar_funcionario};

  Funcionario registro[TOTAL_REGISTROS];
  int pos;
  ERROS erro = funcoes[3](registro, &pos);
  if(erro != OK)
      pos = 0;

  int opcao;
  do{
      printf("\n---------------------------------\n");
      printf("\n\tMenu principal\n\n");
      printf("1. Adicionar funcionário\n");
      printf("2. Listar funcionários\n");
      printf("3. Salvar funcionários\n");
      printf("4. Carregar funcionários\n");
      printf("0. Sair\n");
      printf("Escolha uma opção: ");

      scanf("%d", &opcao);
      opcao--;
      if(opcao > 3 || opcao < -1)
          printf("Opção inválida\n");
      else if(opcao >= 0)
          funcoes[opcao](registro, &pos);
      else
          printf("Sair...\n");

  } while(opcao >= 0);

  funcoes[2](registro, &pos);

  return OK;
}