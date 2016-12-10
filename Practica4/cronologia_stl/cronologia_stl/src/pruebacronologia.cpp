#include "chronology.hpp"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  if (argc != 2) {
      cout << "Dime el nombre del fichero con la cronologia" << endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
   }
   
   Chronology mi_cronologia;
   f >> mi_cronologia; //Cargamos en memoria, en el traductor.
   
   int anio;
   cout << "Dime un año a consultar:";
   cin >> anio;
   
   HistoricEvent eventos;
   eventos = mi_cronologia.get_date_events(anio);  
   

   // Recorremos con iterador los acontecimientos para mostrarlos por pantalla 
   // Este proceso requiere la definición de un tipo iterator // const_iterator en EventoHistorico
   // Y la definición de los métodos begin() y end() en EventoHistorico
  HistoricEvent::const_iterator it;
   cout << anio << ":";              //Imprimimos el anio
   for (it = eventos.cbegin(); it != eventos.cend(); ++it) {
     cout << (*it) << '#';
   cout << endl;
   }
}
