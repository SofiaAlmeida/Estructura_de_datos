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

  int fecha_fechastrin = fecha_string.get_date();

  cout << "La fecha de fecha_string (\"Lamiamamma\") es: " << fecha_fechastrin << endl;

  vector<string> test_get_befalls = fecha_vector.get_befalls();
  cout << "Test_get_befalls (prueba de get_befalls) devuelve un vector que contiene: " << test_get_befalls[0] << "  " << test_get_befalls[1] << endl;

  cout << "El HistoricEvent vacío tiene (prueba de befalls_size): " << vacio.befalls_size() << endl; 
  return 0;
}
