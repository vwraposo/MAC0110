/*****************************************************************************/
/*  	Nome: Victor Wichmann Raposo                                         */
/*  	Número USP: 9298020            					     				 */
/*  	Exercício-programa 4						   						 */
/*****************************************************************************/
#include <stdio.h>
#define MAX 500

void insere_fila (int x, int f[MAX], int *final) {
	*final=*final+1;
	f[*final%MAX]=x;
}

int remove_fila (int *comeco, int f[MAX]) {
	int tmp;
	tmp=f[*comeco%MAX];
	*comeco=*comeco+1;

	return tmp;
}

void insere_pilha (int x, int p[MAX], int *topo) {
	*topo=*topo+1;
	p[*topo]=x;
}

int remove_pilha (int p[MAX], int *topo) {
	*topo=*topo-1;

	return p[*topo];
}

/* Vai receber o vetor com as coordenadas e irá imprimi-las */
void imprime (int v[MAX], int tamanho) {
	int count=0, i=0;
	while (i<=tamanho) {
		/* Para quebrar a linha quando houverem 80 caracteres admitindo
		 que cada numero tem 3 caracteres*/
		count=count+11;
		if (count>80) {
			count=0;
			printf("\n");
		}
		printf("(%d,%d)>>", v[i]/MAX, v[i]%MAX);
		i++;
	}
	printf("\n*************************************************************\n");
}

int main () {
	int L[MAX][MAX], n, m;
	/* Matriz que representa o labirinto e seus paremetros */
	int T[2], S[2];
	/* Vetores que guardarao as coordenadas do Thomas e da Saida, 
	repectivamente */
	int f[MAX];
	/* Vetor que sera usado para fazer a fila */
	int caminho[MAX];
	/* Vetor que sera usado para armazenar as coordenadas do caminho, 
	atravez do metodo da pilha */
	int proibido[MAX];
	/* Vetor que sera usado para armazenar as coordenadas de caminhos ja 
	percorridos, com os valores de 0 a 4
	 - 0 significa que nao na casa determinada pode se ir para qualquer lado
	 - 1 significa que nao pode ir para a direita 
	 - 2 significa que nao pode ir para a direita e para baixo
	 - 3 significa que nao pode ir para a direita, baixo e esquerda
	 - 4 significa que nao pode ir para nenhuma direção */
	int tamanho;
	/* tamanho do vetor "proibido" */
	int atual;
	/* Variavel que armazenará a coordenada atual, durante o processo de achar
	a saida e de achar os menores caminhos. 
		Ela e da seguinte forma: (coordenada x)*MAX+(coordenada y)
	Eu multiplico por MAX, porque nunca havera conflito de coordenadas se o MAX
	for grande o suficente */
	int i, j, k, l;
	/* Auxiliares para os vetores e a matriz */
	int aux;
	/* Variavel auxilar */
	int end=0, flag=0;
	/* Variaveis de parada */	
	int count=0;
	/* Contador */	

	/* Lendo o arquivo de entrada (ENTRADA.txt) */
	FILE * entrada;
	entrada=fopen("labirinto.txt", "r");
	/* Lendo os parametros */
	fscanf(entrada, "%d", &T[0]);
	fscanf(entrada, "%d", &T[1]);
	fscanf(entrada, "%d", &S[0]);
	fscanf(entrada, "%d", &S[1]);
	fscanf(entrada, "%d", &n);
	fscanf(entrada, "%d", &m);
	/* Lendo a matriz */
	for (i=0;i<n;i++)
		for (j=0;j<m;j++) {
			fscanf(entrada, "%d", &aux);
			if (aux=='\n') {
				i--; j--;
			}
			else 
				L[i][j]=aux;
		}
	k=-1;
	/* Fim da fila */
	l=0;
	/* Começo da fila */
	atual=T[0]*MAX+T[1];
	insere_fila (atual, f, &k);
	/* o valor -1, sera uma marcaçao no vetor para saber quando ira mudar o 
	contador das casas */
	insere_fila (-1, f, &k);
	/* Achando a saida atravéz da fila */

	while (!end) {
		atual=remove_fila (&l, f);
		/* Se tiverem dois -1 seguidos significa que acabou */
		if (atual==-1 && flag) end=1;
		if (atual==-1) {
			count++;
			flag++;
			insere_fila (-1, f, &k);
		}
		else {
			flag=0;
			i=atual/MAX;
			j=atual%MAX;
			L[i][j]=count;
			if (i+1<n && L[i+1][j]==0)
				insere_fila ((i+1)*MAX+j, f, &k);
			if (i-1>=0 && L[i-1][j]==0) 
				insere_fila ((i-1)*MAX+j, f, &k);
			if (j+1<m && L[i][j+1]==0) 
				insere_fila (i*MAX+j+1, f, &k);
			if (j-1>=0 && L[i][j-1]==0)
				insere_fila (i*MAX+j-1, f, &k);
			L[S[0]][S[1]]=count+1;
		}
	}
	count=L[S[0]][S[1]];
	L[T[0]][T[1]]=0;
	if (flag==1) 
		printf ("Nao exite caminho entre Thomas e a Saida\n");
	else {
		tamanho=count;
		count--;
		/* Zerando o Vetor proibe */
		for(l=0;l<tamanho;l++)
			proibido[l]=0;
		/* Encontrando todos os caminhos mais curtos que Thomas pode fazer */

		end=0;
		l=0;
		k=-1;
		/* Topo da pilha */		
		atual=S[0]*MAX+S[1];
		insere_pilha (atual, caminho, &k);
		while (!end) {
			i=atual/MAX;
			j=atual%MAX;
			flag=0;
			/* Procurando o proximo passo do caminho, se encontrar colocar no 
			topo da pilha */
			if (j+1<m && L[i][j+1]==count && proibido[k]<1) {
				proibido[k]=1;
				atual=i*MAX+j+1;
				insere_pilha (atual, caminho, &k);
				flag=1;
				count--;
			}
			else if (i+1<n && L[i+1][j]==count && proibido[k]<2) {
				proibido[k]=2;
				atual=(i+1)*MAX+j;
				insere_pilha (atual, caminho, &k);
				flag=1;
				count--;
			}
			else if (j-1>=0 && L[i][j-1]==count && proibido[k]<3) {
				proibido[k]=3;
				atual=i*MAX+j-1;
				insere_pilha (atual, caminho, &k);
				flag=1;
				count--;
			}
			else if (i-1>=0 && L[i-1][j]==count && proibido[k]<4) {
				proibido[k]=4;
				atual=(i-1)*MAX+j;
				insere_pilha (atual, caminho, &k);
				flag=1;
				count--;
			}
			if (!flag) {
				/* Se chegar aonde o Thomas está, imprimir o caminho */
				if (atual==T[0]*MAX+T[1]) {
					imprime (caminho, tamanho);
					atual=remove_pilha (caminho,&k);
					count++;
				}
				atual=remove_pilha (caminho,&k);
				count++;
				for (l=k+1;l<tamanho;l++) 
					proibido[l]=0;				
				/* Se chegar novamente na saida, significa que acabou */
				if (k==-1) end=1;
			}
			
		}
	}

	return 0;
}
