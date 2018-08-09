#ifndef PLAYER_LIB_H
#define PLAYER_LIB_H
//Player functions
ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo); // JAFE
ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand); // OK (TESTE)
tp_hand player_choose(tp_hand *player); // Ask which piece he wants to play or if he wants to get from stack

ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand) {	//Pega uma peça do deck;
	int r_L, r_R;
	
	if (stack_empty(deck_stack)){	//Verifica se o deck estah vazio;
		return 0;	// Retorna '0' se for verdadeiro;
	} else { 	// Caso seja falso, continua;
		
	pop(deck_stack,&r_L, &r_R);	// Retira uma ficha do deck;
	
	listad_insere_peca(&p_hand, r_L, r_R);	// Insere a ficha na mão do jogador;

		return 1;	// Retorna '1' se o processo for bem sucedido.
	}		
}


ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo) {
	return 1;
}

#endif
