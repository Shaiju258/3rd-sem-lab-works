#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

class Stack{
	public:
	int precedence(char c){
	    if (c == '^' || c =='$') 
	 return 3;
    if (c == '*' || c == '/' || c == '%')
	 return 2;
    if (c == '+' || c == '-')
	 return 1;
	 
    return 0;
}

void display(stack<char>st){
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}

void infixToPrefix(string s){
    string temp, res, prefix;
    stack<char> st;

    // Step 1: Reverse infix
    for(int i = s.length() - 1; i >= 0; i--){
        temp += s[i];
    }

    // Step 2: Swap brackets
    for(int i = 0; i < temp.length(); i++){
        if(temp[i] == '(')
            temp[i] = ')';
        else if(temp[i] == ')')
            temp[i] = '(';
    }

    cout<<"Characters  |Poststack     | opstack"<<endl;
    cout<< "---------------------------------------------------\n";

    // Step 3: Postfix conversion of reversed expression
    for(int i = 0; i < temp.length(); i++){
        char c = temp[i];

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            res += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(c) <= precedence(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }

        cout << "     " << c << "       " << res << "           ";
        display(st);
        cout << endl;
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    cout << "Intermediate Postfix: " << res << endl;

    // Step 4: Reverse postfix ? prefix
    for(int i = res.length() - 1; i >= 0; i--){
        prefix += res[i];
    }

    cout << "Prefix Expression: " << prefix << endl<<endl;
}

string infixToPostfix(string s){
	stack<char>st;
	string res;
	cout<<"Characters  |Poststack     | opstack"<<endl;
	cout<< "---------------------------------------------------\n";
	for(int i=0;i<s.length();i++){
		char c=s[i];
		
	if((c>='A'&&c<='Z')|| (c>='a'&&c<='z')||(c>='0'&&c<='9'))
	  {
	  	res+=c;
	  }
	  else if(c=='(')
	  {
	  	st.push(c);
	  }
	  else if(c==')')
	  {
	  	while(!st.empty() && st.top()!='('){
	  		res+=st.top();
	  		st.pop();
		  }
		  st.pop();
	  }
	  else{
	  	while(!st.empty() && precedence(c)<=precedence(st.top())){
	  		res+=st.top();
	  		st.pop();
		  }
		  st.push(c);
	  }
	  cout << "     " << c << "       " << res << "           ";
            display(st);
            cout << endl;
        }
        while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	cout<<"Postfix expression: "<<res<<endl<<endl;
    return res;
	}
	

/* -------- POSTFIX EVALUATION (BOTTOM -> TOP STACK) -------- */
void postfixEvaluation(string postfix) {
    stack<int> st;

    cout << "\nScanned\tResult\t\tStack\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            st.push(ch - '0');
            cout << ch << "\tPush " << ch << "\t\t";
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = 0;

            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '%': res = a % b; break;
                case '^':
                case '$': res = pow(a, b); break;
            }

            st.push(res);
            cout << ch << "\t" << a << " " << ch << " " << b << " = " << res << "\t";
        }

        // display stack bottom -> top
        stack<int> temp = st;
        int arr[50], n = 0;

        if (temp.empty()) cout << "-";
        else {
            while (!temp.empty()) {
                arr[n++] = temp.top();
                temp.pop();
            }
            for (int j = n - 1; j >= 0; j--)
                cout << arr[j] << " ";
        }
        cout << endl;
    }

    cout << "\nFinal Result = " << st.top() << endl;
}
};
int main()
{
	Stack obj;
	string exp;
	int choice;
	
	do{
		cout<<"\n=====Shaiju Maharjan====="<<endl;
		cout<<"=====MENU====="<<endl;
		cout<<"1. Infix to Postfix."<<endl;
		cout<<"2. Infix to Prefix"<<endl;
		cout<<"3. Expression evaluation."<<endl;
		cout<<"4. Exit."<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the infix expression: ";
				cin>>exp;
				obj.infixToPostfix(exp);
				break;
					
				
			case 2:
				cout<<"Enter the infix expression: ";
				cin>>exp;
				obj.infixToPrefix(exp);
				break;
				
			case 3:
				cout<<"Enter the expression: ";
				cin>>exp;
				obj.postfixEvaluation(exp);
				break;
			
			case 4:
				cout<<"Exiting"<<endl;
				break;
			default:
				cout<<"Please enter number from 1 to 4. Thankyou!"<<endl;
				break;
		}
	}while(choice!=4);
return 0;
}

//4542$+22$93/*-+
//a$b*c$d/e+f$g
