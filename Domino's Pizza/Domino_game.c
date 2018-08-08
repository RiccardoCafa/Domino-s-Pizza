//########################## DOMINÓ #####################################\\
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Domino_lib.h"


int main() {
	tp_deck baralho;
	tp_jogada *jogo;
	tp_hand *p1;
	tp_hand *p2;
	tp_hand *aux;
	
	p1 = inicializa_listad();
	p2 = inicializa_listad();
	jogo = inicializa_listade();
	
	shuffle_cards(&baralho);
	printf("Baralho:\n");
	print_stack(baralho);
	tecla_continuar();
	AllotCards(&baralho, &p1, &p2);
	printf("Mao jogador p1: \n");
	listad_imprime(&p1);
	tecla_continuar();
	printf("Mao jogador p2: \n");
	listad_imprime(&p2);
	tecla_continuar();
	insere_lista_no_fim(jogo, 1, 2);
	insere_lista_no_fim(jogo, 2, 3);
	insere_lista_no_inicio(jogo, 4, 7);
	aux = AIChoose_card(p1, jogo);
	if(aux == NULL) printf("-1");
	else printf("-2");
	return 0;
}

void tecla_continuar() {
	printf("\nPression qualquer tecla para continuar...\n");
	getch();
	system("cls");
}
