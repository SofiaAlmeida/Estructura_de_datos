//Añadir elemento
void Pila_max::push(const elemento &e) {
   elemento e_aux = e;
   //Arreglamos el máximo
   if (pila.frente().max < e_aux.ele)
      e_aux.max = e_aux.ele;
   else
      e_aux.max = pila.frente().max;

   //Añadimos el elemento al principio
   Cola<elemento> aux;
   aux.poner(e_aux);
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
