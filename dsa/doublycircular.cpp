#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->info = value;

        if (head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted value: " << value << endl;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->info = value;

        if (head == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
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

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Invalid position!\n";
                return;
            }
        }

        Node* newNode = new Node();
        newNode->info = value;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        cout << "Inserted value: " << value << endl;
    }

    void deleteBegin() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else if (head->next == head) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        } else {
            Node* last = head->prev;
            Node* temp = head;
            cout << "Deleted value: " << temp->info << endl;
            head = head->next;
            head->prev = last;
            last->next = head;
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else if (head->next == head) {
            cout << "Deleted value: " << head->info << endl;
            delete head;
            head = NULL;
        } else {
            Node* last = head->prev;
            cout << "Deleted value: " << last->info << endl;
            last->prev->next = head;
            head->prev = last->prev;
            delete last;
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

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == head) {
                cout << "Invalid position!\n";
                return;
            }
        }

        cout << "Deleted value: " << temp->info << endl;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty!\n";
        } else {
            Node* temp = head;
            cout << "Circular Doubly Linked List: ";
            do {
                cout << temp->info << " <-> ";
                temp = temp->next;
            } while (temp != head);
            cout << "(HEAD)\n";
        }
    }
};

int main() {
    CircularDoublyLinkedList list;
    int choice, subChoice, value, pos;

    while (true) {
        cout << "\n===== Shaiju Maharjan =====\n";
        cout << "===Doubly Circular===\n";
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

