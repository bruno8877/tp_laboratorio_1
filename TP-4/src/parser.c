#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* auxEmployee;
    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListEmployee);

        char buffer[4][128];

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {


            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
            if (cant == 4)
            {
                auxEmployee = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                if (auxEmployee != NULL)
                {

                    ll_add(pArrayListEmployee, auxEmployee);
                    todoOk = 1;

                }
            }

        }

    }



    return todoOk;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        ll_clear(pArrayListEmployee);
        do
        {
            auxEmployee = employee_new();
            if(fread(auxEmployee, sizeof(Employee), 1, pFile) == 1)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                todoOk = 0;
            }
        }while(!feof(pFile));
    }


    return todoOk;
}
