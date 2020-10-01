#include <stdio.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

//FUNCION PARA INICIALIZAR
int initEmployees(eEmployee* list, int len);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */


//FUNCIONES PARA MOSTRAR EMPLEADO/S
void PrintEmployee(eEmployee unEmpleado);
int PrintEmployeers(eEmployee* list, int len);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */


//FUNCION PARA DAR DE ALTA
int addEmployees(int idx,eEmployee* list,int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/


//FUNCION PARA BUSCAR ESPACIO LIBRE
int buscarLibre(eEmployee* list, int len);

//FUNCION PARA BUSCAR EMPLEADO POR SU ID
int findEmployeeById(eEmployee* list, int len,int id);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */



//FUNCION PARA DAR DE BAJA EMPLEADO
int removeEmployee(eEmployee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */



//FUNCION PARA MODIFICAR EMPLEADOS
int modifyEmployee(eEmployee* list, int len, int id);

//FUNCION DE MENU DE INFORMES
void informes(eEmployee* list, int len);
int menuInformes();

//ORDENAMIENTO
int sortEmployees(eEmployee* list, int len, int order);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

//INFORME SALARIOS
int informarSalarios(eEmployee* list, int len);
