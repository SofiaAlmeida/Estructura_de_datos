#include <iostream>
#include <string>
#include <vector>

class HistoricEvent {
private:
	unsigned int date;
	vector<string> befalls;

public:
	HistoricEvent();
	HistoricEvent(const HistoricEvent& he);
	HistoricEvent(unsigned int d, string s);

	unsigned int get_date() const {return date};
	vector<string> get_befalls() const {return befalls};

	void set_date(unsigned int d) {date = d};
	void add(string s) {befalls.pushback(s)}; /*puede que sea push_back*/
}
