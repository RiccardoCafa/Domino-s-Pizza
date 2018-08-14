//########################## DOMINÓ #####################################\\
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Domino_lib.h"

int main() {
	// Declarar as variáveis
	tp_deck montinho;
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



void tecla_continuar() {
	printf("\nPression qualquer tecla para continuar...\n");
	getch();
	system("cls");
}
