  HistoricEvent() {

  }


  HistoricEvent(int d, const string& s) {
	p.first = d;
	p.second.insert(s);
  }


  HistoricEvent(pair <int ,set<string> > p_alt){
	p.first = p_alt.first;
	p.second = p_alt.second;
  }

  HistoricEvent(int d, set<string> v) {
	  p.first = d;
	  p.second = v;
  }

/*jaja no se que hacer con esto*/
  void HistoricEvent::show(int i) {
  }

/** @brief Busca una cadena dentro de un vector de eventos y muestra las encontradas
  * @param s String a buscar
  * @param show si es true muestra el string encontrado
  * @retval true si encuentra el string
  */
  bool search(const string &s, bool be_shown);

/**
  * @brief Sobrecarga del operador == |n
  *        Dos HistoricEvent se consideran iguales si tienen la misma fecha y los mismos acontecimientos
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si este objeto es igual a h
  */
  bool operator==(const HistoricEvent &h);

/**
  * @brief Sobrecarga del operador >
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si el año del objeto implícito es mayor que el de h
  */
  bool operator>>(const HistoricEvent &h);

/**
  * @brief Sobrecarga del operador >
  * @param h HistoricEvent a comparar con el objeto implícito
  * @retval true si el año del objeto implícito es menor que el de h
  */
  bool operator<<(const HistoricEvent &h);

/**
  * @brief Sobrecarga del operador +
  * @param h objeto a sumar con el implícito
  * @return objeto implícito al que se ha añadido los acontecimientos que no tenía de h.befalls
  */
  HistoricEvent& operator+(const HistoricEvent &h);
};
