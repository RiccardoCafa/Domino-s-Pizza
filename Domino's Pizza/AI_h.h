#ifndef AI_LIB_H
#define AI_LIB_H
// A.I.
tp_hand *AIChoose_card(tp_hand *AI_hand, tp_jogada *jogo); // OK
ret_resp AIPlay(tp_hand *ai_hand, tp_jogada *jogo, tp_deck *baralho); // RICCARDO

tp_hand *AIChoose_card(tp_hand *AI_hand, tp_jogada *jogo) /*verificar a mao do IA*/ {
	/*se ele tiver uma peca jogar*/
	tp_hand *x;
	tp_hand *y;
	tp_no *jg1;
	tp_no *jg2;
	jg1 = jogo->ini;
	jg2 = jogo->fim;
	x = y = NULL;
	if(jg1 == NULL || jg2 == NULL) return NULL;
	x = listad_search_for(&AI_hand, jg1->v_L, jg1->v_R);
	y = listad_search_for(&AI_hand, jg2->v_L, jg2->v_R);
	
	if(x != NULL){		
		return x;/*se conseguiu achar no ini*/
	} else if(y != NULL){
		return y; /*se conseguiu achar no fim*/
	} else{
		return NULL;/*se n conseguir*/	
	}	
}

ret_resp AIPlay(tp_hand *ai_hand, tp_jogada *jogo, tp_deck *baralho) {
	// Lógica
	// Checar se tem cartas para jogar na mesa
	// Caso haja, jogue
	// Caso não tenha, cave
	tp_hand *aux;
	aux = AIChoose_card(aux, jogo); // Escolha uma peça que possa encaixar
	if(aux == NULL) { // Caso for nulo
		// Não há cartas para serem jogadas
		pickupCard(baralho, ai_hand); // cava
		return 0;
	} else { // se não
		// Há peças que podem ser jogadas
		play_card(aux, jogo); // jogue a peça
		return 1;
	}
}


#endif
