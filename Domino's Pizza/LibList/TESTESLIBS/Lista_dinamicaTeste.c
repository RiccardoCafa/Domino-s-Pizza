#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\ricca\OneDrive\Documentos\GitHub\Domino-s-Pizza\Domino's Pizza\LibList\lista_dinamica.h"

int main () {
	tp_listad *lista;
	tp_listad *list_to;
	lista = inicializa_listad();
	listad_insere_peca(&lista, 3, 4);
	listad_insere_peca(&lista, 4, 2);
	listad_insere_peca(&lista, 1, 2);
	listad_insere_peca(&lista, 5, 2);
	listad_imprime(&lista); printf("\n");
	listad_insere_peca(&lista, 2, 1);
	list_to = listad_search_for(&lista, 4, 2);
	listad_remove_peca(&lista, list_to);
	listad_imprime(&lista); printf("\n");
	list_to = listad_search_for_dif(&lista, 3, 4);
	listad_remove_peca(&lista, list_to);
	listad_imprime(&lista);
	return 0;
}
