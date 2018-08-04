#include <stdio.h>
#include <stdlib.h>
#include "ListaDE.h"

int main () {
	tp_listad *listad;
	tp_listad *list_to;
	listad = inicializa_listad();
	insere_lista_no_fim(listad, 6, 4);
	insere_lista_no_fim(listad, 2, 2);
	insere_lista_no_fim(listad, 3, 1);
	insere_lista_no_fim(listad, 1, 5);
	imprime_listad(listad, 1);
	remove_listad(listad, 2, 2);
	list_to = busca_listad(listad, 3, 1);
	if(list_to != NULL) remove_listad(listad, 3, 1);
	imprime_listad(listad, 1);
	return 0;
}
