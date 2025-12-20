#include<stdio.h>
#include<math.h>

double f(double x) {
	return x-cos(x);
}

int main(){	
	double a, b, c;
	int iteration = 0;
	printf("=====Shaiju Maharjan=====\n");
	printf("To find the root of the function f(x) = x -cos (x) using secant method is: \n");
	printf("Enter 1st initial guess: \n");
	scanf("%lf", &a);
	printf("Enter the 2nd initial guess:");
	scanf("%lf", &b);
	
	while(iteration < 20){
		iteration ++ ;
		if(fabs(f(a) -f(b)) < 1e-6){
			printf("Please enter another initial guess.");
			return 1;
		}
		c = b - f(b) * (b-a) / (fabs(f(b) - f(a)));
		printf("\n Iteration %d: x = %.3f, f(x) = %.3f \n", iteration, c, f(c));
		if(fabs(c-b) < 0.0001)
		break;
		
		a = b;
		b =  c;
	}
	printf("\n Estimated root: %.3f", c);
	printf("\n f(%.3f): %.3f", c, f(c));
	printf("\n Total no. of iteration: %d", iteration);
	
	return 0;
}
