#include "historic_event.h"

//Operador == (1 si son iguales)
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls.size() == h.befalls.ize())) ? true : false;

   for(int i=0; i<befalls.size() && eq; ++i)
      if(strcmp(befalls.at(i),h.befalls.at(i)) != 0)   //strcmp devuelve 0 si son iguales
         eq = false;

   return eq;
}

//Operador > (1 si es mayor que h)
bool HistoricEvent::operator>(const HistoricEvent &h) {
   return date > h.get_date();
}

//Operador <
bool HistoricEvent::operator<(const HistoricEvent &h) {
   return date < h.get_date();
}

// HEADER
/**
  * @brief Sobrecarga del operador +
  * @param h objeto a sumar con el implícito
  * @return objeto implícito al que se ha añadido los acontecimientos que no tenía de h.befalls
  */
  HistoricEvent& operator+(const HistoricEvent &h);
  // SOURCE
  HistoricEvent& HistoricEvent::operator+(const HistoricEvent &h) {
     if(date == h.date) {
        for(int i = 0; i < h.befalls.size(); ++i) {
           //Doy por hecho que el evento this está bien
           //simplemente añado los eventos de h que no estén
           if(!this.search(h.befalls.at(i)))
           // REVIEW tabulación
              this.add_befall(h.befalls.at(i));
        }
     }
     return *this;
 }


/////////////////////////////////////////////////////////////////////7
/**
  * @brief Constructor de copia de la clase
  * @param h.date fecha del evento a construir
  * @param h.befalls acontecimientos del evento a construir
  */
  HistoricEvent(const HistoricEvent& he);

/**
    * @brief Sobrecarga del operador =
    * @param h elemento a asginar al objeto implícito
    * @return el objeto implícito adquiere los datos de h
    */
    HistoricEvent& operator=(const HistoricEvent &h);

    //Operador =
    HistoricEvent& HistoricEvent::operator=(const HistoricEvent &h) {
       if(this != &h) {
          date = h.date();
          befalls = h.get_befalls();
       }

       return *this;
    }
