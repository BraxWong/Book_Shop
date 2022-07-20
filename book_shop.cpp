#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <limits>
using namespace std;

class Books {
    public:
        list <string> author;
        list <string> title;
        list <int> price;
        list <string> publisher;
        list <int> stock_position;
        void check_availability(string b_title, string b_author);
        void book_entry(string b_title, string b_author, int b_price, string b_publisher, int b_stock_position);
        void show_stock();
    private:
        void traverse_list(int counter);
};
void Books::traverse_list(int counter) {
    int counter2 = 0;
    list <int>::iterator ptr;
    list <string>::iterator ptr2;
    for(ptr2 = title.begin();counter2 != counter; counter2++){
        ptr2++;
    }
    cout << "Title: " << *ptr2 << endl;
    for(ptr2 = title.begin();counter2 != 0; counter2--){
        ptr2++;
    }
    cout << "Author: " << *ptr2 << endl;
    for(ptr = price.begin();counter2 != counter; counter2++){
        ptr++;
    }
    cout << "Price: " << *ptr << endl << "Publisher: ";
    for(ptr2 = publisher.begin(); counter2 != 0; counter2--){
        ptr2++;
    }
    cout << *ptr2 << endl << "Stock Position: ";
    counter2 = 0;
    for(ptr = stock_position.begin(); counter2 != counter; counter2++){
        ptr++;
    }
    cout << *ptr << endl;
}

void Books::book_entry(string b_title, string b_author, int b_price, string b_publisher, int b_stock_position){
    title.push_back(b_title);
    author.push_back(b_author);
    price.push_back(b_price);
    publisher.push_back(b_publisher);
    stock_position.push_back(b_stock_position);
    cout << "Data entry has been completed\n";
}

void Books::show_stock() {
    traverse_list(0);
}

void Books::check_availability(string b_title, string b_author){
    bool check_1 = false, check_2 = false;
    int counter = 0;
    list <string>::iterator ptr;
    for(ptr = title.begin(); ptr != title.end(); ptr++) {
        counter++;
        if(b_title == *ptr) {
            check_1 = true;
        }
    }
    for(ptr = author.begin(); ptr != author.end(); ptr++){
        if(b_author == *ptr) {
            check_2 = true;
        }
    }
    if(check_1 == true && check_2 == true){
        traverse_list(counter+1);
        return;
    }
    cout << "Title: " << b_title << endl << "Author: " << b_author << endl << "Status: Out of Stocks" << endl;
}
int main() {
    Books new_bookstore;
    int num, price, stock_position; string title, author, publisher;
    cout << "Welcome to Brax's Book Store (Version 1.0.0)\n" << "Press 1 if you are a staff\n" << "Press 2 if you are a customer\n";
    cin >> num;
    if(num == 1){
        while(true){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter the title of the book (Press Q then ENTER to exit)\n";
            getline(cin, title);
            cout << "Please enter the author of the book\n";
            getline(cin,author);
            cout << "Please enter the publisher of the book\n";
            getline(cin,publisher);
            cout << "Please enter the price of the book\n";
            cin >> price;
            cout << "Please enter the stock position of the book\n";
            cin >> stock_position;
            new_bookstore.book_entry(title,author,price,publisher,stock_position);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Will that be all? (Y/N)\n";
            getline(cin, title);
            if(title == "Y" || title == "y"){
                break;
            }
        }
        new_bookstore.show_stock();
    }
    else if(num ==2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter the title of the book\n";
        getline(cin,title);
        cout << "Please enter the author of the book\n";
        getline(cin,author);
        new_bookstore.check_availability(title,author);
    }
    else {
        cout << "Its either 1 or 2, please try again later.\n";
    }
    return 0;
}