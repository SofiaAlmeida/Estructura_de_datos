/**
  * Funcionalidades extra: Dentro de la clase cronología implementaremos los siguientes métodos extra:
  * 
  * -Unión de cronologías
  * -Filtro por palabras
  * -Filtro por rango de fecha
  * -Estadísticas
  */


/**
  * @brief Une dos cronologías indicadas en una tercera
  * @param Archivo donde se encuentra la primera cronología
  * @param Archivo donde se encuentra la segunda cronología
  * @param Nombre del archivo en el cual se introducirá la nueva cronología
  * @return void
  */
                                                                            

void concat_chron(string input_1, string input_2, string output){

  Chronology chron1, chron2, chron3;

  ifstream file1, file2;
  
  if (file1.open(input_1)){				 
    file1 >> chron1;	
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

  chron3 = chron1 + chron2; 

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

  Chronology chron;
  istream input;

  if (input.open(word)){
    input >> chron;
    input.close();
  }
  else
    cout << "Error en la apertura del fichero " << word << endl;

  chron = word_search(word);
  
  return chron;
}

/**
  * @brief Filtrado por dos fechas, lee de un fichero y escribe en otro
  * @param nombre del fichero de lectura
  * @param primera fecha
  * @param segunda fecha
  * @parm nombre del fichero de salida
  * @return void 
  */

void date_filter(const string& filein, const int& lower, const int& upper, const string& fileout){

  Chronology chron;
  istream in;

  if (in.open(word)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;

  chron = range(lower, upper);

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
 
  Chronology chron;
  istream in;

  if (in.open(word)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura del fichero " << filein << endl;

  chron = range(lower, upper);
  
  cout << chron;
}


/**
  * @brief Datos estadísticos acerca de la cronología: Recuento de años, número de eventos ocurridos, máximo de eventos y promedio de eventos por año(salida estándar)
  * @param Fichero con la cronología
  * @return void
  */

void stats(const string& filename){

  istream in;
  Chronology chron;

  if (in.open(filename)){
    in >> chron;
    in.close();
  }
  else
    cout << "Error en la apertura de " << filename << endl;

  double total_years = 0;
  double total_befalls = 0, mean_befalls; // Total de eventos y promedio de eventos/año

  Chronology::const_iterator c_it;

  total_years = events.size();
  
  for(c_it = begin(); c_it != end(); ++it) 
    total_befalls += (*it).second.befalls_size();
  
  mean_befalls = total_befalls / total_years;
  
  cout << "Hay un total de " << total_befalls << " ocurridos en " << total_years << " años\nEsto hace una media de " << mean_befalls << " eventos/año" << endl;
  
}




  

  
