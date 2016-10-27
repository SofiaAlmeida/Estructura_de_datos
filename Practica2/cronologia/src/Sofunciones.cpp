#include "historic_event.h"

//Operador == (1 si son iguales)
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls.size() == h.befalls.ize())) ? true : false;

   for(int i=0; i<befalls.size() && eq; ++i)
      if(strcmp(befalls.at(i),h.befalls.at(i)) != 0)   //strcmp devuelve 0 si son iguales
         eq = false;

   return eq;
}

// TODO
//Operador > (1 si es mayor que h)
bool HistoricEvent::operator>(const HistoricEvent &h) {
   bool
}

// TODO
//Operador <
bool HistoricEvent::operator<(const HistoricEvent &h) {

}

//Operador =
HistoricEvent& HistoricEvent::operator=(const HistoricEvent &h) {
   if(this != &h) {
      date = h.date();
      befalls = h.get_befalls();
   }

   return *this;
}
