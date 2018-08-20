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
	
	printf("Para Maximizar ou Minimizar o Prompt, utilize a combinação Alt+Enter.\n\n");
		
	printf("Escolha uma das opções: \n");
	printf("1- Jogar\n2- Sobre Nós\n3- Sair\n\n Opção: ");
	scanf("%d", &opcao_menu);
	
	switch (opcao_menu){
		case 1:
			break;
		break;
		case 2:
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("   Jogo de Dominó feito pela equipe:\n");
			
			printf("\t\t  ___                             ___   \n");
			printf("\t\t |o o|        Domino's Pizza     |o o|  \n");
			printf("\t\t |o_o| ___ ___  ___ ___  ___ ___ |o_o|  \n");
			printf("\t\t |o  ||o  |o  ||o  |ooo||ooo|o o||o o|  \n");
			printf("\t\t |__o||__o|__o||__o|ooo||ooo|o_o||o_o|  \n");
			printf("\t\t Jafe   Jander   Gabriel  Miguel Riccardo\n");
			printf("\t\tFerreira Silva 	  Melo    Falcão  Cafagna \n\n");
			
			printf("   Graduandos da Engenharia de Computação do SENAI CIMATEC\n   da disciplina de estrutura de dados I orientada pelo professor:\n");
			
			printf("\t\t\t   ________  \n");
			printf("\t\t\t  /Márcio /| \n");
			printf("\t\t\t / Soussa/ | \n");
			printf("\t\t\t | o   o | | \n");
			printf("\t\t\t | o   o | | \n");
			printf("\t\t\t |-------| | \n");
			printf("\t\t\t | o   o | | \n");
			printf("\t\t\t | o   o | / \n");
			printf("\t\t\t |_______|/ \n\n");
			
			printf("1- Voltar ao menu\n2- Sair\n\nOpção: ");
			scanf("%d", &sobre);
			switch (sobre){
				case 1:
					system("cls");
					return introduction();
					break;
				case 2:
					system("cls");
					
					printf(" _____  _                                 _                      _   _         _    _              ___                                         _ \n");
					printf("(  _  )( )           _                   ( )                    ( ) ( )       (_ ) ( )_           (  _`\\                                      ( )\n");
					printf("| ( ) || |_    _ __ (_)   __     _ _    _| |   _         __     | | | |   _    | | | ,_)   __     | (_(_)   __    ___ ___   _ _    _ __   __  | |\n");
					printf("| | | || '_`\\ ( '__)| | /'_ `\\ /'_` ) /'_` | /'_`\\     /'__`\\   | | | | /'_`\\  | | | |   /'__`\\   `\\__ \\  /'__`\\/' _ ` _ `\\( '_`\\ ( '__)/'__`\\| |\n");
					printf("| (_) || |_) )| |   | |( (_) |( (_| |( (_| |( (_) )   (  ___/   | \\_/ |( (_) ) | | | |_ (  ___/   ( )_) |(  ___/| ( ) ( ) || (_) )| |  (  ___/| |\n");
					printf("(_____)(_,__/'(_)   (_)`\\__  |`\\__,_)`\\__,_)`\\___/'   `\\____)   `\\___/'`\\___/'(___)`\\__)`\\____)   `\\____)`\\____)(_) (_) (_)| ,__/'(_)  `\\____)(_)\n");
					printf("		       ( )_) |                                                                                             | |                (_)\n");
					printf("		        \\___/'                                                                                             (_)                   \n");
					
					printf("\nObrigado e volte sempre.");
					
					exit(0);
					break;
				default:
					return introduction();
			}
			break;
		case 3:
			system("cls");
			
	printf(" _____  _                                 _                      _   _         _    _              ___                                         _ \n");
	printf("(  _  )( )           _                   ( )                    ( ) ( )       (_ ) ( )_           (  _`\\                                      ( )\n");
	printf("| ( ) || |_    _ __ (_)   __     _ _    _| |   _         __     | | | |   _    | | | ,_)   __     | (_(_)   __    ___ ___   _ _    _ __   __  | |\n");
	printf("| | | || '_`\\ ( '__)| | /'_ `\\ /'_` ) /'_` | /'_`\\     /'__`\\   | | | | /'_`\\  | | | |   /'__`\\   `\\__ \\  /'__`\\/' _ ` _ `\\( '_`\\ ( '__)/'__`\\| |\n");
	printf("| (_) || |_) )| |   | |( (_) |( (_| |( (_| |( (_) )   (  ___/   | \\_/ |( (_) ) | | | |_ (  ___/   ( )_) |(  ___/| ( ) ( ) || (_) )| |  (  ___/| |\n");
	printf("(_____)(_,__/'(_)   (_)`\\__  |`\\__,_)`\\__,_)`\\___/'   `\\____)   `\\___/'`\\___/'(___)`\\__)`\\____)   `\\____)`\\____)(_) (_) (_)| ,__/'(_)  `\\____)(_)\n");
	printf("		       ( )_) |                                                                                             | |                (_)\n");
	printf("		        \\___/'                                                                                             (_)                   \n");


			printf("\nObrigado e volte sempre.");
			exit(0);
			break;
		default:
			return introduction();
		}
		return 0;
}
#endif
