%{
#include <stdio.h>
int count = 0;

int incrementaCounter()
{
	return count++;
}
%}
%token INCREMENT

commands:
	| commands command
	;

command:
	increment
	;

increment:
	
