//Añadir elemento FIXME template
void Pila_max::push(const int &dato) {
   elemento e;
   e.ele = dato;

   //Arreglamos el máximo
   if (pila.frente().max < dato)
      e.max = dato;
   else
      e.max = pila.frente().max;

   //Añadimos el elemento al principio
   Cola<elemento> aux;
   aux.poner(e);
   while(!pila.vacia()) {
      aux.poner(pila.frente());
      aux.quitar();
   }
   pila = aux;
}

//Sobrecarga operador =
Pila_max& Pila_max::operator=(const Pila_max &p) {
   pila = p.pila;
   return *this;
}
