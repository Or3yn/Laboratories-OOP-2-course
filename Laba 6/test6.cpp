#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    Book()
    {
        author = "N.V. Gogol";
        title = "Vechera na hytore";
        publishing = "FabricaShop";
        genre = "classic";
        value = 1000;
        date.day = 01;
        date.month = 01;
        date.year = 2000;
    }
    Book(string my_author, string my_title, string my_publishing, string my_genre, int my_value, int my_data_day, int my_data_month, int my_data_year)
    {
        author = my_author;
        title = my_title;
        publishing = my_publishing;
        genre = my_genre;
        date.day = my_data_day;
        date.month = my_data_month;
        date.year = my_data_year;
        value = my_value;
        if (my_data_day >= 1 && my_data_day <= 31)
            date.day = my_data_day;
        else
        {
            cout << "Invalid day. Please enter a value between 1 and 31." << endl;
            return;
        }

        if (my_data_month >= 1 && my_data_month <= 12)
            date.month = my_data_month;
        else
        {
            cout << "Invalid month. Please enter a value between 1 and 12." << endl;
            return;
        }
    }

    ~Book() { cout << "Destructor has been called" << endl; }

    void Print();
    void Set();
    Book operator++()
    {
        value = value + (value * 0.02);
        return *this;
    }
    int operator+(Book &other)
    {
        int sum;
        sum = this->value + other.value;
        return sum;
    }
    friend ostream &operator<<(ostream &os, Book &book);
    friend istream &operator>>(istream &is, Book &book);
    friend void operator!(Book &book);
    friend bool operator<=(Book &book1, Book &book2);

private:
    string author;
    string title;
    string publishing;
    string genre;
    double value;
    struct data
    {
        short int day;
        short int month;
        short int year;
    } date;
};

void Book::Print()
{
    cout << "Author: " << author << "\n"
         << "Title: " << title << "\n"
         << "Publishing: " << publishing << "\n"
         << "Genre: " << genre << "\n"
         << "Date: " << date.day << "\t" << date.month << "\t" << date.year << "\n"
         << "Cost: " << value << "\n";
    cout << "=====================" << endl;
}

void Book::Set()
{
    string temp_string;
    int temp_int;
    cout << "Enter object's data" << endl
         << "Enter author \t";
    cin >> temp_string;
    author = temp_string;
    cout << "Enter title" << endl;
    cin >> temp_string;
    title = temp_string;
    cout << "Enter publishing" << endl;
    cin >> temp_string;
    publishing = temp_string;
    cout << "Enter genre" << endl;
    cin >> temp_string;
    genre = temp_string;
    cout << "Enter day" << endl;
    cin >> temp_int;
    date.day = temp_int;
    cout << "Enter month" << endl;
    cin >> temp_int;
    date.month = temp_int;
    cout << "Enter year" << endl;
    cin >> temp_int;
    date.year = temp_int;
}

ostream &operator<<(ostream &os, Book &book)
{
    book.Print();
    return os;
}

istream &operator>>(istream &is, Book &book)
{
    book.Set();
    return is;
}
void operator!(Book &book)
{
    if (2024 - book.date.year < 10)
    {
        cout << "Book is young" << endl;
    }
    else
    {
        cout << "Book isn't young" << endl;
    }
}
bool operator<=(Book &book1, Book &book2)
{
    if (book1.publishing == book2.publishing)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Book myBook1("Kostenko L.V.", "300 poems", "Dnipro", "poem", 2100, 01, 12, 2014);
    Book myBook2("Shevchenko T.G.", "Taras Bylba", "Kiev", "classic", 3500, 01, 12, 204);
    Book myBook3;
    cout << "Value multiply check. Before operator:" << endl;
    myBook1.Print();
    ++myBook1;
    cout << "After:" << endl;
    myBook1.Print();
    cout << "Operation << check" << endl;
    cout << myBook2;
    cout << "Operation >> check for Book3" << endl;
    cin >> myBook3;
    cout << "Operation << check for Book3 after >> operation" << endl;
    cout << myBook3;
    cout << "Book age check" << endl;
    !myBook3;
    cout << "Sum of values equals:" << endl;
    cout << myBook1 + myBook2 << endl;
    cout << "Publishing equal or not equal check" << endl;
    if (myBook1 <= myBook3 == 1)
    {
        cout << "Equal publishing" << endl;
    }
    else
    {
        cout << "Not equal publishing" << endl;
    }
    return 0;
}
