#ifndef FILA_D
#define FILA_D
#define NOTSET -1
#include <stdio.h>
#include <stdlib.h>
typedef int tp_peca;
typedef struct tp_listad {
	tp_peca p_L; // Valor esquerdo da pe�a
	tp_peca p_R; // Valor direita  da pe�a
	struct tp_listad *next;
}tp_listad;

tp_listad *inicializa_listad() {
	return NULL;
}

tp_listad *listad_aloca(){
	tp_listad *novo;
	novo = (tp_listad *) malloc(sizeof(tp_listad));
	return novo;
}

int listad_vazia(tp_listad *l) {
	if(l == NULL) return 1;
	else return 0;
}

tp_listad *listad_peca_pos(tp_listad *fil, int pos) {
	int tmp = 0;
	tp_listad *aux = fil;
	if(pos >= listad_size(fil)) return NULL;
	while(tmp != pos) {
		if(aux == NULL) return NULL;
		aux = aux->next;
		tmp++;
	}
	return aux;
}

tp_listad *listad_search_for(tp_listad **fil, tp_peca L, tp_peca R) {
	// Retorna o endere�o onde se encontra o valor de e
	// Retorna null caso ele n�o encontre nada
	tp_listad *aux = *fil;
	while((aux != NULL)) {
		if((aux->p_L == L || aux->p_L == R) && ((aux->p_R == L || aux->p_R == R))) {
			// Encontrou a pe�a
			return aux;
		}
		aux=aux->next;
	}
	return NULL;
}

tp_listad *listad_search_for_dif(tp_listad **fil, tp_peca L, tp_peca R) {
	// Retorna o endere�o onde se encontra o valor de e
	// Retorna null caso ele n�o encontre nada
	tp_listad *aux = *fil;
	while((aux != NULL)) {
		if(aux->p_L == L && aux->p_R == R) {
			// Encontrou a pe�a
			return aux;
		}
		aux=aux->next;
	}
	return NULL;
}

int listad_insere_peca(tp_listad **fil, tp_peca L, tp_peca R) {
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

int listad_remove_peca(tp_listad **fil, tp_listad *endereco_peca) {
	tp_listad *ant, *atu;
	ant = NULL;
	atu = *fil;
	if(endereco_peca == NULL) return 0;
	while(atu->next != NULL && atu != endereco_peca) {
		ant = atu;
		atu = atu->next;
	}
	if(atu == NULL) {
		//Nao existe o endere�o para tal pe�a
		return 0;
	} else {
		if(ant != NULL) {
			ant->next = atu->next;
		} else {
			*fil = atu->next;
		}
	}
	free(atu);
	atu = NULL;
	return 1;
}

void listad_imprime(tp_listad *fil){
	tp_listad *aux;
	aux = fil;
	while(aux != NULL) {
		printf("[%d|%d]\t", aux->p_L, aux->p_R);
		aux = aux->next;
	}
	printf("\n");
}

int listad_soma(tp_listad *fil){ /*OK*/
	tp_listad *aux;
	int soma = 0;
	aux = fil;
	while(aux != NULL) {
		soma += aux->p_L;
		soma += aux->p_R;
		aux = aux->next;
	}
	return soma;
}

int listad_size(tp_listad *fil) { /*OK*/
	tp_listad *aux;
	aux = fil;
	int count = 0;
	while(aux != NULL) {
		count++;
		aux = aux->next;
	}
	return count;
}

#endif
