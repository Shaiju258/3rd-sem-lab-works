#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted value: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->info = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted value: " << value << endl;
    }

    void insertPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node();
        newNode->info = value;

        if (pos == 1) {
            insertBegin(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!\n";
            delete newNode;
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            cout << "Inserted value: " << value << endl;
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else {
            Node* temp = head;
            cout << "Deleted value: " << temp->info << endl;
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else if (head->next == NULL) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            cout << "Deleted value: " << temp->info << endl;
            temp->prev->next = NULL;
            delete temp;
        }
    }

    void deletePosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!\n";
        } else {
            cout << "Deleted value: " << temp->info << endl;

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            delete temp;
        }
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else {
            Node* temp = head;
            cout << "Doubly Linked List: ";
            while (temp != NULL) {
                cout << temp->info << " <-> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, subChoice, value, pos;

    while (true) {
        cout << "\n===== Shaiju Maharjan =====\n";
        cout << "===Doubly Linked List===\n";
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

