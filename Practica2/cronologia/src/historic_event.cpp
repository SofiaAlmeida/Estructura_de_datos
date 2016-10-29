#include "historic_event.h"

//Constructor por defecto
HistoricEvent::HistoricEvent() {
	set_date(0);
}

//Constructor
HistoricEvent::HistoricEvent(int d, string s) {
	set_date(d);
	add_befalls(s);
}

//Constructor
HistoricEvent::HistoricEvent(int d, vector<string> v) : befalls(v) {
	set_date(d);
}

//Borrar acontecimiento
void HistoricEvent::rm_befalls(string s) {
	int size = befalls_size();
	for(int i = 0; i < size; ++i){
		if(s.compare(befalls[i]) == 0){
			befalls.erase(i);
			--i;
		}
	}
}

//Mostrar acontecimiento i-ésimo
void HistoricEvent::show(int i){
  cout << "Year:" << date << befalls[i] << endl;
}

//Buscar
bool HistoricEvent::search(string s){
	bool find = false;
	int size = befalls_size();

	for(int i = 0; size < i; ++i)
		if (befalls[i].find(s) < befalls[i].size()) {
		 show(befalls[i]);
		find = true;
		}

	return find;
}

//Operador ==
bool HistoricEvent::operator==(const HistoricEvent &h) {
   bool eq = ((date == h.date) && (befalls_size() == h.befalls_size())) ? true : false;

   for(int i = 0; i < befalls.size() && eq; ++i)
      if(befalls[i].compare(h.befalls[i]) != 0)   //compare devuelve 0 si son iguales
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
