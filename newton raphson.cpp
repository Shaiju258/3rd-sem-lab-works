#include<stdio.h>
#include<math.h>
//function x-cos(x)
double f(double x){
	return x-cos(x);
}

double f_prime(double x){
	return 1+sin(x);
}

int main(){
	double x0,x1;
	int iteration=0;
	printf("=====Shaiju Maharjan=====");
	printf("\nFunction: f(x)= x - cos(x)");
	printf("\nEnter your initial guess:");
	scanf("%.3f",&x0);
	while(iteration<20){
		iteration++;
		
		if(fabs(f_prime(x0))<1e-6){
			printf("please choose different inital. the derivative of function is 0.");
			return 1;
		}
		
		x1=x0- f(x0)/f_prime(x0);
		printf("Iteration %d: x=%.3f, f(x)=%.3f\n",iteration, x1,f(x1));
		
		if(fabs(x1-x0)< 0.001)
		break;
		
		x0=x1;
	}
	printf("\n===Newton Raphson Method===");
	printf("\nEstimated root: %.3f",x1);
	printf("\n f(root);%.3f",f(x1));
	printf("\nTotal iteration process:%d", iteration);
}
