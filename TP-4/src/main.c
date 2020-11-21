/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"



int main(void)
{
        //DESMARCAR PARA VERIFICAR LAS FUNCIONES DEL LINKEDLIST
        /*startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort*/

  int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listafiltrada;
    int flagText = 0;
    int flagBin = 0;

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
        printf("10. Filtrar lista de empleados por sueldo en rango mayor a 25000\n");
        printf("11. Eliminar lista\n");
        printf("12. Salir \n");
        printf("\nElija una opcion\n");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            //CARGAR LOS DATOS MODO TEXTO
            if(flagText ==0)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                flagText = 1;
            }
            else
            {
                printf("\nEl archivo modo texto ya fue cargado...\n");
            }

            break;
        case 2:
            //CARGAR LOS DATOS MODO BINARIO
            if(flagBin ==0)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                flagBin =1;
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
                controller_saveAsText("data1.csv",listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 9:
            if(flagText==1 || flagBin==1)
            {
                controller_saveAsBinary("data1.bin",listaEmpleados);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 10:
                    //FILTRAR POR RANGO SUELDO
            if(flagText==1|| flagBin==1)
            {
                listafiltrada = ll_filter(listaEmpleados, comparaSueldo);
                controller_saveAsText("listaFiltrada.csv", listafiltrada);

            }
            else
            {
                printf("Debe cargar los empleados para poder filtrarlos\n");
            }
        break;

            case 11:
                if(flagText==1 || flagBin==1)
                {
                    ll_deleteLinkedList(listaEmpleados);
                    listaEmpleados=NULL;
                    printf("\nLa lista se elimino con exito...\n");
                    system("pause");
                }

                    break;

        case 12:
            option=12;
            printf("Saliendo...");
            break;

        default:
            printf("Opcion invalida...");
            break;
        }
        system("pause");//pone pausa
        system("cls");//limpia la consola
    }
    while(option != 12);
    return 0;

}

































