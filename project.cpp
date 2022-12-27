#include<iostream>
#include<fstream>
#include<cctype>
#include<windows.h>
#include"USER.h"
#include"STORES.h"
#include"ORDER.h"
#include"RIDER.h"

using namespace std;



UserTemplate user;
StoresTemplate stores;
FoodsTemplate foods;
OrderTemplate order;
RiderTemplate riders;

//Global Variables
string username, address, password, name, userPhone;
string storeName, storePassword, storeAddress, storeOwnerName;
string riderName, riderPassword, riderAddress, rideBy;
int riderIds, riderSize, riderId;
string adminLogin, adminPass;
int id=1000;

// Function Initialization
void dashboard();
void customer();
void customerLogin(string path);
void customerRegister();
void customerDashboard();
void orderFood();
void store();
void storeRegister();
void storeDashboard();
void storePendingOrders();
void storeAllOrders();
void storeMyAccount();
void storeEditFood();
void storeDeleteFood();
void addFoods();
void rider();
void riderRegister();
void riderDashboard();
void riderPendingOrders();
void riderPickedOrders();
void admin();
void adminDashboard();
void pendingStores();
void adminAllStores();
void pendingRiders();
void adminAllRiders();

// Admin Part
void adminAllRiders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Stores]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;

    riders.showAllRiders();
    int c;
    cout << endl<<"\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c==0) adminDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void pendingRiders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Stores]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;

    riders.showRidersNotApproved();
    char z;
    int opt;
    cout << "\t\t\t-> Press 1 to Approve to approve the First Store: ";
    cin >> opt;
    if(opt==1)riders.approveRider();
    char c;
    cout << endl<<"\t\t\t -> Approve More?(y/n): ";
    cin >> c;
    if(c=='n') adminDashboard();
    else if(c=='y') pendingRiders();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void adminAllStores(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Stores]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;

    stores.showAllStores();
    int c;
    cout << endl<<"\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') adminDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void pendingStores(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Stores]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;

    stores.showStoresNotApproved();
    char z;
    int opt;
    cout << "\t\t\t-> Press 1 to Approve to approve the First Store: ";
    cin >> opt;
    if(opt==1)stores.approveStore(opt);
    char c;
    cout << endl<<"\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') adminDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void adminDashboard(){
    system("color 0e");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Admin Dashboard]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Pending Stores" << endl;
        cout << "\t\t\t\t  [2] All Stores" << endl;
        cout << "\t\t\t\t  [3] Pending Riders" << endl;
        cout << "\t\t\t\t  [4] All Riders" << endl;
        cout << "\t\t\t\t  [5] Add Location" << endl;
        cout << "\t\t\t\t  [6] Delete Location" << endl;
        cout << "\t\t\t\t  [7] Create Voucher" << endl;
        cout << "\t\t\t\t  [8] Edit Voucher" << endl;
        cout << "\t\t\t\t  [9] Delete Voucher" << endl;
        
        cout << "\t\t\t\t  [0] Log Out" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                pendingStores();
                break;
            case 2:
                adminAllStores();
                break;
            case 3:
                pendingRiders();
                break;
            case 4:
                adminAllRiders();
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y'){
                    storeName = "";
                    storePassword = "";
                    dashboard();
                }
                break;
        }
    }
}

void admin(){
    system("color 0a");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t\tEAT NOW -- [ADMIN]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Login" << endl;
        
        cout << "\t\t\t\t  [0] Exit" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                customerLogin("admin");
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

// Rider Part
void riderPickedOrders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Rider Picked Order]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
    order.riderPickedOrder(riderName);
    cout << "\t\t\t\t  --> Press Order Number which have you completed: ";
    int b;
    cin >> b;
    if(b>0){
        order.deliverOrderByRider(b, riderName);
        riders.orderUpdate(riderName);
    }
    char c;
    cout << "\t\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') riderDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void riderPendingOrders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Rider Pending Order]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
    order.riderPendingOrder(riderName);
    cout << "\t\t\t\t  --> Press Order Number to Take the Order: ";
    int b;
    cin >> b;
    if(b>0) order.confirmOrderByRider(b, riderName);
    char c;
    cout << "\t\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') riderDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void riderDashboard(){
    system("color 0e");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Rider Dashboard]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] My Pending Order" << endl;
        cout << "\t\t\t\t  [2] Picked Order" << endl;
        
        cout << "\t\t\t\t  [0] Log Out" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                riderPendingOrders();
                break;
            case 2:
                riderPickedOrders();
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y'){
                    storeName = "";
                    storePassword = "";
                    dashboard();
                }
                break;
        }
    }
}

