/*  **************************************************************************  */
/*  	Nome: Victor Wichmann Raposo                                            */
/*  	Número USP: 9298020            						*/
/*  	Exercício-programa 1							*/
/*  **************************************************************************  */

#include<stdio.h>

int main () {
	
	int n, m, p, U, C, aux, end=0;
	/* n = número de peças totais
	   m = número máximo de peças
	   p = peças que estão no tabuleiro no momento
	   U = peças que o usuário irá retirar
	   C = peças que o computador irá retirar */
	printf("Imprima quantas peças terá o jogo: \n");
	scanf("%d", &n);
	printf("Imprima o máximo de peças"
		" que pode ser tirada em uma rodada \n");
	scanf("%d", &m);
	p=n;
	C = m; /*C deve ser igual a m para entrar no for adiante*/
		
	/* Verficação se o usuário começa */
	if (n%(m+1)==0) {
		printf("----------------------- \n");
		printf("É a sua vez: ");
		scanf("%d", &U);
		printf("----------------------- \n");
		p = p - U;	
	}
	while (p > 0) {

	/* Jogo do computador */
		printf("----------------------- \n");
		printf("É a vez do computador \n");
		printf("----------------------- \n");
		/* Quantas peças ele tirará */
		for (aux=1;aux<m&&C!=(aux-1);aux++) {
			if ((p-aux)%(m+1)==0)
				C = aux;
			else 
				C = m;
		}
		p = p - C;
		/* Indicar se o computador ganhou */
		if (p == 0) 
			end=1;

		printf("O computador tirou %d peças \n", C);
		printf("Sobraram %d peças \n", p);

		/* Para o "for" funcionar novamente */
		aux=1;
		C=m;

	/* Jogo do usuário */
		if (p != 0) {
			printf("----------------------- \n");
			printf("É a sua vez: ");
			scanf("%d", &U);
			printf("----------------------- \n");
			
			p = p - U;
			if (p<0)
				p=0;
			printf("Você tirou %d peças \n", U);
			printf("Sobraram %d peças \n", p);			
		}
	}

	/*Fim do Jogo */
	if (end == 1) 
		printf("O computador venceu!\n");	
	else 
		printf("Você venceu!\n");			
	
	return 0;
}	
