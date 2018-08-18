#ifndef GAMEPLAY_LIB
#define GAMEPLAY_LIB

//Gameplay
int AllotCards(tp_deck *baralho, tp_hand **p1, tp_hand **p2); // OK
int shuffle_cards(tp_deck *deck_to_shuffle); // OK
int checkWin(tp_hand *p1, tp_hand *p2, tp_jogada *jogo ,tp_deck *baralho); // JAFE
int firstPlay(tp_hand *p1, tp_hand *p2, tp_jogada *jogo, tp_hand **atu, ret_resp *turn);

int firstPlay(tp_hand *p1, tp_hand *p2, tp_jogada *jogo, tp_hand **atu, ret_resp *turn) { /*PRECISA SER FEITA*/
	int i = 0;
	tp_hand *aux;
	for(i = 6; i >= 0; i--) {
		aux = listad_search_for_dif(&p1, i, i);
		if(aux != NULL) {
			*turn = 2;
			*atu = p2;
			insere_lista_no_fim(jogo, i, i);
			listad_remove_peca(&p1, aux);
			return 1;
		}
		aux = listad_search_for_dif(&p2, i, i);
		if(aux != NULL) {
			*turn = 1;
			*atu = p1;
			insere_lista_no_fim(jogo, i, i);
			listad_remove_peca(&p2, aux);
			return 1;
		}
	}
	printf("Ocorreu um erro (002)...\nPor favor, nos informe pelo GitHub o ocorrido -\n");
	printf("https://github.com/RiccardoCafa/Domino-s-Pizza\nMuito Obrigado!\n");
	return 0;
}

int shuffle_cards(tp_deck *deck_to_shuffle)/*criar e embaralhar o deck*/ {
	int x,y,tamanhopilha = 0;
	/*inicializou*/
	start_stack(deck_to_shuffle);
	srand((unsigned)time(NULL));
	x = rand() % 7; /*gerar numero aleatorio de 0-6*/
	y = rand() % 7;
	while(tamanhopilha != MAX_STACK)/*verificar se ainda n prencheu tudo*/{
		if(stack_lookup(*deck_to_shuffle, x, y) == 0){
			push(deck_to_shuffle, x, y); /*colocar os numeros gerados na pilha*/
			tamanhopilha++;
		}else{
			x = rand() % 7;
			y = rand() % 7;
		}
	}
	return 1;
	/*retorna 1 dizendo que prencheu*/
}


int AllotCards(tp_deck *baralho, tp_hand **p1, tp_hand **p2) {	// Preenche a mão do jogador com as fichas;
 
	int i;
	tp_item x;
	tp_item y;
		
	if (stack_empty(baralho)) { // Verifica se o deck está vazio;
		return 0;
	} else {
		for (i=0; i<7; i++) {	//Loop para add 7 fichas na mão do jogador;
			
			pop(baralho, &x, &y); // Retira as fichas do deck
			listad_insere_peca(p1, x, y); // Insere as fichas na mÃ£o do jogador p1.
			
			pop(baralho, &x, &y); 
			listad_insere_peca(p2, x, y); // Insere as fichas na mÃ£o do jogador p2.
		} 
		return 1;
	}
}

int checkWin(tp_hand *p1, tp_hand *p2, tp_jogada *jogo ,tp_deck *baralho){ // JAFE
	if(!stack_empty(baralho)) return 0;
	if(listad_vazia(p1)) {
		return 1;
	} else if(listad_vazia(p2)) {
		return 2;
	} else {
		int count = 0;
		int valor_r, valor_l;
		//valor_r = jogo->fim->v_R;
		//valor_l = jogo->fim->v_L;
		if(listad_search_for(&p1, jogo->fim->v_L, jogo->fim->v_R) != NULL) return 0;
		if(listad_search_for(&p2, jogo->fim->v_L, jogo->fim->v_R) != NULL) return 0;
		valor_r = jogo->ini->v_R;
		valor_l = jogo->ini->v_L;
		if(listad_search_for(&p1, valor_l, valor_r) != NULL) return 0;
		if(listad_search_for(&p2, valor_l, valor_r) != NULL) return 0;
		if(listad_soma(&p1) > listad_soma(&p2)) {
			return 1;
		} else {
			return 2;
		}
	}
}

#endif
