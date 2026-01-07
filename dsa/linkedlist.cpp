#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted value: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else if (head->next == NULL) {
            head->next = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted value: " << value << endl;
    }

    void insertPosition(int value, int pos) {
        Node* newNode = new Node();
        newNode->info = value;

        if (pos <= 0) {
            cout << "Invalid position!\n";
            delete newNode;
        }
        else if (pos == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted value: " << value << endl;
        }
        else if (head == NULL) {
            cout << "Invalid position!\n";
            delete newNode;
        }
        else {
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
                temp = temp->next;
            }

            if (temp->next == NULL && pos > 2) {
                cout << "Invalid position!\n";
                delete newNode;
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << "Inserted value: " << value << endl;
            }
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!\n";
        }
        else if (head->next == NULL) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        }
        else {
            Node* temp = head;
            cout << "Deleted value: " << temp->info << endl;
            head = head->next;
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
        }
        else if (head->next == NULL) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            cout << "Deleted value: " << temp->next->info << endl;
            delete temp->next;
            temp->next = NULL;
        }
    }

    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!\n";
        }
        else if (pos <= 0) {
            cout << "Invalid position!\n";
        }
        else if (pos == 1) {
            Node* temp = head;
            cout << "Deleted value: " << temp->info << endl;
            head = head->next;
            delete temp;
        }
        else if (head->next == NULL) {
            cout << "Invalid position!\n";
        }
        else {
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
                temp = temp->next;
            }

            if (temp->next == NULL) {
                cout << "Invalid position!\n";
            } else {
                Node* del = temp->next;
                cout << "Deleted value: " << del->info << endl;
                temp->next = del->next;
                delete del;
            }
        }
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else {
            Node* temp = head;
            cout << "Linked List: ";
            while (temp != NULL) {
                cout << temp->info << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    LinkedList list;
    int choice, subChoice, value, pos;

    while (true) {
        cout << "\n===== Shaiju Maharjan =====\n";
        cout << "1. Insertion\n";
        cout << "2. Deletion\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n-----Insertion-----\n";
            cout << "1. Beginning\n";
            cout << "2. End\n";
            cout << "3. Position\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1 || subChoice == 2 || subChoice == 3) {
                cout << "Enter value: ";
                cin >> value;
            }

            if (subChoice == 1)
                list.insertBegin(value);
            else if (subChoice == 2)
                list.insertEnd(value);
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> pos;
                list.insertPosition(value, pos);
            }
            else
                cout << "Invalid choice!\n";
            break;

        case 2:
            cout << "\n-----Deletion-----\n";
            cout << "1. Beginning\n";
            cout << "2. End\n";
            cout << "3. Position\n";
            cout << "Enter your choice: ";
            cin >> subChoice;

            if (subChoice == 1)
                list.deleteBegin();
            else if (subChoice == 2)
                list.deleteEnd();
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> pos;
                list.deletePosition(pos);
            }
            else
                cout << "Invalid choice!\n";
            break;

        case 3:
        	cout << "\n-----Traverse-----\n";
            list.traverse();
            break;

        case 4:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

