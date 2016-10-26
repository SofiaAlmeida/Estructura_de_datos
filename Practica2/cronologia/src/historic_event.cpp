#include "historic_event.h"


HistoricEvent::HistoricEvent(unsigned int d, string s) {
	*this.set_date(d);
	*this.add_befalls(s);
}

HistoricEvent::HistoricEvent() {
	*this.set_date(0);
}

HistoricEvent::HistoricEvent(unsigned int d, vector<string> v) : befalls (v) {
	set_date(d);
}

void HistoricEvent::rm_befalls(string s) {
	int i = 0;
	while (s.compare(befalls[i])) {				//compare vale 0 si son iguales
		i++;
	}

	befalls.erase(i);
}

/** @brief Muestra el nombre de un determinado evento de un año (indicando este último)
  *
  * @param i Posición del string de "befalls" a mostrar
  *
  */
void HistoricEvent::show(i){
  cout << "Year:" << date << befalls.at(i) << endl;
}

void HistoricEvent::search(s){
	int found_pos;
  for(int i = 0; befalls.size() < i; i++){
    if (befalls.at(i).find(s) < befalls.at(i).size()) {
      mostrar(befalls.at(i));
    }
  }
}
