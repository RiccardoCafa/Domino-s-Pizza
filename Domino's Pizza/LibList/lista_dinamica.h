#ifndef FILA_D
#define FILA_D

typedef struct listad {
	tp_Piece *hand;
	struct listad *next;
} tp_listad;

tp_listad *inicializa_listad() {//inicializa a lista dinamica
	return NULL;
}

tp_listad *listad_aloca(){//aloca espaco
	tp_listad *novo;
	novo = (tp_listad *) malloc(sizeof(tp_listad));
	return novo;
}

int listad_insere_peca(tp_listad **fil) {//insere a peca na lista
	tp_listad *aux;
	tp_listad *novo_no;
	novo_no = listad_aloca();
	if(!novo_no) return 0;
	novo_no->p_L = L;
	novo_no->p_R = R;
	novo_no->next = NULL;
	if(listad_vazia(*fil)) {
		*fil = novo_no;
	} else {
		aux = *fil;
		while(aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = novo_no;
	}
	return 1;
}
#endif
