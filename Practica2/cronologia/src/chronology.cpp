#include "chronology.h"


void Chronology::InsertBefall(int date,string s){
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
      event.at(i).add_befall(s);
      insert = true;
    }
  }
}
