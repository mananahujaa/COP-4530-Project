#include "string"
#ifndef CakeStore_H
#define CakeStore_H
using namespace std;
class CakeStore
{
private:
    string name;
    string dateOfBirth;
    int zipcode;
    float total;
    bool orderStatus;
    

public:
    CakeStore();                                    // Constructor
    CakeStore(string name, string DOB, int zip);    // Constructor
    string GetName();                               // return name of the user
    bool userAuth(string dateOfBirth, int zip);     // Authenticates the user
    bool GetOrderStatus();                          // returns the status of the order (false -> in-progress, true -> Completed)
    void OrderCompleted();                          // Sets order status as true;
};

#endif