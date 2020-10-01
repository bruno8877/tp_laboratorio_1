#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

//#define A 1000
#define A 3


int main()
{
    eEmployee list[A];
    int opcion;
    int flag = 0;
    int proximoId = 1000;
    initEmployees(list, A);



        do
        {
            printf("\n****** MENU DE EMPLEADOS ******\n");
            printf("-------------------------------------------------------------|");
            printf("\n1. Alta                                                      |\n");
            printf("2. Modificar                                                 |\n");
            printf("3. Baja de empleado                                          |\n");
            printf("4. Informes                                                  |\n");
            printf("5. Salir                                                     |\n");
            printf("-------------------------------------------------------------|");
            printf("\nElija una opcion\n");
            scanf("%d", &opcion);



            switch(opcion)
            {
            case 1:// se pide que ingrese los datos del empleado, se muestra la lista de empleados para ver cada vez que se carga un empleado mas

                system("cls");


                if(addEmployees(proximoId,list, A)== 0)
                {
                    proximoId++;
                    printf("\nEl alta fue exitosa...\n\n");
                    printf("\n");
                    PrintEmployeers(list, A);
                }
                flag = 1;


                break;

            case 2:// se muestra la lista de los empleados con sus datos, despues se pide la id del empleado para modificar dichos datos.
                if(flag == 1)
                {
                    PrintEmployeers(list, A);
                    printf("\n");
                    modifyEmployee(list, A, 0);

                }
                else
                {
                    printf("\nNo hay empleados cargados\n");


                }
                break;

            case 3://se ingresa la ID del empleado para darle de baja, se valida preguntando si le quiere dar de baja si o no
                if(flag == 1)
                {
                    system("cls");
                    printf("\n");
                    removeEmployee(list, A,0);
                }
                else
                {
                  printf("\nNo hay empleados cargados\n");


                }
                break;

               case 4://se muestra la lista de empleados ya ordenada
                if(flag == 1)
                {

                    informes(list, A);

                }
                else
                {
                    printf("\nNo hay empleados cargados\n");


                }
                break;

            case 5://Salir
                opcion=5;
                printf("Saliendo... \n");
                break;

            default:
                printf("Error. Por favor elija una opcion valida.\n");
                break;

            }
            system("pause");//pone pausa
            system("cls");//limpia la consola


        }
        while(opcion != 5);




    return 0;



}

















