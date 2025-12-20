#include <stdio.h>
#include <math.h>

//function : x -cosx
double f(double x){
	return x-cos(x);
}

int main(){
	double a,b,c;
	int iteration=0;
	
	a=0;
	b=1;
	 if(f(a)* f(b) >= 0){
	 	printf("Invalid interval: f(a) and f(b) should have opposite signs.\n");
	 	return 1;
	 }
	 printf("=====Shaiju Maharjan=====\n");
	 printf("Bisection Method for f(x)= x - cos(x))\n");
	 printf("Initial interval :(%.3f,%.3f):\n\n",a,b);
	 
	 while ((b-a)>=0.001){
	 	iteration++;
	 	c=(a+b)/2.00;
	 	
	 	printf("Iteration %d: a=%.3f, b=%.3f, c=%.3f, f(c)=%.3f\n",iteration, a , b, c, f(c));
	 	 
	 	if(fabs(f(c))<0.001){  //root
	 		break;
		 }
		 
		 if(f(a)*f(c) < 0){
		 	b=c;
		 }
		 else{
		 	a=c;
		 }
	}
		 printf("Appropriate root after %d iteration:%.3f\n",iteration,c);
		 return 0;
	 
}
