//########################## DOMINÓ #####################################\\
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Domino_lib.h"

int main() {
	// Declarar as variáveis
	tp_deck baralho;
	tp_hand *p1;
	tp_hand *p2;
	tp_hand *atu;
	tp_jogada *jogo;
	ret_resp turno;
	
	p1 = inicializa_listad();
	p2 = inicializa_listad();
	jogo = inicializa_listade();
	
	shuffle_cards(&baralho); // Embaralha o montinho 
	AllotCards(&baralho, &p1, &p2); // Distribui as peças
	firstPlay(p1, p2, &atu, &turno); // Verificar se a peça 1|1 existir, caso não encontrar pula +1 
	// Verificar de quem é o turno
	  //ShowGameplay(p1, p2, jogo, turno);// **mostra interface
	insere_lista_no_inicio(jogo, 4, 2);
	insere_lista_no_inicio(jogo, 3, 2);
	insere_lista_no_inicio(jogo, 3, 3);
	imprime_listad(jogo, 1);
	listad_imprime(&p1);
	player_choose(p1, &baralho, jogo);// Perguntar o que o jogador deseja fazer
	printf("P1:\n");
	listad_imprime(&p1);
	printf("JOGO:\n");
	imprime_listad(jogo, 1);
	while(checkWin(p1, p2, jogo, &baralho)) { // Verifica quem ganhou
		
		// Jogar carta caso seja possivel, se n pesque
		  //passTurn(&turno);// Passa o turno
		// Esconder os valores
		// Aperte para continuar
		// Mostre o proximo jogador
		  //ShowGameplay(p1, p2, jogo, turno);
	}// Até alguem ganhar ai finaliza a rodada
	
	
	return 0;
	
}

//Game
void game_logic() {
}

void tecla_continuar() {
	printf("\nPression qualquer tecla para continuar...\n");
	getch();
	system("cls");
}
