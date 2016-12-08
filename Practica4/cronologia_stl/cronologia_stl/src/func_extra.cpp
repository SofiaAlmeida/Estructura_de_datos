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

  chronology chron1, chron2, chron3;

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
  //TODO
}

/**
  * @brief Filtrado por dos fechas
  * @param primera fecha
  * @param segunda fecha
  * @return Chronology con los eventos del intervalo especificado
  */

Chronology::Chronology date_filter(const int& lower, const int& upper){

  // TODO
}



/**
  * @brief Datos estadísticos acerca de la cronología: Recuento de años, número de eventos ocurridos, máximo de eventos y promedio de eventos por año(salida estándar)
  * @param Fichero con la cronología
  * @return void
  */

void stats(const string& filename){
  //TODO
}




  

  
