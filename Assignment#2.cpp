// Singly Linked List Guided Exercise
// Project: Contact List Manager
// Student name: Amber Gill

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* next;

    // add constructor here
    Contact(string name, string phone) {

        this-> name = name;
        this->phone = phone;
        next = nullptr;
    }
};

// Function prototypes
void insertAtBeginning(Contact*& head, string name, string phone);
void insertAtEnd(Contact*& head, string name, string phone);
void displayList(Contact* head);
Contact* searchByName(Contact* head, string name);
bool deleteByName(Contact*& head, string name);
void menu(Contact* head);

int main() {

    Contact* head = nullptr;
    menu(head);

    return 0;
}

void insertAtBeginning(Contact*& head, string name, string phone) {
    
    Contact *newHead = new Contact(name, phone);
    newHead->next = head;
    head = newHead;
    
}

void insertAtEnd(Contact*& head, string name, string phone) {
    
    Contact *newContact = new Contact(name, phone);
    
    if (head == nullptr) {
        head = newContact;
        return;
        

    }

    Contact * temp = head;

    while (temp-> next != nullptr) {
        temp = temp->next;
    } 

    temp->next = newContact;
}

void displayList(Contact* head) {
     
    Contact * current = head;
    cout<< "Name, Phone: ";

    while (current != nullptr) {
        cout << current->name << " -> " << current->phone <<  endl;
        current = current->next;
    }
    cout << "NULL" << endl;
}

Contact* searchByName(Contact* head, string name) {
     
    Contact * search = head;

    while (search != nullptr){
        if (name == search->name){
          return search;
        }
        search = search->next;
    }
    return nullptr;
}

bool deleteByName(Contact*& head, string name) {
        
    Contact * current = head;
    Contact * previous = nullptr;

    while (current != nullptr) {
        if (name == current->name) {
            if (previous == nullptr) {

                head = current->next;
            }
            else {
                previous->next = current-> next;
            }
            delete current;
            return true;
        }
        else{
            
            previous = current;
            current = current->next;
        }       
    }
    return false;
}

void menu(Contact* head) {

    int choice;
    string name, phone;

    do {
        cout << "\nContact List Menu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Display Contacts\n";
        cout << "4. Search by Name\n";
        cout << "5. Delete by Name\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtBeginning(head, name, phone);
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtEnd(head, name, phone);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Enter name to search: ";
                getline(cin, name);
                {
                    Contact* found = searchByName(head, name);
                    if (found) {
                        cout << "Found: " << found->name << " - " << found->phone << endl;
                    } else {
                        cout << "Contact not found.\n";
                    }
                }
                break;
            case 5:
                cout << "Enter name to delete: ";
                getline(cin, name);
                if (deleteByName(head, name)) {
                    cout << "Deleted successfully.\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
        }

    } while (choice != 6);


}
