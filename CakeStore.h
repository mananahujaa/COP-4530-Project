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
    CakeStore();
    CakeStore(string name, string DOB, int zip);
    // ~CakeStore();
};

#endif