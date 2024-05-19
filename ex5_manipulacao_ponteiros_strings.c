#include <stdio.h> 
#include <string.h>
#include "funcoes.h"

ERROS manipulacao_ponteiros_strings()
{
  char *pos;
  char string[100];

  clearBuffer();
  printf("\nDigite uma palavra: ");
  fgets(string, 100, stdin);

  pos = string;

  printf("\nLetras convertidas para maiúsculas: ");
  for(int i = 0; pos[i] != '\0'; i++)
  {
    if(pos[i] >= 'a' && pos[i] <= 'z')
    {
      pos[i] -= 32;
      printf("%c", pos[i]);
    }
    else{
      printf("%c", pos[i]);
    }
  }

  return OK;
}