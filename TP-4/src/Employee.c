#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validaciones.h"
#include "Controller.h"



int findEmployeeById(LinkedList* lista, int id,int* indice)
{
    int tam = ll_len(lista);
    int todoOk = 1;
    Employee* auxEmployee;
    *indice = -1;

    for(int i = 0; i < tam; i++)
    {
        auxEmployee = (Employee*) ll_get(lista,i);
        if(auxEmployee->id == id)
        {
            *indice = i;
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

int altaEmpleado(LinkedList* lista)
{
       int todoOK = -1;
    int auxInt;
    int indice;

    Employee* auxEmployee;

    auxEmployee = (Employee*) employee_new();

    if(auxEmployee != NULL && lista != NULL)
    {

        system("cls");

        printf("***** ALTA EMPLEADO *****\n\n");

        while(todoOK==-1)
        {
            //ID
            if((utn_getEntero(&auxInt,2,"Ingrese el id(1001-2000): ","Error. Reingrese el id\n",1001,2000))==0)
            {
                if(findEmployeeById(lista,auxInt,&indice)==1)
                {
                    employee_setId(auxEmployee,auxInt);
                }
                else
                {
                    printf("El id ingresado ya existe\n");
                    todoOK=1;
                    break;
                }
            }

            //NOMBRE

                      printf("Ingrese nombre: ");
                    fflush(stdin);
                    scanf("%s", auxEmployee->nombre);


            //HORAS TRABAJADAS
            if((utn_getEntero(&auxInt,2,"Ingrese horas trabajadas(1-300): ","Error. Reingrese horas trabajadas\n",1,300))==0)
            {
                employee_setHorasTrabajadas(auxEmployee,auxInt);
            }

            //SUELDO
            if((utn_getEntero(&auxInt,2,"Ingrese el sueldo(3000-200000): ","Error. Reingrese el sueldo\n",3000,200000))==0)
            {
                employee_setSueldo(auxEmployee,auxInt);
                todoOK=0;
            }

        }
        if(todoOK==0)
        {
            if(ll_add(lista,auxEmployee)==0)
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("No se pudo realizar el alta\n");
            }
        }
        else if(todoOK == 1 || todoOK ==-1)
        {
            printf("Se cancelo el alta\n");
            free(auxEmployee);
        }



    }

    free(auxEmployee);


    return todoOK;

}

int bajaEmpleado(LinkedList* lista)
{
    int indice;
    int id;
    char confirma;
    int todoOk = 1;


    printf("**** BAJA EMPLEADO ****\n\n");

    if(utn_getEntero(&id,2,"Ingrese id del empleado: ","Error. Reingrese el id\n",1001,1002)==0)
    {
        if(findEmployeeById(lista,id,&indice)==0)
        {

            printf("Confirma la baja? (s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma == 's')
            {
                if(ll_remove(lista,indice)==0)
                   {
                       printf("Se realizo al baja con exito\n");
                       todoOk = 0;
                   }
                   else
                    {
                        printf("No se pudo realizar la baja\n");
                    }
            }
            else
            {
                printf("Se cancelo la baja\n");
            }
        }
        else
        {
            printf("No hay ningun empleado con el id: %d",id);
        }
    }


    return todoOk;
}



Employee* employee_new()
{
    Employee* pEmple1 = NULL;
    pEmple1= (Employee*) malloc(sizeof(Employee));
    if(pEmple1 !=NULL)
    {
        pEmple1->id =0;
        pEmple1->sueldo =0;
        pEmple1->horasTrabajadas = 0;
        strcpy(pEmple1->nombre, " ");
    }

    return pEmple1;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* SueldoStr)
{
    Employee* nuevoEmpleado = employee_new();


   if(nuevoEmpleado != NULL  && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && SueldoStr!=NULL)
    {
             employee_setId(nuevoEmpleado,atoi(idStr));
            employee_setNombre(nuevoEmpleado,nombreStr);
            employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr));
            employee_setSueldo(nuevoEmpleado,atoi(SueldoStr));
    }
        else
        {
            free(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }



    return nuevoEmpleado;
}

//-------------------------------------------------------
int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if(this!=NULL && id >=0)
    {
        this->id=id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//-------------------------------------------------------

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre != NULL && strlen(nombre) >= 2 && strlen(nombre)< 20)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}
//-------------------------------------------------------

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL&& horasTrabajadas != NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

//-------------------------------------------------------
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if(this!=NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;
    if(this!=NULL&& sueldo != NULL)
    {
        *sueldo=this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

//-------------------------------------------------------

void employee_delete(Employee*this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//-------------------------------------------------------
int employee_ComparaId(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->id > Aux2->id)
        {
            retorno = 1;
        }
        else if(Aux1->id < Aux2->id)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaSueldo(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->sueldo > Aux2->sueldo)
        {
            retorno = 1;
        }
        else if(Aux1->sueldo < Aux2->sueldo)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaHorasTrabajadas(void* a, void* b)
{
    int retorno=0;
    Employee* Aux1;
    Employee* Aux2;
    if(a != NULL && b != NULL)
    {
        Aux1 = (Employee*)a;
        Aux2= (Employee*)b;
        if(Aux1->horasTrabajadas > Aux2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(Aux1->horasTrabajadas < Aux2->horasTrabajadas)
        {
            retorno =-1;
        }
    }

    return retorno;
}

int employee_ComparaNombre(void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a != NULL && b != NULL)
    {
        p1 = (Employee*)a;
        p2 = (Employee*)b;
        retorno =strcmp(p1->nombre,p2->nombre);
    }

    return retorno;
}


int comparaSueldo(void* empleado)
{
    int todoOk = 0;
    Employee* auxEmp;

    if(empleado != NULL)
    {
        auxEmp = (Employee*) empleado;

        if(!(auxEmp->sueldo > 25000))
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
