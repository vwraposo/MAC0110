#include <stdio.h>
#define MAX 100000

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
	entrada=fopen("dicionario.txt", "r");
	leitura=fscanf(entrada, "%c", &dic[i]);
	while (achei==0 && leitura != EOF){
		count=0;
		while (dic[i]!='\n') {
			if ( dic[i]!='-') {
				count++;
				i++;
			}
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
	char palavra[MAX];
	int i, n;
	scanf("%d", &n);
	for (i=0;i<n;i++)
		scanf("%c", &palavra[i]);
	printf("%d\n", dicionario(palavra, &i));		

	return 0;
}
