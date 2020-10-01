#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"


//VALIDACION
int getInt(char msj[])
{
    char aux[10];
    int intAdd;

    printf("%s", msj);
    scanf("%s", aux);
    fflush(stdin);
    intAdd = atoi(aux);

    while(intAdd == 0 || intAdd < 0)
    {
        printf("%s", "Error. Por favor Ingrese un solo numero entero \n");
        scanf("%s", aux);
        fflush(stdin);
        intAdd = atoi(aux);
    }

    return intAdd;
}


int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStr(char msj[], char input[])
{
    char aux[256];
    getString(msj,aux);

    while(esSoloLetras(aux) == 0)
    {
        getString("Error. Por favor Ingrese solo letras \n", aux);
    }
    strcpy(input,aux);
    return 1;
}

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int isOk = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                isOk = 0; //exito
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int isOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        isOk = 0; //exito
    }
    return isOk;
}
int getCadena(char* pAux, int limit)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limit > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limit)
        {
            strncpy(pAux, auxString, limit);
            isOk=0; //exito
        }
    }

    return isOk;
}

int isFloat(char* pAux)
{
    int isOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0; //exito
    }
    return isOk;
}
