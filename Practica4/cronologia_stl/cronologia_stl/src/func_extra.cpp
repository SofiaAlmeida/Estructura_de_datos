/**
  * Funcionalidades extra: Dentro de la clase cronología implementaremos los siguientes métodos extra:
  * 
  * -Unión de cronologías: Inidicadas dos cronologías crea una tercera unión de ambas y las almacena en un nuevo fichero
  *
  */


/**
  * @brief Une dos cronologías indicadas en una tercera
  * @param Archivo donde se encuentra la primera cronología
  * @param Archivo donde se encuentra la segunda cronología
  * @param Nombre del archivo en el cual se introducirá la nueva cronología
  * @return void
  */
                                                                              // NOTE: Los métodos en mayúscula o minúscula? 

void concat_chron(string input_1, string input_2, string output){

  Chronology chron1, chron2, chron3;

  ifstream file1, file2;
  
  if ( file1.open(input_1)){					// Abrimos los ficheros indicados y de ellos leemos los 
    file1 >> chron1;		// NOTE: No tengo claro si esto es así
    file1.close();
  }
  else
    cout << "No se pudo leer el archivo " << input_1 << endl;
  

  if (file2.open(input_2)){
    file2 >> chron2;
    file2.close();
  }
  else
    cout << "No se pudo leer el archivo " << input_2 << endl;

  // Aquí empezamos a copiar y unir ambas cronologías, que depende de los métodos de los que dispongamos en chronology así haremos:

  // NOTE: COMO merge(Chronology) está implementado en cronología podemos hacer uso de ese método
  /*
    // Si el operador + en chronology está implementado junto al de asignación podemos usar simplemente
    	chron3 = chron1 + chron2; (+ devolvería el objeto suma de ambos y = lo asignaría)

    // Si no lo está entonces habría que apañárselas de otro modo, por ejemplo copiando chron1 en chron3 y luego recorrer chron2 insertando bien nuevos pairs si la 
    // clave no coincide con ninguna de las existentes o si coincide añadiendo los eventos al set de esa clave


   */
    

  ofstream file3;
  
  if (file3.open(output)){
    file3 << chron3;
    file3.close();
  }
  
  else
    cout << "No se pudo abrir el archivo " << output << endl;
  
  
  return 0;
}


/**
  * @brief Dada una palabra clave devolvemos un subconjunto de elementos de cronología cuyos eventos contengan esa palabra
  * @param string a buscar
  * @return Devuelve una Chronology con los eventos coincidentes
  */

Chronology::Chronology word_filter(const string& word){
  //DOING

  Chronology chron;
  istream input;

  if (input.open(word)){
    input >> chron;
    input.close();
  }
  else
    cout << "Error en la apertura del fichero " << word << endl;

  chron = word_search(word, false); 		//false evita que se muestre por la salida estándar

  return chron;
}

/**
  * @brief Filtrado por dos fechas, lee de un fichero y escribe en otro
  * @param nombre del fichero de lectura
  * @param primera fecha
  * @param segunda fecha
  * @parm nombre del fichero de salida
  * @return Chronology con los eventos del intervalo especificado
  */

void date_filter(const string& filein, const int& lower, const int& upper, const string& fileout){
  // TODO

  Chronology chron;
  istream in;

  if (in.open(word)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;

  chron.events = range(lower, upper); 		// NOTE: Tal vez esto no funcione
  // Alternativa: Implementar un constructor que acepte un map<int, HistoricEvent> para poder hacer Chronology(chron.range(int,int)) (que no sé si en un constructor se puede llamar a una función, tendría sentido que si) (en este caso habría que crear una nueva cronología resultante)

  ofstream out;
  
  if (out.open(fileout)){
    out << chron;
    out.close();
  }
  else
    cout << "Error en la apertura del fichero " << fileout << endl;
}


/**
  * @brief Filtrado por dos fechas, lee de un fichero y escribe en salida estándar
  * @param nombre del fichero de lectura
  * @param primera fecha
  * @param segunda fecha
  * @return Chronology con los eventos del intervalo especificado
  */

void date_filter(const string& filein, const int& lower, const int& upper){
  // TODO

  Chronology chron;
  istream in;

  if (in.open(word)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;

  chron.events = range(lower, upper); 		// NOTE: Tal vez esto no funcione
  // Alternativa: Implementar un constructor que acepte un map<int, HistoricEvent> para poder hacer Chronology(chron.range(int,int)) (que no sé si en un constructor se puede llamar a una función, tendría sentido que si) (en este caso habría que crear una nueva cronología resultante)

  cout << chron;
}


/**
  * @brief Datos estadísticos acerca de la cronología: Recuento de años, número de eventos ocurridos, máximo de eventos y promedio de eventos por año(salida estándar)
  * @param Fichero con la cronología
  * @return void
  */

void stats(const string& filename){
  //TODO

  istream in;
  Chronology chron;

  if (in.open(filename)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura de " << filename << endl;

  int total_years = 0;
  int total_befalls = 0, mean_befalls; // Total de eventos y promedio de eventos/año

  Chronology::const_iterator c_it;
  HistoricEvent::const_iterator chron_c_it;

  for(c_it = begin(); c_it != end(); ++it){  // ESTO NO SE HACE A PELO
    total_years++;

    for(chron_c_it = c_it->begin(); chron_c_it != c_it->end(); ++chron_c_it){	//FIXME: Poner bien cómo se recorre todos los Befalls de cada HistoricEvent
      total_befalls++;
    }
  }

	  //Quiero recorrer cada Befall de cada HistoricEvent dentro de esta Chronology

  mean_befalls = total_befalls / total_years;  // Con enteros igual no hace bien la media :/
  cout << "Hay un total de " << total_befalls << " ocurridos en " << total_years << " años\nEsto hace una media de " << mean_befalls << " eventos/año" << endl;
  
}




  

  
