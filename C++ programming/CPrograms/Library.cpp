#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    float price;
    int bookID;

public:
    // Constructor to initialize book details
    Book(int id, string t, string a, string p, float pr) {
        bookID = id;
        title = t;
        author = a;
        publisher = p;
        price = pr;
    }

    // Member function to display book details
    void displayBook() {
        cout << "\n--- Book Details ---" << endl;
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: ₹" << price << endl;
    }
};

int main() {
    int id;
    string title, author, publisher;
    float price;

    // Taking input from user
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(); // To clear the newline character

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    cout << "Enter Publisher Name: ";
    getline(cin, publisher);

    cout << "Enter Price: ₹";
    cin >> price;

    // Creating Book object
    Book b1(id, title, author, publisher, price);

    // Displaying book info
    b1.displayBook();

    return 0;
}
