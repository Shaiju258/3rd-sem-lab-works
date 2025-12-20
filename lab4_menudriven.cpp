#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

/* -------- PRECEDENCE FUNCTION -------- */
int precedence(char ch) {
    if (ch == '^' || ch == '$') return 3;
    if (ch == '*' || ch == '/' || ch == '%') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

/* -------- DISPLAY STACK (BOTTOM -> TOP) -------- */
void displayStackBottomTop(stack<char> st) {
    if (st.empty()) {
        cout << "-";
        return;
    }

    char arr[50];
    int n = 0;

    while (!st.empty()) {
        arr[n++] = st.top();
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
        cout << arr[i];
}

/* -------- INFIX TO POSTFIX -------- */
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    cout << "\nScanned\tPostfix\t\tOpStack\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }

        cout << ch << "\t" << postfix << "\t\t";
        displayStackBottomTop(st);
        cout << endl;
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "End\t" << postfix << "\t\t-\n";
    return postfix;
}

/* -------- REVERSE EXPRESSION -------- */
string reverseExp(string exp) {
    int n = exp.length();
    for (int i = 0; i < n / 2; i++) {
        char t = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = t;
    }
    return exp;
}

/* -------- INFIX TO PREFIX -------- */
string infixToPrefix(string infix) {
    infix = reverseExp(infix);

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    cout << "\nINFIX TO POSTFIX TABLE (After Reverse)\n";
    string postfix = infixToPostfix(infix);

    return reverseExp(postfix);
}

/* -------- POSTFIX EVALUATION (BOTTOM -> TOP STACK) -------- */
void evaluatePostfix(string postfix) {
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
            cout << ch << "\t" << a << ch << b << "=" << res << "\t";
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

/* -------- MAIN FUNCTION -------- */
int main() {
    int choice;
    string infix, postfix;

    do {
    	cout << "\n=====Shaiju Maharjan=====";
        cout << "\n===== MENU =====\n";
        cout << "1. Infix to Prefix\n";
        cout << "2. Postfix Evaluation\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "\nPrefix Expression: "
                     << infixToPrefix(infix) << endl;
                break;

            case 2:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                evaluatePostfix(postfix);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

