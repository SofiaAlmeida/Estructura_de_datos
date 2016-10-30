/**
  * @file chronology.h
  * @brief Fichero cabecera del TDA Chronology
  * @author Sofía Almeida Bruno (@SofiaAlmeida)
  * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
  * @author Pedro Bonilla Nadal (@pedrobn23)
  * @bug
  */

#ifndef __CHRONOLOGY
#define __CHRONOLOGY

#include "historic_event.h"
#include <iostream>

/**
  *  @brief T.D.A. Chronology
  *
  * Una instancia @e h del tipo de datos abstracto @c Chronology se compone
  * de un conjunto de eventos históricos. Se representará un vector de eventos
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
	vector<HistoricEvent> event; /**< vector con los eventos historicos */


 public:
/**
  * @brief Crea una cronología a partir de otra
  * @param chrono
  * @return Cronología con las propiedades de la anterior
  */
  Chronology(const Chronology& chrono);

/**
  * @brief Eventos
  * @return Devuelve un vector de eventos
  */
  vector<HistoricEvent> get_events() const {return event;};

/**
  * @brief Obtiene vector con los befalls de un año
  * @param date Año a buscar
  * @return Vector de befalls del año date
  */
  vector<string> get_befalls(int date);

/** @brief Inserta un evento en su posición correspondiente
  * @param date Fecha del evento
  * @param s Nombre del evento
  * @retval true si el evento ha sido insertado correctamente
  */
  bool InsertBefall(int date, const string &s);

/**
  * @brief Añade un HistoricEvent a la cronología
  * @param h evento a añadir
  * @retval true si el evento ha sido insertado correctamente
  */
  bool InsertEvent(const HistoricEvent &h);

/**
  * @brief Borra un evento
  * @param date fecha del evento a borrar
  * @return Void
  */
  void rm_event(int date);

/**
  * @brief Ordenar por fecha
  * @return Cronología ordenada
  */
  Chronology& sort();

/**
  * @brief Mezclar de forma ordenada dos cronologías
  * @param c cronología a mezclar con la implícita
  * @return cronología mezclada y ordenada
  */
  Chronology& merge(Chronology &c);

/** @brief Suma la cronología implícita con la que es pasada como argumento
  * @param chrono Cronología a sumar
  * @return Cronología suma de ambas
  */
  Chronology sum_chrono(const Chronology &chron2);

/**
  * @brief Eventos anteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> prev_events(int d);

/**
  * @brief Eventos posteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> post_events(int d);

/** @brief  Muestra todos los eventos situados entre dos fechas
  * @param inf Extremo inferior de la búsqueda
  * @param sup Extremo superior de la búsqueda
  * @return Void
  */
  void show_range(int inf, int sup);
};

/**
  * @brief Busca los años en que exista un evento con la palabra dada.
  *        Además, puede sacar por el flujo os el año y evento que la contienen    .
  * @param s palabra/s a buscar
  * @param be_show decide si quiere ser sacado por flujo
  * @return Vector con los años que tienen un evento con esa palabra.
  */
  vector<int> word_search(string s, bool be_show = false);

/**
  * @brief Sobrecarga del operador <<
  * @param os flujo de salida
  * @param c cronología a mostrar
  * @return muestra una cronología con el formato:
  *         Year: date eventos
  */
  ostream& operator<<(ostream &os, const Chronology &c);

/**
  * @brief Sobrecarga del operador >>
  * @param is flujo de entrada
  * @param c cronología a escribir
  * @return flujo de entrada
  */
  istream& operator>>(istream &is, Chronology &c);

#endif
