/******************************************************************************/
/*  	Nome: Victor Wichmann Raposo                                          */
/*  	Número USP: 9298020            					      */
/*  	Exercício-programa 2						      */
/******************************************************************************/
#include <stdio.h>
#define MAX 25
/* Escolhi o k valendo 25, devido a uma série de testes feitos com o varios
inputs de números. Após esses testes conclui que 25 era o número que resulta
em um melhor desempenho do computador em jogos onde o usuário não está tentando
prever as jogadas do computador. */

int main () {
	int nivel;
	int usuAnt=0, usuario, computador=0; 
	/* variaveis que irao receber alguma jogada do usuario e do computador 
	respectivamente */
	int vU=0, vC=0, count=0;
	/* Contadores de vitoria (vU e vC) e contador de rodadas*/
				/*Nv1*/
	unsigned long x0=42, x1; 
	/*Variáveis para gerar numeros aleatorios através do metodo das 
	congruencias lineares */
	float rand; 
	/*Numero entre 0 e 1 que representará a jogada aleatoria do computador*/
				/*Nv2*/
	int v[MAX]; 
	/* Vetor que armazenara k jogadas do usuario */
	int P, PR, PP, PS; 
	/* Variaveis de probabilidade
	P=quantidade de vezes que apareceu a jogada anterior do usuario
	PR=probabilidade de sair pedra
	PP=probabilidade de sair papel
	PS=probabilidade de sair tesoura */
	int i, j, h=100; 
	/* auxiliares para usar no vetor*/
				/*Nv3*/
	int k=MAX-1;
	/* k sera dinamico, visando a melhor adaptaçã do computador para as 
	mudanças do padrão do usuário */
	int venceu;
	/*venceu sera uma variavel para derminar mais facilmente quem venceu a 
	rodada anterior:
		venceu=0 - Usiario venceu
		venceu=1 - Computador venceu  	
		venceu=2 - Empate    					     */
	
			/*Escolhendo o Nivel*/
	printf("Escolha um dos seguintes niveis:\n");
	printf("\t Fácil   - 1\n");
	printf("\t Médio   - 2\n");
	printf("\t Difícil - 3\n");	
	
	scanf("%d", &nivel);
	if (nivel==1) {
		printf("O jogo irá começar\n");
		printf("Imprima sua jogada\n");
		printf("\t1 - Pedra\n");
		printf("\t2 - Tesoura\n");
		printf("\t3 - Papel\n");
		
		/* Primeira jogada do usuario */
		scanf("%d", &usuario);	
		while (usuario!=0) {
			count++;
			/* Jogada do Computador*/
			
			/*Congruencia Linear*/	
			x1=(22695477*x0+1)%4294967296;
			x0=x1;
			rand=(float)x1/4294967295;
			/*******************/
			if (0<=rand && rand<0.3333) {
				computador=1;
				printf("O computador jogou Pedra\n");
			}				
			else if (0.3333<=rand && rand<0.6666) {
				computador=2;
				printf("O computador jogou Tesoura\n");
			}
			else if (0.6666<=rand && rand<1) {
				computador=3;
				printf("O computador jogou Papel\n");
			}
			/* Ver quem ganhou */
			if (computador== usuario) 
				printf("\tFoi um empate!\n");
			else if ((computador==1 && usuario==2) || 
				 (computador==2 && usuario==3) ||
				 (computador==3 && usuario==1)) {
			 	printf("\tO Computador ganhou!\n");
			 	vC++;
			}		
			else {
				printf("\tVocê ganhou!\n");
				vU++;
			}
			printf("----------------------- \n");
			printf("Proxima rodada\n"); 
			/* Jogada do Usuario */
			scanf("%d", &usuario);
			
		} /*while*/
		
		/*Estatisticas de Jogo*/			
		printf("\tEstatisticas de jogo:\n");
		printf("Vitórias do Computador: %d\n", vC);
		printf("Vitórias do Usuário: %d\n", vU);
		printf("Total de rodadas: %d\n", count);
	}/*Nv1*/
	else if (nivel==2) {
		printf("O jogo irá começar\n");
		printf("Imprima sua jogada\n");
		printf("\t1 - Pedra\n");
		printf("\t2 - Tesoura\n");
		printf("\t3 - Papel\n");
		
		/* Zerando todos valores do vetor */
		for(j=0;j<MAX;j++) {
		v[j]=0;
		}
		printf("O jogo vai começar\n");
		printf("imprima sua jogada: 1-Pedra 2-Tesoura 3-Papel \n");
	
		/*Primeira jogada do usuario */
		i=0;
		scanf("%d", &usuario);
		while (usuario!=0) {		
			count++;
			/*Jogada do Computador*/

			/* Análise probabilistica das jogadas ateriores */
			P=PR=PP=PS=0;
			for (j=0;j<MAX-1;j++) {				
				if (v[j]==usuAnt) {
					P++;
					if (v[j+1]==1)
						PR++;
					else if (v[j+1]==2) 
						PS++;				
 					else if(v[j+1]==3)
 						PP++;
				
				}
			}			
				
			/* Escolha da jogada do computador */
			if ((PR==0 && PS==0 && PP==0) ||
			     (PR==PS && PR==PP)) {
				/*Congruencia Linear*/	
				x1=(22695477*x0+1)%4294967296;
				x0=x1;
				rand=(float)x1/4294967295;
				/*******************/
				if (0<=rand && rand<0.3333) {
					computador=1;
					printf("O computador jogou Pedra\n");
				}				
				else if (0.3333<=rand && rand<0.6666) {
					computador=2;
					printf("O computador jogou Tesoura\n");
				}
				else if (0.6666<=rand && rand<1) {
					computador=3;
					printf("O computador jogou Papel\n");
				}
			}
			else if (PR>=PP && PR>=PS) {
				computador=3;
				printf("O computador jogou Papel\n");
			}	
			else if (PS>=PP && PS>=PR) {
				computador=1;
				printf("O computador jogou Pedra\n");
			}	
			else if (PP>=PS && PP>=PR) {
				computador=2;						
				printf("O computador jogou Tesoura\n");
		
			}
			
			/* Salvando a jogada do usuário */
			v[i]=usuario;
			usuAnt=usuario;
					
			/* Ver quem ganhou */
			if (computador==v[i]) 
				printf("Foi um empate\n");
			else if ((computador==1 && v[i]==2) ||
				 (computador==2 && v[i]==3) ||
				 (computador==3 && v[i]==1)) {
			 	printf("O Computador ganhou!\n");
			 	vC++;
			}
			else {
				printf("Você ganhou!\n");
				vU++;
			}			 	
				
			/* Posiçao atual no vetor (mesmo que ultrapasse o MAX)*/
			h++;
			i=h%MAX;
		
			/* Proxima jogada do usuario */
			printf("----------------------- \n");
			printf("Proxima rodada!\n");
			scanf("%d", &usuario);
		}
	
		printf("Estatisticas de jogo:\n");
		printf("Vitórias do Computador: %d\n", vC);	
		printf("Vitórias do Usuário: %d\n", vU);
		printf("Total de rodadas: %d\n", count);
		
		
	} /*Nv2*/
	else {
		printf("O jogo irá começar\n");
		printf("Imprima sua jogada\n");
		printf("\t1 - Pedra\n");
		printf("\t2 - Tesoura\n");
		printf("\t3 - Papel\n");
	
	/* Como o nivel médio estava sendo facilmente previsiviel, decidi fazer
	o nivel dificil com a mesma base do nivel medio (que ja e muito
	boa) so que tentando retirar ao maximo a previsibilidade das jogadas, 
	para isso usei um k dinamico 
		Além de diminir a previsibilidade usei, também, as informações
	obtidas no estudo da universidade chinesa encontrado no site:
	http://motherboard.vice.com/read/game-theory-rock-paper-scissors .
		No entanto o computador nao será tão eficiente em um caso de 
	input aleátorio, já que supõe que o usuário esta pensando em suas 
	jogadas. */
	
	/* Zerando todos valores do vetor */	
		for(j=0;j<MAX;j++) {
		v[j]=0;
		}
		printf("O jogo vai começar\n");
		printf("imprima sua jogada: 1-Pedra 2-Tesoura 3-Papel \n");
	
		/*Primeira jogada do usuario */
		venceu=2; 
		/* Por ser a primeira rodada */ 
		i=0;
		scanf("%d", &usuario);
		
		while (usuario!=0) {		
			count++;
			/*Jogada do Computador*/

			/* Análise probabilistica das jogadas ateriores */
			P=PR=PP=PS=0;
			if (venceu==1) {
			/* Pelos estudos, a melhor tática após uma vitoria é
			jogar o que o adversário jogou na rodada passada, 
			portanto estou aumentando a probabilidade do computador
			jogar o que o usuario jogou */
				if (usuAnt==1) 
					PS=PS+5;
				else if (usuAnt==2)
					 PP=PP+5;
				else if (usuAnt==3)
					PR=PR+5;
			}
			else if (venceu==0) {
			/* Segundo os estudos ao vencer o jogador tende a 
			jogar o mesmo que jogou para vencer a anterior, portanto
			estou levando isto em conta para determinar as 
			probabilidades de jogada do usuario */
				if (usuAnt==1)
					PR=PR+5;
				if (usuAnt==2)
					PS=PS+5;
				if (usuAnt==3)
					PP=PP+5;
			
			}
				
			for (j=0;j<k;j++) {				
				if (v[j]==usuAnt) {
					P++;
					if (v[j+1]==1)
						PR++;
					else if (v[j+1]==2) 
						PS++;				
 					else if(v[j+1]==3)
 						PP++;
				
				}
			}		
				
			/* Escolha da jogada do computador */
			if ((PR==0 && PS==0 && PP==0) ||
			     (PR==PS && PR==PP)) {
				/*Congruencia Linear*/	
				x1=(22695477*x0+1)%4294967296;
				x0=x1;
				rand=(float)x1/4294967295;
				/*******************/
				if (0<=rand && rand<0.3333) {
					computador=1;
					printf("O computador jogou Pedra\n");
				}				
				else if (0.3333<=rand && rand<0.6666) {
					computador=2;
					printf("O computador jogou Tesoura\n");
				}
				else if (0.6666<=rand && rand<1) {
					computador=3;
					printf("O computador jogou Papel\n");
				}
			}
			else if (PR>=PP && PR>=PS) {
				computador=3;
				printf("O computador jogou Papel\n");
			}	
			else if (PS>=PP && PS>=PR) {
				computador=1;
				printf("O computador jogou Pedra\n");
			}	
			else if (PP>=PS && PP>=PR) {
				computador=2;						
				printf("O computador jogou Tesoura\n");
		
			}
			/* Salvando a jogada do usuário */
			v[i]=usuario;
			usuAnt=usuario;
		
			/* Ver quem ganhou */
			if (computador==v[i])  {
				printf("Foi um empate\n");
				venceu=2;
			}
			else if ((computador==1 && v[i]==2) ||
				 (computador==2 && v[i]==3) ||
				 (computador==3 && v[i]==1)) {
			 	printf("O Computador ganhou!\n");
			 	vC++;
			 	venceu=1;
			 	/* Como o computador venceu, ele provavelmente 
			 	esta calculando certo o padrao do usuário, então
			 	pode levar enconta masi roodadas */
			 	if (k<MAX-1) k++;
			}
			else {
				printf("Você ganhou!\n");
				vU++;
				venceu=0;
				/* Como o computador perdeu, o jogador deve 
				estar mudando do seu padrão, portanto o k deve 
				diminuir para o computador se adaptar mais 
				rapidamente ao novo padrão. */
				if (k>5) k--;
			}			 	
				
			/* Posiçao atual no vetor (mesmo que ultrapasse o MAX)*/
			h++;
			i=h%MAX;
		
			/* Proxima jogada do usuario */
			printf("----------------------- \n");
			printf("Proxima rodada!\n");
			scanf("%d", &usuario);
		}
	
		printf("Estatisticas de jogo:\n");
		printf("Vitórias do Computador: %d\n", vC);	
		printf("Vitórias do Usuário: %d\n", vU);
		printf("Total de rodadas: %d\n", count);
	} /*Nv3*/
	
	return 0;
}
