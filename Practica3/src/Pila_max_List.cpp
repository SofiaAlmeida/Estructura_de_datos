#include "pila_max_list.h"

Pila_max::Pila_max() {
	*Celda aux = new Celda;
	cabecera = aux;
	aux->ant = 0;
}

int Pila_max::size () {
	int i = 0;
	Celda* p =cabecera->ant

	while (p != cabecera){
		i++;
		p = p->ant;
	}

	return i;
}

/*NOTE:recordadme que ponga el algoritmo algo mas fino si sobra tiempo, este es la version simple*/
Pila_max::Pila_max(const Pila_max& p) {
	int s = size;
	T [s];
	Celda* p = cabecera->ant;

	for (int i = 0; i < s; ++i){
		t[i] = p->dato.ele;
		p = p->ant
	}

	for (int i = (s-1); i > -1; --i){
		push(t[s]);
	}
}

// Esto asi va bien?
Pila_max& Pila_max::operator= (const Pila_max& p){
	if (this != &p) {
		while (cabecera->ant) {
			pop();
		}

		int s = size;
		T [s];
		Celda* p = cabecera->ant;

		for (int i = 0; i < s; ++i){
			t[i] = p->dato.ele;
			p = p->ant
		}

		for (int i = (s-1); i > -1; --i){
			push(t[s]);
		}
	}
}


void Pila_max::push(T y) {
	if (cabecera->ant != 0) {
		*Celda aux = new Celda;
		aux->ant = cabecera->ant;
		cabecera->ant = aux;

		aux->dato.ele = y;
		x = (aux->ant->dato.max)
		aux->dato.max = (y>x ? y : x);
	}

	else {
		*Celda aux = new Celda;
		aux->ant = cabecera;
		cabecera->ant = aux;
		aux->dato.ele = aux.dato.max = y
	}
}

void Pila_max::pop () {
	if (cabecera->ant) {
		Celda* aux = cabecera->ant
		cabecera->ant = cabecera->ant->ant;
		delete aux;
	}
}


Pila_max::~Pila_max () {
	while (cabecera->ant) {
		pop();
	}
	delete cabecera;
}