void riderRegister(){
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [Rider Register]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << "\t\t\t\t  => Enter your name: ";
    fflush(stdin);
    getline(cin, riderName);
    cout << "\t\t\t\t  => Enter your address: ";
    fflush(stdin);
    getline(cin, riderAddress);
    cout << "\t\t\t\t  => Enter your password: ";
    fflush(stdin);
    cin >> riderPassword;
    cout << "\t\t\t\t  => How will you ride? (Bike/Bycycle): ";
    cin >> rideBy;
    
    riders.riderRegistration(riderIds+1000, riderName, riderAddress, riderPassword, rideBy, "no", 0, 0, 0);
    system("cls");
    system("color 0a");
    cout << "\t\t\t\t  Registration Successfull" << endl;
    customerLogin("rider");

}

void rider(){
    system("color 0a");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t\tEAT NOW -- [Rider]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << "\t\t\t\t  [1] Login" << endl;
        cout << "\t\t\t\t  [2] Register" << endl;
        
        cout << "\t\t\t\t  [0] Exit" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                customerLogin("rider");
                break;
            case 2:
                riderRegister();
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

// store owner part
void storeDeleteFood(){
    system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Delete Food]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        cout << endl;
        foods.displayFoodFromShop(storeName);
        cout << "\t\t\t->Which Food you want to delete?: ";
        int choice;
        cin >> choice;
        string selected = foods.selectedFood(choice, storeName);
        int pos = foods.findIndexOfFood(selected, storeName);
        int last = foods.foodCount();
        if(pos==1) foods.deleteHeadFood();
        else if(pos==last) foods.deleteTailFood();
        else foods.deleteFood(pos);
        Sleep(2000);
}

void storeEditFood(){
    system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Edit Food]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    foods.displayFoodFromShop(storeName);
    cout << "\t\t\t->Which Food you want to edit?: ";
    int choice;
    cin >> choice;
    cout << endl;
    cout << "\t\t\t\t1. Edit Name" << endl;
    cout << "\t\t\t\t2. Edit Price" << endl;
    cout << "\t\t\t\t3. Edit Stock" << endl;
    int z;
    cout << "->Enter your choice: ";
    cin >> z;

    if(z==1){
        cout << "\t\t\tEnter New Name: ";
        string newName;
        fflush(stdin);
        getline(cin, newName);
        fflush(stdin);
        string selected = foods.selectedFood(choice, storeName);
        foods.editName(selected, newName, storeName);
        cout << "\t\t-------------Name Updated-----------";
        Sleep(1000);
    }
    else if(z==2){
        cout << "\t\t\tEnter New Price: ";
        int newPrice;
        cin >> newPrice;
        string selected = foods.selectedFood(choice, storeName);
        cout << selected;
        foods.editPrice(selected, newPrice, storeName);
        cout << "\t\t-------------Price Updated-----------";
        Sleep(1000);
    }
    else if(z==3){
        cout << "\t\t\t\tHow many you want to add now?: ";
        int newStock;
        cin >> newStock;
        string selected = foods.selectedFood(choice, storeName);
        foods.updateStock(selected, -newStock, storeName);
        cout << "\t\t--------Stock Updated--------";
        Sleep(1000);
    }
}

void storeMyAccount(){
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [My Account]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    stores.myAccount(storeName);
    cout << endl << "\t\t\t -->Press any key to go back: ";
    char z;
    cin >> z;
}

