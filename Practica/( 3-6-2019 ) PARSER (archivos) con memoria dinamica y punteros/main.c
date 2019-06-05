#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

void mostrarEmpleados(eEmpleado** lista, int len);
eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();

int listaParaImprimir(eEmpleado** lista, int len, char* path);
int guardarEmpleadosCSV(eEmpleado** lista, int len, char* path);
int guardarEmpleadosBIN(eEmpleado** lista, int len, char* path);

int main()
{
     FILE* f;

     char buffer[4][20]; // datos de entrada (osea datos del archivo)
     eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*)); //sizeof de un puntero a empleado, osea tamaño de una direccion de memoria
     eEmpleado** pAuxEmpleado;
     int cont = 0;
     int cant;

    f = fopen("./empleados.csv","r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while( !feof(f) )
    {

        cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if( cant < 4)
        {
            break;
        }

        eEmpleado* nuevoEmpleado = new_EmpleadoParam(atoi(buffer[0]), buffer[1],buffer[2],atof(buffer[3]));

        *(lista + cont) = nuevoEmpleado;
        cont++;

        pAuxEmpleado = (eEmpleado**) realloc(lista, sizeof(eEmpleado*) *(cont+1));

        if(pAuxEmpleado == NULL)
        {
            exit(1);
        }

        lista = pAuxEmpleado;
    }

    mostrarEmpleados(lista, cont);



    fclose(f);

    if ( listaParaImprimir(lista, cont, "listaEmpleados.txt") == 0 )
    {
        printf("se ha impreso la lista");
    }
    else
    {
        printf("ERROR :c");
    }

    if ( guardarEmpleadosCSV(lista, cont, "Lista de excel") == 0 )
    {
        printf("se ha impreso la lista");
    }
    else
    {
        printf("ERROR :c");
    }

    if ( guardarEmpleadosBIN(lista, cont, "ListaBinaria") == 0 )
    {
        printf("se ha impreso la lista");
    }
    else
    {
        printf("ERROR :c");
    }

    return 0;
}


void mostrarEmpleados(eEmpleado** lista, int len)
{
    for(int i=0; i < len; i++)
    {
        printf(" %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");
}


eEmpleado* new_Empleado()
{

    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = 0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;

    }
    return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo)
{
    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = leg;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;
    }

    return emp;

}

int listaParaImprimir(eEmpleado** lista, int len, char* path)
{
    int error = 0;

    FILE* f = fopen(path, "w");

    if (f == NULL)
    {
        error = 1;
    }
    else
    {
        fprintf(f, "listado de empleados\n\n");
        fprintf(f, "Legajo | Nombre | Apellido | Sueldo\n\n");
        for(int i=0; i < len; i++)
        {
            fprintf(f," %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
        }
    }
    fclose(f);
    printf("\n\n");
    return error;
}

int guardarEmpleadosCSV(eEmpleado** lista, int len, char* path)
{
    char extencion[] = ".csv";
    char nombreArchivo[100];
    int error = 0;
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, extencion);

    FILE* f = fopen(nombreArchivo, "w");

    if (f == NULL)
    {
        error = 1;
    }
    else
    {
        fprintf(f, "id,first_name,last_name,sueldo\n");
        for(int i=0; i < len; i++)
        {
            fprintf(f,"%d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
        }
    }
    fclose(f);
    printf("\n\n");
    return error;
}

int guardarEmpleadosBIN(eEmpleado** lista, int len, char* path)
{
    char extencion[] = ".bin";
    char nombreArchivo[100];
    int error = 0;
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, extencion);

    FILE* f = fopen(nombreArchivo, "wb");

    if (f == NULL)
    {
        error = 1;
    }
    else
    {
        fprintf(f, "id,first_name,last_name,sueldo\n");
        for(int i=0; i < len; i++)
        {
            fwrite( *(lista+i) , sizeof(eEmpleado), 1, f);
            //fprintf(f,"%d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
        }
    }
    fclose(f);
    printf("\n\n");
    return error;
}

//para leevantar empleados desde el binario

/*

    fopen ==== path de empleados.bin, "rb"
    fscanf no se usa
    *(lista + cont) = nuevoEmpleado;
    cant = fread( *nuevoEmpleado ,sizeof(eEmpleado), 1, f;
    (if cant < 1)

    homework: hacer un programita con... (y colarle un abm)
    *hacer listado TEXTO
    *cargar empleado CSV
    *guardar empleado CSV
    *cargar empleado BIN
    *guardar empleado BIN
*/
