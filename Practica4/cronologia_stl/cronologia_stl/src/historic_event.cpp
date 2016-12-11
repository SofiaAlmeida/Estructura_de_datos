#include "historic_event.hpp"
#include <cassert>

// Constructor
HistoricEvent::HistoricEvent(int d, const string& s) {
  p.first = d;
  p.second.insert(s);
}

// Constructor
HistoricEvent::HistoricEvent(const pair<int, set<string> > &p_alt){
  p.first = p_alt.first;
  p.second = p_alt.second;
}

// Constructor
HistoricEvent::HistoricEvent(int d, const set<string> &s) {
  p.first = d;
  p.second = s;
}

// Añadir acontecimiento
void HistoricEvent::add_befall(const string &s) {
  //Insert no añade si el elemento ya está
    p.second.insert(s);
}

// Indica si ha encontrado string 
bool HistoricEvent::search(const string &s) const {
  if(p.second.find(s) != p.second.cend())
    return true;
  else
    return false;
}

// Acontecimientos que contienen string
HistoricEvent HistoricEvent::get_coincidences(const string &s) const {
  HistoricEvent result;
  HistoricEvent::const_iterator c_it;
  
  for(c_it = cbegin(); c_it != cend(); ++c_it) {
    if((*c_it).find(s) != string::npos)
      result.add_befall(*c_it);
  }
 
  return result;
}

// Sobrecarga +
HistoricEvent& HistoricEvent::operator+(const HistoricEvent &h) {
  assert((*this).get_date() == h.get_date());
  HistoricEvent::const_iterator c_it;

  for(c_it = h.cbegin(); c_it != h.cend(); ++c_it)
    (*this).add_befall(*c_it);

  return *this;
}

// Sobrecarga <<
ostream& operator<<(ostream& os, const HistoricEvent &h) {
  HistoricEvent::const_iterator c_it;
  
  os << h.get_date();
  for(c_it = h.p.second.cbegin(); c_it != h.p.second.cend(); ++c_it)
    os << "#" << *c_it;

  os << endl;

  return os;
}

istream& operator>>(istream& is, HistoricEvent &h) {
  string buffer, aux;
  
  return is;

  /*   PRUEBA DE LEER E INTRODUCIR TODO LO OCURRIDO EN UN AÑO DE UN STRING

       void HistoricEvent::line_reader(string& line){
       
       string aux;

       pos = line.find('#');
       aux = line.substr(0, pos);
       h.set_date(stoi(aux));

       while((pos = line.find('#')) != string::npos) {
       aux = line.substr(0, pos);
       buffer.erase(0, ++pos);
       h.add_befall(aux);
  }

  h.add_befall(line);

   */
}
