//MATHEUS STEIN FONTANA - 201120300
#include <iostream>
#include <fstream>

using namespace std;

void ex1()
{
    printf("Exercicio 1\n\n");
    for (int index = 1; index<=10; index++) {
        printf("Linha %d \n", index);
    }
    printf("\n##############################\n\n");
}

void ex2()
{
    printf("Exercicio 2\n\n");

    char current;
    char previous = NULL;
    int contador = 0;

    fstream file("in1.txt", fstream::in);
    while (file >> noskipws >> current) {

        if(isdigit(current) == false && isdigit(previous) == true){
            contador++;
            cout << "contou: " << contador << " - current: " << current << " - previous: " << previous  << endl;
        }

        previous = current;
    }
    cout << "Total de numeros: " << contador << endl;
    printf("\n##############################\n\n");
}

int main()
{
    ex1();
    ex2();
    return 0;
}
