#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int dia;
    int mes;
    int year;

} sFecha;

typedef struct {

    int legajo;
    char nombre[20];
    char genero;
    float sueldo;
    sFecha fecha;

} sEmpleado;

// clase 13/05/2019

void leerPuntero (int* p);

void mostrarVector1(int vec[], int tam);
void mostrarVector2(int vec[], int tam);
void mostrarVector3(int* vec, int tam);
void mostrarVector4(int* vec, int tam);

void mostrarCadena(char* nombre);

int main()
{
    sEmpleado unEmpleado[] = { { 1234, "juan", 'm', 3000, {13,5,2019} }, { 1232, "peter", 'm', 3000, {13,5,2019}} };

    sEmpleado* punteroEmpleado;

    punteroEmpleado = &unEmpleado[0];

    printf("dia: %d\n\n", punteroEmpleado->fecha.dia);
    printf("dia: %s\n\n", (*punteroEmpleado).nombre);

//---------------------------------------------------------------------------------------
    int x = 10;

    int* p; // este P va a guardar la direccion de memoria de una variable entera (leelo como complemento A2)

    p = &x; // P apunta a X (P, guarda a la direccion de memoria de X, pero la direccion, no el valor)

    // DOS FORMAS DE MOSTRAR X

    printf("X sola, vale %d\n\n", x);

    printf("P, guarda la direccion de memoria de X. y en esa direccion, esta guardado del valor: %d \n\n", *p);

    // %x es HEXADECIMAL %p es POINTER
    printf("-----------------------------------------------\n\n");
    printf("X direccion de memoria %p\n", &x);
    printf("P direccion de memoria %p\n\n", p);
    printf("-----------------------------------------------\n\n");

    printf("antes de la funcion leer puntero, X vale: %d\n\n", x);
    leerPuntero(&x);
    printf("despues de la funcion leer puntero, X vale: %d\n\n", x);

    printf("-----------------------------------------------\n\n");

    int o = 10;
    int* j = &o;
    int** r = &j;

    printf("la variable 'r', tiene la direccion de 'J', y 'J' tiene la direccion de 'o', y 'o' vale: %d\n", **r); //puntero a puntero a puntero a puntero etc etc etc
    printf("\n-----------------------------------------------\n\n");

    int vec[] = {3,5,2,4,3}; // esto es asi a partir de memoria dinamica

    printf("&vec = %x || vec = %x || *vec = %x\n\n", &vec, vec, *vec);

    printf("VECTOR RECORRIDO CON *(VEC+I): ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(vec+i));
    }

    printf("\n\n-----------------------LLAMADAS DE FUNCIONES-----------------------\n\n");
    int tam = 5;
    mostrarVector1(vec, tam);
    mostrarVector2(vec, tam);
    mostrarVector3(vec, tam);
    mostrarVector4(vec, tam);

    printf("-----------------------------------------------\n\n");

    char nombre[20] = "sebastian";
    mostrarCadena(nombre);
    return 0;
}


void leerPuntero (int* p) // int* p va a campturar una direccion de memoria de un entero (ejemplo: "&x" y X es un int)
{
    *p = 38;
}

void mostrarVector1(int vec[], int tam) //recibe con nomenclatura vectorial y trabaja con la misma
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("end of function...\n\n");
} // Lo correcto es esto. si lo recibo como rochete, lo trabajo como corchete. COHERENCIA, DUH

void mostrarVector2(int vec[], int tam) //recibe con nomenclatura vectorial y trabaja con nom. puntero
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(vec+i));
    }
    printf("end of function...\n\n");
} // NO ESTA BIEN VISTO, NO NO NO NO NO >:C

void mostrarVector3(int* vec, int tam) //recibe con nomenclatura puntero y trabaja con nom. vectorial
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("end of function...\n\n");
} // NO ESTA BIEN VISTO, NO NO NO NO NO >:C

void mostrarVector4(int* vec, int tam) //recibe con nomenclatura puntero y trabaja con la misma
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(vec+i));
    }
    printf("end of function...\n\n");
} // esto tambien esta correcto, si utilizo puntero, trabajo con puntero COHERENCIA, DUH UTILIZAR ESTO A TODA COSTA PROGRAMADOR PROFESIONAL

void mostrarCadena(char* nombre)
{
    char* x = nombre;

    while ( *x != '\0' )
    {
        printf("%c", *x);
        x++;
    }
    printf("\n\nend of function...\n\n");
}
