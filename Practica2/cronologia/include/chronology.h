// NOTE yo tampoco sé donde poner lo de autores si justo aquí o en la descripción de la clase
/**
  * @file chronology.h
  * @brief Fichero cabecera del TDA Chronology
  *
  */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.h"

/**
  *  @brief T.D.A. Chronology
  *
  * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
  * de un conjunto de eventos históricos. Se representara un vector de eventos
  * históricos. Ver documentación de historic_event para más información.
  *
  	TODO (si sobra tiempo)
  * Un ejemplo de su uso:
  * @include
  */

class Chronology {

 private: // TODO
/**
  * @page repConjunto Rep del TDA Chronology
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Chronology representa
  *
  *
  *
*/
	vector<Chronology> befalls; /**< vector con los eventos historicos */

 public:

/** @brief Inserta un evento en su posición correspondiente
  * @param date Fecha del evento
  * @param s Nombre del evento
  * @return void
  */
  void InsertBefall(int date, string s);
};

#endif
