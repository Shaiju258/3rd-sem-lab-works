#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	else{
		return (gcd(b,a % b));
	}
}

int main(){
	int a,b;
	cout << "=====Shaiju Maharjan =====\n";
	cout<< "\nEnter two numbers to find gcd:";
	cin >> a >> b;
	cout<< "The gcd of (" << a << "," << b <<") " << " is " << gcd(a,b) <<endl;
	}
