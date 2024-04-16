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
           printf("anio[%d] mes[%d]= %d \n",i,j,matriz[i][j]);
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
    
    return 0;
}
