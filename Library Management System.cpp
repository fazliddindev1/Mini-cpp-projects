#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string isbn;
    int quantity;
};

// Function declarations
void addBook(vector<Book>& library);
void removeBook(vector<Book>& library);
void searchBook(const vector<Book>& library);
void borrowBook(vector<Book>& library);
void returnBook(vector<Book>& library);
void displayBooks(const vector<Book>& library);

int main() {
    vector<Book> library;
    int choice;

    while (true) {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(library); break;
            case 2: removeBook(library); break;
            case 3: searchBook(library); break;
            case 4: borrowBook(library); break;
            case 5: returnBook(library); break;
            case 6: displayBooks(library); break;
            case 7: return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to add a book to the library
void addBook(vector<Book>& library) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    cout << "Enter book quantity: ";
    cin >> newBook.quantity;
    library.push_back(newBook);
    cout << "Book added successfully.\n";
}

// Function to remove a book from the library
void removeBook(vector<Book>& library) {
    string isbn;
    cout << "Enter book ISBN to remove: ";
    cin.ignore();
    getline(cin, isbn);

    auto it = remove_if(library.begin(), library.end(), [&](Book& b) {
        return b.isbn == isbn;
    });

    if (it != library.end()) {
        library.erase(it, library.end());
        cout << "Book removed successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

// Function to search for a book in the library
void searchBook(const vector<Book>& library) {
    string query;
    cout << "Enter book title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    for (const auto& book : library) {
        if (book.title == query || book.author == query || book.isbn == query) {
            cout << "Book found: \n";
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "ISBN: " << book.isbn << "\n";
            cout << "Quantity: " << book.quantity << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to borrow a book from the library
void borrowBook(vector<Book>& library) {
    string isbn;
    cout << "Enter book ISBN to borrow: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : library) {
        if (book.isbn == isbn) {
            if (book.quantity > 0) {
                --book.quantity;
                cout << "Book borrowed successfully.\n";
            } else {
                cout << "Book is out of stock.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to return a borrowed book to the library
void returnBook(vector<Book>& library) {
    string isbn;
    cout << "Enter book ISBN to return: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : library) {
        if (book.isbn == isbn) {
            ++book.quantity;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to display all books in the library
void displayBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    for (const auto& book : library) {
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "ISBN: " << book.isbn << "\n";
        cout << "Quantity: " << book.quantity << "\n";
        cout << "-------------------------\n";
    }
}
