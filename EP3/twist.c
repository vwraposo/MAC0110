#include <stdio.h>
#define MAX 1000000

/*void twist (int n, int k, int plaintext[MAX], int */

int main () {
	char plaintext[MAX], ciphertext[MAX];
	int n, k=0, i=0, plaincode[MAX], ciphercode[MAX];
	FILE * saida;
	/*Lendo o codigo a ser encriptado */	
	printf("Dê o codigo a ser encriptado\n");
	/*leitura=scanf("%c", &plaintext[i]);
	while (leitura != EOF) {
		i++;
		leitura=scanf("%c", &plaintext[i]);
		n=i-1;
	}
	*/
	scanf("%d", &n);
	for (i=0;i<n;i++) 
		scanf("%c", &plaintext[i]);
				
	/*Conveertendo o plaintext em plaincode */
	for (i=0;i<n;i++) {
		if (plaintext[i]=='_')
			plaincode[i]=0;
		else if (plaintext[i]=='.')
			plaincode[i]=27;
		else 
			plaincode[i]=plaintext[i]-'A'+1;
	}
		
	/*plaincode >>>>>> ciphercode*/
	printf("Dê a chave\n");
	scanf("%d", &k);
	for (i=0;i<n;i++) {
		ciphercode[i]=(plaincode[(k*i)%n]-i);
		if (ciphercode[i]<0) 
			ciphercode[i]=(ciphercode[i]+28)%28;
		else 
			ciphercode[i]=ciphercode[i]%28;			
		if (ciphercode[i]==0)
			ciphertext[i]='_';
		else if (ciphercode[i]==27)
			ciphertext[i]='.';
		else 
			ciphertext[i]=ciphercode[i]-1+'A';
	}
	
	for (i=0;i<n;i++)
		printf("%c", ciphertext[i]);
	printf("\n");
	saida=fopen("DECRYPTIN.txt", "w");
		for (i=0;i<n;i++)
		fprintf(saida,"%c", ciphertext[i]);
	fprintf(saida,"\n");
	
	fclose(saida);		
	 
	return 0;
}	
