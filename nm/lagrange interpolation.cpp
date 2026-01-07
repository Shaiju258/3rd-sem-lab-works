#include<stdio.h>
#define max 10
int main(){
	int n,i,j;
	float x[max], y[max],xp,yp,value;
	printf("=====Shaiju Maharjan=====\n");
	printf("-----Lagrange Interpolation-----\n");
	printf("\nEnter the number of data:");
	scanf("%d",&n);
	
		printf("Enter the data points (x): ");
	for(i=0; i < n; i++){
		scanf("%f", &x[i]);
	}
	
    printf("Enter the data points (y): ");
	for(i=0; i < n; i++){
		scanf("%f", &y[i]);
	}
	
	
	printf("\nEnter the value of x to find the point f(x):");
	scanf("%f",&xp);
	
	for(i = 0; i<n; i++){
		value = y[i];
		for(j = 0; j<n; j++){
			if(j != i){
				value = value* (xp - x[j]) / (x[i]- x[j]);
				
			}
		}
		yp = yp + value;
	}
	
	printf("\n The approximate value at x= %.2f is f(x)= %.2f", xp, yp);
	return 0;	
}
