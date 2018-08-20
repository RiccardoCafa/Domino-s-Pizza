#ifndef INTERFACE_H
#define INTERFACE_H

//Interface

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
	printf("1- Jogar\n2- Sobre Nós\n3- Sair\n\nOpção: ");
	scanf("%d", &opcao_menu);
	
	switch (opcao_menu){
		case 1:
			break;
		break;
		case 2:
			system("cls");
			printf("   Jogo de Dominó feito pela equipe:\n\t\tGabriel Melo;\n\t\tJander Silva; \n\t\tJafe Ferreira; \n\t\tMiguel Falcão e Riccardo Cafagna.\n\t\t\n");
			printf("   Graduandos da Engenharia de Computação do SENAI CIMATEC\n   da disciplina de estrutura de dados I orientada pelo professor:\n\t\tMárcio Soussa.\n\n");
			printf("1- Voltar ao menu\n2- Sair\n\nOpção: ");
			scanf("%d", &sobre);
			switch (sobre){
				case 1:
					system("cls");
					return introduction();
					break;
				case 2:
					system("cls");
					printf("Obrigado e volte sempre");
					exit(0);
					break;
				default:
					return introduction();
			}
			break;
		case 3:
			system("cls");
			printf("Obrigado e volte sempre.");
			exit(0);
			break;
		default:
			return introduction();
		}
		return 0;
}
#endif
