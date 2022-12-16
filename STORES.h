#include<iostream>
#include<fstream>
using namespace std;

class Stores{
    public: 
        string ownerName;
        string storeName;
        string password;
        int balance;
        string address;
        bool isApproved;
        Stores *next;

        Stores(string oName, string sName, string pass, string ad){
            ownerName = oName;
            storeName = sName;
            password = pass;
            balance = 0;
            address = ad;
            isApproved = false;
            next = NULL;
        }
};

class StoresTemplate{
    Stores *head;
    public:
    void storeRegisterLinked(string sName, string pass, string ad, string name, int file){
    Stores *newStore = new Stores(name, sName, pass, ad);

    if(head==NULL){
        head = newStore;
        if(file==0){
            ofstream fout;
            fout.open("store.txt", ios::out | ios::app);
            fout << head->ownerName << endl;
            fout << head->storeName << endl;
            fout << head->password << endl;
            fout << head->balance << endl;
            fout << head->address << endl;
            fout << head->isApproved << endl;
            fout.close();
        }
        return;
    }

    Stores *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newStore;
        if(file==0){
            ofstream fout;
                fout.open("store.txt", ios::out | ios::app);
                fout << temp->next->ownerName << endl;
                fout << temp->next->storeName << endl;
                fout << temp->next->password << endl;
                fout << temp->next->balance << endl;
                fout << temp->next->address << endl;
                fout << temp->next->isApproved << endl;
                fout.close();
        }
    }
    void showStores(){
        Stores *temp = head;
        int i = 1;
        while(temp!=NULL){
            cout << "\t\t\t\t ==> " << i << " " <<  temp->storeName<<endl;
            i++;
            temp=temp->next;
        }
    }
};

class Foods{
    public:
        string storeName;
        string name;
        int price;
        int stock;
        Foods *next;
        
        Foods(string sName, string nam, int pr, int st){
            storeName = sName;
            name = nam;
            price = pr;
            stock = st;
            next = NULL;
        }
};

class FoodsTemplate{
    Foods *head;
    public:
        void addFood(string store, string food, int price, int stock, int file){
            Foods *newFood = new Foods(store, food, price, stock);
            if(head==NULL){
                head = newFood;
                if(file==0){
                    ofstream fout;
                    fout.open("food.txt", ios::out | ios::app);
                    fout << head->storeName << endl;
                    fout << head->name << endl;
                    fout << head->price << endl;
                    fout << head->stock << endl;
                    fout.close();
                }
                return;
            }
            Foods *temp = head;
            while(temp->next!=NULL) temp = temp->next;
            temp->next = newFood;
                 if(file==0){
                    ofstream fout;
                    fout.open("food.txt", ios::out | ios::app);
                    fout << temp->next->storeName << endl;
                    fout << temp->next->name << endl;
                    fout << temp->next->price << endl;
                    fout << temp->next->stock << endl;
                    fout.close();
                }
        }
        void displayFood(){
            Foods *temp = head;
            while(temp!=NULL){
                cout << temp->name << endl;
                cout << temp->price << endl;
                cout << temp->storeName << endl;
                temp=temp->next;
            }
        }
};