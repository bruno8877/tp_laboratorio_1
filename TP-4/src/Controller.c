#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(parser_EmployeeFromText(f,pArrayListEmployee))
        {
            todoOk =0;
            printf("\nLos datos del archivo de modo texto se han cargado con exito...\n");
        }

    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 1;//error
    FILE* f;

    f = fopen(path, "rb");

    if(f != NULL)
    {
        if(!parser_EmployeeFromBinary(f, pArrayListEmployee))
        {
            todoOk = 0; //exito
            printf("Archivo cargado con exito\n");
        }
        else
        {
            printf("No se pudo leer el archivo correctamente\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }
    fclose(f);
    return todoOk;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

    if(altaEmpleado(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char auxNombre[128];
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    int option;
    int tamList;


    Employee* auxEmployeeModify;
    tamList = ll_len(pArrayListEmployee);


    if(pArrayListEmployee!=NULL)
    {
        utn_getEntero(&auxId,2,"Ingrese el id(1-2000): ","Error. Reingrese el id\n",1,2000);


        for(int i=0; i<tamList; i++)
        {
            auxEmployeeModify = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxId==auxEmployeeModify->id)
            {


                do
                {

                    printf("\n****** Menu de modificacion de empleado ******\n");
                    printf("\n*** Que desea modificar *** \n");
                    printf("\n1. Para modificar el nombre del empleado.\n");
                    printf("2. Para modificar las horas trabajadas\n");
                    printf("3. Para modificar el sueldo \n");
                    printf("4. Para salir. \n");
                    printf("\nElija una opcion\n");
                    scanf("%d", &option);

                    switch(option)
                    {
                    case 1:
                        system("cls");
                        printf("Ingrese nombre: ");
                        fflush(stdin);
                        scanf("%s", auxNombre);
                        employee_setNombre(auxEmployeeModify, auxNombre);
                        printf("\nEl nombre fue modificado con exito...\n");

                        break;
                    case 2:
                        system("cls");
                        utn_getEntero(&auxHorasTrabajadas,2,"Ingrese horas trabajadas(1-2000): ","Error. Reingrese horas trabajadas\n",1,2000);

                        employee_setHorasTrabajadas(auxEmployeeModify,auxHorasTrabajadas);
                        printf("\nLas horas trabajadas fueron modificadas con exito...\n");

                        break;
                    case 3:
                        system("cls");
                        utn_getEntero(&auxSueldo,2,"Ingrese el sueldo(3000-200000): ","Error. Reingrese el sueldo\n",3000,200000);

                        employee_setSueldo(auxEmployeeModify,auxSueldo);
                        printf("\El sueldo fue modificado con exito...\n");


                        break;
                    case 4:
                        system("cls");
                        option = 4;
                        break;
                    default:
                        printf("\nIngrese una opcion valida...\n");
                        break;
                    }
                    system("pause");//pone pausa
                    system("cls");//limpia la consola
                }
                while(option != 4);
            }

        }


    }


    return 0;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    if(bajaEmpleado(pArrayListEmployee)==0)
    {
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSalario;
    int tam=1;

    tam = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        printf("   Id           Nombre       Horas trabajadas     Sueldo \n");

        for(int i=1; i<tam; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getHorasTrabajadas(auxEmployee,&auxHorasTrabajadas);
            employee_getSueldo(auxEmployee,&auxSalario);
            printf("%5d  %15s %15d  %15d\n",auxId, auxNombre, auxHorasTrabajadas, auxSalario);

        }
    }
    else
    {
        printf("\nError, los datos no se pudieron cargar");
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int option;
    LinkedList* auxList=ll_clone(pArrayListEmployee);
    if(pArrayListEmployee != NULL)
    {
        do
        {
            printf("\n****** Menu de ordenamiento de empleados ******\n");
            printf("\n*** De que manera desea ordenar los empleados *** \n");
            printf("\n1. Por nombre.\n");
            printf("2. Por ID.\n");
            printf("3. Por sueldo.\n");
            printf("4. Por horas trabajadas.\n");
            printf("5. Para salir.\n");
            printf("\nElija una opcion\n");
            scanf("%d", &option);

            switch(option)
            {
            case 1:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaNombre,1);
                controller_ListEmployee(auxList);


                break;

            case 2:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaId,1);
                controller_ListEmployee(auxList);

                break;

            case 3:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaSueldo,1);
                controller_ListEmployee(auxList);


                break;

            case 4:
                system("cls");
                system("pause");
                ll_sort(auxList, employee_ComparaHorasTrabajadas,1);
                controller_ListEmployee(auxList);


                break;

            case 5:
                system("cls");
                option = 5;
                break;

            default:
                printf("\nIngrese una opcion valida...\n");
                break;
            }
        }
        while(option != 5);

    }

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int tamList;
    int todoOK=1;
    int AuxId;
    char auxNombre[51];
    int auxhorasTrabajadas;
    int auxSueldo;
    Employee* auxEmployeeSaveText;
    FILE* pFile;
    pFile = fopen(path, "w");

    tamList = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && path !=NULL)
    {
        todoOK =0;
        fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

        if(pFile != NULL)
        {
            for(int i=1; i<tamList; i++)
            {
                auxEmployeeSaveText = (Employee*)ll_get(pArrayListEmployee, i);

                        employee_getId(auxEmployeeSaveText, &AuxId);
                        employee_getNombre(auxEmployeeSaveText, auxNombre);
                        employee_getHorasTrabajadas(auxEmployeeSaveText,&auxhorasTrabajadas);
                        employee_getSueldo(auxEmployeeSaveText,&auxSueldo);

                    fprintf(pFile, "%d,%s,%d,%d\n", AuxId, auxNombre, auxhorasTrabajadas,auxSueldo);


            }
            fclose(pFile);
            printf("\nArchivo guardado...\n");
        }


    }

    return todoOK;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int tamList;

    Employee* auxEmployeeSaveBin;
    FILE*pFile;
    pFile= fopen(path, "wb");

    tamList = ll_len(pArrayListEmployee);

    if(pFile == NULL)
    {

        printf("Error al guardar..\n");
        return 0;
    }

    if(pArrayListEmployee!=NULL)
    {
        for(int i=1; i<tamList; i++)
        {
            auxEmployeeSaveBin = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmployeeSaveBin,sizeof(Employee), 1, pFile);
        }
        printf("\nArchivo Guardado...\n");
    }

    fclose(pFile);
    return 1;

}

