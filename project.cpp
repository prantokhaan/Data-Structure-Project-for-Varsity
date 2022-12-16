#include<iostream>
#include<fstream>
#include"USER.h"
#include"STORES.h"

using namespace std;



UserTemplate user;
StoresTemplate stores;
FoodsTemplate foods;

//Global Variables
string username, address, password, name;

// Function Initialization
void customer();
void customerLogin(string path);
void customerRegister();
void customerDashboard();
void store();
void storeDashboard();
void addFoods();

void addFoods(){
    string food;
    int stock, price;
    char o;
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [Add Food]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t  => Enter Food Name: ";
    cin >> food;
    cout << "\t\t\t\t  => Enter Price: ";
    cin >> price;
    cout << "\t\t\t\t  => Enter Stock: ";
    cin >> stock;
    cout << "\t\t\t\t  => Add More? (y/n): ";
    cin >> o;
    foods.addFood(username, food, price, stock, 0);
    cout << "\t\t\t\t  Food Added Successfully" << endl;
    if(o=='y' || o=='Y') addFoods();
    else storeDashboard();
}

// store owner part
void storeDashboard(){
    system("color 0e");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Store Dashboard]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Pending Orders" << endl;
        cout << "\t\t\t\t  [2] All Orders" << endl;
        cout << "\t\t\t\t  [3] My Account " << endl;
        cout << "\t\t\t\t  [4] All Foods" << endl;
        cout << "\t\t\t\t  [5] Add Food" << endl;
        cout << "\t\t\t\t  [6] Edit Food" << endl;
        cout << "\t\t\t\t  [7] Delete Food" << endl;
        cout << "\t\t\t\t  [8] Create Voucher" << endl;
        cout << "\t\t\t\t  [9] Edit Voucher" << endl;
        cout << "\t\t\t\t  [10] Delete Voucher" << endl;
        
        cout << "\t\t\t\t  [0] Back" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 5:
                addFoods();
            case 4:
                foods.displayFood();
                char a;
                cout << "\t\t\t\t  Press any key to go back: ";
                cin >> a;
                // function for show foods
                break;
            case 2:
                // function for show my orders
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y') run = 0;
                break;
        }
    }
}

void storeRegister(){
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [Store Register]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t  => Enter your name: ";
    cin >> name;
    cout << "\t\t\t\t  => Enter your store name: ";
    cin >> username;
    cout << "\t\t\t\t  => Enter your password: ";
    cin >> password;
    cout << "\t\t\t\t  => Enter your address: ";
    cin >> address;
    
    stores.storeRegisterLinked(username, password, address, name, 0);
    system("cls");
    system("color 0a");
    cout << "\t\t\t\t  Registration Successfull" << endl;
    customerLogin("store");
}
void store(){
    system("color 0a");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t\tEAT NOW -- [Store]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Login" << endl;
        cout << "\t\t\t\t  [2] Register" << endl;
        
        cout << "\t\t\t\t  [0] Exit" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                customerLogin("store");
                break;
            case 2:
                storeRegister();
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y') run = 0;
                break;
        }
    }
}

// customer part

void customerDashboard(){
    system("color 0d");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Customer Dashboard]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Order Food" << endl;
        cout << "\t\t\t\t  [2] My Orders" << endl;
        cout << "\t\t\t\t  [3] My Account " << endl;
        cout << "\t\t\t\t  [4] Display Users " << endl;
        
        cout << "\t\t\t\t  [0] Back" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                stores.showStores();
                char c;
                cin >> c;
            case 4:
                user.displayUser();
                char a;
                cout << "\t\t\t\t  Press any key to go back: ";
                cin >> a;
                // function for show foods
                break;
            case 2:
                // function for show my orders
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y') run = 0;
                break;
        }
    }
}

void customerRegister(){
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [Customer Register]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t  => Enter your username: ";
    cin >> username;
    cout << "\t\t\t\t  => Enter your password: ";
    cin >> password;
    cout << "\t\t\t\t  => Enter your address: ";
    cin >> address;
    
    user.userRegister(username, password, address, 0);
    system("cls");
    system("color 0a");
    cout << "\t\t\t\t  Registration Successfull" << endl;
    customerLogin("customer");
}

void customerLogin(string path){
    string us, pass;
    system("cls");
    system("color 0b");
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- ["<<path<<" Login]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t  => Enter your username: ";
    cin >> us;
    cout << "\t\t\t\t  => Enter your Password: ";
    cin >> pass;
    if(us==username && pass == password){
        if(path=="customer") customerDashboard();
        else storeDashboard();
    }
    else cout << "Something Wrong" << endl;
    
}

void customer(){
    system("color 0a");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t\tEAT NOW -- [Customer]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Login" << endl;
        cout << "\t\t\t\t  [2] Register" << endl;
        
        cout << "\t\t\t\t  [0] Exit" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                customerLogin("customer");
                break;
            case 2:
                customerRegister();
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y') run = 0;
                break;
        }
    }
}

int main(){
    system("color 0a");
    string u, p, a, b,  n;
    ifstream fin("user.txt");
    if(!fin.fail()){
        while(getline(fin, u)){
            getline(fin, p);
            getline(fin, a);
            getline(fin, b);
            getline(fin, n);
            user.userRegister(u, p, a, 1);
        }
    }
    fin.close();
    string owner, storename, pass, add, bal, is;
    ifstream finStore("store.txt");
    if(!finStore.fail()){
        while(getline(finStore, owner)){
            getline(finStore, storename);
            getline(finStore, pass);
            getline(finStore, bal);
            getline(finStore, add);
            getline(finStore, is);
            stores.storeRegisterLinked(storename, pass, add, name, 1);
        }
    }
    finStore.close();
    string stor, foo;
    int pric, stock;
    ifstream finf("food.txt");
    if(!finf.fail()){
        while(finf >> stor){
            finf >> foo;
            finf >> pric;
            finf >> stock;
            foods.addFood(stor, foo, pric, stock, 1);
        }
    }
    finf.close();
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t\tEAT NOW" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Customer" << endl;
        cout << "\t\t\t\t  [2] Store Owner" << endl;
        cout << "\t\t\t\t  [3] Rider" << endl;
        cout << "\t\t\t\t  [4] Administrator" << endl;
        cout << "\t\t\t\t  [0] Exit" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                customer();
                break;
            case 2:
                store();
                break;
            case 3:
                // rider login page
                break;
            case 4:
                
                break;
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y') run = 0;
                break;
        }
    }
}