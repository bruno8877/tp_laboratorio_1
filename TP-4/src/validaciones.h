#include <stdio.h>


int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);
int getInt(int* pAux);
int isInt(char *pAux);

int getStr(char msj[], char input[]);
void getString(char mensaje[],char input[]);
int esSoloLetras(char str[]);

int getFloat(float*pAux);
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);
int getCadena(char* pAux, int limit);
int isFloat(char* pAux);
