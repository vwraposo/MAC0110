#include <stdio.h>
#include <math.h>

int main () {
	int n,t, v1=0, v2=0, v3=0;
	unsigned long x0=42, x1;
	float rand;
	scanf("%d", &n);
	t=n;
	for ( ;n>0;n--) {
		x1=(22695477*x0+1)%4294967296;
		rand=(float)x1/4294967295;
		x0=x1;
		if (0<=rand && rand<0.3333) v1++;				
		else if (0.3333<=rand && rand<0.6666) v2++;
		else if (0.6666<=rand && rand<1) v3++;
	} 	
	printf("Entre 0 e 1/3: %d/%d  = %f\n", v1, t, (float)(v1/t));
	printf("Entre 1/3 e 2/3: %d/%d  = %f\n", v2, t, (float)(v2/t));
	printf("Entre 2/3 e 1: %d/%d  = %f\n", v3, t, (float)(v3/t));
	
	return 0;
}
