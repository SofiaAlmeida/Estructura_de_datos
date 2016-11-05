template <class T>
Pila::Pila<T>(const Cola<T> &c) {
   Cola aux(c);
   while (!aux.vacia()) {
      if(num_elementos() == 0)
         poner(aux.frente())
      else {
         if (frente() <= aux.frente()) {
            poner(aux.frente());
            aux.quitar();
         }
         else {
            
         }
      }
   }

}
