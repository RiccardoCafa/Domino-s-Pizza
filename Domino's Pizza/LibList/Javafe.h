//NOVA LISTA SUPER PODEROSA JAVAFE
#ifndef LISTA_PIECE
#define LISTA_PIECE

typedef struct Piece {
    unsigned left;
    unsigned right;
    struct Piece *next;
} tp_Piece;

tp_Piece *init_piece() {
	return NULL;
}

tp_Piece *alloc_piece(){
	tp_Piece *novo;
	novo = (tp_Piece *) malloc(sizeof(tp_Piece));
	return novo;
}


int empty_piece(tp_Piece *l) {
	if(l == NULL) return 1;
	else return 0;
}

int size_piece(tp_Piece *piece) {
	tp_Piece *aux;
	aux = piece;
	int count = 0;
	while(aux != NULL) {
		count++;
		aux = aux->next;
	}
	return count;
}

tp_Piece *position_piece(tp_Piece *piece, int pos) {
	int tmp = 0;
	tp_Piece *aux = piece;
	if(pos >= size_piece(piece)) return NULL;
	while(tmp != pos) {
		if(aux == NULL) return NULL;
		aux = aux->next;
		tmp++;
	}
	if(aux == NULL) return NULL;
	return aux;
}

int search_Piece(tp_Piece *fil, int left, int right) {
    // Retorna null caso ele não encontre nada
    tp_Piece *aux = fil;
    while((aux != NULL)) {
        if(aux->left == left && aux->right == right) {
            // Encontrou a peça
            return 1;
        }
        aux=aux->next;
    }
    return 0;
}

int remove_by_value_piece(tp_Piece **piece, int valor_l, int valor_r) {
	tp_Piece *ant, *atu;
	ant = NULL;
	atu = *piece;
	while(atu != NULL) {
		if(atu->left == valor_l && atu->right == valor_r) {
			break;
		}
		ant = atu;
		atu = atu->next;
	}
	if(atu == NULL) {
		//Nao existe o endereço para tal peça
		return 0;
	} else {
		if(ant != NULL) {
			ant->next = atu->next;
		} else {
			*piece = atu->next;
		}
	}
	free(atu);
	atu = NULL;
	
	return 1;
}

int listad_insere_peca(tp_Piece **piece, int left, int right) {
    tp_Piece *aux;
    tp_Piece *novo_no;
    novo_no = alloc_piece();
    if(!novo_no) return 0;
    novo_no->left = left;
    novo_no->right = right;
    novo_no->next = NULL;
    if(empty_piece(*piece)) {
        *piece = novo_no;
    } else {
        aux = *piece;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = novo_no;
    }
    return 1;
}

void player_imprime(tp_Piece *piece){
    tp_Piece *aux;
    aux = piece;
    int count = 0;
    while(aux != NULL) {
        //printf("[%d|%d]\t", aux->left, aux->right);
        fprintf(stderr, "%d - [%d|%d]\t", count, aux->left, aux->right);
        aux = aux->next;
        count++;
    }
    printf("\n");
}

int player_pecas_soma (tp_Piece *piece){ 
    tp_Piece *pie;
    int soma = 0;
    pie = piece;
    while(pie != NULL) {
        soma += pie->left;
        soma += pie->right;
        pie = pie->next;
    }
    return soma;
}


#endif
