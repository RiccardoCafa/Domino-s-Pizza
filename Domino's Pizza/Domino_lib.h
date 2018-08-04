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

// ################## Define tipos de variáveis ##################
typedef int tp_card; // Para o tipo de peça
typedef int ret_resp; // Para os tipos de retorno

// ################## Importando bibliotecas ##################

#ifndef LISTA_DE // Lista dinamica duplamente encadeada onde ficarão as peças jogadas
#include ".\LibList\ListaDE.h"
typedef tp_listade tp_jogada;
#define LISTA_DE
#endif

#ifndef LISTADIN_H // LISTA DINAMICA SIMPLES PARA A MÃO DO JOGADOR
#include ".\LibList\lista_dinamica.h"
typedef tp_listad tp_hand;
#define LISTADIN_H
#endif

#ifndef PILHA_H
#include ".\LibList\Stack.h"
typedef tp_stack tp_deck; // declara uma struct da biblioteca Stack
#define PILHA_H
#endif

//################## Declaração das funções ##################
// Hand funcionts
ret_resp shuffle_cards(tp_deck *deck_to_shuffle); // MIGUEL OK
//Player functions
/*ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand); // JANDER
node_game *choose_card(); // RICC Busca item
ret_resp play_card(tp_hand *p_hand); // JAFE
ret_resp checkWin(tp_deck *p_hand, int p_turn); // JAFE
//A.I.
ret_resp AIPlay(tp_hand *ai_hand); // RICCARDO
ret_resp AIPickUp(tp_deck *deck_stack, tp_hand *ai_hand); // JANDER
node_game *AIChoose_card(); // MIGUEL OK
//In-game funcionts
void introduction();
void passTurn(int *p_turn); // 
ret_resp choosGameType(); // 
//Game JANDER
int game(); //*/

// ################## Criar funções ##################
ret_resp shuffle_cards(tp_deck *deck_to_shuffle)/*criar e embaralhar o deck*/ {
	int x,y,tamanhopilha = 0;
	/*inicializou*/
	start_stack(deck_to_shuffle);
	srand((unsigned)time(NULL));
	x = rand() % 7;/*gerar numero aleatorio de 0-6*/
	y = rand() % 7;
	while(tamanhopilha != MAX_STACK)/*verificar se ainda n prencheu tudo*/{
		if(stack_lookup(*deck_to_shuffle, x, y) == 0){
			push(deck_to_shuffle, x, y);/*colocar os numeros gerados na pilha*/
			tamanhopilha++;
		}else{
			x = rand() % 7;
			y = rand() % 7;
		}
	}
	return 1;
	/*retorna 1 dizendo que prencheu*/
}

tp_hand *AIChoose_card(tp_hand *AI_hand) /*verificar a mao do IA*/ {
	/*se ele tiver uma peca jogar*/
	tp_jogada *jogo;
	tp_hand *x;
	tp_hand *y;
	if((x == NULL)||(y==NULL)){
		return NULL;
	}
	x = listad_search_for(&AI_hand,jogo->ini->v_L,jogo->ini->v_R);
	y = listad_search_for(&AI_hand,jogo->fim->v_L,jogo->fim->v_R);
	if(x != NULL){		
		return x;/*se conseguiu achar no ini*/
	} else if(y != NULL){
		return y; /*se conseguiu achar no fim*/
	} else{
		return NULL;/*se n conseguir*/	
	}	
}

#endif
