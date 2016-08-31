#include <stdio.h>
int mdc (int k, int n) {
	int r;
	while (n>0) {
		r=k%n;
		k=n;
		n=r;		
	}
	return k;
}

int main () {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", mdc(x,y));
	
	return 0;
}
