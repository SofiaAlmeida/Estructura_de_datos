#include "historic_event.h"


// Muestra el string contenido en la posición indicada note no está puesto en header aún

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

void InsertBefall(const int &date, const string &s);

// Para el src
bool Chronology::InsertBefall(const int &date,const string &s){
  bool insert = false;
  int var_date;
  for(int i=0; insert == false; i++){
    var_date = event.at(i).get_date();
    if (var_date > date){
      HistoricEvent event(date,string);
      event.insert(i,event);
      insert = true;
    }
    else if (var_date == date){
      if (event.at(i).compare(string s)!=0){
      event.at(i).add_befall(s);
      insert = true;
      }
    }
  }
  return insert;
}


// Función sum

/** @brief Suma la cronología y la que se llama con la que es pasada como argumento
  * @param chrono Cronología a sumar
  * @return Cronología suma de ambas
  */

Chronology sum_chrono(const Chronology &chron);

// src
Chronology Chronology::sum_chrono(const Chronology &chron2){
  std::vector<HistoricEvent> v;
  int size_chron1 = *this.event.size();
  int size_chron2 = chron2.event.size();

  for(int i = 0; i < size_chron1; i++){
    v.push_back(*this.event.at(i));
  }

  for(int i = 0; i < size_chron2; i++){
    v.push_back(chron2.event.at(i);
  }

  Chronology result(v);
  result.sort();

  return result;
}

// Funición show_range

/** @brief  Muestra todos los eventos situados entre dos fechas
  * @param begin Extremo inferior de la búsqueda
  * @param end Extremo superior de la búsqueda
  * @return void
  */

void show_range(int inf, int sup);

// src

void Chronology::show_range(int inf, int sup){
  if (inf > sup)
    std::swap(inf,sup);
  int size = this->event.size();
  int befalls_size;

  for(int i = 0; i < size; i++){                                                          // Comprueba si la fecha de cada HistoricEvent
      if (this->event.at(i).get_date() >= inf && this->event.at(i).get_date() <= sup){    // es correcta y procede a mostrar su contenido
        befalls_size = this->event.at(i).befalls_size();
          for(int j = 0; j < befalls_size; i++){
            show(event.at(i).show(i));
          }
      }
  }
}
