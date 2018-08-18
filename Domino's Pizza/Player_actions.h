#ifndef PLAYER_LIB_H
#define PLAYER_LIB_H
//Player functions

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


ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo, int posicao, int inioufim) {
	/*PRECISA SER TESTADO
	  Verificar se a pe�a encaixa*/
	tp_hand *aux;
	aux = listad_peca_pos(p_hand, posicao);
	if(aux == NULL) return 0;
	if(inioufim == 1) {	
		if(jogo->ini->v_L == aux->p_L) {
			insere_lista_no_inicio(jogo, aux->p_R, aux->p_L);
			listad_remove_peca(&p_hand, aux);
		} else if(jogo->ini->v_L == aux->p_R) {
			insere_lista_no_inicio(jogo, aux->p_L, aux->p_R);
			listad_remove_peca(&p_hand, aux);
		} else {
			return 0;
		}
	} else if(inioufim == 2){
		if(jogo->fim->v_R == aux->p_L) {
			insere_lista_no_fim(jogo, aux->p_L, aux->p_R);
			listad_remove_peca(&p_hand, aux);
		} else if(jogo->fim->v_R == aux->p_R) {
			insere_lista_no_fim(jogo, aux->p_R, aux->p_L);
			listad_remove_peca(&p_hand, aux);
		} else {
			return 0;
		}
	} else {
		printf("Posicao invalida\n");
	}
	
	return 1;
}

// Ask which piece he wants to play or if he wants to get from stack
void player_choose(tp_hand *player, tp_deck *baralho, tp_jogada *jogo) {
	int certo = 0;
	int esc, iof, exist;
	tp_hand *aux;
	aux = player;
	while (certo == 0) {
		printf("Que operacao deseja realizar?\n1 - Jogar peca\n2 - Cava\n");
		fflush(stdin);
		scanf("%d", &esc);
		if(esc == 2) {
			pickupCard(baralho, player);
			printf("Mao do jogador: \n");
			listad_imprime(player);
			return;
		} else if(esc == 1) {
			printf("Escolha de 0 a %d qual peca deseja jogar na mesa...\n", listad_size(player) - 1);
			fflush(stdin);
			scanf("%d", &esc);
			if(esc < 0 || esc > listad_size(player) - 1) {
				printf("Peca escolhida nao existe!\n");
				continue;
			}
			printf("Deseja jogar no inicio ou no fim?\n1 - inicio\n2 - fim\n");
			fflush(stdin);
			scanf("%d", &iof);
			aux = listad_peca_pos(player, esc);
			if(aux == NULL) {
				//printf("Ocorreu um erro (001)...\nPor favor, nos informe pelo GitHub o ocorrido -\n");
				//printf("https://github.com/RiccardoCafa/Domino-s-Pizza\nMuito Obrigado!\n");
				continue;
			} else {
				exist = play_card(player, jogo, esc, iof);
				if(exist == 0) {
					printf("Peca nao inserida\n");
				} else if(exist == 1) {
					printf("Peca inserida\n");
					certo = 1;
					return;
				}
			}
		} else {
			continue;
		}
		
	}
}

#endif
