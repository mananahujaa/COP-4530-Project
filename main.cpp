
#include "iostream"
#include "fstream"
#include "CakeStore.h"
#include "bits/stdc++.h"
#include "stdlib.h"


using namespace std;

template<typename T>
class CNode
{
    private:
        T data;
        double price;
        CNode<T>* next;
        template<typename U> friend class LLCart;
    public:
        CNode()
        {
            this->next = NULL;
        }
};

template<typename T> 
class LLCart
{
    private:
        CNode<T>* head;
        int cartSize;
        float total;
    public:
        LLCart()
        {
            this->head = NULL;
            this->cartSize = 0;
            this->total =0;
        }

        void addCake(T prod, double price)
        {
            CNode<T>* cake = new CNode<T>;
            cake->data = prod;
            cake->price = price;
            if(head == NULL)
            {
                head = cake;
                cartSize++;
                cout << "Cake Added to cart!!!" << endl;
                return;
            }

            CNode<T>* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = cake;
            cartSize++;
            //cout << "Cake Added" << endl;
        }

        template<typename id>
        void removeCake(id uid)
        {
            int size = GetCartSize();
            if(head == NULL || size == 0)
            {
                cout << "Cart is empty";
                return;
            }

            if(size == 1 || head->data == uid)
            {
                head = head->next;
                return;
            }
            int counter = 0;
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                
                if(uid == temp->next->data && counter != size)
                {
                    temp->next = temp->next->next;
                    cout << "Cake Removed" << endl;
                    cartSize--;
                    return;
                }else if(uid == temp->data)
                {
                    removeAtEnd();
                    return;
                }
                temp = temp->next;
                counter++;
            }
            
        }

        void DisplayCart()
        {
            CNode<T>* temp = head;
            if(temp == NULL)
            {
                cout << "Cart is Empty" << endl;
            }
            cout << "\n";
            while (temp != NULL)
            {
                cout<< temp->price << " -> ";
                temp = temp->next;
            }
            
        }

        void removeAtEnd()
        {
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                if(temp->next->next == NULL)
                {
                    temp->next = NULL;
                    cout << "Cake Removed" << endl;
                    break;
                }
                temp = temp->next;
            }
            
        }

        int GetCartSize()
        {
            return cartSize;
        }

        void DisplayProducts()
        {
            CNode<T>* temp = head;
            int counter = 1;
            cout << endl << "\t\tHere is our product list" << endl << endl;
            while(temp != NULL)
            {
                cout << "\t\t" << counter << ". " << temp->data << " Cake \t- " << temp->price << "$" << endl;
                temp = temp->next;
                counter++;
            }
        }
};

// This is used to split the data from the txt file(cake data)
vector<string> split(string str, char delimiter) 
{ 
  vector<string> internal; 
  stringstream ss(str); 
  string data; 
 
  while(getline(ss, data, delimiter)) 
  { 
    internal.push_back(data); 
  } 
 
  return internal; 
} 

int main()
{
    string name, dob;
    int zip;
    LLCart<string> CartList;
    LLCart<string> PriceList;

    // Reads Data from the txt file and splits data into PriceList object
    fstream cakeData;
    cakeData.open("cakeData.txt", ios::in);
    if(cakeData.is_open())
    {
        string tp;
        
        while(getline(cakeData,tp))
        {
            vector<string> sep = split(tp,' ');
            double price = ::atof(sep[1].c_str());
            PriceList.addCake(sep[0], price);
        }
    }
    cakeData.close();


    //system("cls");                                      //for windows
    system("clear");                                      //for linux

    system("clear");

    cout << "\t\t\tWelcome to the Cake Shop" << endl;
    cout << "\t\tEnter the details below to start the order!!!" << endl << endl;
    cout << "\t\tName:";
    cin >> name;
    cout << "\n\t\tDate Of Birth:";
    cin >> dob;
    cout << "\n\t\tZipcode:";
    cin >> zip;

    CakeStore store = CakeStore(name,dob,zip);
    PriceList.DisplayProducts();
    while(!store.GetOrderStatus())
    {
         
    }
}