void storeAllOrders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Store Orders]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
    order.displayStoreAllOrder(storeName);
    
    char c;
    cout << "\t\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') storeDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

void storePendingOrders(){
    system("cls");
    system("color 3e");
    cout << "\t\t\t\t-------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t     EAT NOW -- [Store Pending Orders]" << endl;
    cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
    order.displayStoreOrder(storeName);
    cout << "\t\t\t\t  --> Press Order Number to Confirm Order: ";
    int b;
    cin >> b;
    if(b>0) order.confirmOrderByStore(b, storeName, "pending");
    char c;
    cout << "\t\t\t\t -> Press 0 to go to dashboard: ";
    cin >> c;
    if(c=='0') storeDashboard();
    else{
        cout << "\t\t\t\t --> Wrong Input. Try Again: ";
        cin >> c;
    }
}

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
    fflush(stdin);
    cout << "\t\t\t\t  => Enter Food Name: ";
    getline(cin, food);
    cout << "\t\t\t\t  => Enter Price: ";
    cin >> price;
    cout << "\t\t\t\t  => Enter Stock: ";
    cin >> stock;
    cout << "\t\t\t\t  => Add More? (y/n): ";
    cin >> o;
    foods.addFood(storeName, food, price, stock, 0);
    cout << "\t\t\t\t  Food Added Successfully" << endl;
    if(o=='y' || o=='Y') addFoods();
    else storeDashboard();
}

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
        
        int status = stores.returnApprovalStatus(storeName);
        if(status==1){
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
        }else{
            cout << "\t\t\t\t  Your Store is not Approved" << endl;
            cout << "\t\t\t\t  Please wait until admin approve your store" << endl;
        }
        
        cout << "\t\t\t\t  [0] Log Out" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                storePendingOrders();
                break;
            case 2:
                storeAllOrders();
                break;
            case 3:
                storeMyAccount();
                break;
            case 5:
                addFoods();
                break;
            case 6:
                storeEditFood();
                break;
            case 7:
                storeDeleteFood();
                break;
            case 4:
                system("cls");
                cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\t  FOODS OF " << storeName << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
                foods.displayFoodFromShop(storeName);
                char a;
                cout << "\t\t\t\t  Press any key to go back: ";
                cin >> a;
                // function for show foods
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y'){
                    storeName = "";
                    storePassword = "";
                    dashboard();
                }
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
    cin >> storeOwnerName;
    cout << "\t\t\t\t  => Enter your store name: ";
    fflush(stdin);
    getline(cin, storeName);
    cout << "\t\t\t\t  => Enter your password: ";
    fflush(stdin);
    cin >> storePassword;
    cout << "\t\t\t\t  => Enter your address: ";
    cin >> storeAddress;
    
    stores.storeRegisterLinked(storeName, storePassword, storeAddress, storeOwnerName, 0, 0, 0);
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
void depositMoney(){
    system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  EAT NOW -- [Deposit Money]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    cout << endl;
    int money;
    string pass;
    cout << "\t\t\tHow many you want to deposit?: ";
    cin >> money;
    cout << "\t\t\tEnter your Password: ";
    cin >> pass;

    if(pass==password){
        user.depositMoney(username, money);
        cout << endl << "\t\t\tDeposit Money Successfull" << endl;
        Sleep(3000);
    }else{
        cout << "\t\t\tHow Can I add your money if you give me the wrong Pass? :)" << endl;
        Sleep(3000);
        depositMoney();
    }
}

void userMyAccount(){
    system("color 0c");
    system("cls");
    
    cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t\tEAT NOW -- [My Account]" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
    user.myAccount(username);
    cout << endl << "\t\t\t -->Press any key to go back: ";
    char z;
    cin >> z;
}

