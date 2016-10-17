# Ideas fabulosas para nuestra segunda práctica <3

## <u>EventoHistorico</u>

*Nuestro TDA "EventoHistorico" almacena una fecha y uno o varios eventos históricos, la fecha es el año en número natural, y cada acontecimiento puede contener más de una palabra*

* La fecha es un entero natural (unsigned int)
* Para guardar los acontecimientos tenemos dos opciones:
  1. Un único string con sus separadores entre acontecimientos (#), en cuyo caso tendríamos que adaptar la lectura de estos strings a los separadores (usar muchos strings auxiliares y demás)
  2. Usar un vector dinámico de strings, cuyo acceso es más simple, pero tiene la complicación de trabajar con todo lo que acarrea usar un vector (campos para su tamaño, etc)

## <u>Cronologia</u>

*Es un conjunto de datos históricos ordenados por fechas*

Tenemos dos opciones de implementación:

1. Hacer un vector (dinámico) de EventoHistorico 's

  <u>Pros:</u> Implementación más familiar

  <u>Contras:</u> Para hacer operaciones tales como la inserción requiere mucho coste recolocar todos los elementos del vector

2. Utilizar celdas enlazadas

  Cada una con un EventoHistorico y un puntero al siguiente EventoHistorico

  <u>Pros:</u> Soluciona el problema de la inserción y eliminación de los vectores

  <u>Contras:</u> Trabajar con celdas
