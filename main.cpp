#include <iostream>

using namespace std;

class Shopping
{
private:
    int pcode;
    float price;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void Shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_____________________________________\n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t        supermarket Main Menu        \n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t_____________________________________\n";
    cout << "\t\t\t\t                                     \n";
    cout << "\t\t\t\t|   1) Administrator   |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|   2) Buyer           |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|   3) Exit            |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|Please select!";
    cin >> choice;

    switch(choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email   \n";
        cin >> email;
        cout << "\t\t\t Password        \n";
        cin >> password;

        if(email == "robby@email.com" && password == "robby@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;

    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
        default:
        {
            cout << "Please select from the given options";
        }

    }

    goto m;
 }

void Shopping::administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|_____1) Add the product_____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____1) Modify the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____1) Delete the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____1) Back to main menu   |";

    cout <<"\n\n\t Please enter your choice! ";
    cin >> choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid choice!";
    }
    goto m;
}

void Shopping:: buyer()
{
    int choice;
    cout << "\t\t\t 1)  Buyer   \n";
    cout << "\t\t\t_____________\n";
    cout << "\t\t\t             \n";
    cout << "                   \n";
    cout << "\t\t\t1)Buy product\n";
    cout << "                   \n";
    cout << "\t\t\t1) Go back   \n";
    cout << "\t\t\t Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;

    }
    }

    void Shopping::add()
    {

        fstream data;
        int c;
        int token = 0;
        float p ;
        float d;
        string n;

        cout << " \n\n \t\t\tAdd new product";
        cout << "\n\n \t Product code of the product ";
        cin >> pcode;
        cout <<"\n\n\t Name of the product";
        cin >> pname;
        cout <<"\n\n\t Price of the product";
        cin >> price;
        cout <<"\n\n\t Discount of the product";
        cin >> dis;

        data.open("database.txt",ios:in);
    }
int main()
{
    Shopping shopobject;
    shopobject.menu();
}


