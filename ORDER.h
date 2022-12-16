#include<iostream>
#include<fstream>
using namespace std;

class Order{
    public:
        string username;
        string address;
        string storeName;
        string foodName;
        string storeApproved;
        string riderAccepted;
        string delivered;
        int amount;
        int price;
        Order *next;
        Order *front;
        Order *rear;

        Order(string us, string ad, string sn, string fn, string sta, string ra, string del, int am, int pr){
            username = us;
            address = ad;
            storeName = sn;
            foodName = fn;
            storeApproved = sta;
            riderAccepted = ra;
            delivered = del;
            amount = am;
            price = pr;
            next = NULL;
            front = NULL;
            rear = NULL;
        }
};

class OrderTemplate{
    Order *head;

    public:
        void newOrder(string us, string ad, string sn, string fn, string sta, string ra, string del, int am, int pr, int file){
            Order *newOrders = new Order(us, ad, sn, fn, sta, ra, del, am, pr);
            if(head==NULL){
                head = newOrders;
                if(file==0){
                ofstream fout;
                    fout.open("order.txt", ios::out | ios::app);
                    fout << head->username << endl;
                    fout << head->address << endl;
                    fout << head->storeName << endl;
                    fout << head->foodName << endl;
                    fout << head->storeApproved << endl;
                    fout << head->riderAccepted << endl;
                    fout << head->delivered << endl;
                    fout << head->amount << endl;
                    fout << head->price << endl;
                    fout.close();
                }
                return;
            }
            Order *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newOrders;
            if(file==0){
                ofstream fout;
                    fout.open("order.txt", ios::out | ios::app);
                    fout << temp->next->username << endl;
                    fout << temp->next->address << endl;
                    fout << temp->next->storeName << endl;
                    fout << temp->next->foodName << endl;
                    fout << temp->next->storeApproved << endl;
                    fout << temp->next->riderAccepted << endl;
                    fout << temp->next->delivered << endl;
                    fout << temp->next->amount << endl;
                    fout << temp->next->price << endl;
                    fout.close();
                }
        }

        void displayMyOrder(string username){
            Order *temp = head;
            if(temp==NULL) return;
            while(temp!=NULL){
                if(temp->username==username){
                    cout << temp->foodName << endl;
                    cout << temp->amount << endl;
                    cout << temp->delivered << endl;
                }
                temp=temp->next;
            }
        }
};