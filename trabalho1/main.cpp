//MATHEUS STEIN FONTANA - 201120300
#include <iostream>
#include <fstream>

using namespace std;

void ex1()
{
    /*
        Implementar um programa em linguagem C que imprima 10 linhas, de 1 a 10,
        cada uma com os números de um ao número da linha.
    */

    printf("Exercicio 1\n\n");
    for (int index = 1; index<=10; index++) {
        printf("Linha %d \n", index);
    }
    printf("\n##############################\n\n");
}

void ex2()
{
    /*
        Implementar um programa em linguagem C que conte quantos números existem no arquivo in1.txt
    */

    printf("Exercicio 2\n\n");

    char current;
    char previous;
    int contador = 0;

    fstream file("files/in1.txt", fstream::in);
    while (file >> noskipws >> current) {

        if(isdigit(current) == false && isdigit(previous) == true){
            contador++;
        }

        previous = current;
    }
    cout << "Total de numeros: " << contador << endl;
    printf("\n##############################\n\n");
}

void ex3()
{
    /*
        Implementar um programa em linguagem C que imprima quantos números existem em cada linha lógica terminada
        por ; do arquivo in2.txt (resposta: 1 1 1 3 12 3 5 2 1 2 1 4 2 2 2 3 3 1).
    */
    printf("Exercicio 3\n\n");

    int countLine = 0;
    int contador = 0;
    char current;
    char previous;
    char value;

    fstream file("files/in2.txt", fstream::in);
    while (file >> noskipws >> value) {

        if (isdigit(value) ){
            countLine++;
        } else {
            cout << "Total da linha: " << countLine << endl;
            countLine = 0;
        }

    }
    printf("\n##############################\n\n");
}

void ex4()
{
    /*
        Ler o arquivo in2.txt e implementar um programa em linguagem C referente ao 3)
        contanto o número de linhas físicas.
    */
}

void ex5()
{

    /*
        Implementar um programa em linguagem C para ler o arquivo e fazer a soma dos números em cada nível de
        parênteses (contando ou não os que estão dentro de outro nível). Ler os arquivos in3.txt e in4.txt.
    */
}

int main()
{
    ex1();
    ex2();
    ex3();
    return 0;
}
