#include <iostream>
#include <fstream>

using namespace std;

class Shopping
{
private:
    int pcode;
    float price;
    string pname;
    int dis;

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
    cout << "\t\t\t\t|    Please select!";
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
    cout << "\n\t\t\t|_____2) Modify the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____3) Delete the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____4) Back to main menu   |";

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
    cout << "\t\t\t 1)  Buyer    \n";
    cout << "\t\t\t_____________ \n";
    cout << "\t\t\t              \n";
    cout << "                    \n";
    cout << "\t\t\t 1)Buy product\n";
    cout << "                    \n";
    cout << "\t\t\t 2) Go back   \n";
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
    } //end of menu

    void Shopping::add()
    {
        m:
        fstream data;
        int c;
        int token = 0;
        float p ;
        float d;
        string n;

        cout << " \n\n \t\t\t Add new product";
        cout << "\n\n \t Product code of the product ";
        cin >> pcode;
        cout <<"\n\n\t Name of the product";
        cin >> pname;
        cout <<"\n\n\t Price of the product";
        cin >> price;
        cout <<"\n\n\t Discount of the product";
        cin >> dis;

        data.open("database.txt",ios::in);  // here, 'in' stands for read mode
        if(!data)
        {
            data.open("database.txt", ios::app|ios::out); // 'out' is write mode and 'app' stands for append mode
            data << " "<<pcode<< " "<<pname<< " " <<price<< " "<<dis<< "\n";
            data.close();
        }
        else
        {
           data>>c>>n>>p>>d;

           while(!data.eof())
           {
               if(c == pcode)
               {
                   token++;
               }
               data>>c>>n>>p>>d;
            }
               data.close();

           }
           if(token== 1)
           goto m;
           else
           {
               data.open("database.txt", ios::app|ios::out); // 'out' is write mode and 'app' stands for append mode
               data << " "<<pcode<< " "<<pname<< " " <<price<< " "<<dis<< "\n";
               data.close();
           }
           cout << "Record inserted!";

        } // End of add

        void Shopping::edit()
        {
            fstream data,data1;
            int pkey;
            int token=0;
            int c;
            float p, d;
            string n;

            cout <<"\n\t\t\t Modify the record!";
            cout << "Product code ";
            cin >>pkey;

            data.open("database.txt",ios::in);
            if(!data)
            {
                cout << "File does not exist!";
            }
            else
            {
                data1.open("database2.txt",ios::app|ios::out);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pkey == pcode)
                    {
                        cout <<"\n\t\t Product new code?";
                        cin >>c;
                        cout <<"\n\t\t Name of the product?";
                        cin>>n;
                        cout << "\n\t\t Price?";
                        cin >>p;
                        cout <<"\n\t\t Discount?";
                        cin >>d;
                        data1 << " "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                        cout<<"\n\n\t\t Record edited";
                        token++;
                    }
                    else
                    {
                        data1 <<" "<<pcode<<" "<<pname<<" "<<price<< " "<<dis<<"\n";
                    }
                    data>>pcode>>pname>>pname>>price>>dis;
                }
                data.close();
                data1.close();
                remove("database.txt");
                rename("database.txt","database.txt");
                if(token == 0)
                {
                    cout << "\n\n Record not found, sorry!";
                }
            }

        }

        void Shopping::rem()
        {
            fstream data, data1;
            int pkey;
            int token = 0;
            cout << "\n\n Delete Product";
            cout << "Enter the product code!";
            cin >>pkey;
            data.open("database.txt",ios::in);
            if(!data)
            {
                cout <<"File doesnt exists!";
            }
            else
            {
                data1.open("database1.txt",ios::app|ios::out);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pcode==pkey)
                    {
                        cout<<"\n\n\t Product deleted successfully";
                        token++;
                    }
                    else
                    {
                            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                    }
                    data>>pcode>>pname>>price>>dis;
                }

                    data.close();
                    data1.close();
                    remove("database.txt");
                    rename("database1.txt","database1.txt");

                    if(token == 0)
                    {
                        cout<<"\n\n record not found";
                    }
                }
            } //end of delete

        void Shopping:: list()
        {
            fstream data;
            data.open("database.txt", ios::in);
            cout << "\n\n|__________________________________________\n";
            cout << "ProNo\t\tName\t\tPrice\n";
            cout <<"\n\n|____________________________________________\n";
            data >>pcode>>pname>>price>>dis;

            while(!data.eof())
            {
                cout<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
                data>>pcode>>pname>>price>>dis; // for iteration purpose
            }
            data.close();
        } // end of list

    void Shopping::receipt()
    {
        m:
        fstream data;
        int arrc[100];
        int arrq[100];
        char choice;
        int c = 0;
        float amount = 0;
        float dis = 0;
        float total = 0;

        cout <<"\n\n\t\t\t RECEIPT";
        data.open("dabase.txt", ios::in);
        if(!data)
        {
            cout<<"\n\n empty database";
        }
        else
        {
            data.close();
            list();
            cout << "\n_______________________________________\n";
            cout << "\n|                                      \n";
            cout << "\n    Please place the order             \n";
            cout << "\n|                                       \n";
            cout << "\n_______________________________________\n";
            do
            {
                cout << "\n\n Enter product code :";
                cin >> arrc[c];
                cout << "\n\n Enter the product quantity :";
                cin >>arrq[c];
                for(int i=0;i<c;i++)
                {
                    if(arrc[c]==arrc[i])
                    {
                        cout<<"\n\n Duplicate product code. Please try again!";
                        goto m;
                    }
                }
                c++;
                cout << "\n\n Do you want to buy another product? If yes then pres y else no";
                cin >> choice;
            }while(choice == 'y');

            cout <<"\n\n\t\t\t________________RECEIPT_______________\n";
            cout << "\nProduct No\t Product Name\t Product Quantity\t price\t Amount with discount\n";

            for(int i=0;i<c;i++)
            {
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pcode==arrc[i])
                    {
                        amount=price*arrq[i];
                        dis=(amount*dis/100);
                        total=total+dis;
                        cout <<"\n"<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                    }
                    data>>pcode>>pname>>price>>dis;
                }
            }
            data.close();
        }
        cout << "\n\n__________________________________";
        cout << "\n Total Amount : "<<total;
    }


int main()
{
    Shopping shopobject;
    shopobject.menu();
}


