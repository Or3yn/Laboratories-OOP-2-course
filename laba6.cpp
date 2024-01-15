#include<iostream>
#include <string>
using namespace std;

int size = 50;
class book{
    string author[size];
    string title[size];
    string publishing[size];
    struct data{
        short int day;
        short int month;
        short int year;
    }
    int value;
    public:
    book(){
        author="Николай Васильевич Гоголь";
        title="Вечера на хуторе близ диканьки"
        publishing = "FabricaShop";
        data.day = 01;
        data.month = 01;
        data.year = 2000;
    }
    book(string my_author, string my_title, string my_publishing, struct my_data){
        author = my_author;
        title=my_title;
        publishing=my_publishing;

    };
    ~book{};
}
int main{
    setlocale("LC_ALL", "Rus");
    return 0;
}