1.- Comparar Vertices
2.- Comparar Aristas
3.- Seleccionar primer vertice en GA y buscar uno con mismo grado en GB
4.- 






Dos grafos, probar a con u. agarrar las cabezas o igualar los head y asignar cuando tengan el mismo grado

a tiene una lista de adjacencia, (e->d->c) 

a: e->d->c

u: v->y->z

"Tomamos el primero que seria e y lo tratamos de asignar con el primero de adjacente que seria el otro, v"
"miras lista de adjacencia de e"

e: b->c->(a que ya no se puede)
v: (u que ya esta marcado)->x->w
hicimos que a es u. O sea ya esta marcado.

e seria v, entonces esos ya estan marcados. "Ya no podrias decir este podria ser v porque ya lo agarraste con otro vertice"


"RECORRER LA LISTA DE ADYACENCIA PERO CADA NODO TENDRIA QUE TENER UN BOOLEANO DE ASIGNACION QUE LE DIGA SI YA FUE ASIGNADO O NO."


e: b->c->(a que ya no se puede)
v: (u que ya esta marcado)->x->w

"Tenes dos disponibels en cada uno"

"3/3 DISPOINBLES"
a: e->d->c  

u: v->y->z

"2/2 disponibles"
e: b->c->(a que ya no se puede)
v: (u que ya esta marcado)->x->w




"Entonces aqui hay error porque ya hay dos de uno."
b: f->(e)->d
x: (v)->(u)->z



"Regresamos a la asignacion anterior"


e:
v:




COMPARAR LISTAS DE ADYACENCIAS DE DOS VERTICES (A, U, tablitaIsomorfismo)
{
	// TENEMOS A: e, d, c
	// TENEMOS U: v, y, z

	//COMPARAR LISTAS DE ADYACENCIAS DE VERTICES 1 DE A Y U
	SI  (DISPONIBILIDAD(A) == DISPONIBILIDAD(U) && DISPONIBILIDAD(A) != 0)
	{
		ASIGNAR A TABLITA ADYACENTES


		TOMAR LOS HEAD SI ESTAN DISPOINIBLES
			COMPARAR LISTAS DE ADYACENCIAS DE DOS VERTICES(e, v)
		SINO
			TOMAR heads nexts HASTA QUE HAYA DISPONIBILIDAD

	}
	SINO 
	{
		return false;
	}


	SI (CASO TRIVIAL == TRUE) // DISPONIBILIDADES TODAS FALSE O 0/0
	-
		return true;









	






}












