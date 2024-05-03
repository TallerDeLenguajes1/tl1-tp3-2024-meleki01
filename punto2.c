#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define MES 12
#define ANIO 2

int main()
{
    int matriz[ANIO][MES];
    srand(time(NULL));
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
            matriz[i][j]=rand()%40000+10000;
        }
        
    }


        for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
           printf("anio[%d] mes[%d]= %d \n",i+1,j+1,matriz[i][j]);
        }
        
    }
    
 printf("\n\n");
    float promedio[5];
    int suma=0;


          for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MES; j++)
        {
           suma+=matriz[i][j];
        }
        promedio[i]=suma/12;
        suma=0;
    }
    for (int i = 0; i < ANIO; i++)
    {
        printf("promedio anio[%d]=%.2f \n",i,promedio[i]);
    }
    printf("\n\n");
    
//punto d
float valMaximo=0, valMinimo=0;
int mesMaximo=0, mesMinimo=0, j=0;
for (int i = 0; i < ANIO; i++)
{
    valMaximo=matriz[i][j];
    valMinimo=matriz[i][j];
    for (int j = 0; j < MES; j++)
    {
        if (valMaximo < matriz[i][j])
        {
            valMaximo= matriz[i][j];
            mesMaximo= j+1;
        }
          if (valMinimo > matriz[i][j])
        {
            valMinimo= matriz[i][j];
            mesMinimo= j+1;
        }
        
    }
    printf("el valor Minimo obtenido en el anio %d ocurrido en el mes %d es: %.2f \n",i+1,mesMinimo,valMinimo);
    printf("el valor Maximo obtenido en el anio %d ocurrido en el mes %d es: %.2f \n",i+1,mesMaximo,valMaximo);
    printf("\n");
    mesMaximo=0;
    mesMinimo=0;
    
}


    return 0;
}
