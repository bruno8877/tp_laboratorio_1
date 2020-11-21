#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


int altaEmpleado(LinkedList* lista);
int findEmployeeById(LinkedList* lista, int id,int* indice);

int bajaEmpleado(LinkedList* lista);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* SueldoStr);

void employee_delete(Employee*this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_ComparaNombre(void* a, void* b);
int employee_ComparaHorasTrabajadas(void* a, void* b);
int employee_ComparaSueldo(void* a, void* b);
int employee_ComparaId(void* a, void* b);

int comparaSueldo(void* empleado);
#endif // employee_H_INCLUDED
