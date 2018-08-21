#ifndef LISTADE_H
#define LISTADE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct tp_no_aux {
	int v_R;
	int v_L;
	struct tp_no_aux *ant;
	struct tp_no_aux *prox;
} tp_no;

typedef struct {
	tp_no *ini;
	tp_no *fim;
} tp_listade;

tp_listade *inicializa_listade() {//inicializa lista duplamente encadeada
	tp_listade *lista = (tp_listade *) malloc(sizeof(tp_listade));
	lista->ini = NULL;
	lista->fim = NULL;
	return lista;
}

tp_no *aloca() {//aloca espaco
	tp_no *pt;
	pt = (tp_no *) malloc(sizeof(tp_no));
	return pt;
}

int insere_lista_no_fim(tp_listade *lista, int L, int R) {//insere no fim da lista
	tp_no *novo;
	novo=aloca();
	if(!novo) return 0;
	novo->v_R = R;
	novo->v_L = L;
	if((lista->ini == NULL) && (lista->fim == NULL)) {
		novo->prox = NULL;
		novo->ant = NULL;
		lista->ini = lista->fim = novo;		
	} else {
		novo->prox = NULL;
		novo->ant = lista->fim;
		lista->fim->prox = novo;
		lista->fim = novo;
	}
	return 1;
}

int insere_lista_no_inicio(tp_listade *lista, int L, int R) {//insere no inicio da lista
	tp_no *novo;
	novo=aloca();
	if(!novo) return 0;
	novo->v_R = R;
	novo->v_L = L;
	if((lista->ini == NULL) && (lista->fim == NULL)) {
		novo->prox = NULL;
		novo->ant = NULL;
		lista->ini = lista->fim = novo;		
	} else {
		novo->prox = lista->ini;
		novo->ant = NULL;
		lista->ini = novo;
	}
	return 1;
}


void imprime_listad(tp_listade *lista, int ordem) {//mostra os valores dentro da lista
	tp_no *atu;
	
	switch(ordem) {
		case 1: atu = lista->ini;
		while(atu != NULL) {
			printf("[%d|%d] ", atu->v_L, atu->v_R);
			atu=atu->prox;
		}
		printf("\n");
		break;
		case 2: atu = lista->fim;
		while(atu != NULL) {
			printf("[%d|%d] ", atu->v_L, atu->v_R);
			atu = atu->ant;
		}
		break;
		default: printf("codigo invalido"); break;
	}
	printf("\n");
}

int listade_vazia(tp_listade *lista) {//verificar se a lista esta vazia
	if((lista->ini == NULL) && (lista->fim==NULL)) return 1;
	return 0;
}

int remove_listad(tp_listade *lista, int r_L, int r_R) {
	tp_no *atu;
	atu = lista->ini;
	while((atu!=NULL)&&(atu->v_L != r_L && atu->v_R != r_R)) {
		atu=atu->prox;
	}
	if(atu==NULL) return 0;
	if(lista->ini == lista->fim) {
		lista->ini = lista->fim = NULL;
	} else {
		if(lista->ini == atu) {
			lista->ini = atu->prox;
			atu->prox->ant = NULL;
		}else {
			if(lista->fim == atu) {
				lista->fim = atu->ant;
				atu->ant->prox = NULL;
			}else {
				atu->prox->ant = atu->ant;
				atu->ant->prox = atu->prox;
			}
		}
	}
	free(atu);
	return 1;
}
#endif
