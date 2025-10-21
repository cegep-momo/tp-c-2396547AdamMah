#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Book {
    private:
        string title;
        string author;
        string isbn;
        bool isAvailable;
        string borrowerName;

    public:
        // Constructors
        Book();
        Book(const string& title, const string& author, const string& isbn) {
            this->title = title;
            this->author = author;
            this->isbn = isbn;
            this->isAvailable = false;
            this->borrowerName = "";
        }
        
        // Getters
        string getTitle() const {
            return this->title;
        }
        string getAuthor() const {
            return this->author;
        }
        string getISBN() const {
            return this->isbn;
        }
        bool getAvailability() const {
            return this->isAvailable;
        }
        string getBorrowerName() const {
            return this->borrowerName;
        }
        
        // Setters
        void setTitle(const string& title) {
            this->title = title;
        }
        void setAuthor(const string& author) {
            this->author = author;
        }
        void setISBN(const string& isbn) {
            this->isbn = isbn;
        }
        void setAvailability(bool available) {
            this->isAvailable = available;
        }
        void setBorrowerName(const string& name) {
            this->borrowerName = name;
        }
        
        // Methods
        void checkOut(const string& borrower) {
            this->borrowerName = borrower;
            this->isAvailable = false;
        }
        void returnBook() {
            this->borrowerName = "";
            this->isAvailable = true;
        }
        string toString() const {
            string availableInt = to_string(this->isAvailable);
            return "" + this->title + "|" + this->author + "|" + this->isbn; + "|" + availableInt + "|" + this->borrowerName;
        }

        //TODO: ts
        string toFileFormat() const {
            string availableInt = to_string(Book::getAvailability());
            return "" + Book::getTitle() + "|" + Book::getAuthor() + "|" + Book::getISBN(); + "|" + availableInt + "|" + Book::getBorrowerName();
        }
        void fromFileFormat(const string& line) {
            stringstream stream(line);
            string segment;
            vector<string> seglist;

            while (!getline(stream,segment,'_').eof()) {
                seglist.push_back(segment);
            }

            this->title = seglist[0];
            this->author = seglist[1];
            this->isbn = seglist[2];
            this->isAvailable = stoi(seglist[3]);
            //possible que si dernier line vide, elem 4 pas ajoute
            this->borrowerName = seglist[4];
        }
};
