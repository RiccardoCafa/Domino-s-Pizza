#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "domino_libs.h"

int main() {
keybd_event (VK_MENU, 0x36, 0, 0); 
keybd_event (VK_RETURN, 0x1C, 0, 0); 
keybd_event (VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0); // Indica ao computador ativar a combinação de teclado Alt+Enter
keybd_event (VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);// para maximizar a tela ao abrir o executável

	tp_Piece *p1 = init_piece();//cria jogador um
	tp_Piece *p2 = init_piece();//cria jogador dois
	tp_Piece *p_atu, *p_aux;//cria as listas auxiliares
	
	tp_stack heap;
	
	tp_listade *game = inicializa_listade();//turno atual
	
	int turno = 0;
	int chs, chs2, chs3, feito = 0;
	int l, r, vl, vr;
	int WhoWins = 0;
	introduction();//introducao do jogo (interface)
	system("cls");//apaga tudo que esta anterior a ele no prompt
	
	Game_init(&heap, &p1, &p2);//funcao que embaralha e distribui as pecas para os jogadores
	firstPlay(&p1, &p2, &game, &p_atu, &turno);//verificar quem vai jogar
	
	while(WhoWins == 0) {//comeco da partida
		WhoWins = Checkwin(p1, p2, game, &heap);//verificar quem ganhou
		if(WhoWins == -1) passTurn(&turno, p1, p2, &p_atu);
		feito = 0;
		printf("\n\n\n\n\n\n\n\n\n");
		printf("* Vez do Jogador %d *\n", turno);
		printf("\n\nMesa:\n");
		imprime_listad(game, 1);
		printf("Peças do jogador:\n");
		player_imprime(p_atu);
		while(feito == 0) {//escolher a opcao de jogada
			printf("\nO que deseja fazer?\n1 - Jogar peça\n2 - Cava\n\n Opção: ");
			scanf("%d", &chs);
			if(chs == 1) {
				// Jogar peça
				printf("\nQual peça desejas jogar na mesa?\n Opção: ");
				scanf("%d", &chs2);
				p_aux = position_piece(p_atu, chs2);
				if(p_aux == NULL) {//caso a peca n seja compativel com os lados
					printf("Ops! Não foi encontrado!\n"); continue;
				} else {
					printf("\nQueres jogar no inicio (1) ou no fim (2)?\n Opção: ");
					scanf("%d", &chs3);
					vl = p_aux->left; vr = p_aux->right;
					if(chs3 == 1) {
						//caso jogue no Inicio
						if(game->ini->v_L == vl) {//para colocar na posicao correta
							insere_lista_no_inicio(game, vr, vl);
								system("cls");
						} else if(game->ini->v_L == vr) {//para colocar na posicao correta
							insere_lista_no_inicio(game, vl, vr);
								system("cls");	
						} else {//caso nao foi possivel
							printf("\n\nNão foi possível jogar a peça!\n");
							continue;
						}
					} else {
						//caso jogue no Fim
						if(game->fim->v_R == vl) {//para colocar na posicao correta
							insere_lista_no_fim(game, vl, vr);
								system("cls");
						} else if(game->fim->v_R == vr) {//para colocar na posicao correta
							insere_lista_no_fim(game, vr, vl);	
								system("cls");
						} else {//caso nao foi possivel
							printf("\n\nNão foi possível jogar a peça!\n");
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
				if(stack_empty(&heap)) {//caso o cave esta vazio
					printf("Ops! Está vazio!\n");
					continue;
				}
				pop(&heap, &l, &r);
				listad_insere_peca(&p_atu, l, r);
				printf("Peças do jogador:\n");
				player_imprime(p_atu);
				feito = 1;
					system("cls");
			}
		}
		passTurn(&turno, p1, p2, &p_atu);
	}
	
	switch(WhoWins) {//apartir do valor que a funcao retorna mostra a mensagem
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
