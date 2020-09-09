#include "biblioteca.h"
#include <stdlib.h>

/** \brief suma los numeros ingresados
 *
 * \param num1 float  primer numero ingresado
 * \param num2 float  segundo numero ingresado
 * \return float devuelve el resultado de la suma
 *
 */
float suma(float num1, float num2)
{
    float sumar;
    sumar = num1 + num2;
    return sumar;
}

/** \brief resta los numeros ingresados
 *
 * \param num1 float primer numero ingresado
 * \param num2 float segundo numero ingresado
 * \return float devuelve el resultado de la resta
 *
 */
float resta(float num1, float num2)
{
    float restar;
    restar = num1 - num2;
    return restar;
}

/** \brief divide los numeros ingresados
 *
 * \param num1 float primer numero ingresado
 * \param num2 float segundo numero ingresado
 * \return float devuelve el resultado de la division
 *
 */
float division(float num1, float num2)
{
    float dividir;

    dividir = num1 / num2;



    return dividir;
}

/** \brief multiplica los numeros ingresados
 *
 * \param num1 float primer numero ingresado
 * \param num2 float segundo numero ingresado
 * \return float devuelve el resultado de la multiplicacion
 *
 */
float multiplicacion(float num1, float num2)
{
    float multiplicar;
    multiplicar = num1 * num2;
    return multiplicar;
}


/** \brief hace el factorial del numero ingresado
 *
 * \param num1 int numero ingresado
 * \return int devuelve el resultado del factorial
 *
 */
int factorial(int num)
{
    int resultado;

    if(num < 0)
    {
        resultado =0;

    }
    else if(num ==0)
    {
        resultado = 1;
    }
    else
    {
        resultado = num * factorial(num-1);
    }
    return resultado;
}

float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    while(scanf("%f", &aux)!=1)
    {
        fflush(stdin);
        printf("Error, Ingrese un valor numerico...\n");
        printf("%s", msj);
    }
    return aux;
}



