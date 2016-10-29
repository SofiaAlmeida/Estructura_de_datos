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
   for(int i = 0; befalls.size() < i; ++i){
     if (befalls.at(i).find(s) < befalls.at(i).size()) {
      show(befalls.at(i));
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
         //NOTE InserteBefall actualmente no funciona con estos parámetros
         // se puede sobrecargar o modificar esto aquí
         // REVIEW >=??
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
            rm_event(event.begin().get_date());     //NOTE se puede sobrecargar rm_event o dejar esto así
         }
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
