#include "historic_event.h"


// Muestra el string contenido en la posición indicada NOTE no está puesto en header aún

/** @brief Muestra el nombre de un determinado evento de un año (indicando este último)
  *
  * @param i Posición del string de "befalls" a mostrar
  *
  */
void HistoricEvent::show(i){
  cout << "Year:" << date << befalls.at(i) << endl;
}

// Recorre todos los strings en befalls comprobando si la palabra a buscar está contenida en ellos
// En vez de devolver un booleano para ver si lo ha encontrado o devolver un string, llama a show si lo ha encontrado,
// si no lo ha encontrado, no hace nada, por lo que conviene en la clase Chronology emitir un mensaje de finalización de búsqueda
void HistoricEvent::search(string s){
  int found_pos;
  for(int i = 0; befalls.size() < i; i++){
    if (befalls.at(i).find(s) < befalls.at(i).size()) {
      mostrar(befalls.at(i));
    }
  }
}

#include "chronology.h"

// Constructor copia

/** @brief Crea una cronología a partir de otra
  * @param chrono
  * @return Cronología con las propiedades de la anterior
  */

Chronology Chronology(Chronology chrono);


// Para el src

Chronology Chronology::Chronology(chrono){
  befalls = chrono.get_befalls();
}

// Insertar evento

/** @brief Inserta un evento en su posición correspondiente
  * @param s Nombre del evento
  * @param date Fecha del evento
  * @return void
  */

void InsertBefall(int date, string s);

// Para el src
void Chronology::InsertBefall(date, s){
  bool insert = false;
  for(int i=0; insert == false; i++){
    if (befalls.at(i).get_date() > date){
      HistoricEvent event(date, string);      // FIXME si la fecha ya existe se crearían 2 objetos con la misma fecha
      befalls.insert(i,event);
      insert = true;
    }
  }
}
