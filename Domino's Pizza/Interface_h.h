#ifndef INTERFACE_LIB_H
#define INTERFACE_LIB_H
//Interface
void passTurn(int *p_turn); // Gabriel
ret_resp chooseGameType(); // Gabriel
void introduction(); // OK IMPLEMENTAR
void ShowGameplay(tp_hand *p1, tp_hand *p2, tp_jogada *jogo, ret_resp turno);
//
introduction () {
	setlocale(LC_ALL, "portuguese");
	int opcao_menu, sobre;
	printf(" ___                                       _           ___                         \n");
	printf("(  _`\\                    _               ( )         (  _`\\  _                    \n");
	printf("| | ) |   _     ___ ___  (_)  ___     _   |/   ___    | |_) )(_) ____  ____    _ _ \n");
	printf("| | | ) /'_`\\ /' _ ` _ `\\| |/' _ `\\ /'_`\\    /',__)   | ,__/'| |(_  ,)(_  ,) /'_` )\n");
	printf("| |_) |( (_) )| ( ) ( ) || || ( ) |( (_) )   \\__, \\   | |    | | /'/_  /'/_ ( (_| |\n");
	printf("(____/'`\\___/'(_) (_) (_)(_)(_) (_)`\\___/'   (____/   (_)    (_)(____)(____)`\\__,_)\n\n");
	
	printf("Escolha uma das opções: \n");
	printf("1- Jogar\n2- Sobre Nós\n3- Sair\n");
		scanf("%d", &opcao_menu);
	
	switch (opcao_menu){
		case 1:
			//Inicializa o game;
		break;
		case 2:
			system("cls");
			printf("   Jogo de Dominó feito pela equipe:\n\t\tRiccardo Cafagna,\n\t\tMiguel Falcão, \n\t\tJander Silva, \n\t\tJafe Ferreira e \n\t\tGabriel Melo.\n");
			printf("   Graduandos da Engenharia de Computação do SENAI CIMATEC\n   da disciplina de estrutura de dados I orientada pelo professor:\n\t\tMárcio Soussa.\n\n");
			printf("1- Voltar ao menu\n2- Sair\n");
			scanf("%d", &sobre);
			switch (sobre){
				case 1:
					system("cls");
					return main();
					break;
				case 2:
					system("cls");
					printf("Obrigado e volte sempre");
					system("exit");
					return;
					break;
			}
			break;
		case 3:
			system("cls");
			printf("Obrigado e volte sempre.");
			system("exit");
			return;
			break;
		default:
			return main();
		}
		return 0;
}
#endif
