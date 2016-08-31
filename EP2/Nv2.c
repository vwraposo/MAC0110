#include <stdio.h>
#define MAX 25

int main () {
	int usuAnt=0, usuario, computador; /* variaveis que irao receber alguma jogada do usuario e do computador respectivamente */
	int v[MAX]; /* Vetor que armazenara k jogadas do usuario */
	int P, PR, PP, PS; /* Variaveis de probabilidade
	P=quantidade de vezes que apareceu a jogada anterior do usuario
	PR=probabilidade de sair pedra
	PP=probabilidade de sair papel
	PS=probabilidade de sair tesoura */
	float MP;/*
	MP=maior probabilidade */
	int i, j, h=100; /* auxiliares para usar no vetor*/
	int vU=0, vC=0, count=0; /* Contadores de vitoria (vU e vC) e contador de rodadas*/
	
	/* Zerando todos valores do vetor */
	for(j=0;j<MAX;j++) {
		v[j]=0;
	}
	printf("O jogo vai começar\n");
	printf("imprima sua jogada: 1-Pedra 2-Tesoura 3-Papel \n");
	
	/*Primeira jogada do usuario */
	i=0;
	scanf("%d", &usuario);
	while (usuario>0) {		
		count++;
/*Jogada do Computador, com base nas jogadas anteriores do usuario */

	/* Análise probabilistica das jogadas ateriores */
		P=PR=PP=PS=0;
		for (j=0;j<MAX-1;j++) {				
			if (v[j]==usuAnt) {
				P++;
				if (v[j+1]==1)
					PR++;
				else {
					if (v[j+1]==2) 
						PS++;
						
 					else {
 						if(v[j+1]==3)
 							PP++;
					}
				}
			}			
		}
		v[i]=usuario;
		usuAnt=usuario;		
	/* Escolha da jogada do computador */
		if (PR==0 && PS==0 && PP==0) {
			/* RANDOM */ computador=2;
			printf("O computador jogou Tesoura\n");
		}
		else {
			if (PR>=PP && PR>=PS) {
				computador=3;
				MP=(float)PR/P;
				printf("O computador jogou Papel\n");
				/*printf("Probabilidade do usuário jogar pedra: %.4f\n", MP);*/
			}	
			else {
				if (PS>=PP && PS>=PR) {
					computador=1;
					MP=(float)PS/P;
					printf("O computador jogou Pedra\n");
					/*printf("Probabilidade do usuário jogar tesoura: %.4f\n", MP);*/
				}	
				else {	
					if (PP>=PS && PP>=PR) {
						computador=2;
						MP=(float)PP/P;
						printf("O computador jogou Tesoura\n");
						/*printf("Probabilidade do usuário jogar papel: %.4f\n", MP);*/
					}
				}
			}	
		}
		/* Ver quem ganhou */
		if (computador==v[i]) 
			printf("Foi um empate\n");
		else {
			if ((computador==1 && v[i]==2) || (computador==2 && v[i]==3)
			 || (computador==3 && v[i]==1)) {
			 	printf("O Computador ganhou!\n");
			 	vC++;
			}
			else {
				printf("Você ganhou!\n");
				vU++;
			}			 	
		}
		
		/* Posiçao atual no vetor */
		h++;
		i=h%MAX;
		
		/* Proxima jogada do usuario */
		printf("Proxima rodada!\n");
		scanf("%d", &usuario);
	
	}
	printf("Estatisticas de jogo:\n");
	printf("Vitórias do Computador: %d\n", vC);
	printf("Vitórias do Usuário: %d\n", vU);
	printf("Total de rodadas: %d\n", count);	
		
	return 0;
}
