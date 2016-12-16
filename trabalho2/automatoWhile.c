#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define NSTATES 10
#define NCHARS 256

#define KW_IF 1
#define INTEGER 2
#define EOL 3
#define KW_WHILE 5 
/*
Exercício  1: 
Analisar  o  código  C  do  arquivo 
automato.c e  desenhar  um  grafo  do 
autômato finito correspondente.

Exercício 2:
Modificar o programa 
automato.c para reconhecer a palavra 
while. O novo programa e novo
grafo devem também ser apresentados
*/


char accept_state[NSTATES] = { 0,0,KW_IF,INTEGER,EOL,0,0,0,0,KW_WHILE };
int table[NSTATES][NCHARS]; 
int state = 0;
char next = 0;
  
int init (FILE *file)
  {
  char c = 0;
  
  // keyword if
  table[0]['i'] = 1;
  table[1]['f'] = 2;
  // keyword while 
  table[0]['w'] = 5;
  table[5]['h'] = 6;
  table[6]['i'] = 7;
  table[7]['l'] = 8;
  table[8]['e'] = 9;
  // integer
  for (c='0'; c<='9'; ++c)
    {
    table[0][c] = 3;
    table[3][c] = 3;
    }
  table[0]['\n'] = 4;
  next = fgetc(file); 
  state = 0;
  }
  
int getToken (FILE *file)
  {
  int recognized;
  while (TRUE) 
    { 
    if (next < 0) break;
    if (table[state][next] == 0)
      {
      recognized = state;
      state = 0;
      return accept_state[recognized];
      }
    state = table[state][next]; 
    next = fgetc(file); 
    }
  return 0;
  }
  
void printToken(int tok)
  {
  switch (tok)
    {
    case 0: printf("ERROR "); exit(0);
    case KW_IF: printf("KW_IF "); break;
    case KW_WHILE: printf("KW_WHILE "); break;
    case INTEGER: printf("INTEGER "); break;
    case EOL: printf("EOL "); break;
    default: printf("UNKNOWN "); break;
    }
  }

int main (int argc, char **argv)
  {
  int tok = 0;
  init(stdin);
  while (!feof(stdin))
    {
    tok = getToken(stdin);
    printToken(tok);
    }
  }
