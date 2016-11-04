#include "pila_max_list.h"

PilaMaxList::PilaMaxList() : cabecera(0) {
	;
}


void PilaMaxList::push(T t) {
	*Celda aux = new Celda;
	aux->sig = 0;
	aux->ant = cabecera->ant;
	aux->dato = y;

	cabecera->ant->sig = aux;
	cabecera->ant = aux;
}

T PilaMaxList::pop () {
	Celda* ult = *cabecera.ant;
	Celda* pen = *ult.ant;
	T ret = ult.dato;
	delete ult;
	pen.sig = 0;
	*cabecera.ant = pen;

	return ret;
}


T PilaMaxList::top () const {
	return cabecera->ant->dato;
}

PilaMaxList::~PilaMaxList () {

}
