////########################## DOMINÓ #####################################
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Domino_lib.h"

void tecla_continuar() {
	printf("\nPression qualquer tecla para continuar...\n");
	char c = getch();
	fflush(stdin);
	system("cls");
}

int main() {
	// Introducao do jogo
	//introduction();
	// Declarar as variáveis
	tp_deck baralho;
	tp_hand *p1;
	tp_hand *p2;
	tp_hand *atu;
	tp_jogada *jogo;
	ret_resp turno;
	int WhoWins = 0;
	
	p1 = inicializa_listad();
	p2 = inicializa_listad();
	jogo = inicializa_listade();
	
	shuffle_cards(&baralho); // Embaralha o montinho 
	AllotCards(&baralho, &p1, &p2); // Distribui as peças
	firstPlay(p1, p2, jogo, &atu, &turno); // Verificar se a peça 1|1 existir, caso não encontrar pula +1 
	// Verificar de quem é o turno
	  //ShowGameplay(p1, p2, jogo, turno);// **mostra interface

	while(WhoWins == 0) { // Verifica quem ganhou
		if(turno == 1) {
			printf("Mesa:\n");
			imprime_listad(jogo, 1);
			printf("Mao do jogador %d\n", turno);
			listadin_imprime(p1);
			player_choose(p1, &baralho, jogo);// Perguntar o que o jogador deseja fazer
			// Jogar carta caso seja possivel, se n pesque
			printf("Mesa:\n");
			imprime_listad(jogo, 1); // Imprime a jogada antes de sair
			tecla_continuar();// Aperte para continuar
			//passTurn(p1, p2, &atu, &turno); // Passa o turno
		} else if(turno == 2) {
			printf("Mesa:\n");
			imprime_listad(jogo, 1);
			printf("Mao do jogador %d\n", turno);
			listadin_imprime(p2);
			player_choose(p2, &baralho, jogo);// Perguntar o que o jogador deseja fazer
			// Jogar carta caso seja possivel, se n pesque
			printf("Mesa:\n");
			imprime_listad(jogo, 1); // Imprime a jogada antes de sair
			tecla_continuar();// Aperte para continuar
			//passTurn(p1, p2, &atu, &turno); // Passa o turno
		}
		
		  //ShowGameplay(p1, p2, jogo, turno);
		WhoWins = checkWin(p1, p2, jogo, &baralho);
	}// Até alguem ganhar ai finaliza a rodada
	
	if(WhoWins == 1) {
		printf("Player 1 Ganhou!");
	} else {
		printf("Player 2 Ganhou!");
	}
	printf("Deseja começar outro jogo?\nS - Sim\nN - Nao\n");
	char c = getch();
	switch(c) {
		case 's':
		case 'S':
			return main();
			break;
		case 'n': case 'N':
			system("exit");
			break;
	}
	return 0;
}

