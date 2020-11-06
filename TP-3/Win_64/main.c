#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flagText = 0;
    int flagBin = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("\n------Menu de empleados------\n");
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
        printf("3. Alta de empleado \n");
        printf("4. Modificar datos de empleado \n");
        printf("5. Baja de empleado \n");
        printf("6. Listar empleados \n");
        printf("7. Ordenar empleados \n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario). \n");
        printf("10. Salir \n");
        printf("\nElija una opcion\n");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            if(flagText==0)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                flagText=1;

            }
            else
            {
                printf("\nEl archivo modo texto ya fue cargado...\n");
            }

            break;
        case 2:
            if(flagBin==0)
            {

                controller_loadFromBinary("data.bin",listaEmpleados);
                flagBin=1;
            }
            else
            {

                printf("\nEl archivo modo binario ya fue cargado...\n");
            }
            break;
        case 3:
            if(flagText==1 || flagBin==1)
            {
                 controller_addEmployee(listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }

            break;
        case 4:
            if(flagText==1 || flagBin==1)
            {
                controller_ListEmployee(listaEmpleados);
                controller_editEmployee(listaEmpleados);

            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 5:
            if(flagText==1 || flagBin==1)
            {
                controller_ListEmployee(listaEmpleados);
                controller_removeEmployee(listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 6:
            if(flagText==1 || flagBin==1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;

        case 7:
            if(flagText==1 || flagBin==1)
            {
            controller_sortEmployee(listaEmpleados);


            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;

        case 8:
            if(flagText==1 || flagBin==1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 9:
            if(flagText==1 || flagBin==1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;

        case 10:
            option=10;
            printf("Saliendo...");
            break;

        default:
            printf("Opcion invalida...");
            break;
        }
        system("pause");//pone pausa
        system("cls");//limpia la consola
    }
    while(option != 10);
    return 0;
}
