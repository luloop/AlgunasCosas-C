
#ifndef INGRESOEGRESOS_H
#define INGRESOEGRESOS_H

#include "funciones.h"
#include "propietarios.h"

typedef struct
{
    int idIngresoEgreso;
    int idPropietario;
    char patente [10];
    int marca ;
    int status;
    int numeroTarjetaCredito;
    int tiempoTranscurrido;
    int totalPagado;

} eIngresoyEgreso;

/** \brief niicializa los estados a cero
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
void indiceIngresoyEgreso(eIngresoyEgreso  [], int );

/** \brief carga inicial de llamados para poder operar
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
int cargarIngresos(eIngresoyEgreso ingresos [], int tamanio);

/** \brief recibir ingreso
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \return
 *
 */
 void recibiringreso(eIngresoyEgreso ingreso [], ePropietario propiestarios[],int CantLugares, int CantPropietarios, int);

 /** \brief LISTADO DE ingresos
 *
 * \param array de estrcutura DE ingreso
 * \param  tamanio del arraY
 * \return
 *
 */
 void listaringreso (eIngresoyEgreso ingreso [], int tamanio);

 /** \brief MOSTRAR 1 ingreso
 *
 * \param array de estrcutura DE ingreso
 * \param  tamanio del arraY
 * \return
 *
 */
 void mostraringreso (eIngresoyEgreso ingreso);
  /** \brief FINALIZAR ingreso
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \return
 *
 */
 void finzalarIngreso(eIngresoyEgreso ingreso [], ePropietario propiestarios[],int CantLugares, int CantPropietarios);

 /** \brief recorre propiestarios, busca LA ingreso , LA DA POR FINALIZADA
 *
 * \param ARRAY ESTRUCTURA de ingresos
 * \param ARRAY ESTRUCTURA de propiestarioss
 * \param CANT DE ingresos
 * \param CANT DE propiestarios
 * \param CANT DE ambulancias
 * \return
 *
 */
void egresarAuto(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int devolverHorasEstadia();
void menuConsulta(eIngresoyEgreso ingresoss[], ePropietario cliente[],int CantLugares, int CantPropietarios, int);

void buscarPropySusPatentes (ePropietario propieta [] , eIngresoyEgreso ingresos [] ,int CantPropietarios,int CantLugares, int flag);



/** \brief DAR DE BAJA UN USUARIO PASANDO A 2 SU STATUS
 *
 * \param array estructura de usuario/socio/cliente
 * \param tamanio de usuario/socio/cliente
 * \param flag de prexistencia de carga de usuario/socio/cliente
 * \return
 *
 */
void bajaCliente(eIngresoyEgreso ingresoss [], ePropietario users[], int tamanio,int CantLugares, int flag);

#endif
