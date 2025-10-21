#include <string>
#include <vector>
#include <sstream>

#include "book.h"

using namespace std;


        // Constructors
        Book::Book() : title(""), author(""), isbn(""), isAvailable(""), borrowerName("") {

        }
        Book::Book(const string& title, const string& author, const string& isbn) 
            :title(title), author(author), isbn(isbn) {
                isAvailable = false;
                borrowerName = false;
            }
        // Getters
        string Book::getTitle() const {
            return title;
        }
        string Book::getAuthor() const {
            return author;
        }
        string Book::getISBN() const {
            return isbn;
        }
        bool Book::getAvailability() const {
            return isAvailable;
        }
        string Book::getBorrowerName() const {
            return borrowerName;
        }
        
        // Setters
        void Book::setTitle(const string& title) {
            this->title = title;
        }
        void Book::setAuthor(const string& author) {
            this->author = author;
        }
        void Book::setISBN(const string& isbn) {
            this->isbn = isbn;
        }
        void Book::setAvailability(bool available) {
            this->isAvailable = available;
        }
        void Book::setBorrowerName(const string& name) {
            this->borrowerName = name;
        }
        
        // Methods
        void Book::checkOut(const string& borrower) {
            borrowerName = borrower;
            isAvailable = false;
        }
        void Book::returnBook() {
            borrowerName = "";
            isAvailable = true;
        }
        string Book::toString() const {
            string availableInt = to_string(isAvailable);
            return "" + title + "|" + author + "|" + isbn; + "|" + availableInt + "|" + borrowerName;
        }

        //TODO: ts
        string Book::toFileFormat() const {
            string availableInt = to_string(Book::getAvailability());
            return "" + Book::getTitle() + "|" + Book::getAuthor() + "|" + Book::getISBN(); + "|" + availableInt + "|" + Book::getBorrowerName();
        }
        void Book::fromFileFormat(const string& line) {
            stringstream stream(line);
            string segment;
            vector<string> seglist;

            while (!getline(stream,segment,'_').eof()) {
                seglist.push_back(segment);
            }

            title = seglist[0];
            author = seglist[1];
            isbn = seglist[2];
            isAvailable = stoi(seglist[3]);
            //possible que si dernier line vide, elem 4 pas ajoute
            borrowerName = seglist[4];
        }

