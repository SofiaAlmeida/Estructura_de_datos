#!/bin/csh
@ inicio = 100
@ fin = 1000000
@ incremento = 1000
set ejecutable = /bin/ejercicio_desc_sol
set salida = ./dat/tiempos_ejercicio_desc_sol.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
