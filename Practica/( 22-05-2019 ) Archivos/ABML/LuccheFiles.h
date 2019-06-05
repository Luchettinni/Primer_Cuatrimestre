#include <stdio.h>

typedef struct{

    int isEmpty;
    int legajo;

    char nombre[31];
    char apellido[31];
    float salario;


} sEmpleado;

int readFile(FILE* fileToRead, char path[], sEmpleado persona);
int writeFile(FILE* fileToWrite, char path[], sEmpleado persona);
