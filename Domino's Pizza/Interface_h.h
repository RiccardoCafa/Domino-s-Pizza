#ifndef INTERFACE_LIB_H
#define INTERFACE_LIB_H
//Interface

void passTurn(tp_hand *p1, tp_hand *p2, tp_hand **aux, int *turno){
    if(*turno==1){  //verifica variavel turno pra ver quem estava jogando
        //*aux=p2;    //transfere o proximo jogador pra funcao de mostrar a mao 
        *turno=2;
    }else { 
		//*aux=p1;
        *turno=1;
	}
} // Gabriel

void chooseGameType(){
    int tipo_jogo;
    printf("Quantos jogadores(1 ou 2): ");
    scanf("%d", &tipo_jogo);
    switch(tipo_jogo){
        case 1 : //funcao contra IA
        break;
        case 2 : //funcao 1v1
        break;
        default: //volta em caso de um numero diferente
        system("cls");
        printf("* Tipo nao aceito, digite novamente *\n");
        return chooseGameType();
        break;
    } // Gabriel
}
//void introduction(); // OK IMPLEMENTAR
//
int introduction () {
	setlocale(LC_ALL, "portuguese");
	int opcao_menu, sobre;
	system("cls");
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
					return introduction();
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
			return introduction();
		}
		return 0;
}
#endif
