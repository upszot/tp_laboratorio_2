#include "funciones.h"

//---------------------------------
//---- Funciones Genericas -----
//---------------------------------

void menu(char *opciones)
{
    system("cls");
    printf("%s \n",opciones);
    printf("\n0.  Salir \n");
    printf("\n\tIngrese Opcion: ");
}

void sms_error(int mensaje,int Error)
{
    system("cls");
    printf("\n\n");
    switch(mensaje)
    {
        case -1:
            printf("ERROR-COD: %d -- Inicializar listado",Error);
            break;
        case 1:
            printf("ERROR-COD: %d -- Agregar Persona",Error);
            break;
        case 2:
            printf("ERROR-COD: %d -- Borrar Persona",Error);
            break;
        case 3:
            printf("ERROR-COD: %d -- Imprimir Lista ordenada",Error);
            break;
        case 4:
            printf("ERROR-COD: %d -- Imprimir Grafico de Edades",Error);
            break;
        case -2:
            printf("ERROR-COD: %d -- Opcion de menu Invalida",Error);
            break;
        default:
            printf("Se produjo un Error Inesperado...");
            break;
    }
    printf("\n\n");
    system("pause");
}

int get_int_Rango(char sms[30],int desde,int hasta)
{
    int aux;
    int flag=0;
    do
    {
        if(flag==1)
        {
            printf("\n Valor fuera de Rango Debe ser: (%d< X <%d)  \n",desde-1,hasta+1);
            system("pause");
            system("cls");
        }
        fflush(stdin);
        printf("%s",sms);
        scanf("%d",&aux);
        flag=1;
    }while( (aux<desde) || (aux>hasta) );

    return aux;
}

char *get_char(char sms[],int LongitudCadena)
{
    char *PTexto= (char *) malloc (sizeof(char)*LongitudCadena);

    //Variable temporal donde cargo el texto pedido...
    //es mas larga para de esa forma poder controlar si se exedieron en la longitud
    char TextoLibre[LongitudCadena+4];

    fflush(stdin);
    int flag=0;
    do
    {
        if(flag==1)
        {
            printf("\n La longitud maxima del campo es: %d \n",LongitudCadena);
            system("pause");
            system("cls");
        }
        printf("%s ",sms);
        // fgets lee desde el teclado (stdin) pero solo almacena en la variable
        //la cantidad de caracteres de longitud +3... (trunca todolo lo que se exeda...
        //si lo que ingresa es mas chico que esa longitud.. carga hasta que le das enter..
        //pero carga el retorno de carro en la variable
        fgets(TextoLibre,LongitudCadena+3,stdin);
        flag=1;
    }while(strlen(TextoLibre) >= LongitudCadena);
    //la funcion strtok elimina un caracter de el arreglo... en este caso el retorno de carro...
    strcpy(PTexto,strtok(TextoLibre, "\n"));
    return PTexto;
}

int get_rango_edad(int edad)
{//Menores de 18    -> Rango = -1   //El enunciado no especifica que pasa con los que tienen 18..
// De 19 a 35       -> Rango = 0
// Mayores de 35    -> Rango = 1
    int rango;
    if(edad<18)
    {
        rango=-1;
    }
    if( (edad >= 19) && (edad <= 35) )
    {
        rango=0;
    }
    if(edad>35)
    {
        rango=1;
    }
    return rango;
}

int Mayor_De_3_NrosPositivos(int Nro1,int Nro2,int Nro3)
{//obtiene el mayor valor de 3 numeros positivos
    int Mayor=-1;
    if( (Nro1>=Nro2) && (Nro1>=Nro3) && (Mayor==-1) )
    {
        Mayor=Nro1;
    }
    if( (Nro2>=Nro1) && (Nro2>=Nro3) && (Mayor==-1) )
    {
        Mayor=Nro2;
    }
    if( (Nro3>=Nro1) && (Nro3>=Nro1) && (Mayor==-1) )
    {
        Mayor=Nro3;
    }
    return Mayor;
}

void imprimo_linea(int linea)
{
    printf("\n");
    switch(linea)
    {
        case 1:
            printf(" \t \t*");
            break;
        case 10:
            printf(" \t*");
            break;
        case 11:
            printf(" \t* \t*");
            break;
        case 100:
            printf("* ");
            break;
        case 101:
            printf("* \t \t*");
            break;
        case 110:
            printf("* \t* ");
            break;
        case 111:
            printf("* \t* \t*");
            break;

    }//FIN     switch(linea)
}

void grafica_barras(int barra[])
{
    system("cls");
    //printf("\n <18: %d \t 19-35: %d \t >35: %d  \n\n ",barra[0],barra[1],barra[2]);// Descomentar para Debug
    int flag=0;
    int linea=Mayor_De_3_NrosPositivos(barra[0],barra[1],barra[3]);

    while( ((linea >= barra[0]) || (linea >= barra[1]) || (linea >= barra[2]) ) && (linea>0) )
    {//entra siempre que linea >= cantidad maxima de Asteriscos
        if(barra[0]>=linea)
        {//<18
            flag=flag+100;
        }
        if(barra[1]>=linea)
        {//19-35
            flag=flag+10;
        }
        if(barra[2]>=linea)
        {//>35
            flag=flag+1;
        }
        imprimo_linea(flag);
        linea--;
        flag=0;
    }//FIN while( (linea >=barra[0]) || (linea >=barra[1]) || (linea >=barra[2]) )
    printf("\n<18\t19-35\t>35\n\n");
    system("pause");
}


//-------------------------------------------
// ---- Funciones con uso de estructuras ----
//-------------------------------------------

