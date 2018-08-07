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
// A.I.
tp_hand *AIChoose_card(tp_hand *AI_hand, tp_jogada *jogo);
ret_resp AIPlay(tp_hand *ai_hand, tp_jogada *jogo); // RICCARDO
//Player functions
ret_resp play_card(tp_hand *p_hand, tp_jogada *jogo);
ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand);
//In-Game funcionts
void passTurn(int *p_turn); 
/*ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand); // OK (TESTE)
ret_resp AllotCards(tp_hand *p1, tp_hand *p2, tp_deck *baralho); // OK (TESTE)
node_game *choose_card(); // RICC Busca item
ret_resp play_card(tp_hand *p_hand); // JAFE
ret_resp checkWin(tp_deck *p_hand, int p_turn); // JAFE
//A.I.
node_game *AIChoose_card(); // MIGUEL OK
//In-game funcionts
void passTurn(int *p_turn); // Gabriel
ret_resp choosGameType(); // Gabriel
//Interface
void introduction(); [4|3] [*4 2*] // Jander
void gameplay();
//Game JANDER
int game(); //*/
//ESTE COMENTARIO é um teste para o branches
// ################## Criar funções ##################
introduction() {
	printf("INTRODUCITON\n");
}

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

ret_resp AllotCards(tp_deck *baralho, tp_hand *p1, tp_hand *p2) {	// Preenche a mão do jogador com as fichas;
 
	int i;
	tp_item x[i];
	tp_item y[i];
		
		if (stack_empyt(baralho)) { // Verifica se o deck estah vazio;
			return 0;
		} else {
			for (i=1; i<=7; i++) {	//Pôr 7 fichas na mão do jogador;
				
				pop(&baralho, &r_L[i], &r_R[i]); // Retira as fichas do deck
			
					x[i] = r_L[i]; // Associa o valor esquerdo da ficha ao vetor "x[]";
					y[i] = r_R[i]; // Associa o valor direito da ficha ao vetor "y[]";
			
				listad_insere_peca(&p1, x[i], y[i]); // Insere as fichas na mão do jogador.
				
				
				pop(&baralho, &r_L[i], &r_R[i]); 
				
					x[i] = r_L[i];
					y[i] = r_R[i]; 
				
				listad_insere_peca(&p2, x[j], y[j]);

					return 1;
			} 
		}
}

ret_resp pickupCard(tp_deck *deck_stack, tp_hand *p_hand) {	//Pega uma peça do deck;
	
	if (stack_empyt(deck_stack)){	//Verifica se o deck estah vazio;
		return 0;	// Retorna '0' se for verdadeiro;
	} else { 	// Caso seja falso, continua;
		
	pop(&deck_stack,&r_L, &r_R);	// Retira uma ficha do deck;
		
	tp_item x = r_L; 	// Associa o valor esquerdo da ficha a variável "x";
	tp_item y = r_R;	// Associa o valor esquerdo da ficha a variável "y";
	
	listad_insere_peca(&p_hand, x, y);	// Insere a ficha na mão do jogador;

		return 1;	// Retorna '1' se o processo for bem sucedido.
	}		
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
