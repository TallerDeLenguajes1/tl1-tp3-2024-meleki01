#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT_NOMBRES 5

int main()
{
    char *aux,**nombres;
    aux= (char *) malloc(sizeof(char) * 100);
    nombres = (char **) malloc(sizeof(char*)* CANT_NOMBRES);

    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        puts("ingrese un nombre:");
        gets(aux);

        nombres[i]= (char*) malloc(( strlen(aux) + 1 ) *sizeof(char));

        strcpy(nombres[i],aux);
        
    }
    

    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        printf("nombre[%d]= %s\n",i+1, nombres[i]);
    }
    
    for (int i = 0; i < CANT_NOMBRES; i++)
    {
        free(nombres[i]);
    }
    
    free(nombres);
    free(aux);
    return 0;
}
