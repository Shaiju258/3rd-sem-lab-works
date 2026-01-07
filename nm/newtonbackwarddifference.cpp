#include <stdio.h>
#define max 10
int main(){
	int n, i, j;
	float x[max], y[max][max], xp, h, s, sum, term;
	
	printf("=====Shaiju Maharjan=====\n");
	printf("-----Newton Backward Interpolation-----\n");
	
	printf("\nEnter the number of data points: ");
	scanf("%d", &n);
	
	printf("\nEnter the value of x:");
	for(i = 0; i < n; i++){
	   scanf("%f", &x[i]);	
	}
		
	printf("\nEnter the value of y:");
	for(i = 0; i < n; i++){
	  scanf("%f", &y[i][0]);	
	}
	
	for(j=1; j < n; j++){
		for(i=n-1; i >= j; i--){
			y[i][j] = y[i][j-1] - y[i-1][j-1];
		}
	}	
	
	printf("\nEnter the values of x to find f(x):");
	scanf("%f", &xp);
	
	h = x[1] - x[0];
	s = (xp - x[n-1]) / h;
		
	sum = y[n-1][0];
	term = 1;
	
	for(i = 1; i < n; i++){
		term = term * (s + (i-1)) / i;
		sum  = sum + term * y[n-1][i];	
	}
    
    printf( "\nThe approximate value at x = %.3f is f(x)= %.3f", xp, sum);
    return 0;
	
}
