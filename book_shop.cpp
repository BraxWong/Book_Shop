#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <limits>
using namespace std;

class Books {
    public:
        //linked lists for author,title,price,publisher, and stock position. 
        list <string> author;
        list <string> title;
        list <int> price;
        list <string> publisher;
        list <int> stock_position;
        // Checks if the book is available at the store
        void check_availability(string b_title, string b_author);
        // For staff only, adding books into the system
        void book_entry(string b_title, string b_author, int b_price, string b_publisher, int b_stock_position);
        // Print out what is in stock
        void show_stock();
        // Edit info for books that are in stock
        void edit_stock(string b_title, string b_author, int b_price, string b_publisher, int b_stock_position);
    private:
        //Private function to traverse all the linked list, might create a list <string, string, int, string, int> book in the future to make things easier
        void traverse_list(int counter);
};

// Function that allows staff to edit information on books that are in stock based on the title. In the main function, it will ask for the title, then ask for author, price, publisher and stock position for edit.
void Books::edit_stock(string b_title, string b_author, int b_price, string b_publisher, int b_stock_position) {
    //Creating iteartor for data type string and int
    list <string>::iterator ptr;
    list <int>::iterator ptr2;

    //boolean variable to see whether the book is in stock
    bool check = false;

    //integer variables to make traversing other linked lists easier
    int counter = 0, counter1 = 0;

    //Assigning ptr to the head of the title linked list, adding 1 to the counter in each iteartion
    for(ptr = title.begin(); ptr != title.end(); ptr++){
        counter++;
        //if the data is equal to the title, change check from false to true and break out of the for loop
        if(*ptr == b_title){
            check = true;
            break;
        }
    }
    //if check is still false, that means the book does not exist within the system, exit the function
    if(!check){
        cout << "Your book is not in our system.\n";
        return;
    }

    //Start with author linked list, adding 1 to ptr to move from 1 memory block to another til counter1 is equal to counter
    for(ptr = author.begin(); counter1 != counter; counter1++){
        ptr++;
    }
    //Deference ptr and assign the b_author to it
    *ptr = b_author;

    //Pretty much the same as above for the next 3 for loops
    for(ptr2 = price.begin(); counter1 != 0; counter1--){
        ptr2++;
    }
    *ptr2 = b_price;
    for(ptr = publisher.begin(); counter1 != counter; counter1++) {
        ptr++;
    }
    *ptr = b_publisher;
    for(ptr2 = stock_position.begin(); counter1 != 0; counter1--){
        ptr2++;
    }
    *ptr2 = b_stock_position;
}
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
        cout << "Press 1 if you would like to add books into the system. \nPress 2 if you would like to edit info based on the title of the book.\n";
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
        }
        else if(num == 2){
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
            new_bookstore.edit_stock(title,author,price,publisher,stock_position);
        }
        else {
            cout << "Please try again later.\n";
            return -1;
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