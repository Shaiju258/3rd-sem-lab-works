#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->info = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted value: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->info = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted value: " << value << endl;
    }

    void insertPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertBegin(value);
            return;
        }

        if (head == NULL) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node();
        newNode->info = value;

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head && pos > 2) {
            cout << "Invalid position!\n";
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted value: " << value << endl;
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!\n";
        }
        else if (head->next == head) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* del = head;
            cout << "Deleted value: " << del->info << endl;
            head = head->next;
            temp->next = head;
            delete del;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
        }
        else if (head->next == head) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            cout << "Deleted value: " << temp->next->info << endl;
            delete temp->next;
            temp->next = head;
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
            deleteBegin();
        }
        else {
            Node* temp = head;
            for (int i = 1; i < pos - 1 && temp->next != head; i++) {
                temp = temp->next;
            }

            if (temp->next == head) {
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
            cout << "Circular Linked List: ";
            do {
                cout << temp->info << " -> ";
                temp = temp->next;
            } while (temp != head);
            cout << "(head)\n";
        }
    }
};

int main() {
    CircularLinkedList list;
    int choice, subChoice, value, pos;

    while (true) {
        cout << "\n===== Shaiju Maharjan =====\n";
        cout << "===Singly Circular===\n";
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