void orderFood(){
    system("color 0d");
    int run = 1;
    while(run==1){
        int opt;
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  AVAILABLE STORES" << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl;
        stores.showStores();
        
        cout << "\t\t\t\t  [0] Back" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        string found = stores.searchStoreFood(opt);
        
        system("cls");
        cout << "\t\t\t\t-------------------------------------"<<endl;
        cout << endl;
        cout << "\t\t\t\t  FOOD OF " << found << endl;
        cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
        foods.displayFoodFromShop(found);

        cout << "\t\t\t\t   [0] Back" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        if(opt==0) customerDashboard();
        cout << "\t\t\t\t  -> How many?: ";

        int orderAmount;
        cin >> orderAmount;

        string selected = foods.selectedFood(opt, found);
        int orderPrice = foods.orderFoodPrice(opt, found);

        int price = orderPrice * orderAmount;

        int userBalance = user.updateMoney(username, price);


        if(userBalance>= 0){
            string riderOrder = riders.riderFounder(id++);

        
        
        int upBalance = price - (price/100)*15;
        
        stores.updateStoreBalance(found, upBalance);
        
        int st = foods.updateStock(selected, orderAmount, found);
        cout << userBalance;
        string uAd = user.addressFinder(username);

        if(st>0){
            order.newOrder(username, uAd, found, selected, "no", riderOrder, "pending", orderAmount, price, 0);
            user.updateNoOfOrder(username);
        } 
        
        cout << "Order Placed Successfully" << endl;
        cout << endl << "Press a to go back: ";
        char o;
        cin >> o;
        if(o>='a' && o<='z') customerDashboard();
        }else{
            user.depositMoney(username, price);
            cout << "\t\t\tInsufficient Balance, Please Deposit" << endl;
            Sleep(3000);
            depositMoney();
        }
    }
}

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
        cout << "\t\t\t\t  [4] Deposit Money " << endl;
        
        cout << "\t\t\t\t  [0] Log Out" << endl;
        cout << "\t\t\t\t  -> Enter your choice: ";
        cin >> opt;
        switch(opt){
            case 1:
                orderFood();
                break;
            case 2:
                system("cls");
                system("color 3e");
                cout << "\t\t\t\t-------------------------------------"<<endl;
                cout << endl;
                cout << "\t\t\t\t     EAT NOW -- [My Orders]" << endl;
                cout << endl << "\t\t\t\t--------------------------------------" << endl << endl;
                order.displayMyOrder(username);
                cout << "\t\t\t\t  --> Press any key to go back: ";
                char b;
                cin >> b;
                break;
            case 3:
                userMyAccount();
                break;
            case 4:
                depositMoney();
                // function for show foods
                break;
            case 6:
                // function for show my orders
                break;
            
            case 0:
                char o;
                cout << "\t\t\t\t  -> Are you sure? (y/n): ";
                cin >> o;
                if(o=='y'){
                    username = "";
                    password ="";
                    address = "";
                    dashboard();
                };
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
    fflush(stdin);
    cout << "\t\t\t\t  => Enter your username: ";
    getline(cin, username);
    fflush(stdin);
    int dupChk = user.duplicateUserCheck(username);
    if(dupChk==0){
        cout << "username already exists" << endl;
        cout << "Try Again Please." << endl;
        Sleep(2000);
        customerRegister();
    }
    cout << "\t\t\t\t  => Enter your password: ";
    cin >> password;
    cout << "\t\t\t\t  => Enter your address: ";
    cin >> address;
    
    user.userRegister(username, password, address, 0, 0, 0);
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
    fflush(stdin);
    cout << "\t\t\t\t  => Enter your username: ";
    getline(cin, us);
    fflush(stdin);
    cout << "\t\t\t\t  => Enter your Password: ";
    cin >> pass;
    if(path=="customer"){
        int check = user.userLogin(us, pass);
        if(check==1){
            username = us;
            password = pass;
            customerDashboard();
        }
        else{
            cout << "\t\t\t\tMaybe, You are So much HUNGRY!!" << endl;
            cout << "\t\t\t\tCool down and Login then you can order food anytime" << endl;
            Sleep(2000);
            customerLogin("customer");
        };
    }
    else if(path=="store"){
        int check = stores.storeLogin(us, pass);
        if(check==1){
            storeName = us;
            storePassword = pass;
            storeDashboard();
        }
        else{
            cout << "\t\t\t\tHey, Your store is on Profit. Don't panic!!" << endl;
            cout << "\t\t\t\tCool down and Login" << endl;
            Sleep(2000);
            customerLogin("store");
        }
    }
    else if(path=="rider"){
        int check = riders.riderLogin(us, pass);
        if(check==1){
            riderName = us;
            riderPassword = pass;
            riderDashboard();
        }else{
            cout << "\t\t\t\tHey, What's up? So busy with deliveries?" << endl;
            cout << "\t\t\t\tTake Rest and Login Later" << endl;
            Sleep(2000);
            customerLogin("rider");
        }
    }
    else if(path=="admin"){
        if(us==adminLogin && pass==adminPass){
            adminDashboard();
        }else{
            cout << "\t\t\t\tThis area is full of ghostes :D," << endl;
            cout << "\t\t\t\tCome with Proper Assets :)" << endl;
            Sleep(2000);
            customerLogin("admin");
        }
    }
    
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

void dashboard(){
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
                rider();
                break;
            case 4:
                customerLogin("admin");
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
    //user
    string u, p, a, b,  n, phone;
    int bala, nof;
    ifstream fin("user.txt");
    if(!fin.fail()){
        while(getline(fin, u)){
            getline(fin, p);
            getline(fin, a);
            getline(fin, b);
            getline(fin, n);
            bala = stoi(b);
            nof = stoi(n);
            user.userRegister(u, p, a, bala, nof, 1);
        }
    }
    fin.close();
    //store owner
    string owner, storename, pass, add, bal, is;
    int sbalance, isap;
    ifstream finStore("store.txt");
    if(!finStore.fail()){
        while(getline(finStore, owner)){
            getline(finStore, storename);
            getline(finStore, pass);
            getline(finStore, bal);
            getline(finStore, add);
            getline(finStore, is);
            sbalance = stoi(bal);
            isap = stoi(is);
            stores.storeRegisterLinked(storename, pass, add, owner, sbalance, isap, 1);
        }
    }
    finStore.close();
    //food
    string stor, foo, pr, st;
    int pric, stock;
    ifstream finf("food.txt");
    if(!finf.fail()){
        while(getline(finf,stor)){
            getline(finf, foo);
            getline(finf, pr);
            getline(finf, st);
            pric = stoi(pr);
            stock = stoi(st);
            foods.addFood(stor, foo, pric, stock, 1);
        }
    }
    finf.close();
    //orders
    string orderUser, orderAddress, orderStore, orderFood, orderStoreApprove, orderRider, orderDeli, orderAmount, orderPrice;
    ifstream orders("order.txt");
    if(!orders.fail()){
        while(getline(orders, orderUser)){
            getline(orders, orderAddress);
            getline(orders, orderStore);
            getline(orders, orderFood);
            getline(orders, orderStoreApprove);
            getline(orders, orderRider);
            getline(orders, orderDeli);
            getline(orders, orderAmount);
            getline(orders, orderPrice);
            int a = stoi(orderAmount);
            int b = stoi(orderPrice);
            order.newOrder(orderUser, orderAddress, orderStore, orderFood, orderStoreApprove, orderRider, orderDeli, a, b, 1);
        }
    }
    orders.close();

    string riderName, riderAddress, riderPassword, rideyBy, riderApproved;
    int riderBalance, orderCompleted;
    ifstream rider("rider.txt");
    if(!rider.fail()){
        while(rider>>riderId){
            rider>>riderName;
            rider>>riderAddress;
            rider>>riderPassword;
            rider>>rideBy;
            rider>>riderApproved;
            rider>>riderBalance;
            rider>>orderCompleted;
            riders.riderRegistration(riderId, riderName, riderAddress, riderPassword, rideBy, riderApproved, riderBalance, orderCompleted, 1);
            
        }
    }
    rider.close();

    ifstream adminFile("admin.txt");
    if(!adminFile.fail()){
        while(getline(adminFile, adminLogin)){
            getline(adminFile, adminPass);
        }
    }


    

    dashboard();
}