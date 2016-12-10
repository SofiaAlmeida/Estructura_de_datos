#include <iostream>
#include "historic_event.hpp"

using namespace std;

int main () {

  cout << "Prueba de la clase evento histórico: \n" << "Prueba constructores:" << endl;
                                      // PROBAMOS CONSTRUCTORES
  set<string> set_strines;
  set_strines.insert("hola");
  set_strines.insert("adios");
  pair<int, set<string> > p(2014, set_strines);
  
  HistoricEvent vacio, fecha_string(1621,"Lamiamamma"), fecha_set(2048, set_strines), pair(p), copia(fecha_string);

// Mostramos lo mostrable
  cout << "Debería mostrar: Lamiamamma\n hola adios\n 2014 2";
  cout << "Muestra:\n";

  cout << fecha_string << endl;
  cout << fecha_set << endl;
  
  cout << "Comprobamos el funcionamiento del constructor copia:\n";

  cout << copia << endl;

  /*¿¿¿¿¿ CÓMO PROBAMOS LOS ITERADORES DIRECTAMENTE????? */

  // Probamos get_date
  cout << "Probamos get_date()  (En fecha_set) :" << endl;
  cout << fecha_set.get_date() << endl;

  // Probamos get_befalls (creamos un nuevo objeto a partir del set de strings de fecha_set, pero con otro año) 
  HistoricEvent prueba_get_befalls(2222,fecha_set.get_befalls()); 

  cout << "Probamos get_befalls():" << endl;
  cout << prueba_get_befalls() << endl;

  //Probamos befalls_size()

  cout << "Que tiene un tamaño de: " << endl;
  cout << prueba_get_befalls.befalls_size() << endl;

  // Probamos setdate()

  cout << "Vamos a cambiarle la fecha a 1111: " << endl;

  prueba_get_befalls.setdate(1111);

  cout << prueba_get_befalls << endl;

  // Probamos añadir un acontecimiento

  cout << "Añadimos un acontecimiento, \"cositaquepasó\":" << endl;
  prueba_get_befalls.add_befall("cositaquepasó");
  cout << prueba_get_befalls << endl;
  
    
  /*// A PARTIR DE AQUÍ NO ESTÁ ADAPTADO
  
  copia.set_date(2040);

  cout << copia.get_date() << " " << set_string << endl;

// Probamos befalls_size()
  cout << "El HistoricEvent vacío tiene (prueba de befalls_size): " << vacio.befalls_size() << endl;

// Probamos set_date(int)
  fecha_string.set_date(9667);
  cout << "La fecha de fecha_string es ahora: " << fecha_string.get_date() << " (Prueba de  setdate)" << endl;

  // Probamos add_befall y rm_befalls

  fecha_vector.rm_befalls("hola");
  cout << "Eliminamos \"hola\" del HistoricEvent con hola y adios y mostramos cual es el nuevo elemento primero (prueba rm_befalls): " << endl;
  fecha_vector.show(0);

  fecha_vector.add_befall("yanosaludo");
  cout << "Ahora para probar add_befall mostramos el segundo elemento de fecha_vector: " << endl;
  fecha_vector.show(1);

  // Prueba search(string, bool)

  cout << "Ahora vamos a comprobar si \"o\" lo podemos encontrar en la cadena, y si sí lo mostraremos" << endl;

  if (fecha_vector.search("o",true))
    cout << "Encontrado y mostrado" << endl;

// Prueba de operador ==

  HistoricEvent igual_1(1000,"igual"), igual_2(1000,"igual"), desigual(1000,"desigual");

  if(igual_1 == igual_2)
    cout << "Probado con == que son iguales \"gual_1(1000,\"igual\"), igual_2(1000,\"igual\");\"" << endl;
  else
    cout << "No son iguales (== usado)" << endl;

  if(!(igual_1 == desigual))
    cout << "\"desigual(100,\"desigual\")\" e igual_1 son distintos" << endl;

  // Probamos < y >

  if(fecha_vector < igual_1)
    cout << "fecha_vector sucedió antes que los acontecimientos de igual_1" << endl;
  else if (fecha_vector > igual_1)
    cout << "fecha_vector sucedió después que igual_1" << endl;

    fecha_vector.show(0);
    igual_1.show(0);

  // Probamos el operador +

  HistoricEvent suma;
  suma = desigual + igual_1;

  cout << "Probamos a sumar desigual e igual_1 y lo mostramos en un Evento suma" << endl;

  vector<string> test_sum = suma.get_befalls();
  for(int i = 0; i < test_sum.size(); ++i) // Probamos si puede mostrar todos los Eventos de suma
  suma.show(i);*/

  return 0;
}
