#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validation.h"


int initEmployees(eEmployee* list, int len)
{
    int TODOok = 1;
    if(list !=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty =1;
            strcpy(list[i].name," ");
            strcpy(list[i].lastName," ");
            list[i].salary=0;
            list[i].sector=0;
            list[i].id=0;
        }
        TODOok =0;
    }

    return TODOok;
}

void PrintEmployee(eEmployee unEmpleado)
{
    printf(" %2d      %8s      %10s        %.2f      %5d\n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector);
}

int PrintEmployeers(eEmployee* list, int len)
{
    int TODOok = 1;
    int flag=0;

    if(list !=NULL && len>0)
    {
        printf("********************** Listado de Empleados ***********************\n");
        printf("------------------------------------------------------------------\n");
        printf(" ID          Nombre        Apellido         Salario       Sector\n");
        printf("------------------------------------------------------------------\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty ==0)
            {
                PrintEmployee(list[i]);
                flag =1;
            }
        }

        if(flag ==0)
        {
            printf("No hay empleados cargados...\n\n");
        }
        else
        {
            printf("\n\n");
        }
        TODOok =0;
    }

    return TODOok;
}

int addEmployees(int idx,eEmployee* list,int len)
{
    int TODOok = 1;
    int indice;
    eEmployee newEmployee;

    if(list !=NULL && len >0 && idx > 0)
    {
        indice = buscarLibre(list, len);
        if(indice == -1)
        {
            printf("Sistema Completo...\n\n");
        }
        else
        {
            newEmployee.id = idx;
            getStr("\nIngrese el nombre del empleado: ", newEmployee.name);
            getStr("\nIngrese el apellido del empleado: ", newEmployee.lastName);
            printf("\n");
            utn_getFlotante(&newEmployee.salary, 2, "Ingrese sueldo (1000-200000): ", "\nError. Reingrese sueldo\n", 1000, 200000);
            newEmployee.sector = getInt("\nIngrese el sector: ");
            newEmployee.isEmpty = 0;

            list[indice] = newEmployee;
            TODOok = 0;
        }

    }
    return TODOok;
}

int buscarLibre(eEmployee* list, int len)
{
    int indice = -1;

    for(int i =0; i< len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int retorno = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty == 0)
        {
            retorno = i;
            break;

        }
    }
    return retorno;
}

int removeEmployee(eEmployee* list, int len,int id)
{
    int existe;
    char confirma;

    PrintEmployeers(list, len);
    printf("***** Baja Empleado *****\n\n");
    id = getInt("\nIntroduzca el id:\n");

    existe = findEmployeeById(list, len,id);

    if(existe == -1)
    {
        printf("Error. No hay registro de un empleado con el id: %d\n", id);

    }
    else
    {
        printf("\n");
        PrintEmployee(list[existe]);
        printf("\nEsta seguro de eliminarlo? (s para si/ n para no)\n");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            list[existe].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }

        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

    return 0;
}

int modifyEmployee(eEmployee* list, int len, int id)
{
    int existe;
    char confirma;
    int opcion;
    char newName[51];
    char newLastname[51];
    float newSalary;
    int newSector;


    system("cls");
    PrintEmployeers(list, len);
    printf("***** Modificar Empleado *****\n");
    id = getInt("\nIntroduzca el id del empleado a modificar:\n");

    existe = findEmployeeById(list, len, id);

    if(existe == -1)
    {
        printf("Error. No hay registro de un empleado con el id: %d\n", id);

    }

    else
    {
        printf("\n");
        printf("El empleado a modificar es: ");
        PrintEmployee(list[existe]);
        printf("\nEsta seguro de modificar? (s para si/ n para no)\n");
        fflush(stdin);
        scanf("%c",&confirma);
        PrintEmployeers(list, len);

        if(confirma == 's')
        {
            do
            {
                system("cls");
                PrintEmployeers(list, len);
                printf("\n*** Que desea modificar? ***  \n");
                printf("    1. Modificar nombre\n");
                printf("    2. Modificar apellido\n");
                printf("    3. Modificar salario\n");
                printf("    4. Modificar sector\n\n");
                printf("    5. Volver al menu inicial \n");
                printf("\nElija una opcion\n");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    getStr("\nIngrese el nuevo nombre del empleado: ", newName);
                    strcpy(list[existe].name, newName);
                    printf("\nSe ha actualizado el nombre con exito...\n\n");
                    system("pause");
                    break;
                case 2:
                    getStr("\nIngrese el nuevo apellido del empleado: ", newLastname);
                    strcpy(list[existe].lastName, newLastname);
                    printf("\nSe ha actualizado el apellido con exito..\n\n");
                    system("pause");
                    break;
                case 3:

                    printf("\nIngrese el nuevo salario: ");
                    scanf("%f", &newSalary);
                    list[existe].salary = newSalary;
                    printf("\nSe ha actualizado el sueldo con exito...\n\n");
                    system("pause");
                    break;
                case 4:
                    newSector=getInt("\nIngrese el nuevo Sector: ");
                    list[existe].sector = newSector;
                    printf("\nSe ha actualizado el sector con exito...\n\n");
                    system("pause");
                    break;
                case 5://Salir
                    opcion=5;
                    printf("Volviendo al menu inicial... \n");

                    break;
                default:
                    printf("No es una opcion valida.\n\n");

                }





            }
            while(opcion != 5);
        }

    }

    return 0;
}

void informes(eEmployee* list, int len)
{

    int opcion;

    do
    {
        switch(menuInformes(opcion))
        {
        case 1:
            sortEmployees(list, len, 1);
            PrintEmployeers(list, len);
            break;
        case 2:
            informarSalarios(list, len);
            printf("\n");
            break;
        case 3:
            opcion =3;
            printf("Saliendo... \n");
            break;

        default:
            printf("Error. Por favor elija una opcion valida.\n");
            break;

        }
        system("pause");//pone pausa

    }
    while(opcion != 3);
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("\n***** INFORMES DE EMPLEADOS *****\n");
    printf("------------------------------------------------------------------------------------------|");
    printf("\n1. Listar empleados ordenados alfabeticamente por Apellido y Sector)                      |\n");
    printf("2. Mostrar total de salarios y promedio, y cuantos empleados superan el salario promedio  |\n");
    printf("3. Volver al menu inicial                                                                 |\n");
    printf("------------------------------------------------------------------------------------------|");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int sortEmployees(eEmployee* list, int len, int order)
{
    system("cls");
    eEmployee auxEmpleado;

    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(list[i].sector > list[j].sector)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
            else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }
        }
    }

    return 0;
}

int informarSalarios(eEmployee* list, int len)
{
    int i;
    float total = 0;
    int accountant = 0;
    float average = 0;
    int retorno=-1;
    int accountantHigh = 0;

    if(list!=NULL && len>=0)
    {


        for (i=0; i<len; i++)
        {

            if (list[i].isEmpty == 1)
            {
                continue;

            }
            else
            {
                total += list[i].salary;
                accountant++;
            }
        }
        average =  total/ accountant;

        for(i=0; i<len; i++)
        {
            if(list[i].salary>average)
            {
                accountantHigh++;
            }
        }

        printf("\nEl total de los salarios es : %.2f\n",total);
        printf("\nEl promedio total de salarios es : %.2f\n",average);
        printf("\nEl total de empleados que superan los salarios promedio son : %d\n",accountantHigh);
        printf("\n");
        retorno=0;

    }
    return retorno;
}

