#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_Per 20

int main()
{
    int Error=-9;
    char seguir='s';
    int opcion;
    int barras[3]={0,0,0};
    //int barras[3]={5,0,1};
    //int barras[3]={5,3,1};

    EPersona Personas[TAM_Per];
    EPersona temp[TAM_Per];

    Error=inicializaVector(Personas,TAM_Per);
    if(Error==0)
    {
        do
        {
            menu("1- Agregar persona\n"                         //OK
                 "2- Borrar persona\n"                          //OK
                 "3- Imprimir lista ordenada por  nombre\n"     //OK
                 "4- Imprimir grafico de edades\n\n");          //OK

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error=Alta_Persona(Personas,TAM_Per);
                    break;
                case 2:
                    Error=Borrar_persona(Personas,TAM_Per);
                    break;
                case 3:
                    //Mostrar ordenado por Nombre
                    Error=CopiaVector(Personas,TAM_Per,temp);
                    if(Error==0)
                    {
                        Error=Ordena_x_Nombre(temp,TAM_Per);
                        if(Error==0)
                        {
                            Error=muestra_personas(temp,TAM_Per);
                            if(Error!=0)
                            {//algun error al mostrar los dados
                                Error=Error*1000;
                            }
                        }
                        else
                        {//Algun error al ordenar el vector
                            Error=Error*100;
                        }
                    }
                    else
                    {// Algun error en la copia de vectores
                        Error=Error*10;
                    }

                    break;
                case 4:
                    Error=catalogo_edades(Personas,TAM_Per,barras);
                    if(Error==0)
                    {
                        grafica_barras(barras);
                    }
                    else
                    {
                        Error=Error*10;
                    }
                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');
    }
    else
    {
        sms_error(-1,Error);
    }//FIN if(Error==0)

    return Error;
}
