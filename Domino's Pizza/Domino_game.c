//########################## DOMINÓ #####################################
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
	printf("Pression qualquer tecla para continuar...\n");
	getch();
	system("cls");
	listad_insere_peca(&p1, 2, 5);
	listad_insere_peca(&p1, 4, 7);
	listad_insere_peca(&p1, 2, 1);
	listad_insere_peca(&p1, 6, 3);
	insere_lista_no_fim(jogo, 1, 2);
	insere_lista_no_fim(jogo, 2, 3);
	insere_lista_no_inicio(jogo, 4, 7);
	printf("1");
	aux = AIChoose_card(p1, jogo);
	printf("2");
	if(aux == NULL) printf("-1");
	else printf("-2");
	//istad_insere_peca
	/*tp_hand *m_player;
	tp_hand *h_to_seek;
	
	printf("Inicializando fila...\n");
	m_player = inicializa_filad();
	printf("inicializado.\n");
	
	printf("inserindo 0-0...\n");
	filad_insere_peca(&m_player, 0, 0);
	printf("Peca 0-0 inserida.\n");
	
	printf("inserindo 1-2...\n");
	filad_insere_peca(&m_player, 1, 2);
	printf("Peca 1-2 inserida.\n");
	//printf("Valor L/R: %d/%d", m_player->next->p_L, m_player->next->p_R);
	printf("Procurando por 0-0.\n");
	h_to_seek = filad_search_for(&m_player, 0, 0);
	printf("Busca finalizada\n");
	
	printf("Removendo peca encontrada\n");
	filad_remove_peca(&m_player, h_to_seek);
	printf("Peca removida\n");
	
	printf("Printando mao do jogador\n");
	filad_imprime(&m_player);
	
	printf("inserindo 2-2...\n");
	filad_insere_peca(&m_player, 2, 2);
	printf("Peca 2-2 inserida.\n");
	
	printf("inserindo 2-1...\n");
	filad_insere_peca(&m_player, 2, 1);
	printf("Peca 2-1 inserida.\n");
	
	printf("Printando mao do jogador\n");
	filad_imprime(&m_player);
	
	printf("Procurando por 0-0.\n");
	h_to_seek = filad_search_for(&m_player, 0, 0);
	printf("Busca finalizada\n");
	
	printf("Removendo peca encontrada\n");
	filad_remove_peca(&m_player, h_to_seek);
	printf("Peca removida\n");
	
	printf("Printando mao do jogador\n");
	filad_imprime(&m_player);*/
	return 0;
}
