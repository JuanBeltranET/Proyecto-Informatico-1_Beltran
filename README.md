# TP N°4 Uso de sensores + Monitor Serial
-Leer datos que nos brinda un sensor de temperatura(TPM35) y uno de luz ambiental(LDR).
-Mostrar esos 2 datos por el monitor serial con el siguiente formato:

"El nivel de luz actual es:"  VALOR " y la temperatura actual:" VALOR  "ºc"   c/u en una linea distinta.
( utilizar condicional compuesto)

-Hacer prender un led RGB según la temperatura que mida el sensor:

-rojo: si es más de 90°c

-azul: si es menos de 18°c

-verde: si está entre 18ºc y 90ºc

(utilizar condicional compuesto y MAP invertido)
-Solo se deberá prender el led como se indica arriba, siempre y cuando la luz ambiental este entre el 30% y 70%. 
siendo 0%  TODA LA LUZ ENCENDIDA
siendo 100% TODA LA LUZ APAGADA

Todos los pines deberán ser demarcados como variables constantes con nombres declarativo y los mensajes acortados con Macros

Juan Manuel Beltran Gimenez 4°1 | etjuanmanuelbeltran@gmail.com
Gonzalo Consorti | consor92@gmail.com