int  inicializaVector(EPersona lista[],int tam)
{
    int retorno=-1;
    if(tam>0 && lista!=NULL)
    {
        retorno=0;
        for(int i=0; i<tam ;i++)
        {
            lista[i].estado=0;
        }//fin for(int i=0; i<tam ;i++)
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona lista[],int cant)
{
    int retorno=-1;//pq no es un valor valida para el subindice de un vector
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        for(int i=0; i<cant ;i++)
        {//recorro mi listado de personas
            if(lista[i].estado==0)
            {//Esta libre
                retorno=i;
                break;
            }
        }//for(int i=0; i<cant ;i++)
    }//fin if(cant>0&&lista!=NULL)
    return retorno;
}

EPersona carga_datos_persona()
{
    EPersona persona;
    system("cls");
    strcpy(persona.nombre,get_char("\nIngrese Nombre: ",50));
    persona.edad=get_int_Rango("\n Ingrese Edad: ",1,120);
    persona.dni=get_int_Rango("\n Ingrese DNI: ",0,36700);
    persona.estado=1;

    return persona;
}

int Alta_Persona(EPersona personas[],int cant)
{
    int retorno=-1;
    int Pos_libre;
    if(cant>0&&personas!=NULL)
    {
        retorno=-2;
        Pos_libre= obtenerEspacioLibre(personas,cant);
        if(Pos_libre>=0)
        {//Encontre una posicion libre
            retorno=0;
            personas[Pos_libre]=carga_datos_persona();
        }
        else
        {
            printf("\n No hay espacio libre..");
        }
    }//if(cant>0&&personas!=NULL)
    return retorno;
}

void muestra_datos_persona(EPersona persona, int Nro)
{// impreme los datos de una persona
    printf("\n Nro de persona: %d",Nro);
    printf("\n Nombre: %s",persona.nombre);
    printf("\n Edad: %d",persona.edad);
    printf("\n DNI: %d",persona.dni);
    printf("\n");
}

int muestra_personas(EPersona personas[],int cant)
{
    int retorno=-1;
    system("cls");
    if(cant>0&&personas!=NULL)
    {
        retorno=-2;
        for(int i=0;i<cant;i++)
        {//recorro e imprimo
            if(personas[i].estado==1)
            {
                muestra_datos_persona(personas[i],i);
                retorno=0;
            }
        }
        if(retorno==0)
        {
            system("pause");
        }
    }//FIN if(cant>0&&personas!=NULL)
    return retorno;
}

int Borrar_persona(EPersona personas[],int cant)
{
   int retorno=-1;
    int aux;

    if(muestra_personas(personas,cant)==0)
    {
        retorno=-2;
        printf("\n Ingrese el Nro de persona a borrar: ");
        scanf("%d",&aux);
        if((aux>=0) && (aux<cant))
        {//Valor valido para longitud del vector
            retorno =-3; //Si retorna esto, es: No Existe o esta dada de baja la persona
            if(personas[aux].estado==1)
            {//Persona dada de alta
                retorno=0;
                personas[aux].estado=0;
            }
        }//FIN if((aux>=0) && (aux<cant))
    }
    return retorno;
}

int CopiaVector(EPersona personas[],int cant,EPersona copia[])
{// copio un vector en otro pero solo de los que estan dados de alta..
    int retorno=-1;
    int pos=0;
    if(cant>0&&personas!=NULL)
    {
        retorno=-2;
        if(inicializaVector(copia,cant)==0)
        {
            retorno=-3;
            for (int i=0;i<cant;i++)
            {
                if(personas[i].estado==1)
                {
                    copia[pos]=personas[i];
                    pos++;
                    retorno=0;
                }
            }//FIN for (int i=0;i<cant;i++)
        }//FIN if(inicializaVector(copia,cant)==0)
    }//FIN if(cant>0&&personas!=NULL)

    return retorno;
}

int Ordena_x_Nombre(EPersona personas[],int cant)
{//uso metodo de la burbuja
    EPersona aux;
    int retorno=-1;
    if(cant>0&&personas!=NULL)
    {
        retorno=0;//doy valida la salida aca, pq si hay 1 sola persona no tiene que ordenar... y por lo tanto ya esta ordenado
        for(int i=0;i<cant-1;i++)
        {
            for(int j=i+1;j<cant;j++)
            {
                if((personas[i].estado==1) &&( personas[j].estado==1))
                {// Para comparar personas dadas de alta..
                    if( strcmp(personas[i].nombre,personas[j].nombre ) > 0)
                    {// el primero > que el segundo
                        aux=personas[i];
                        personas[i]=personas[j];
                        personas[j]=aux;
                    }//FIN if( strcmp(personas[i].nombre,personas[j].nombre ) > 0)
                }//FIN if(personas[i].estado==1)
            }//FIN for(int j=i+1;j<cant;j++)
        }//FIN for(int i=0;i<cant-1;i++)

    }//FIN if(cant>0&&personas!=NULL)
    return retorno;
}

int catalogo_edades(EPersona personas[],int cant,int barra[])
{
    int rango;
    int retorno=-1;
    barra[0]=0;
    barra[1]=0;
    barra[2]=0;

    if(cant>0&&personas!=NULL)
    {
        retorno=-2;
        for(int i=0;i<cant;i++)
        {
            if(personas[i].estado==1)
            {//solo para personas dadas de alta
                retorno=0;
                rango=get_rango_edad(personas[i].edad);
                switch(rango)
                {
                    case -1:
                        barra[0]=barra[0]+1;
                        break;
                    case 0:
                        barra[1]=barra[1]+1;
                        break;
                    case 1:
                        barra[2]=barra[2]+1;
                        break;
                }//FIN switch(rango)
            }//FIN if(personas[i].estado==1)
        }//FIN for(int i=0;i<cant;i++)
    }//FIN if(cant>0&&personas!=NULL)
    return retorno;
}


