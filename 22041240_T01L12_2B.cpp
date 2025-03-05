#include "bits.h"
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
    }
};

class Library {
private:
    vector<Book> inventory;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;

public:

    void addBook(const Book& book) {
        inventory.push_back(book);
    }

    
    void borrowBook(const string& ISBN) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getISBN() == ISBN) {
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                cout << "Book borrowed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in inventory!" << endl;
    }

    
    void returnBook(const string& ISBN) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if (it->getISBN() == ISBN) {
                inventory.push_back(*it);
                borrowedBooks.erase(it);
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in borrowed list!" << endl;
    }

    
    void archiveBook(const string& ISBN) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getISBN() == ISBN) {
                archivedBooks.push_back(*it);
                inventory.erase(it);
                cout << "Book archived successfully!" << endl;
                return;
            }
        }
        cout << "Book not found in inventory!" << endl;
    }

    
    void displayAllBooks() const {
        cout << "Inventory:" << endl;
        for (const auto& book : inventory) {
            book.display();
        }

        cout << "\nBorrowed Books:" << endl;
        for (const auto& book : borrowedBooks) {
            book.display();
        }

        cout << "\nArchived Books:" << endl;
        for (const auto& book : archivedBooks) {
            book.display();
        }
    }
    void saveData() const {
        ofstream invFile("inventory.txt"), borFile("borrowed.txt"), arcFile("archived.txt");

        if (!invFile || !borFile || !arcFile) {
            cerr << "Error opening files for saving!" << endl;
            return;
        }

        for (const auto& book : inventory) {
            invFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }

        for (const auto& book : borrowedBooks) {
            borFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }

        for (const auto& book : archivedBooks) {
            arcFile << book.getTitle() << "," << book.getAuthor() << "," << book.getISBN() << endl;
        }

        cout << "Data saved successfully!" << endl;
    }

    void loadData() {
        ifstream invFile("inventory.txt"), borFile("borrowed.txt"), arcFile("archived.txt");

        if (!invFile || !borFile || !arcFile) {
            cerr << "Error opening files for loading!" << endl;
            return;
        }

        string line;
        while (getline(invFile, line)) {
            string title, author, isbn;
            stringstream ss(line);
            if(getline(ss, title, ',') && getline(ss, author, ',') && getline(ss, isbn)){
                inventory.push_back(Book(title, author, isbn));
            }
            
        }

        while (getline(borFile, line)) {
            string title, author, isbn;
            stringstream ss(line);
            if(getline(ss, title, ',') && getline(ss, title, ',') && getline(ss, isbn)){
                borrowedBooks.push_back(Book(title, author, isbn));
            }
            
        }

        while (getline(arcFile, line)) {
            string title, author, isbn;
            stringstream ss(line);
            if(getline(ss, title, ',') && getline(ss, title, ',') && getline(ss, isbn)){
                archivedBooks.push_back(Book(title, author, isbn));
            }
        }

        cout << "Data loaded" << endl;
    }
};

void addBook(Library& lib) {
    string title, author, ISBN;
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    lib.addBook(Book(title, author, ISBN));
    cout << "Book added successfully!" << endl;
}


int main() {
    Library lib;
    int choice;
    string ISBN;
    lib.loadData();
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Archive Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Save Data\n";
        cout << "7. Load Data\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook(lib);
                break;
            case 2:
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                lib.borrowBook(ISBN);
                break;
            case 3:
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                lib.returnBook(ISBN);
                break;
            case 4:
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                lib.archiveBook(ISBN);
                break;
            case 5:
                lib.displayAllBooks();
                break;
            case 6:
                lib.saveData();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            case 7:
                lib.loadData();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}