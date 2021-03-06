#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "llamados.h"

#define motivo1 "INFARTO"
#define motivo2 "ACV"
#define motivo3 "GRIPE"

#define estado0 "LIBRE"
#define estado1 "PENDIENTE"
#define estado2 "CUMPLIDO"


/** \brief niicializa los estados a cero
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
void indiceLlamados(eLlamados llamadas [], int tamanio)
{
     int i;
    for (i=0 ; i<tamanio;i++)
    {
    strcpy(llamadas[i].status, estado0);
    llamadas  [i].tiempoAsignacion= 0;
     }
}

/** \brief carga inicial de llamados para poder operar
 *
 * \param array de estrcutura
 * \param  tamanio del arrau
 * \return
 *
 */
void cargarLlamados(eLlamados llamadas [], int tamanio)
{
     int i;
    int auxSocio [10] ={10, 11, 10, 10, 11, 15, 14,10, 11, 16};
    int auxAmbulancia[10] ={41,42, 41, 43, 41,41,42, 41, 43, 41};
    int auxTiempoA[10] ={1,2,3,4,5,6,7,8,9,10};
     for (i=0 ; i<10;i++)
    {
    llamadas [i].idLlamado=i+1;
    llamadas  [i].idSocios= auxSocio[i];
    llamadas  [i].idAmbulancia = auxAmbulancia[i];
    llamadas  [i].tiempoAsignacion= auxTiempoA[i];
    strcpy(llamadas [i].status,estado1);
      }

      for (i=0 ; i<3;i++)
      strcpy(llamadas [i].motivo, motivo1);
      for (i=3 ; i<6;i++)
      strcpy(llamadas [i].motivo, motivo2);
      for (i=6 ; i<10;i++)
      strcpy(llamadas [i].motivo, motivo2);
   }

/** \brief recibir llamado
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */

    void recibirLlamado(eLlamados llamado [], eSocio socio[],eAmbu ambulancia[],int CantLlamadas, int CantSocios ,int CantAmbulancias )
    {
     int i;
     int j;
     int k;
     int l;
     int m;
     int n;
     int idClienteAux;
     int idOperadorAux;
     int idEquipoAux;


    listadoDeSocio(socio, CantSocios);
    printf("\n\nIngrese el id de Socio que necesita una ambulancia :");
    scanf("%d", &idClienteAux);


for (i=0; i <CantLlamadas; i++)
{
    if (strcmp(llamado[i].status,estado0)==0) // busco el indice disponible en las relaciones de llamado
    {
    ingresarMotivo(llamado[i]);
       strcpy(llamado[i].status, estado1);
       llamado [i].idLlamado=i+1;
       for (j=0; j<CantSocios; j++) // recorro
        {
           if (idClienteAux== socio[j].idSocio)
                {
                llamado [i].idSocios=idClienteAux;
                listadoDeAmbus(ambulancia, CantAmbulancias);
                printf("\n\nIngrese el id de ambulancia:");
                scanf("%d", &idEquipoAux);
                for (k=0; k<CantAmbulancias; k++)
                {
                    if (idEquipoAux== ambulancia[k].idAmbu)
                    {
                        llamado [i].idAmbulancia=idEquipoAux;
                        ambulancia[k].status=2;
                        printf("\n\nIngrese la hora de asignacion de ambulancia id %d : ", llamado [i].idAmbulancia);
                        scanf("%f", &llamado[i].tiempoAsignacion);
                        break;
                    }
                }
                break;
                }

            }
             break;
    }
}
       printf("\n================================================");
        printf("\nSocio:");
        showOneClient(socio[j]);
        printf("\n");
        printf("\nAmbulancia:");
        showOneAmbu(ambulancia[k]);
        printf("\n");
        mostrarLlamado(llamado[i]);

    printf("\n\n=========== AMBULANCIA ENVIADA ==============");

 }


 /** \brief FINALIZAR LLAMADO
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
 void finzalarLlamada(eLlamados llama[], eSocio socio [],eAmbu ambulanc[],int CantLlamadas,int CantSocios,int CantAmbulancias)
 {
     int i;
     int j;
     int k;
     int l;
     int m;
     int idAlquilerAux;
     int idClienteAux;
     int idEquipoAux;
     int auxTiempo;
     char seguir;
     int flag=0;

    flag=buscarLlamado(llama, socio,ambulanc,CantLlamadas, CantSocios,CantAmbulancias);
    if (flag==0)
         {
             printf("\n\n=========== No existe la llamada ==============\n");
         }
    else
         {

         }

}




/** \brief recorre SOCIO, busca LA LLAMADA , LA DA POR FINALIZADA
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
   int buscarLlamado(eLlamados llamadass[], eSocio cliente[],eAmbu equipo[],int CantLlamadas, int CantSocios,int CantAmbulancias)
  {
      int i;
      int j;
      int idClienteAux;
      int flag=0;

    listarLlamado(llamadass, CantLlamadas);
    printf("\n\nIngrese el id de llamada que desea dar de baja :");
    scanf("%d", &idClienteAux);

       for (j=0; j<CantSocios; j++) // recorro los clientes
        {
           if (idClienteAux==llamadass[j].idLlamado) // si el cliente es igual al que busco
                {
                flag=1;
                mostrarLlamado(llamadass[j]);
                strcpy(llamadass[j].status,estado2);
                for (j=0; j<CantAmbulancias; j++)
                {
                    if (equipo[i].idAmbu==llamadass[j].idAmbulancia)
                    {
                        equipo[i].status=1;
                        printf("\nAmbulancia %d ya disponible ", equipo[i].idAmbu);
                    }
                }



                printf("\n\n=========== LLAMADA FINALIZADA ==============\n");
                break;
                }
          }
          return flag;
}


/** \brief MOSTRAR 1 LLAMADO
 *
 * \param array de estrcutura DE LLAMADA
 * \param  tamanio del arraY
 * \return
 *
 */
 void mostrarLlamado (eLlamados llamado)
 {
     printf("\nLlamado: %d\ Socio: %d Motivo: %s  Estado %s  Hora: %.2f " ,llamado.idLlamado , llamado.idSocios , llamado.motivo, llamado.status, llamado.tiempoAsignacion);
 }


 /** \brief LISTADO DE LLAMADAS
 *
 * \param array de estrcutura DE LLAMADA
 * \param  tamanio del arraY
 * \return
 *
 */
 void listarLlamado (eLlamados llamado [], int tamanio)
 {
      int i;
      printf("\n\n\n========================\nLLAMADAS PENDIENTES\n========================\n");
                for (i=0; i<tamanio; i++)
                {
                    if (strcmp(llamado[i].status,estado1)==0)
                    {
                        mostrarLlamado(llamado[i]);
                    }

                }
 }

