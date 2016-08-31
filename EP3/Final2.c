/******************************************************************************/
/*  	Nome: Victor Wichmann Raposo                                          */
/*  	Número USP: 9298020            					      */
/*  	Exercício-programa 3						      */
/******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#define MAX 100000

/* Funçao que ira calcular o mdc entre dois números pelo algoritmo de Euclides*/
int mdc (int k, int n) {
	int r;
	while (n>0) {
		r=k%n;
		k=n;
		n=r;		
	}
	return k;
}

/* Funçao que verifica se uma palavra, contida no vetor palavra e de tamanho *j, está no dicionário */
 int dicionario ( char palavra[MAX], int *j) {
	char dic[MAX];
	/* vetor dic ira conter palavras do dicionário */
	int achei=0;
	/* achei é uma variavel que receberá o valor 1 quando a palavra buscada 	for encontrada */
	int end=0;
	/* variavel que ira receber o valor 1 quando as palavras comparadas nao 
	forem iguais */
	int i=0;
	/* variavel de auxilio para os vetores */
	int count;
	FILE * entrada;
	int leitura;
	/* Variaveis para ler o arquivo do Dicionario */
	entrada=fopen("Dicionario.txt", "r");
	leitura=fscanf(entrada, "%c", &dic[i]);
	while (achei==0 && leitura != EOF){
		count=0;
		while (dic[i]!='\n') {
			count++;
			i++;
			leitura=fscanf(entrada, "%c", &dic[i]);
		}
		if (count==*j) {
		/* Comparando as palavras */
			i=0;
			while (!end && i<*j) {
				if (palavra[i]!=dic[i])	end=1;
				i++;
			}
			if (!end) achei=1;
		}
		i=0;
		end=0;
		leitura=fscanf(entrada, "%c", &dic[i]);	
	
	}
	/* 0 valor do tamanho do vetor é zerado, para o mesmo vetor ser 
	reutilizado na main */
	*j=0;
	
	return achei;
}

int main () {
	char plaintext[MAX];
	/* Vetor que tera o texto decriptado */
	int plaincode[MAX];
	/* Vetor que tera os numeros do texto decriptado*/
	char ciphertext[MAX];
	/* Vetor que tera o texto encriptado */
	int ciphercode[MAX];
	/* Vetor que tera os numeros do texto encriptado*/
	char palavra[MAX];
	/* Vetor que tera uma palavra decriptada para verificar seela esta no 
	dicionario */	
	int n;
	/* Tamanho do texto a ser decriptado */
	int k;
	/* Variavel que armazena as possíveis chaves */
	int end=1;
	/* Variavel de parada */
	int i=0, j=0, l;
	/* Variáveis de auxilio para manipulação de vetores */
	
	
	/* Para ler o arquivo DECRYPT.IN e criar o DECRYPT.OUT */
	FILE * entrada;
	FILE *saida;
	int leitura;
	/* ABRINDO O ARQUIVO DECRYPT.IN */
	entrada=fopen("DECRYPT.IN", "r"); 	
	leitura=fscanf(entrada, "%c", &ciphertext[i]);
	while (ciphercode[i]!='\n' && leitura != EOF) {
		i++;
		leitura=fscanf(entrada, "%c", &ciphertext[i]);
	}
	n=i-1;	
	/* CHIPHERTEXT >>>>>>>>> CIPHERCODE */
	for (i=0;i<n;i++) {
		if (ciphertext[i]=='_')
			ciphercode[i]=0;
		else if (ciphertext[i]=='.')
			ciphercode[i]=27;
		else 
			ciphercode[i]=ciphertext[i]-'A'+1;
	}
	/* BUSCANDO O K */
	/* Se end==0 para, pois isso sinifica que todas as palavras do vetor
	plaintext, decripitado com certo k, estao no dicionário */
	for (k=1;k<=300 && end==1;k++) 
		if (mdc(k,n)==1) {
			end=0;
		/* Decriptando com esse K */
			for (i=0;i<n;i++) {
				/* Como cada valor do ciphercode representa um 
				valor do plaincode, simplismente se inverte
				a formula do twist */  
				plaincode[(k*i)%n]=(ciphercode[i]+i)%28;
				j=(k*i)%n;
				/* PLAINCODE >>>>>>> PLAINTEXT */
				if (plaincode[j]==0)
					plaintext[j]='_';
				else if (plaincode[j]==27)
					plaintext[j]='.';
				else 
					plaintext[j]=plaincode[j]-1+'A';
				
			}
			/*
			for (l=0;l<n;l++)
				printf("%c", plaintext[l]);
			printf("\nO k é: %d\n", k);
			sleep(1);
		 Vendo se as palavras com esse k estao no dicionario*/
			j=0;
			for (i=0;i<n && end==0;i++) {
				if(plaintext[i]!='_' && plaintext[i]!='.') {
					palavra[j]=plaintext[i];
					j++;					
					/* Caso nao haja um ponto ou espaço no fim da palavra */
					if(i==(n-1))
						if (dicionario(palavra,&j)==0) end=1;
				}
				else if (j!=0){
					/* Se uma das palavras decriptadas nao 
					estiver no dicionário, parar o loop */
					if (dicionario(palavra,&j)==0) end=1;
				}
			}
		}
	printf("%d\n", k);
	/* CRIANDO O ARQUIVO DECRYPT.OUT */
	
	saida=fopen("DECRYPT.OUT", "w");
	for (i=0;i<n;i++)
		fprintf(saida,"%c", plaintext[i]);
	fprintf(saida,"\n");		
		
	fclose(entrada);
	fclose(saida);
	
	return 0;
}
