#ifndef GAMEPLAY_LIB
#define GAMEPLAY_LIB

//Gameplay
ret_resp AllotCards(tp_deck *baralho, tp_hand **p1, tp_hand **p2); // OK
ret_resp shuffle_cards(tp_deck *deck_to_shuffle); // OK
ret_resp checkWin(tp_deck *p_hand, int p_turn); // JAFE

ret_resp shuffle_cards(tp_deck *deck_to_shuffle)/*criar e embaralhar o deck*/ {
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


ret_resp AllotCards(tp_deck *baralho, tp_hand **p1, tp_hand **p2) {	// Preenche a mão do jogador com as fichas;
 
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
/*REVER
ret_resp checkWin(tp_deck *p_hand, int p_turn){ // JAFE
	
	if( (listade_vazia (p_hand)) && (stack_empyt(tp_deck)) ){ 	// Ver se o jogador ainda tem cartas 
		return 1;
	}else{
		return 0; // Dizendo que ainda tem carta 	
	}
}
*/
#endif
