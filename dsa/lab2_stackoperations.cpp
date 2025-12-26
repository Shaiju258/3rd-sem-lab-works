#include<iostream>
#define max 10
using namespace std;
class Stack{
	public:
		int top;
		int stack[max];
	
		void makeEmptyStack(){
			top=-1;
		}
		
		bool Overflow(){
			if(top == max-1){
				return true;
			}
			else{
				return false;
			}
		}
		
		bool Underflow(){
			if(top == -1){
				return true;
			}
			else{
				return false;
			}
		}
		
		void Push(){
			if(Overflow()){
				cout << "Stack is full.\n";
			}
			else{
				int num;
				top++;
				cout<< "Enter a number:";
				cin >> num;
				stack[top]=num;
				cout << num << " is pushed in stack.\n";
			}
		}
		
		void Pop(){
			if(Underflow()){
				cout << "Stack is empty.\n";
			}
			else{
				int temp;
				temp = stack[top];
				top--;
				cout <<temp << " is popped out from stack.\n";
			}
		}
		
		void Transverse(){
			if(Underflow()){
				cout<< "Stack is empty.\n";
			}
			else{
				int i;
				cout<< "Data in the stack are:";
				for (i=top; i>=0;i--){
					cout << stack[i] << " ";
				}
				cout << endl;
			}
		}
		
		void Top(){
			if(Underflow()){
				cout << "Stack is empty.\n";
			}
			else{
				cout << "The top value in stack is:" << stack[top]<<endl;;
			}
		}
};

int main(){
	Stack s;
	s.makeEmptyStack();
	int choice;
	
	do{
		cout << "\n===== Stack Operations ====== <Shaiju Maharjan>";
		cout << "\n1. Make stack empty";
		cout << "\n2. Push";
		cout << "\n3. Pop";
		cout << "\n4. Transverse";
		cout << "\n5. Top";
		cout << "\n6. Exit";
		cout << "\nEnter your choice:";
		cin >> choice;
		
		switch(choice){
			
			case 1:{
				s.makeEmptyStack();
				cout << "The stack is made empty.\n";
				break;
			}
			
			case 2:{
				s.Push();
				break;
			}
			
			case 3:{
				s.Pop();
				break;
			}
			
			case 4:{
				s.Transverse();
				break;
			}
			
			case 5:{
				s.Top();
				break;
			}
			
			case 6:{
				cout << "Exiting.";
				break;
			}
			
			default:{
				cout << "Please enter number between 1 to 6.Thank you!\n";
				break;
			}
		}
	} while(choice!=6);
	return 0;
}
