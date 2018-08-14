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
#include <locale.h>

// ################## Define tipos de vari√°veis ##################
typedef int tp_card; // Para o tipo de pe√ßa
typedef int ret_resp; // Para os tipos de retorno

// ################## Importando bibliotecas ##################

#ifndef LISTA_DE // Lista dinamica duplamente encadeada onde ficar√£o as pe√ßas jogadas
#include ".\LibList\ListaDE.h"
typedef tp_listade tp_jogada;
#define LISTA_DE
#endif

#ifndef LISTADIN_H // LISTA DINAMICA SIMPLES PARA A M√ÉO DO JOGADOR
#include ".\LibList\lista_dinamica.h"
typedef tp_listad tp_hand;
#define LISTADIN_H
#endif

#ifndef PILHA_H
#include ".\LibList\Stack.h"
typedef tp_stack tp_deck; // declara uma struct da biblioteca Stack
#define PILHA_H
#endif

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Gameplay.h"
#endif

#ifndef INTERFACE_H
#define INTERFACE_H
#include "Interface_h.h"
#endif

#ifndef PLAYER_ACTIONS_H
#define PLAYER_ACTIONS_H
#include "Player_actions.h"
#endif

#ifndef AI_H
#define AI_H
#include "AI_h.h"
#endif

//################## Declara√ß√£o das fun√ß√µes ##################
//In-Game funcionts
void passTurn(int *p_turn); 

//Game
game_logic() {

	shuffle_cards(&montinho); // Embaralha o montinho 
	AllotCards(&montinho, &p1, &p2); // Distribui as peÁas
	firstPlay(p1, p2, &atu, &turno); // Verificar se a peÁa 1|1 existir, caso n„o encontrar pula +1 
	// Verificar de quem È o turno
	ShowGameplay(p1, p2, jogo, turno);// **mostra interface 
	while(checkWin(atu, turno)) { // Verifica quem ganhou
		player_choose(atu);// Perguntar qual È a carta
		// Jogar carta caso seja possivel, se n pesque
		passTurn(&turno);// Passa o turno
		// Esconder os valores
		// Aperte para continuar
		// Mostre o proximo jogador
		ShowGameplay(p1, p2, jogo, turno);
	}// AtÈ alguem ganhar ai finaliza a rodada
}

#endif