/** \brief MODIFICAR LOS DATOS DE UNA LLAMADA
 *
 * \param ARRAY ESTRUCTURA de llamadas
 * \param ARRAY ESTRUCTURA de socios
 * \param ARRAY ESTRUCTURA de ambulancias
 * \param CANT DE llamadas
 * \param CANT DE socio
 * \param CANT DE ambulancias
 * \return
 *
 */
 void modificarLlamada(eLlamados llamada[], eSocio socio[],eAmbu ambu[],int CantLlamadas, int CantSocios,int CantAmbulancias)
 {
    int i;
     int idAux;
     int auxMotivo;
     int confirm;
     int flagchange=0;
     int opcion;


               listarLlamado(llamada, CantLlamadas);
               printf("\n===================================================================================\n");
               printf("\n\n Ingrese el Id del llamada que desea Modificar:\t");
               scanf("%d", &idAux);

               for (i=0; i<CantLlamadas;i++)
                            {
                                if (llamada[i].idLlamado == idAux)
                                    {
                                    mostrarLlamado(llamada[i]);
                                    confirm =preguntarSiNo("Seguro que desea modificar la llamada :\t");
                                    break;
                                    }
                            }

                flagchange=0;
                if( confirm == 's')
                    {
                for (i=0; i<CantLlamadas;i++)
                {
                    if (llamada[i].idLlamado  == idAux)
                        {
                        printf("\n \nEl Equipo a modificar es");
                        mostrarLlamado(llamada[i]);

                        printf("\n=========================\n \nOPCIONES \n 1- Socio\n 2- Ambulancia \n 3- Motivo\n 4- Hora Asignacion \n 5- Hora Finalizado\n \t \t Que dato desea modificar?\t");
                        scanf ("%d", &opcion);
                        switch(opcion)
                                {
                                case 1:
                                    listadoDeSocio(socio, CantSocios);
                                     printf("\n Ingrese el nuevo IDdeSocio\t");
                                     printf("%dl", &llamada[i].idSocios);
                                     break;
                                case 2:
                                    listadoDeAmbus(ambu, CantAmbulancias);
                                    printf("\n Ingrese el ID Ambulancia\t");
                                    printf("%dl", &llamada[i].idAmbulancia);
                                    break;

                                case 3:
                                    ingresarMotivo(llamada [i]);
                                    break;
                                case 4:
                                     printf("\n Ingrese el nuevo hora asignacion\t");
                                     scanf("%f",&llamada[i].tiempoAsignacion);
                                     break;
                                case 5:
                                   printf("\n Ingrese el nuevo hora finalizado\t");
                                     scanf("%f",&llamada[i].tiempoDevolucion);
                                     break;
                                    break;
                                 default:
                                    printf("\n NO INGRESO UNA OPCION VALIDA\t");
                                    break;
                                  }

                        printf("\n\n\n======================\n llamada modificado\n======================\n");
                        flagchange=1;
                        mostrarLlamado(llamada[i]);
                        break;
                        }
                }
                    }
                    else
                          {
                printf("\n\n=====================================\n");
                printf("OPERACION CANCELADA");
                printf("\n=====================================\n");
                }
            }


/** \brief ACCESORIA A MODIFICAR LLAMADA, PARA MODIFICAR EL MOTIVO
*
* \param
* \param
* \return
*
*/
void ingresarMotivo (eLlamados llamada)
{
    int auxMotivo;
    printf("\n1- %s\n2- %s\n3- %s\n\t Ingrese el Nro del motivo\t", motivo1, motivo2, motivo3);
    scanf("%d", &auxMotivo);
    switch (auxMotivo)
      {
        case 1:
        strcpy(llamada.motivo, motivo1);
        strcat(llamada.motivo, " ");
        break;
        case 2:
        strcpy(llamada.motivo, motivo2);
        strcat(llamada.motivo, " ");
        break;
        case 3:
        strcpy(llamada.motivo, motivo3);
        strcat(llamada.motivo, " ");
        break;
        default:
        printf("\n accion cancelada");
        break;
        }
}

