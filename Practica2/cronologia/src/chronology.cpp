#include "chronology.h"

//Inserta una acontecimiento
void Chronology::InsertBefall(date, s){
  bool insert = false;
  for(int i=0; insert == false; i++){
    if (event.at(i).get_date() > date){
      HistoricEvent event(date, string);      // FIXME si la fecha ya existe se crearían 2 objetos con la misma fecha
      event.insert(i,event);
      insert = true;
    }
  }
}
