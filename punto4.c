#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct Producto
{
    int productoID; //Numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float precioUnitario;// entre 10 - 100

}typedef Producto;


struct Cliente
{
    int ClienteID;  // Numerado en el ciclo iterativo
    char *NombreCliente;  // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Cliente; 


void CargarDatos(Cliente *Clientes, int cantClientes);
void MostrarDatos(Cliente *Clientes, int cantClientes);
float PrecioTotalXProducto(float precioUnitario, int cant);
void LiberarMemoria(Cliente *Clientes, int cantClientes);
int main()
{
    Cliente *Clientes;
    int cantClientes;
    
    puts("ingrese la cantidad de clientes:");
    scanf("%d",&cantClientes);

    Clientes =  (Cliente *) malloc(sizeof(Cliente)*cantClientes);

    CargarDatos(Clientes,cantClientes);
    printf("\n\n");
    MostrarDatos(Clientes,cantClientes);

    float precioTotal;
    for (int i = 0; i < cantClientes; i++)
    {
        printf("cliente nro:%d precios total por productos: \n",i+1);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            precioTotal= PrecioTotalXProducto(Clientes[i].Productos[j].cantidad,Clientes[i].Productos[j].precioUnitario);
            printf("%s:$ %.2f\n",Clientes[i].Productos[j].TipoProducto,precioTotal);
        }
        
    }
    


    return 0;
}

//cargar datos
void CargarDatos(Cliente *Clientes, int cantClientes){
    char nombre[100],tipoProd[50];

    for (int i = 0; i < cantClientes; i++)
    {
        fflush(stdin);
        Clientes->ClienteID = rand()%100000 + 1000;
        puts("ingrese el nombre del cliente:");
        gets(nombre);
        Clientes->NombreCliente= (char *) malloc(sizeof(char) * (strlen(nombre) + 1) );
        strcpy(Clientes->NombreCliente,nombre);
        puts("ingrese la cantidad de productos a pedir");
        scanf("%d",&Clientes->CantidadProductosAPedir);
        Clientes->Productos= (Producto *) malloc(sizeof(Producto) * Clientes->CantidadProductosAPedir);

        for (int j = 0; j < Clientes->CantidadProductosAPedir ; j++)
        {
            fflush(stdin);
            Clientes->Productos[j].productoID = rand()%100000 + 1000;
            Clientes->Productos[j].cantidad= rand() %10 +1;
            puts("ingrese el tipo de producto");
            gets(tipoProd);
            Clientes->Productos[j].TipoProducto= (char *) malloc(sizeof(char) * (strlen(tipoProd)+1 ));

            strcpy(Clientes->Productos[j].TipoProducto,tipoProd);

            Clientes->Productos[j].precioUnitario= rand()%1000+10;
            Clientes->Productos[j].precioUnitario/=100;

        }
        
        Clientes++;
    }
    
}


void MostrarDatos(Cliente *Clientes, int cantClientes){

    for (int i = 0; i < cantClientes; i++)
    {
        printf("cliente: %s   -------------  id: %d   \n",Clientes[i].NombreCliente, Clientes[i].ClienteID);
        printf("cantidad de productos a pedir: %d\n", Clientes[i].CantidadProductosAPedir);
        puts("productos:");

        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("ID  del prod:%d  ---------------  cantidad: %d\n",Clientes[i].Productos[j].productoID,Clientes[i].Productos[j].cantidad);
            printf("tipo de prod:%s ------------------------ precio:%.2f \n",Clientes[i].Productos[j].TipoProducto, Clientes[i].Productos[j].precioUnitario);
            
        }
        
        printf("\n\n");

    }
    
    
}


float PrecioTotalXProducto(float precioUnitario, int cant){
     float cantidad = cant;
    return cantidad * precioUnitario;
}


void LiberarMemoria(Cliente *Clientes, int cantClientes){
    for (int i = 0; i < cantClientes; i++)
    {
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            free(Clientes[i].Productos[j].TipoProducto);
        }
        
    }
    
    for (int i = 0; i < cantClientes; i++)
    {
        free(Clientes[i].Productos);
        free(Clientes[i].NombreCliente);
    }
    
    free(Clientes);
    
}