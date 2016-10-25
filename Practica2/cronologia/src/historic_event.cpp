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
