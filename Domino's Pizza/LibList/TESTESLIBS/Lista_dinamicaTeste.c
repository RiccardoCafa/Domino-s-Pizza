#include <stdio.h>
#include <stdlib.h>
#include "Fila_dinamica.h"

int main () {
	tp_filad *lista;
	tp_filad *list_to;
	lista = inicializa_filad();
	filad_insere_peca(&lista, 3, 4);
	filad_insere_peca(&lista, 4, 2);
	filad_insere_peca(&lista, 1, 2);
	filad_insere_peca(&lista, 5, 2);
	filad_imprime(&lista); printf("\n");
	filad_insere_peca(&lista, 2, 1);
	list_to = filad_search_for(&lista, 4, 2);
	filad_remove_peca(&lista, list_to);
	filad_imprime(&lista); printf("\n");
	list_to = filad_search_for_dif(&lista, 3, 4);
	filad_remove_peca(&lista, list_to);
	filad_imprime(&lista);
	return 0;
}
