#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifndef LUCCHEFILES_H_INCLUDED
#define LUCCHEFILES_H_INCLUDED

#include "LuccheFiles.h"

#endif // LUCCHEFILES_H_INCLUDED


#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED


#define DATA	".\\Peter.data"
int MenuPrincipal();
int MenuDeEmpleados();
void loadPtr(int start, int lenght, sEmpleado* pointerToShow);
void printPtr(char message[], sEmpleado* pointerToShow, int lenght, int start);

void altaEmpleado(sEmpleado* pointerToShow, int tam_Empleados);
int buscarEspacioLibre(sEmpleado* pointerToShow, int tam_Empleado);
int saveFile(FILE* fileToWrite, char path[], sEmpleado* pointerToSave, int tam_Empleados);
int loadData(FILE* fileToWrite, char path[], sEmpleado* pointerToSave, int tam_Empleados);

int main()
{

    int tamEmpleado = 15; // tamaño maximo de lo que permito guardar en tiempo de ejecucion
    int opcion; // opcion para los switch (menu de opciones, etc)
    FILE* savedData; // creo una estructura de tipo FILE* para poder trabajar con archivos
    sEmpleado* empleado;

    empleado = (sEmpleado*) malloc(sizeof(sEmpleado) * tamEmpleado); // hago espacio en memoria para la estructura
    // y aca me parece que me falta un if... ya lo vere mas tarde.

    if ( ( savedData = fopen(DATA, "rb") ) == NULL ) // busco y abro un archivo en el path DATA. si no lo encuentro...
    {
        if ( ( savedData = fopen(DATA, "wb") ) == NULL ) //creo uno nuevo de escritura, y si no lo puedo crear...
        {
            printf("ERROR: no hay suficiente espacio en la pc / error de permisos / problema desconocido."); // error
            exit(1); // salgo del programa por no poder realizar guardado de archivos
        }

        for (int i = 0; i < tamEmpleado; i++) // inicializo mi estructura con todos isEmpty en 1
        {
            (empleado+i)->isEmpty = 1;
        }
        saveFile(savedData,DATA,empleado,tamEmpleado); // la funcion SAVEFILE guarda todos los datos de la estructura, en un archivo
        fclose(savedData);
    }

    loadData(savedData,DATA,empleado,tamEmpleado); // la funcion LOADDATA carga los datos de un archivo a una estructura.
    do
    {
        system("cls");
        opcion = 0;
        switch (MenuPrincipal())
        {
            case 1:
                do
                {
                    system("cls");
                    switch (MenuDeEmpleados())
                    {
                        case 1:
                            //writeFile(savedData, DATA, *empleado);
                            altaEmpleado(empleado,tamEmpleado);
                            printPtr("aaa",empleado, tamEmpleado, 0);
                            saveFile(savedData,DATA,empleado,tamEmpleado);
                            system("pause");
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            opcion = 2;
                            break;
                    }
                } while (opcion != 2);

                break;

            case 2:
                readFile(savedData, DATA, *empleado);
                system("pause");
                break;

            case 3:
                opcion = 1;
                break;

            default:
                break;
        }

    } while (opcion != 1);

    return 0;
}

int MenuPrincipal()
{
    int opcion;

    printf("---------- EMPLEADOS ---------- // Menu principal\n");
    printf("1) Empleados\n");
    printf("2) Informes\n");
    printf("3) Salir...\n\n");
    printf("Early dev-build v0.2\n\n");

    printf("que desea hacer?: ");
    scanf("%d", &opcion);

    return opcion;
}

int MenuDeEmpleados()
{
    int opcion;

    printf("---------- EMPLEADOS ---------- // Menu principal // Empleados\n");
    printf("1) Alta Empleado\n");
    printf("2) Baja Empleado\n");
    printf("3) Modificar Empleado\n");
    printf("4) Salir...\n\n");

    printf("que desea hacer?: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarEspacioLibre(sEmpleado* pointerToShow, int tam_Empleado)
{
    int indice = -1;
    for ( int i = 0; i < tam_Empleado; i++)
    {
        if ( (pointerToShow+i)->isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(sEmpleado* pointerToShow, int tam_Empleados)
{
    int indice = buscarEspacioLibre(pointerToShow,tam_Empleados);
    getString( (pointerToShow+indice)->nombre, "ingrese nombre del empleado: ", "ERROR: nombre demsiado corto / largo.", 2, 21);
    getString( (pointerToShow+indice)->apellido, "ingrese nombre del empleado: ", "ERROR: nombre demsiado corto / largo.", 2, 21);
    (pointerToShow+indice)->isEmpty = 0;
}

int saveFile(FILE* fileToWrite, char path[], sEmpleado* pointerToSave, int tam_Empleados)
{
    // ABRIR ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    int error = 0;

    if ( (fileToWrite = fopen(path,"rb+") ) == NULL )
	{
		printf("No se pudo abrir el archivo");
		error = 1;
	}
    else
    {
        printf("el archivo se abrio correctamente!\n\n"); // DEBUG MESSAGE

    }

    //-------------------------------------------------------------------------------------------------------------//


    // CAMPOS A ESCRIBIR Y ESCRITURA EN EL ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    if(error == 0)
    {
        for ( int i = 0; i < tam_Empleados; i++)
        {
            if( (pointerToSave+i)->isEmpty == 0 || (pointerToSave+i)->isEmpty == 1)
            {
                fseek(fileToWrite,  (long) (i) * sizeof(*pointerToSave), SEEK_SET);
                fwrite((pointerToSave+i), sizeof(*pointerToSave),1,fileToWrite);
            }
        }
    }

    //-------------------------------------------------------------------------------------------------------------//

    fclose(fileToWrite);
    return error;
}


int loadData(FILE* fileToWrite, char path[], sEmpleado* pointerToSave, int tam_Empleados)
{
    // ABRIR ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    int error = 0;

    if ( (fileToWrite = fopen(path,"rb+") ) == NULL )
	{
		printf("No se pudo abrir el archivo");
		error = 1;
	}
    else
    {
        printf("el archivo se abrio correctamente!\n\n"); // DEBUG MESSAGE

    }

    //-------------------------------------------------------------------------------------------------------------//


    // CAMPOS A ESCRIBIR Y ESCRITURA EN EL ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    if(error == 0)
    {
        for ( int i = 0; i < tam_Empleados; i++)
        {
            fseek(fileToWrite,  (long) (i) * sizeof(*pointerToSave), SEEK_SET);
            fread((pointerToSave+i), sizeof(*pointerToSave),1,fileToWrite);
        }
    }

    //-------------------------------------------------------------------------------------------------------------//

    fclose(fileToWrite);
    return error;
}

void loadPtr(int start, int lenght, sEmpleado* pointerToShow)
{
    for (int i = start; i < lenght; i++)
    {
        printf("ingrese un legajo (intento %d):", i+1 );
        scanf("%d", &(pointerToShow+i)->legajo );
    }
}

void printPtr(char message[], sEmpleado* pointerToShow, int lenght, int start)
{
    for ( int j = start; j < lenght; j++)
    {
        if( (pointerToShow+j)->isEmpty == 0 )
        {
            printf("%s", message);
            printf("%d\n", (pointerToShow+j)->isEmpty);
            printf("%s\n", (pointerToShow+j)->nombre);
        }
    }
}
