#include<iostream>
using namespace std;

int factorial(int n){
	if(n==1){
		return 1;
	}
	else{
		return (n*factorial(n-1));
	}
}

int main(){
	int n;
	cout << "=====Shaiju Maharjan =====\n";
	cout<< "\nEnter a number:";
	cin >> n;
	cout<< "The factorial of " << n << " is " << factorial(n) << "."; 
}

