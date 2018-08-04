//########################## DOMINÓ #####################################
#include <stdio.h>
#include <stdlib.h>
#include "Domino_lib.h"


int main() {
	tp_deck baralho;
	//shuffle_cards(&baralho);
	//print_stack(baralho);
	tp_jogada *jogo;
	jogo = inicializa_filad();
	listad_insere_peca(&jogo, 2, 4);
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
