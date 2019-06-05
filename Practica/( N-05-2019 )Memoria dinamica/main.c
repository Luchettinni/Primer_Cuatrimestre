#include <stdio.h>
#include <stdlib.h>

typedef struct{

int legajo;
char nombre[20];
char sexo;
float sueldo;
int isEmpty;

} eEmpleado;

int valptr (void* pointer);
void sortPtr(int* pointerToSort, int lenght);
void loadPtr(int start, int lenght, int* pointerToShow);
void printPtr(char message[], int* pointer, int lenght, int start);
eEmpleado* newStruct ();

int main()
{
    /*int* x;

    x = (int*) malloc(sizeof(int));
    //x = NULL;

    if ( valptr(x) == -1 )
    {
        printf("TE FALLO EL PROGRAMA K-PO :v\n");
        system("pause");
        exit(1);
    }

    *x = 10;
    printf("funco, x = %d\n", *x);
    free(x);
    printf("se libero la memoria..., x = %d\n", *x);*/

    //-------------------------------------------------------------------

    /*int* x;

    x = (int*) malloc(sizeof(int) * 5);

    if (valptr(x) == -1)
    {
        exit(1);
    }

    loadPtr(0, 5, x);
    sortPtr(x, 5);
    printPtr("Esto vale: ", x, 5, 0);

    printf("\n\nagrandando el array a 10 elementos...\n\n");

    int* auxx;
    auxx = realloc(x, sizeof(int) * 10);

    if ( auxx != NULL )
    {
        x = auxx;
    }
    else
    {
        printf("\nno se pudo agrandar el tamaño...\n\n");
    }

    loadPtr(5,10,x);
    sortPtr(x, 10);
    printPtr("esto vale: ", x, 10, 0);

    printf("\n\nreduciendo el array a 5 elementos nuevamente...\n\n");

    auxx = realloc(x, sizeof(int) * 5);

    if ( auxx != NULL )
    {
        x = auxx;
    }
    else
    {
        printf("\nno se pudo achicar el tamaño...\n\n");
    }

    printPtr("esto vale: ", x, 10, 0);*/

    //-------------------------------------------------------------------

    eEmpleado* pemp = newStruct();
    if(pemp == NULL)
    {
        exit (1);
    }

    printf("\nnombre: legajo: %d | nombre: %s | sexo: %c | sueldo: %.2f | isEmpty: %d", pemp->legajo, pemp->nombre, pemp->sexo, pemp->sueldo, pemp->isEmpty);

    printf("ingrese legajo: ");
    scanf("%d", &pemp->legajo);

    printf("ingrese nombre: ");
    //gets(pemp->nombre);
    scanf("%s", pemp->nombre);
    fflush(stdin);

    printf("ingrese sexo: ");
    scanf("%c", &pemp->sexo);
    fflush(stdin);

    printf("ingrese sueldo: ");
    scanf("%f", &pemp->sueldo);

    pemp->isEmpty = 1;

    printf("\nnombre: legajo: %d | nombre: %s | sexo: %c | sueldo: %.2f | isEmpty: %d", pemp->legajo, pemp->nombre, pemp->sexo, pemp->sueldo, pemp->isEmpty);
    fflush(stdin);

    return 0;
}

//----------------------------------------------------------------------------------------------------

int valptr (void* pointer)
{
    int todoOK = 0;

    if (pointer == NULL)
    {
        todoOK = -1;
    }

    return todoOK;
}

void sortPtr(int* pointerToSort, int lenght)
{
    int aux;

    for (int k = 0; k < lenght; k++)
    {
        for (int l = k + 1; l < lenght; l++)
        {
            if ( *(pointerToSort+k) > *(pointerToSort+l) )
            {
                aux = *(pointerToSort+k);
                *(pointerToSort+k) = *(pointerToSort+l);
                *(pointerToSort+l) = aux;
            }
        }
    }
}

void loadPtr(int start, int lenght, int* pointerToShow)
{
    for (int i = start; i < lenght; i++)
    {
        printf("ingrese un numero (intento %d):", i+1 );
        scanf("%d", pointerToShow+i );
    }
}

void printPtr(char message[], int* pointer, int lenght, int start)
{
    for ( int j = start; j < lenght; j++)
    {
        printf("%s", message);
        printf("%d\n", *(pointer+j) );
    }
}

eEmpleado* newStruct()
{
    eEmpleado* estruct = (eEmpleado*) malloc(sizeof(eEmpleado));
    if (estruct == NULL)
    {
        estruct->legajo = 0;
    }
    return estruct;
}
