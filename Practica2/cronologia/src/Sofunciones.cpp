#include "historic_event.h"
#include "chronology.h"

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
           if(!search(h.befalls.at(i)))
              add_befall(h.befalls.at(i));
        }
     }
     return *this;
 }

 //FUNCIÓN SEARCH Modificación 2
 //Buscar
 bool HistoricEvent::search(string s){
   bool find = false;
   int size = befalls_size();
   for(int i = 0; size < i; ++i){
     if (befalls[i].find(s) < befalls[i].size()) {
      show(befalls[i]);
 	   find = true;
     }
   }
   return find;
 }

///////CHRONOLOGY
// HEADER
/**
  * @brief Constructor por defecto de la clase.
  */
  Chronology();

/**
  * @brief Eventos
  * @return Devuelve un vector de eventos
  */
  vector<HistoricEvent> get_events() const {return event;};

/**
  * @brief Ordenar por fecha
  * @return Cronología ordenada
  */
  Chronology& sort();

/**
  * @brief Eventos anteriores
  * @param d año a partir del cual se buscan los eventos
  * @return Vector con los eventos correspondientes
  */
  vector<HistoricEvent> prev_events(unsigned int d);

  /**
    * @brief Eventos posteriores
    * @param d año a partir del cual se buscan los eventos
    * @return Vector con los eventos correspondientes
    */
    vector<HistoricEvent> post_events(unsigned int d);
  /*
   * @brief Sobrecarga operador >>
   */

//SOURCE
//Constructor por defecto
 Chronology::Chronology() {

}
//Ordenar por fecha
Chronology& Chronology::sort() {    //mergesort
   if (event.size() <= 1)
      return *this;
   else {
      Chronology cl, cr, res;
      int middle = event.size() / 2;
      for(int i = 0; i < middle; ++i)
         cl.InsertBefall(event.at(i));
         // InserteBefall actualmente no funciona con estos parámetros
         // se puede sobrecargar o modificar esto aquí
         // >=??
      for(int i = event.size(); event >= middle; --i)
         cr.InsertBefall(event.at(i));

      cl = cl.sort();
      cr = cr.sort();

      if(cl.at(cl.event.back()) < cr.at(cr.event.begin()))
         res = cl.sum_chrono(cr);
      else
         res = merge(cl, cr);
      return res;
   }
}

   Chronology& Chronology::merge( Chronology &c) {
      Chronology res;
      while(event.size() > 0 && c.event.size() > 0)
         if(event.begin() < c.event.begin()) {
            res.InsertBefall(event.begin());
            rm_event(event.begin().get_date());              }
         else {
            res.InsertBefall(c.event.begin());
            c.rm_event(c.event.begin().get_date());
         }

         if(event.size() > 0)
            res = res.sum_chrono((*this));
         if(c.event.size() > 0)
            res = res.sum_chrono(c);
         return res;
   }


//Eventos anteriores (los de d sin incluir)
vector<HistoricEvent> Chronology::prev_events(unsigned int d) {
   vector<HistoricEvent> result;
   sort();

   int i = 0;
   while(event.at(i).get_date() < d)  {
      result.add(event.at(i));
      i++;
   }

   return result;
}

//Eventos posteriores
vector<HistoricEvent> Chronology::post_events(unsigned int d) {
   vector<HistoricEvent> result;
   sort();

   int i = event.size();
   while(event.at(i).get_date() > d)  {
      result.add(event.at(i));
      i--;
   }

   return result;
}

// Modificación funcion word_search
Chronology Chronology::word_search(const string &s, bool be_shown) {
   Chronology c;
   int size = events.size();

   for(int = 0; i < size; ++i)
      if(event[i].search(s,0))
         c.push_back(event[i]);

   if(be_shown) {
      cout << c;
   }

   return c;
}

vector<int> Chornology::word_search(string s, bool be_shown) {
	vector<int> v;
	vector<int> aux;
	intsize = events.size();

	for(int i = 0; i < size; ++i) {
		if(event[i].search(s, 0)) {
			v.push_back(event[i].date);
			aux.push_back(i);
		}
	}

//FIXME:No me gusta esta implementación pero no fuí capaz de hacerla mejor, la ire pensando
	if (be_shown) {
		int s = aux.size()

		if (s != 0) {
			for (int i = 0; i < s; ++i) {
				cout << "#" << event[aux[i]].date;
				event[aux[i]].search(s, 1))
			}
		}
		else {
			cout << "No se encontraron coincidencias";
		}
	}

	return v;
}

//CHANGED modificación operator <<
ostream& operator<<(ostream &os, const Chronology &c) {
  int size = event.size();
  int n_befalls;

  for(int i = 0; i < size; ++i) {
     os << event[i].get_date();
     n_befalls = event[i].befalls_size();
     for(int j = 0; j < n_befalls; ++j) {
        os << '#' << event[i].get_befalls()[j];
     }
     os << endl;
  }

  return os
}

ostream& operator<<(ostream &os, const Chronology &c) {
  int size = c.event.size();
  int n_befalls;
  vector<string> aux;

  for(int i = 0; i < size; ++i){
    aux = event[i].get_befalls();
    n_befalls = event[i].befalls_size();

    for(int j = 0; j < n_befalls; ++j)
      aux.show(j);
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

    /**
      * @brief Sobrecarga del operador +
      * @param c Cronología a asignat
      * @return cronología con la
    Chronology& operator=(const Chronology &c);

    //Operador =
    Chronology& Chronology::operator=(const Chronology &c) {
       event = c.get_events();
    }
