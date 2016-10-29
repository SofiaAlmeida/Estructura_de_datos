#include "chronology.h"

//Constructor por defecto

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
         res = sort(cl, cr);
      return res;
   }
}

//Mezclar dos cronologías
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

//Eventos anteriores
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

bool Chronology::InsertBefall(int date,const string &s){
  bool insert = false;
  int var_date;
  for(int i=0; insert == false; i++){
    var_date = event.at(i).get_date();
    if (var_date > date){
      HistoricEvent event(date,string);
      event.insert(i,event);
      insert = true;
    }
    else if (var_date == date){
      if (event.at(i).compare(string s)!=0){
      event.at(i).add_befall(s);
      insert = true;
      }
    }
  }
  return insert;
}


Chronology::rm_event (int a) {
	int i = 0;
	while (a != events[i].get_date()) {				//NOTE event(s)?
		i++;
	}

	events.erase(i);
}

Chronology Chronology::sum_chrono(const Chronology &chron2){
  std::vector<HistoricEvent> v;
  int size_chron1 = (*this).event.size();
  int size_chron2 = chron2.event.size();

  for(int i = 0; i < size_chron1; i++){
    v.push_back(*this.event.at(i));
  }

  for(int i = 0; i < size_chron2; i++){
    v.push_back(chron2.event.at(i);
  }

  Chronology result(v);
  result.sort();

  return result;
}

void Chronology::show_range(int inf, int sup){
  if (inf > sup)
    std::swap(inf,sup);
  int size = this->event.size();
  int befalls_size;

  for(int i = 0; i < size; i++){                                                          // Comprueba si la fecha de cada HistoricEvent
      if (this->event.at(i).get_date() >= inf && this->event.at(i).get_date() <= sup){    // es correcta y procede a mostrar su contenido
        befalls_size = this->event.at(i).befalls_size();
          for(int j = 0; j < befalls_size; i++){
            show(event.at(i).show(i));
          }
      }
  }
}
