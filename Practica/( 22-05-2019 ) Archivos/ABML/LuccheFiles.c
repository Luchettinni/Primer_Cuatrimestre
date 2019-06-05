#include <stdio.h>
#include <stdlib.h>

#ifndef LUCCHEFILES_H_INCLUDED
#define LUCCHEFILES_H_INCLUDED

#include "LuccheFiles.h"

#endif // LUCCHEFILES_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

int readFile(FILE* fileToRead, char path[], sEmpleado persona)
{
    int cant;

    // ABRIR ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    if ( (fileToRead = fopen(path,"rb+") ) == NULL )
	{
		printf("No se pudo abrir el archivo");
		exit(1);
	}
    else
    {
        printf("el archivo se abrio correctamente!\n\n");

    }

    //-------------------------------------------------------------------------------------------------------------//


    // LECTURA DEL ARCHIVO...
    //-------------------------------------------------------------------------------------------------------------//

    rewind(fileToRead);

    while ( !feof(fileToRead) ) // mientras no llego a el END OF FILE...
    {
        fflush(stdin);
        cant =  fread( &persona, sizeof(persona), 1, fileToRead ); // con cada iteracion, "cant" es la cantidad de elementos que logro leer. como trabajamos con estructuras, leer muchos elementos de UNA estructura resulta en "1"

        if (cant != 1) // si no se llego a leer un elemento del archivo...
        {
            if (feof(fileToRead)) // llegue al fin del archivo?
            {
                break; // sep, entonces termine de leer.
            }
            else
            {
                printf("ERROR: no se pudo leer el ultimo registro..."); //nop, entonces hubo un error, termine de leer.
                break;
            }
        }
        if( persona.isEmpty == 0)
        {
           printf("\nLegajo: %d | Nombre: %s | Apellido: %s ", persona.legajo, persona.nombre, persona.apellido);
        }

    }

    //-------------------------------------------------------------------------------------------------------------//

    fclose(fileToRead);

    return 0;
}

int writeFile(FILE* fileToWrite, char path[], sEmpleado persona)
{
    // ABRIR ARCHIVO
    //-------------------------------------------------------------------------------------------------------------//

    int error = 0;

    if ( (fileToWrite = fopen(path,"wb+") ) == NULL )
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
        getString(persona.nombre, "ingrese nombre del empleado: ", "ERROR: nombre demsiado corto / largo.", 2, 21);

        printf("ingrese apellido:");
        gets(persona.apellido);

        fseek(fileToWrite, 0L, SEEK_END);
        fwrite(&persona, sizeof(persona),1,fileToWrite);
    }

    //-------------------------------------------------------------------------------------------------------------//

    fclose(fileToWrite);
    return error;
}
