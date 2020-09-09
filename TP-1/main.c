#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"//error ortografico
/*1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/


int main()
{

    float num1 = 0;
    float num2 = 0;
    float ResultadoSuma = 0;
    float ResultadoResta = 0;
    float ResultadoMultiplicacion = 0;
    float ResultadoDivision;
    int ResultadoFactoreo1;
    int ResultadoFactoreo2;
    int opcion;
    char respuesta='s';


    do
    {

        printf("\n------------ CALCULADORA ------------\n");
        printf("\n1- Ingresar 1er operando (A=x)");
        printf("\n2- Ingresar 2do operando (B=y)");
        printf("\n3- Calcular todas las operaciones ");
        printf("\n   a) Calcular la suma (A+B)");
        printf("\n   b) Calcular la resta (A-B)");
        printf("\n   c) Calcular la division (A/B)");
        printf("\n   d) Calcular la multiplicacion (A*B)");
        printf("\n   e) Calcular el factorial (A!)");
        printf("\n4- Resultados de las operaciones");
        printf("\n5- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        //ingrese los dos numeros, ponga lo que quiere calcular(+-/*) y despues seleccione la opcion de resultados de las operaciones, si quiere seguir calculando la suma, resta etc con los mismos numeros ingresados no es necesario volver a ingresar num1 y num2
        switch(opcion)
        {
            case 1: //pido el primer operando

                    num1 = getFloat("Ingrese 1er operando(a=x): ");
                    system("pause");
                    break;

            case 2: //pido el segundo operando
                    num2 = getFloat("Ingrese 2do operando(b=y): ");
                    system("pause");
                    break;

            case 3: //calculo las operaciones
                    printf("/nOperaciones calculadas/n");
                    ResultadoSuma = suma(num1,num2);
                    ResultadoResta = resta(num1,num2);
                    ResultadoDivision = division(num1,num2);
                    ResultadoMultiplicacion = multiplicacion(num1,num2);
                    ResultadoFactoreo1 = factorial(num1);
                    ResultadoFactoreo2 = factorial(num2);
                    break;


            case 4: //Muestro los resultados de las operaciones realizadas
                    printf("\nLos numero ingresados son: a=%.2f y b=%.2f\n", num1, num2);
                    printf("\na)El resultado de la suma es(A+B): %.2f\n", ResultadoSuma);
                    printf("\nb)El resultado de la resta es(A-B): %.2f\n", ResultadoResta);

                    if(num2== 0)
                    {
                        printf("\nNo se puede dividir por cero\n");
                    }
                    else
                    {
                        printf("\nc)El resultado de la division es(A/B): %.2f\n", ResultadoDivision);
                    }


                    printf("\nd)El resultado de la multiplicacion es(A*B): %.2f\n", ResultadoMultiplicacion);


                    if(num1 <0 )
                    {
                        printf("\ne)No se puede factorear un numero negativo\n");
                    }
                    else
                    {
                        printf("\ne)El resultado del factorial numero 1 ingresado es(A!): %d\n", ResultadoFactoreo1);
                    }
                    if(num2 <0)
                    {
                        printf("\ne)No se puede factorear un numero negativo\n\n");
                    }
                    else
                    {
                        printf("\ne)El resultado del factorial numero 2 ingresado es(B!): %d\n\n", ResultadoFactoreo2);
                    }

                    system("pause");//pone pausa y deja ver los resultados
                    break;

            case 5:
                    respuesta = 'n';
                    break;

            default:
                    printf("Error, por favor re-ingrese una opcion valida...\n");
                    system("pause");
                    break;


        }
        system("cls");//limpia la consola

    }while(respuesta == 's');
     return 0;


}
