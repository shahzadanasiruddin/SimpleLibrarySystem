#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

// Define the structure for a Book
struct Book {
    string title;
    string author;
    bool available;
};

// Declare an array to store books and a variable to track the number of books
Book library[MAX_BOOKS];
int numBooks = 0;

// Function to display the menu options
void displayMenu() {
    cout << "Library Management System\n";
    cout << "1. Add a Book\n";
    cout << "2. Borrow a Book\n";
    cout << "3. Return a Book\n";
    cout << "4. Display Available Books\n";
    cout << "5. Display All Books\n";
    cout << "6. Search for a Book\n";  // New option
    cout << "7. Exit\n";  // Updated exit option
    cout << "Enter your choice: ";
}

// Function to add a book to the library
void addBook() {
    if (numBooks < MAX_BOOKS) {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, library[numBooks].title);
        cout << "Enter author: ";
        getline(cin, library[numBooks].author);
        library[numBooks].available = true;
        numBooks++;
        cout << "Book added successfully!\n";
    } else {
        cout << "Maximum books limit reached!\n";
    }
}

// Function to borrow a book from the library
void borrowBook() {
    string title;
    cout << "Enter the title of the book you want to borrow: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < numBooks; i++) {
        if (library[i].title == title) {
            if (library[i].available) {
                library[i].available = false;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Sorry, the book is currently unavailable.\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

// Function to return a borrowed book to the library
void returnBook() {
    string title;
    cout << "Enter the title of the book you want to return: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < numBooks; i++) {
        if (library[i].title == title) {
            if (!library[i].available) {
                library[i].available = true;
                cout << "Book returned successfully!\n";
            } else {
                cout << "This book is already in the library.\n";
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

// Function to display either available or all books in the library
void displayBooks(bool onlyAvailable) {
    cout << (onlyAvailable ? "Available Books:\n" : "All Books:\n");
    for (int i = 0; i < numBooks; i++) {
        if (!onlyAvailable || library[i].available) {
            cout << "Title: " << library[i].title << ", Author: " << library[i].author;
            cout << (library[i].available ? " (Available)\n" : " (Borrowed)\n");
        }
    }
}

// Function to search for a book in the library by its title
void searchBook() {
    string title;
    cout << "Enter the title of the book you want to search: ";
    cin.ignore();
    getline(cin, title);
    for (int i = 0; i < numBooks; i++) {
        if (library[i].title == title) {
            cout << "Book found!\n";
            cout << "Title: " << library[i].title << ", Author: " << library[i].author;
            cout << (library[i].available ? " (Available)\n" : " (Borrowed)\n");
            return;
        }
    }
    cout << "Book not found!\n";
}

// Main function where the program starts execution
int main() {
    int choice;
    // Display the menu and process user input until the exit option is selected
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                displayBooks(true);
                break;
            case 5:
                displayBooks(false);
                break;
            case 6:
                searchBook();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

