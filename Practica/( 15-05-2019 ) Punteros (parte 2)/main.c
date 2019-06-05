#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* punteroCadena);
void mostrarInt(int* punteroInt);

int main()
{
    // MISMO EXAMEN completar, todos los puntos hechos que compile y que funque bien. se entrega antes del segundo parcial. nota maxima 6
    /*char cadena[] = "hola";
    char* cadenita = cadena;

    int A[] = {1,2,3,4,5};
    int* B = A;

    mostrarCadena(cadenita);
    mostrarInt(B);*/

    // ------------------------------------------------

    int a = 15;
    int* punteroInt;
    int** punteroPuntero;

    punteroInt = &a;
    punteroPuntero = &punteroInt;

    printf("A = %d\n\nIngrese valor de A nuevo: ", **punteroPuntero);

    scanf("%d", *punteroPuntero);
    printf("\n-punteroPuntero- modifico a A que valia 15, ahora A = %d\n", a);


    return 0;
}

/*void mostrarInt(int* punteroInt)
{
    int i=0;
    while(*(punteroInt + i) != '\0')
    {
        printf("%d", *(punteroInt + i) );
        printf(" %p \n", punteroInt + i );
        i++;
        //system("pause");
    }
}

void mostrarCadena(char* punteroCadena)
{

    //printf("%s ", punteroCadena);
    int i=0;
    while(*(punteroCadena + i) != '\0')
    {
        printf("%c", *(punteroCadena + i) );
        printf(" %p \n", punteroCadena + i );
        i++;
        //system("pause");
    }
}*/
