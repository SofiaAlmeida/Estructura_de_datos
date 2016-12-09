#include "chronology.hpp"

// Constructor copia
Chronology::Chronology(const Chronology &chrono) {
  chrono.events = events;
}

// Constructor
Chronology::Chronology(vector<HistoricEvent> h) {
  int size = h.size();
  for(int i = 0; i < size; ++i) {
    events.insert(pair<int, HistoricEvent> (h[i].first, h[i]);
  }
}

// Obtener vector de befalls
set<string> Chronology::get_befalls(int date) {
  Chronology::iterator it = find(date);
  return (*it).second.second;
}

// Insertar acontecimiento
void Chronology::InsertBefall(int date, const string &s) {
  Chronology::iterator it = events.find(date);

  //Si la fecha ya está, añadimos el string 
  if (it != end()) {
    (*it).second.add_befall(s);
  }
  else {
    HistoricEvent h(date, s);//REVISAR EN HISTORIC EVENT QUE ESTÉ CREADO DICHO CONSTRUCTOR
    insert(pair<int, HistoricEvent> (h.get_date(), h));
  }
}

// Insertar evento
bool Chronology::InsertEvent(const HistoricEvent &h) {
  Chronology::iterator it = events.find(h.first);

  if(it == events.end()) {
    insert(pair<int, HistoricEvent> (h.first, h));
  }
  else {
    //Si la fecha ya está, unimos los dos eventos
    it.second + h; //COMPROBAR QUE ESTÁ SOBRECARGADA + EN HISTORICEVENT
  }
}

// Borrar evento
void Chronology::rm_event(int date) {
  //Solo se ejecutará si hay un evento con esa fecha
  Chronology::iterator it;
  if ((it = events.find(date)) != end()) {
    events.erase(it);
  }
}

//Eventos anteriores
map<int, HistoricEvent> Chronology::prev_events(int d) {
  Chronology result;
  Chronology::iterator tope = events.find(date);
  Chronology::iterator it;

  for(it = events.begin(); it != tope; ++it) {
    result.insert_event((*it).second);
  }
  
  return result;
}

// Eventos posteriores
 map<int, HistoricEvent> Chronology::post_events(int d) {
   Chronology result;
   Chronology::iterator it;
   
   for(it = events.find(date); it != events.end(); ++it) {
     result.insert_event(it->second);
   }

   return result;
}

// Eventos en un rango
 map<int, HistoricEvent> Chronology::range(int inf, int sup) {
  if (inf > sup)
    std::swap(inf,sup);
  Chronology result;
  Chronology::iterator tope = events.find(sup);
  Chronology::iterator it;
  
  for(it = events.find(inf); it != tope; ++it) {
    result.insert_event(it->second);
  }

  return result;
}

// Buscar una palabra
 Chronology Chronology::word_search(const string &s) {
   Chronology result;
   HistoricEvent aux;
   Chronology::const_iterator c_it;

   for(c_it = cbegin(), c_it != cend(); ++c_it) 
     if((*c_it).second.search(s)) {
       aux = (*c_it).second.get_coincidences(s);//IMPLEMENTAR EN HISTORICEVENT
       result.insert_event(aux);
     }
	
   return result;
}
 //Sobrecarga operador +
Chronology& Chronology::operator+(const Chronology &c) {
  Chronology::iterator it;
  
  for(it = c.events.begin(); it != c.events.end(); ++it) {
    (*this).insert_event((*it).second);
  }
  
  return *this;
}

// Operador <<
ostream& operator<<(ostream &os, const Chronology &c) {
  Chronology::iterator it;

  for(it = c.events.begin(); it != c.events.end(); ++it) {
    os << (*it).second; //COMPROBAR QUE ESTÁ SOBRECARGADO << EN HISTORICEVENT
    os << "\n"; //COMPROBAR SI ES NECESARIO
  }

  os << endl;

  return os;
}

// Operador >>
istream& operator>>(istream &is, Chronology &c) {
  HistoricEvent h;
  //COMPROBAR QUE ESTÁ SOBRECARGADO >>
  while(is >> h) {
    c.insert_event(h);
  }
  
  return is;
}

