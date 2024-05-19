#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include "funcoes.h" // Importa o arquivo funcoes.h para que possamos utilizar as funções declaradas nele

int main() { // Função principal
  
funcao funcoes[] = {soma_elementos, manipulacao_strings, cadastro_struct, operacoes_matriciais,
   manipulacao_ponteiros_strings, leitura_escrita_binario, ordenacao_structs, manipulacao_ponteiros, calculo_estatisticas, manipulacao_tempo}; // Definindo um array de funções que serão utilizadas no programa

  int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu principal
  do { // Início do loop do menu de opções até que o usuário escolha a opção de sair
    printf("\n******************************************************\n");   
    printf("\n\t\t Lista de Exercícios \n\n");   // Imprimindo o menu de opções dos exercícios
    printf("1. Soma de Elementos em um Array\n");   // Imprimindo a primeira opção
    printf("2. Manipulação de Strings\n"); // Imprimindo a segunda opção
    printf("3. Cadastro de Produtos usando Struct\n"); // Imprimindo a terceira opção
    printf("4. Operações Matriciais\n"); // Imprimindo a quarta opção
    printf("5. Manipulação de Ponteiros em String\n"); // Imprimindo a quinta opção
    printf("6. Leitura e Escrita de Registros em Arquivos Binários\n"); // Imprimindo a sexta opção
    printf("7. Ordenação de Structs\n"); // Imprimindo a sétima opção
    printf("8. Manipulação de Ponteiros\n"); // Imprimindo a oitava opção
    printf("9. Cálculo de Estatísticas em um Array\n"); // Imprimindo a nona opção
    printf("10. Manipulação de Tempo\n"); // Imprimindo a décima opção
    printf("0. Sair\n");           // Imprimindo a última opção
    printf("\nEscolha uma opção: "); // Pedindo ao usuário para escolher uma opção

    scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário
    opcao--; // Decrementando a opção para acessar o índice do array de funções
    if (opcao > 10 || opcao < -1) // Verificando se a opção escolhida é válida
      printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
    else if (opcao >= 0) // Verificando se a opção escolhida é válida para
                         // acessar o índice do array de funções
      funcoes[opcao](); // Chamando a função correspondente à opção escolhida com
                       // o array de tarefas e a posição atual das tarefas
    else // Caso nenhuma das condições anteriores sejam verdadeiras, a opção
         // escolhida é sair, portanto o programa se encerrará
      printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado

  } while (opcao >= 0); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra

} // Fechando a função principal