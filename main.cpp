
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
                cout << "\n\t\tCake Added to cart!!!" << endl;
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
                cartSize--;
                return;
            }
            int counter = 0;
            CNode<T>* temp = head;
            while (temp != NULL)
            {
                
                if(uid == temp->next->data && counter != size)
                {
                    temp->next = temp->next->next;
                    cout << "\t\tCake Removed" << endl;
                    cartSize--;
                    return;
                }else if(uid == temp->data)
                {
                    removeAtEnd();
                    cartSize--;
                    return;
                }
                temp = temp->next;
                counter++;
            }
            
        }

        void DisplayCart()
        {
            CNode<T>* temp = head;
            int counter = 1;
            if(temp == NULL)
            {
                cout << "Cart is Empty" << endl;
                return;
            }
            cout << "\n";
            cout << " Cart: " << endl;
            while (temp != NULL)
            {
                cout << " " << counter << ". " << temp->data << " Cake \t- " << temp->price << "$" << endl;
                temp = temp->next;
                counter++;
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
            cout << endl << "\nHere is our product list" << endl << endl;
            while(temp != NULL)
            {
                cout << " " << counter << ". " << temp->data << " Cake \t- " << temp->price << "$" << endl;
                temp = temp->next;
                counter++;
            }
        }

        double getCakePrice(string cakeName)
        {
            CNode<T>* temp = head;
            while(temp != NULL)
            {
                if(temp->data == cakeName)
                {
                    return temp->price;
                }
                temp = temp->next;
            }

            return 0;
        }

        double SetCartTotal()
        {
            double totalCost = 0;
            CNode<T>* temp = head;
            while(temp != NULL)
            {
                totalCost += temp->price;
                temp = temp->next;
            }
            this->total = totalCost;
            return this->total;
        }
};

// This is used to split the data from the txt file(cake data)
vector<string> split(string str, char delimiter) 
{ 
  vector<string> strr; 
  stringstream ss(str); 
  string data; 
 
  while(getline(ss, data, delimiter)) 
  { 
    strr.push_back(data); 
  } 
 
  return strr; 
} 

void pause()
{   
    string dummy;
    cout << "\n\nEnter C to continue!!!";
    cin >> dummy;
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


    string cakeName,dummy,dobauth;
    double cakePrice = 0,cartTotal =0;
    int ctr = 0,zipauth;
    char p;
    while(!store.GetOrderStatus())
    {   
        cout <<"\n\n";
        system("clear");
        system("clear");
        cout << "Welcome, " << store.GetName() << endl << "Cart: " << CartList.GetCartSize() << endl << endl;

        cout << "Menu\n 1. Add Cake\n 2. Remove Cake\n 3. Display Cart\n 4. Send Order \n 5. Cancel Order \n " << endl;
        cout << "\nSelection: ";
        cin >> ctr;
        switch (ctr)
        {
            case 1:
                PriceList.DisplayProducts();
                cout << "\n Enter Cake you want to purchase (eq :Vanilla): ";
                cin >> cakeName;
                cakePrice = PriceList.getCakePrice(cakeName);
                if(cakePrice <= 0)
                {
                    cout << " " << cakeName <<" does not exist!!!\n Please Try again";
                    pause();
                    break;
                }
                CartList.addCake(cakeName,PriceList.getCakePrice(cakeName));
                pause();
                break;
            case 2:
                CartList.DisplayCart();
                if(CartList.GetCartSize() == 0)
                {
                    pause();
                    break;
                }
                cout << "Enter name of cake to remove: ";
                cin >> cakeName;
                CartList.removeCake(cakeName);
                pause();
                break;
            case 3:
                CartList.DisplayCart();
                pause();
                break;
            case 4:
                if(CartList.GetCartSize() == 0)
                {
                    cout<<"\nEmpty Cart, Add Cakes to the Cart";
                    pause();
                    break;
                }
                cout << "Inorder to complete the order please enter the following information used while creating account.\n";
                cout << "Date Of Birth: ";
                cin >> dobauth;
                cout << "Zipcode: ";
                cin >> zipauth;
                if(store.userAuth(dobauth,zipauth))
                {
                    cout << "User Authenticated\n Calculating Bill Order..........";
                    cartTotal = CartList.SetCartTotal();
                    CartList.DisplayCart();
                    cout << " Total: " << cartTotal << "$";
                    cout <<"\n Would you like to proceed?(y/n): ";
                    cin >> p;
                    if(p == 'y' || p == 'Y')
                    {
                        system("clear");
                        cout << "\n\n Order Sent........";
                        store.OrderCompleted();
                    }
                    else
                    {
                        cout << "\n\n Exiting............";
                        pause();
                        break;
                    }
                }
                else
                {
                    cout << "Invalid Credentials, try again!!!";
                    pause();
                    break;
                }
                pause();
                cout << "\n\n Enjoy Your Cakes ;)\n\n\n";
                break;
            case 5:
                cout << "\n\n We hate to see you go :(\n But if you ever need cakes you know where to find us !!!!\n GoodBye for now !!!";
                store.OrderCompleted();
                pause();
                break;
            default:
                break;
        }
    }
}