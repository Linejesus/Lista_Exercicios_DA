#include "funcoes.h"
#include <stdio.h> 
#include <string.h>

void clearBuffer() { 
  int c; 
  while ((c = getchar()) != '\n' && c != EOF); 
} 

void upper(char s[])
{
  for(int i = 0; s[i] != '\0'; i++)
  {
    if(s[i] >= 'a' && s[i] <= 'z')
    {
      s[i] -= 32;
    }
  }
}

ERROS manipulacao_strings()
{
  int vogal = 0;
  char string[100];
  
  clearBuffer();
  printf("\nDigite uma palavra: ");
  fgets(string, 100, stdin);

  upper(string);

  for (int i = 0; string[i] != '\0'; i++)
  {
    if(string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
    {
      vogal++;
    }
  }

  printf("\nQuantidade de vogais: %d\n", vogal);

  return OK;
}