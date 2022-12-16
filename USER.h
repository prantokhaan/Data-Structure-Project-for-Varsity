#include<iostream>
#include<fstream>
using namespace std;



class User{
    public:
        string username;
        string password;
        string address;
        int balance;
        int noOfOrder;
        User *next;
    public:
    User(string us, string pass, string ad){
        username = us;
        password = pass;
        address = ad;
        balance = 0;
        noOfOrder = 0;
        next = NULL;
    } 



};

class UserTemplate{
    User *head;
    public:
        void userRegister(string username, string password, string address, int file){
    User *newUser = new User(username, password, address);

    if(head==NULL){
        head = newUser;
        if(file==0){
            ofstream fout;
            fout.open("user.txt", ios::out | ios::app);
            fout << head->username << endl;
            fout << head->password << endl;
            fout << head->address << endl;
            fout << head->balance << endl;
            fout << head->noOfOrder << endl;
            fout.close();
        }
        return;
    }

    User *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newUser;
    if(file==0){
        ofstream fout;
        fout.open("user.txt", ios::out | ios::app);
        fout << temp->next->username << endl;
        fout << temp->next->password << endl;
        fout << temp->next->address << endl;
        fout << temp->next->balance << endl;
        fout << temp->next->noOfOrder << endl;
        fout.close();
    }
}
        void displayUser(){
        User *temp = head;
        while(temp!=NULL){
            cout << temp->username << endl;
            cout << temp->address << endl;
            temp = temp->next;
        }
}
};



