// NOTE no sé donde poner lo de autores si justo aquí o en la descripción de la clase
/**
  * @file historic_event.h
  * @brief Fichero cabecera del TDA HistoricEvent
  *
  */

#ifndef __HISTORICEVENT
#define __HISTORICEVENT

#include <iostream>
#include <string>
#include <vector>

/**
  *  @brief T.D.A. HistoricEvent
  *
  * Una instancia @e h del tipo de datos abstracto @c HistoricEvent se compone
  * de una fecha y uno o más eventos sucedidos en dicha fecha. La fecha
  * representará únicamente el año en el que tuvieron lugar los acontecimientos
  * en forma de número natural, y cada uno de los acontecimientos podrán
  * contener más de una palabra.
  *
  	TODO (si sobra tiempo)
  * Un ejemplo de su uso:
  * @include
  */

class HistoricEvent {

 private: // TODO
/**
  * @page repConjunto Rep del TDA HistoricEvent
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA HistoricEvent representa
  *
  *
  *
*/
	unsigned int date; /**< fecha */
	vector<string> befalls; /**< vector con los acontecimientos */

 public:

/**
  * @brief Constructor por defecto de la clase.
  */
  HistoricEvent();

/**
  * @brief Constructor de la clase
  * @param d fecha
  * @param s acontecimiento ocurrido en dicha fecha
  * @return Crea el evento histórico con fecha d y acontecimiento s
  */
  HistoricEvent(unsigned int d, string s);

/**
  * @brief Constructor de la clase
  * @param d fecha
  * @param c vector de acontecimientos ocurrido en dicha fecha
  * @return Crea el evento histórico con fecha d y acontecimientos v
  */
  HistoricEvent(unsigned int d, vector<string> v);

/**
  * @brief Fecha
  * @return Devuelve la fecha
  */
  unsigned int get_date() const {return date;};

/**
  * @brief Acontecimientos
  * @return Devuelve un vector de acontecimientos
  */
  vector<string> get_befalls() const {return befalls;};

/**
  * @brief Asignar fecha
  * @param d fecha a asignar
  * @return Void
  */
  void set_date(unsigned int d) {date = d;};

/**
  * @brief Añadir acontecimiento
  * @param s acontecimiento
  * @return s void
  * @pre El string a añadir no se encuentra ya en el vector
  */
  void add_befall(string s) {befalls.push_back(s);};

/**
  * @brief Borrar acontecimientos
  * @param s acontecimiento a borrar
  * @return void
  */
  void rm_befalls(string s);

/** @brief Muestra el nombre de un determinado evento de un año (indicando este último)
  * @param i Posición del string de "befalls" a mostrar
  * @return Void
  */
  void show(int i);

/** @brief Busca una cadena dentro de un vector de eventos y muestra las encontradas
  * @param s String a buscar
  * @retval true si encuentra el string
  */
  bool search(string s); // Ahora es void, y llama a show dentro de ella, en vez de devolver el string
// NOTE si devolviera el bool me sería útil para operator+
/**
  * @brief Sobrecarga del operador ==
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si este objeto es igual a h
  */
  bool operator==(const HistoricEvent &h);
// NOTE en el operator == se compara que sean exactamente iguales
// mientras que en los operadores > y < simplemente el año
/**
  * @brief Sobrecarga del operador >
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si el año del objeto implícito es mayor que el de h
  */
  bool operator>(const HistoricEvent &h);

/**
  * @brief Sobrecarga del operador >
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si el año del objeto implícito es menor que el de h
  */
  bool operator<(const HistoricEvent &h);

/**
  * @brief Sobrecarga del operador +
  * @param h objeto a sumar con el implícito
  * @return objeto implícito al que se ha añadido los acontecimientos que no tenía de h.befalls
  */
  HistoricEvent& operator+(const HistoricEvent &h);
};

#endif
