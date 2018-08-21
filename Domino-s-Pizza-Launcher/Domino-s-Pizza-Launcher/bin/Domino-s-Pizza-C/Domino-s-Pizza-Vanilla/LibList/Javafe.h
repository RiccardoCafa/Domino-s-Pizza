//NOVA LISTA SUPER PODEROSA JAVAFE
#ifndef LISTA_PIECE
#define LISTA_PIECE

typedef struct Piece {
    unsigned left;
    unsigned right;
    struct Piece *next;
} tp_Piece;

tp_Piece *init_piece() {//inicializa lista de peca
	return NULL;
}

tp_Piece *alloc_piece(){//aloca espaco para a lista de peca
	tp_Piece *novo;
	novo = (tp_Piece *) malloc(sizeof(tp_Piece));
	return novo;
}


int empty_piece(tp_Piece *l) {//verificar se ela esta vazia
	if(l == NULL) return 1;
	else return 0;
}

int size_piece(tp_Piece *piece) {//tamanho da lista de peca
	tp_Piece *aux;
	aux = piece;
	int count = 0;
	while(aux != NULL) {
		count++;
		aux = aux->next;
	}
	return count;
}

tp_Piece *position_piece(tp_Piece *piece, int pos) {//identifica a peca na posicao dada
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

int search_Piece(tp_Piece *fil, int left, int right) {//procura pela peca na lista
    // Retorna null caso ele nÃ£o encontre nada
    tp_Piece *aux = fil;
    while(aux != NULL) {
        if(aux->left == left && aux->right == right) {
            // Encontrou a peça
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

int look_for_value(tp_Piece *fil, int i_left, int f_right) {//procura uma peca para ser jogada
	tp_Piece *aux = fil;
	while(aux != NULL) {
        if(aux->left == i_left || aux->right == i_left || aux->left == f_right || aux->right == f_right) {
            // Encontrou a peça
            return 1;
        }
        aux = aux->next;
    }
	return 0;
}

int remove_by_value_piece(tp_Piece **piece, int valor_l, int valor_r) {//remove uma peca da lista pelo valor pedido
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
		//Nao existe o endereÃ§o para tal peÃ§a
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

int listad_insere_peca_ord(tp_Piece **l, int left, int right){//insere as pecas em ordem
	
	tp_Piece *new_node, *atu, *ant;
	
	new_node = alloc_piece();

	if (new_node == NULL) return 0;
	
	new_node->left = left;
	new_node->right = right;
	
	atu = *l;
	ant = NULL;

	while((atu != NULL) && (atu->right + atu->left < left + right)){
		ant = atu;
		atu = atu->next;
		
	}
	
	if (ant == NULL) *l = new_node;
	
	else ant->next = new_node;
	
	new_node->next = atu;
	
	return 1;
	
}

int listad_insere_pecas(tp_Piece **piece, int left, int right) {//insere uma peca na lista
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

void player_imprime(tp_Piece *piece){//mosta as pecas na lista
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

int player_pecas_soma (tp_Piece *piece){ //soma as pecas que estao na mao do jogador
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
