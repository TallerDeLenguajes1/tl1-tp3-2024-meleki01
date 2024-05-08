#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    char *aux,**nombres;
    int cantNombres;
    puts("ingrese la cantidad de nombres:");
    scanf("%d",&cantNombres);
    fflush(stdin);
    aux= (char *) malloc(sizeof(char) * 100);
    nombres = (char **) malloc(sizeof(char*) * cantNombres);

    for (int i = 0; i < cantNombres; i++)
    {
        puts("ingrese un nombre:");
        gets(aux);

        nombres[i]= (char*) malloc(( strlen(aux) + 1 ) *sizeof(char));

        strcpy(nombres[i],aux);
        
    }
    

    for (int i = 0; i < cantNombres; i++)
    {
        printf("nombre[%d]= %s\n",i+1, nombres[i]);
    }
    
    for (int i = 0; i < cantNombres; i++)
    {
        free(nombres[i]);
    }
    
    free(nombres);
    free(aux);
    return 0;
}
