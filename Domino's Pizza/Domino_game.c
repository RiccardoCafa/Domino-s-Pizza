//########################## DOMIN� #####################################\\
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Domino_lib.h"

int main() {
	// Declarar as vari�veis
	tp_deck baralho;
	tp_hand *p1;
	tp_hand *p2;
	tp_hand *atu;
	tp_jogada *jogo;
	ret_resp turno;
	
	p1 = inicializa_listad();
	p2 = inicializa_listad();
	jogo = inicializa_listade();
	
	game_logic();
	
	
	return 0;
	
}

//Game
void game_logic() {

	shuffle_cards(&baralho); // Embaralha o montinho 
	AllotCards(&baralho, &p1, &p2); // Distribui as pe�as
	firstPlay(p1, p2, &atu, &turno); // Verificar se a pe�a 1|1 existir, caso n�o encontrar pula +1 
	// Verificar de quem � o turno
	ShowGameplay(p1, p2, jogo, turno);// **mostra interface 
	while(checkWin(atu, turno)) { // Verifica quem ganhou
		player_choose(atu);// Perguntar qual � a carta
		// Jogar carta caso seja possivel, se n pesque
		passTurn(&turno);// Passa o turno
		// Esconder os valores
		// Aperte para continuar
		// Mostre o proximo jogador
		ShowGameplay(p1, p2, jogo, turno);
	}// At� alguem ganhar ai finaliza a rodada
}

void tecla_continuar() {
	printf("\nPression qualquer tecla para continuar...\n");
	getch();
	system("cls");
}
