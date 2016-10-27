#include "historic_event.h"

//Constructor por defecto
HistoricEvent::HistoricEvent() {
	*this.set_date(0);
}

//Constructor
HistoricEvent::HistoricEvent(unsigned int d, string s) {
	*this.set_date(d);
	*this.add_befalls(s);
}

//Constructor
HistoricEvent::HistoricEvent(unsigned int d, vector<string> v) : befalls(v) {
	set_date(d);
}

//Borrar acontecimiento
void HistoricEvent::rm_befalls(string s) {
	int i = 0;
	while (s.compare(befalls[i])) {				//compare vale 0 si son iguales
		i++;
	}

	befalls.erase(i);
}

//Mostrar acontecimiento i-ésimo
void HistoricEvent::show(i){
  cout << "Year:" << date << befalls.at(i) << endl;
}

//Buscar
void HistoricEvent::search(s){
	int found_pos;
  for(int i = 0; befalls.size() < i; i++){
    if (befalls.at(i).find(s) < befalls.at(i).size()) {
      mostrar(befalls.at(i));
    }
  }
}

//Operador ==
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls.size() == h.befalls.size())) ? true : false;

   for(int i=0; i<befalls.size() && eq; ++i)
      if(strcmp(befalls.at(i),h.befalls.at(i)) != 0)   //strcmp devuelve 0 si son iguales
         eq = false;

   return eq;
}

//Operador =
HistoricEvent& HistoricEvent::operator=(const HistoricEvent &h) {
   if(this != &h) {
      date = h.date();
      befalls = h.get_befalls();
   }

   return *this;
}
