#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;
#endif // FUNCIONES_H_INCLUDED

//---------------------------------
//---- Funciones Genericas -----
//---------------------------------

/** \brief Imprime Texto del menu
 *
 * \param opciones char*
 * \return void
 *
 */
void menu(char *opciones);

/** \brief Muestra cartel de Error con su respectivo codigo de Error.
 *
 * \param mensaje int
 * \param Error int
 * \return void
 *
 */
void sms_error(int mensaje,int Error);

/** \brief Devuelve entero dentro de un rango dado.
 *
 * \param sms[30] char
 * \param desde int
 * \param hasta int
 * \return int
 *
 */
int get_int_Rango(char sms[30],int desde,int hasta);

/** \brief Devuelvo un puntero a una cadedna de caracteres
 *
 * \param sms[] char
 * \param LongitudCadena int
 * \return char*
 *
 */
char *get_char(char sms[],int LongitudCadena);

/** \brief Dado un Numero, Devuelve -1,0,1 de acuerdo a la especificacion indicada abajo.
 *
 * Menores de 18    -> Rango = -1   //El enunciado no especifica que pasa con los que tienen 18..
 * De 19 a 35       -> Rango = 0
 * Mayores de 35    -> Rango = 1
 *
 * \param edad int
 * \return int
 *
 */
int get_rango_edad(int edad);

/** \brief Devuelve el Mayor valor de 3 Numeros
 *
 * \param Nro1 int
 * \param Nro2 int
 * \param Nro3 int
 * \return int
 *
 */
int Mayor_De_3_NrosPositivos(int Nro1,int Nro2,int Nro3);

/** \brief Decodifica la linea e Imprime
 *
 * \param linea int
 * \return void
 *
 */
void imprimo_linea(int linea);

/** \brief Realiza el analisis del acumulador de rangos de edad, y codifica linea por linea en binario
 *  Siendo 1 donde tiene que imprimir *  y 0 donde va un blanco.
 *  llama a la funcion imprimir_linea  quien se encarga de la impresion por pantalla
 *
 * \param barra[] int
 * \return void
 *
 */
void grafica_barras(int barra[]);

//-------------------------------------------
// ---- Funciones con uso de estructuras ----
//-------------------------------------------

/** \brief Inicializa el valor de estado en 0 para indicar que esta libre.
 *
 * \param lista[] EPersona
 * \param tam int
 * \return int
 *
 */
int  inicializaVector(EPersona lista[],int tam);

/** \brief Obtiene el primer indice libre del array.
 * Devuelve un negativo cuando no hay lugar o se produce un error
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/** \brief Devuelve una persona con sus datos
 * retorna el registro de una persona con todos sus datos cargados
 * \return EPersona
 *
 */
EPersona carga_datos_persona();

/** \brief Alta de persona
 *
 * \param personas[] EPersona
 * \param cant int
 * \return int
 *
 */
int Alta_Persona(EPersona personas[],int cant);

/** \brief Muestra datos de 1 persona
 *
 * \param persona EPersona
 * \param Nro int
 * \return void
 *
 */
void muestra_datos_persona(EPersona persona, int Nro);

/** \brief Recorre el listado de personas y Para todas las personas activas llama a mostrar datos persona.
 *
 * \param personas[] EPersona
 * \param cant int
 * \return int
 *
 */
int muestra_personas(EPersona personas[],int cant);

/** \brief Muestra Datos de Todas las personas activas, da opcion de ingresar Nro de persona a eliminar y elimina del listado dicha persona
 *
 * \param personas[] EPersona
 * \param cant int
 * \return int
 *
 */
int Borrar_persona(EPersona personas[],int cant);

/** \brief Copio Personas dadas de alta en otro vector de personas
 *
 * \param personas[] EPersona
 * \param cant int
 * \param copia[] EPersona
 * \return int
 *
 */
int CopiaVector(EPersona personas[],int cant,EPersona copia[]);

/** \brief Ordena un vector de personas por nombre
 *
 * \param personas[] EPersona
 * \param cant int
 * \return int
 *
 */
int Ordena_x_Nombre(EPersona personas[],int cant);


/** \brief Carga el vector de Barras con la cantidad de personas que hay de cada Rango (Ver Nota)
 *  NOTA: Como en el enunciado no se especifica que hacer con Personas de Edad=18 las mismas no se catalogan
 *
 *
 * \param personas[] EPersona
 * \param cant int
 * \param barra[] int
 * \return int
 *
 */
int catalogo_edades(EPersona personas[],int cant,int barra[]);
