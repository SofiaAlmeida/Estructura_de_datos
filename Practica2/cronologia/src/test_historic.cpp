#include <iostream>
#include "historic_event.h"
using namespace std;

int main () {

  cout << "Prueba de la clase evento histórico: \n" << "Prueba constructores:\n" << endl;

  vector<string> vector_strines;
  vector_strines.push_back("hola");
  vector_strines.push_back("adios");
  HistoricEvent vacio, fecha_string(1621,"Lamiamamma"),fecha_vector(2048, vector_strines);

  fecha_string.show(0);
  fecha_vector.show(0);
  fecha_vector.show(1);
  return 0;
}
