#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "domino_libs.h"


int main() {
	tp_Piece *p1 = init_piece();
	tp_Piece *p2 = init_piece();
	tp_Piece *p_atu, *p_aux;
	
	tp_stack heap;
	
	tp_listade *game = inicializa_listade();
	
	int turno = 0;
	int chs, chs2, chs3, feito = 0;
	int l, r, vl, vr;
	
	introduction();
	
	Game_init(&heap, &p1, &p2);
	firstPlay(&p1, &p2, &game, &p_atu, &turno);
	
	while(Checkwin(p1, p2, game, &heap) == 0) {
		feito = 0;
		printf("\n\n\n\n\n\n\n\n\n");
		printf("Jogador %d:\n", turno);
		printf("Mesa:\n");
		imprime_listad(game, 1);
		printf("Peças do jogador:\n");
		player_imprime(p_atu);
		while(feito == 0) {
			printf("O que deseja fazer?\n1 - Jogar peça\n2 - Cava\n");
			scanf("%d", &chs);
			if(chs == 1) {
				// Jogar peça
				printf("Qual peça desejas jogar na mesa?\n");
				scanf("%d", &chs2);
				p_aux = position_piece(p_atu, chs2);
				if(p_aux == NULL) {
					printf("Ops! Não foi encontrado!\n"); continue;
				} else {
					printf("Queres jogar no inicio (1) ou no fim (2)?\n");
					scanf("%d", &chs3);
					vl = p_aux->left; vr = p_aux->right;
					if(chs3 == 1) {
						//Inicio
						if(game->ini->v_L == vl) {
							insere_lista_no_inicio(game, vr, vl);
						} else if(game->ini->v_L == vr) {
							insere_lista_no_inicio(game, vl, vr);	
						} else {
							printf("Não foi possível jogar a peça!\n");
							continue;
						}
					} else {
						//Fim
						if(game->fim->v_R == vl) {
							insere_lista_no_fim(game, vl, vr);
						} else if(game->fim->v_R == vr) {
							insere_lista_no_fim(game, vr, vl);	
						} else {
							printf("Não foi possível jogar a peça!\n");
							continue;
						}
					}
					if(turno == 1) {
						remove_by_value_piece(&p1, vl, vr);
					} else {
						remove_by_value_piece(&p2, vl, vr);
					}
					
					feito = 1;
				}
			} else if(chs == 2) {
				// Cava
				if(stack_empty(&heap)) {
					printf("Ops! Está vazio!\n");
					continue;	
				}
				pop(&heap, &l, &r);
				listad_insere_peca(&p_atu, l, r);
				printf("Peças do jogador:\n");
				player_imprime(p_atu);
				feito = 1;
			}
		}
		passTurn(&turno, p1, p2, &p_atu);
	}
	int WhoWins = Checkwin(p1, p2, game, &heap);
	switch(WhoWins) {
		case 1:
			printf("Player 1 ganhou!\n");
			break;
		case 2:
			printf("Player 2 ganhou!\n");
			break;
		case 3:
			printf("Houve empate!\n");
			break;
		case 0:
			printf("What como saiu do loop?\n");
			break;
	}
	
	return 0;
}
