// ################## BIBLIOTECA DOMINO ##################
// ################## 	  SINGLETON 	##################
#ifndef DOMINO_LIB
#define DOMINO_LIB
// ################## DEFINE CONSTANTES ##################
#define MAX_CARDS 28
// ################## IMPORTA BIBLIOTECAS NECESSARIAS ##################
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

// ################## Define tipos de vari�veis ##################
typedef int tp_card; // Para o tipo de pe�a
typedef int ret_resp; // Para os tipos de retorno

// ################## Importando bibliotecas ##################

#ifndef LISTA_DE // Lista dinamica duplamente encadeada onde ficar�o as pe�as jogadas
#include ".\LibList\ListaDE.h"
typedef tp_listade tp_jogada;
#define LISTA_DE
#endif

#ifndef LISTADIN_H // LISTA DINAMICA SIMPLES PARA A M�O DO JOGADOR
#include ".\LibList\lista_dinamica.h"
typedef tp_listad tp_hand;
#define LISTADIN_H
#endif

#ifndef PILHA_H
#include ".\LibList\Stack.h"
typedef tp_stack tp_deck; // declara uma struct da biblioteca Stack
#define PILHA_H
#endif

//################## Declara��o das fun��es ##################
// Hand funcionts
ret_resp shuffle_cards(tp_deck *deck_to_shuffle); // MIGUEL OK
// A.I.
tp_hand *AIChoose_card(tp_hand *AI_hand, tp_jogada *jogo);
ret_resp AIPlay(tp_hand *ai_hand, tp_jogada *jogo); // RICCARDO
//Player functions
ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo);
ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand);
//In-Game funcionts
void passTurn(int *p_turn); 
/*ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand); // JANDER
ret_resp AllotCards(tp_hand *p1, tp_hand *p2, tp_deck *baralho); // JANDER
node_game *choose_card(); // RICC Busca item
ret_resp play_card(tp_hand *p_hand); // JAFE
ret_resp checkWin(tp_deck *p_hand, int p_turn); // JAFE
//A.I.
node_game *AIChoose_card(); // MIGUEL OK
//In-game funcionts
void introduction();
void passTurn(int *p_turn); // Gabriel
ret_resp choosGameType(); // Gabriel
//Game JANDER
int game(); //*/
//ESTE COMENTARIO � um teste para o branches
// ################## Criar fun��es ##################
void passTurn(int *p_turn) {
	printf("passa turno\n");
}

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

ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand) {
	return 1;
}

tp_hand *AIChoose_card(tp_hand *AI_hand, tp_jogada *jogo) /*verificar a mao do IA*/ {
	/*se ele tiver uma peca jogar*/
	tp_hand *x;
	tp_hand *y;
	tp_no *jg1;
	tp_no *jg2;
	jg1 = jogo->ini;
	jg2 = jogo->fim;
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

ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo) {
	return 1;
}

ret_resp AIPlay(tp_hand *ai_hand, tp_jogada *jogo, tp_deck *baralho) {
	// L�gica
	// Checar se tem cartas para jogar na mesa
	// Caso haja, jogue
	// Caso n�o tenha, cave
	tp_hand *aux;
	aux = AIChoose_card(aux, jogo); // Escolha uma pe�a que possa encaixar
	if(aux == NULL) { // Caso for nulo
		// N�o h� cartas para serem jogadas
		pickupCard(baralho, ai_hand); // cava
		return 0;
	} else { // se n�o
		// H� pe�as que podem ser jogadas
		play_card(aux, jogo); // jogue a pe�a
		return 1;
	}
}

#endif
