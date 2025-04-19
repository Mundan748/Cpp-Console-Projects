#include<iostream>
#include<string>
using namespace std;

// Book node structure
struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

// Head pointer for the list
Book* head = nullptr;

// Function to add a new book
void addBook(int id, string title, string author) {
    Book* newBook = new Book();
    newBook->id = id;
    newBook->title = title;
    newBook->author = author;
    newBook->next = nullptr;

    if (head == nullptr) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    cout << "Book added successfully!\n";
}

// Function to display all books
void displayBooks() {
    if (head == nullptr) {
        cout << "Library is empty.\n";
        return;
    }

    cout << "\n--- Book List ---\n";
    Book* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << "\n";
        temp = temp->next;
    }
}

// Function to search a book by ID
void searchBook(int id) {
    Book* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "\nBook Found:\n";
            cout << "ID: " << temp->id << "\nTitle: " << temp->title << "\nAuthor: " << temp->author << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Book with ID " << id << " not found.\n";
}

// Main menu
int main() {
    int choice, id;
    string title, author;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                addBook(id, title, author);
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                cout << "Enter Book ID to search: ";
                cin >> id;
                searchBook(id);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
