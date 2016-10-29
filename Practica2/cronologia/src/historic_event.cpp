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
void HistoricEvent::show(int i){
  cout << "Year:" << date << befalls.at(i) << endl;
}

//Buscar	CHANGED
bool HistoricEvent::search(const string &s){
  for(int i = 0; befalls.size() < i; ++i){
    if (befalls.at(i).find(s) < befalls.at(i).size()) {
      show(befalls.at(i));	//NOTE ¿show? pero está pasando un vector
		return true;	// REVIEW añado esto por aquí (a ver qué opinan)
    }
  }
  return false;		// REVIEW y esto aquí
}

// FIXME dos eventos con los mismos acontecimientos pero distinto orden serían iguales

//Operador ==
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls.size() == h.befalls.size())) ? true : false;

   for(int i=0; i<befalls.size() && eq; ++i)
      if(strcmp(befalls.at(i),h.befalls.at(i)) != 0)   //strcmp devuelve 0 si son iguales
         eq = false;

   return eq;
}

//Operador >
bool HistoricEvent::operator>(const HistoricEvent &h) {
   return date > h.get_date();
}

//Operador <
bool HistoricEvent::operator<(const HistoricEvent &h) {
   return date < h.get_date();
}

// Operador +
HistoricEvent& HistoricEvent::operator+(const HistoricEvent &h) {
	if(date == h.date) {
		for(int i = 0; i < h.befalls.size(); ++i)
			if(!search(h.befalls.at(i)))
				add_befall(h.befalls.at(i));
	}
	return *this;
}
