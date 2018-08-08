
ret_resp checkWin(tp_deck *p_hand, int p_turn){ // JAFE

	
	if( (listade_vazia (*p_hand)) && (stack_empyt(tp_deck)) ){ 	// Ver se o jogador ainda tem cartas 
		return 1;
	}else{
		return 0; // Dizendo que ainda tem carta 	
	}
	
ret_resp play_card(tp_hand *p_hand){
	
	tp_item x = r_L; 	
	tp_item y = r_R;
	
	if (listade_vazia (*p_hand){ // ver se o jogador tem carta 
		return 0;
	}
	
}
	
	
