#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct infracaoVelocidade{
	char placa[8];
	char local[140];
	int velocidadeMaxima;
	int velocidadeVeiculo;
	char data[3];
}infracao;

void cadastrarInfracao(infracao *multa, char *indice){
	char cadastrarNovamente;
	do{
		system("cls");
		printf("Cadastrar infracao:\n\n");
		
		printf("Placa do veiculo:");
		scanf("%s", &multa[*indice].placa);
		
		printf("Local de ocorrencia:");
		scanf("%s", &multa[*indice].local);
		
		printf("Velocidade maxima da via:");
		scanf("%d", &multa[*indice].velocidadeMaxima);
		
		printf("Velocidade do veiculo:");
		scanf("%d", &multa[*indice].velocidadeVeiculo);
		
		printf("Data de ocorrencia:");
		scanf("%s", &multa[*indice].data);
		
		printf("Infracao cadastrada com sucesso. Deseja cadastrar novamente? (S/N)");
		
		while (!kbhit());
		cadastrarNovamente = toupper(getch());
	} while (cadastrarNovamente == 'S');
}

void pesquisarInfracaoPlaca(infracao *multa, char indice){
	char i, pesquisarNovamente, placaPesquisar[8], indicesEncontrados[10], numeroPlacasEncontradas = 0;

	do{
		system("cls");
		printf("Pesquisar pela placa do veiculo\n\nPlaca do veiculo:");
		scanf("%s", &placaPesquisar);

		for (i = 0; i <= indice; i++){
			if (!strcmp(multa[i].placa, placaPesquisar)){
				indicesEncontrados[numeroPlacasEncontradas] = i;
				numeroPlacasEncontradas++;
			}
		}
		if (numeroPlacasEncontradas)
			printf("\n%d infracoes encontradas para o veiculo.\n\n", numeroPlacasEncontradas);
		else
			printf("Veiculo sem infracoes por excesso de velocidade.\n\n");

		printf("Deseja pesquisar novamente? (S/N)");
		while (!kbhit());
		pesquisarNovamente = toupper(getch());
	} while (pesquisarNovamente == 'S');
}



void telaPrincipal(void){
	system("cls");
	printf("C - Cadastrar infracao\nO - Pesquisar pelo codigo da infracao\nP - Pesquisar pela placa do veiculo\nS - Finalizar a execucao.");
}

void main(void){

	char acao, indice = 0;
	infracao multa[10];

	telaPrincipal();

	do{
		while (!kbhit());
		acao = toupper(getch());

		switch (acao){
			case 'C':
				cadastrarInfracao(multa, &indice);
				telaPrincipal();
				break;
			case 'P':
				pesquisarInfracaoPlaca(multa, indice);
				telaPrincipal();
				break;
			default :
				break;
		}
	} while (acao != 'S');
}
