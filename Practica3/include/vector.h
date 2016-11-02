/**
  * @file vector.h
  * @brief Fichero cabecera del TDA Vector
  *
  * Gestiona una secuencia de elementos
  */

#ifndef __Vector_H__
#define __Vector_H__

#include <cassert>

template <class T>

class Vector {
private:
	*T p;
	int n_elem;
	int reservados;

Public:
	Vector ();
	Vector (const Vector& v);

	int size () const {return n_elem;};
	int get_reservados () const {return reservados;};

	void resize (int n);

	~Vector ();

}
