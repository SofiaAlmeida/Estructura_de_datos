#include "chronology.h"


//Constructor copia
Chronology Chronology::Chronology(chrono) {
  events = chrono.get_events();
}

// TODO Constructor
Chronology Chronology::Chronology(vector<HistoricEvent> h) {

}

//Insertar acontecimiento
bool Chronology::InsertBefall(int date,const string &s) {
  bool insert = false;
  int var_date;
  for(int i = 0; insert == false; ++i){
    var_date = event[i].get_date();
    if (var_date > date){
      HistoricEvent e(date,string);
      event.insert(i,e);
      insert = true;
    }
    else if (var_date == date){ //FIXME añade aunque haya dos iguales
      //if (event[i].compare(string s)!=0){
      event[i].add_befall(s);
      insert = true;
      //}
    }
  }
  return insert;
}

//Insertar evento
bool Chronology::InsertEvent(const HistoricEvent &h) {
  int date = h.get_date();
  vector<string> v = h.get_befalls();
  size = v.size();
  bool insert = false;

  for(int i = 0; i < size; ++i)
    insert = InsertBefall(date,v[i]);

  return insert;
}

//Borrar evento
void Chronology::rm_event(int date) {
  size = event.size();
  bool rm = false;

  for(int i = 0; i < size && !rm; ++i)
    if(date == event[i].get_date()) {
      event.erase(i);
      rm = true;
    }
}

//Ordenar por fecha
Chronology& Chronology::sort() {    //mergesort
   if (event.size() <= 1)
      return *this;
   else {
      Chronology cl, cr, res;
      int middle = event.size() / 2;
      for(int i = 0; i < middle; ++i)
         cl.InsertBefall(event[i]);
         //NOTE InserteBefall actualmente no funciona con estos parámetros
         // se puede sobrecargar o modificar esto aquí
         // REVIEW >=??
      int size = event.size()
      for(int i = middle; i < size; ++i)
         cr.InsertBefall(event[i]);

      cl = cl.sort();
      cr = cr.sort();

      if(cl[cl.event.back()] < cr[cr.event.begin()])
         res = cl.event.insert(cl.event.end(),cr.event.begin(),cr.event.end());
         //inserta en la posición final de cl desde el principio hasta el final de cr
      else
         res = cl.merge(cr);
      return res;
   }
}

//Mezclar dos cronologías
Chronology& Chronology::merge(Chronology &c) {
   Chronology res;
   while(event.size() > 0 && c.event.size() > 0)
      if(event.begin() < c.event.begin()) {
         res.InsertBefall(event.begin());
         rm_event(event.begin().get_date());
      }
      else {
         res.InsertBefall(c.event.begin());
         c.rm_event(c.event.begin().get_date());
      }

   if(event.size() > 0)
      res.event.insert(res.event.end(),event.begin(),event.end());
   if(c.event.size() > 0)
      res.event.insert(res.event.end(),c.event.begin(),c.event.end());
   return res;
}

//Sumar dos cronologías
Chronology Chronology::sum_chrono(const Chronology &chron2){
  vector<HistoricEvent> v;
  int size_chron1 = event.size();
  int size_chron2 = chron2.event.size();

  for(int i = 0; i < size_chron1; ++i){
    v.push_back(event[i]);
  }

  for(int i = 0; i < size_chron2; i++){
    v.push_back(chron2.event[i]);
  }

  Chronology result(v);
  result.sort();

  return result;
}

//Eventos anteriores
vector<HistoricEvent> Chronology::prev_events(int d) {
   vector<HistoricEvent> result;
   sort();

   int i = 0;
   while(event[i].get_date() < d)  {
      result.add(event[i]);
      ++i;
   }

   return result;
}

//Eventos posteriores
vector<HistoricEvent> Chronology::post_events(int d) {
   vector<HistoricEvent> result;
   sort();

   int i = event.size();
   while(event[i].get_date() > d) {
      result.add(event[i]);
      i--;
   }

   return result;
}

//Eventos en un rango
void Chronology::show_range(int inf, int sup) {
  if (inf > sup)
    std::swap(inf,sup);
  int size = event.size();
  int befalls_size;

  for(int i = 0; i < size; ++i){                                                          // Comprueba si la fecha de cada HistoricEvent
      if (event[i].get_date() >= inf && event[i].get_date() <= sup){    // es correcta y procede a mostrar su contenido
        befalls_size = event[i].befalls_size();
          for(int j = 0; j < befalls_size; i++){
            event[i].show(j,true));
          }
      }
  }
}

//Operador << TODO

//Operador >>
istream& operator>>(istream &is, Chronology &c) {
   int d, size, j;
   string aux;
   vector<string> v;

   while(is) {
      is >> d;
      aux = is.getline();
      size = aux.size();
      j = 0;
      for(int i = 0; i < size; ++i) {
            v[j].push_back(aux[i])
            if(v[j] == '#') {
               v[j].pop_back();
               ++j;
            }
      }
      HistoricEvent h(date,v);
      c.InsertEvent(h);
   }
