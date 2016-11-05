
void Pila_max::push(const elemento &e) {
   elemento e_aux = e;
   if (pila.frente().max < e_aux.elemento)
      e_aux.max = e_aux.ele;
   else
      e_aux.max = pila.frente().max;

   
}
