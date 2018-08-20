#ifndef GAMEPLAY
#define GAMEPLAY

int Game_init(tp_stack *heap, tp_Piece **p1, tp_Piece **p2) {
	int x, y, tamanhopilha = 0;
	start_stack(heap);
	srand((unsigned)time(NULL));
	x = rand() % 7; /*gerar numero aleatorio de 0-6*/
	y = rand() % 7;
	while(tamanhopilha != MAX_STACK)/*verificar se ainda n prencheu tudo*/{
		if(stack_lookup(*heap, x, y) == 0){
			push(heap, x, y); /*colocar os numeros gerados na pilha*/
			tamanhopilha++;
		}else{
			x = rand() % 7;
			y = rand() % 7;
		}
	}
	printf("\n");
	
	if (stack_empty(heap)) { // Verifica se o deck está vazio;
		return 0;
	} else {
		int i;
		for (i=0; i < 7; i++) {	//Loop para add 7 fichas na mão do jogador;
			pop(heap, &x, &y); // Retira as fichas do deck
			listad_insere_peca(p1, x, y); // Insere as fichas na mÃ£o do jogador p1.
			pop(heap, &x, &y); // Retira as fichas do deck
			listad_insere_peca(p2, x, y);
		}
		return 1;
	}
}

int firstPlay(tp_Piece **p1, tp_Piece **p2, tp_listade **jogo, tp_Piece **atu, int *turn) { //verificar quem vai ser o primeiro a jogar
    int i = 0;
    int aux;
    for(i = 6; i >= 0; i--) {//faz um loop para verificar quem vai ser o primeiro
        aux = search_Piece(*p1, i, i);
        if(aux != 0) {//o primeiro jogador comeca
            *turn = 2;
            *atu = *p2;
            insere_lista_no_inicio(*jogo, i, i);
            remove_by_value_piece(p1, i, i);
            return 1;
        }
        aux = search_Piece(*p2, i, i);;
        if(aux != 0) {//segundo jogador comeca
            *turn = 1;
            *atu = *p1;
            insere_lista_no_inicio(*jogo, i, i);
            remove_by_value_piece(p2, i, i);
            return 1;
        }
    }
    printf("Ocorreu um erro (002)...\nPor favor, nos informe pelo GitHub o ocorrido -\n");
    printf("https://github.com/RiccardoCafa/Domino-s-Pizza/ \nMuito Obrigado!\n");
    return 0;
}

void passTurn(int *turno, tp_Piece *p1, tp_Piece *p2, tp_Piece **p_at){
    if(*turno==1){  //verifica variavel turno pra ver quem estava jogando
        //transfere o proximo jogador pra funcao de mostrar a mao 
        *p_at = p2;
        *turno=2;
    }else {
		*p_at = p1; 
        *turno=1;
    }
}

int Checkwin(tp_Piece *p1, tp_Piece *p2, tp_listade *jogo ,tp_stack *baralho){
	//checa quem se alguem ganhou e qual foi
    if(empty_piece(p1) == 1) {//verificar se mao do jogador 1 esta vazia
        return 1;
    } else if(empty_piece(p2) == 1) {//verifica se a mao do jogador 2 esta vazia
        return 2;
    } else if(stack_empty(baralho)) { //verifica se o baralho esta vazio 
        int valor_r, valor_l;
        if(search_Piece(p1, jogo->ini->v_L, jogo->ini->v_R) == 0) return 0;//verifica os lados do jogo 
        if(search_Piece(p2, jogo->ini->v_L, jogo->ini->v_R) == 0) return 0;//se existir chances de jogar
        if(search_Piece(p1, jogo->fim->v_L, jogo->ini->v_R) == 0) return 0;//retorna 0 e continua o jogo
        if(search_Piece(p2, jogo->fim->v_L, jogo->ini->v_R) == 0) return 0;
        if(player_pecas_soma(p1) > player_pecas_soma(p2)) {
		//soma as pecas que estao na mao de cada jogar se o jogador 1 tiver menos ele ganha se n o 2 ganha.
            return 1;
        } else if(player_pecas_soma(p1) < player_pecas_soma(p2)) {
            return 2;
        } else {
        	return 3;
		}
        return 0;
    } else {
    	return 0;
	}
}

#endif
