#include "iostream"
#include "string"
#include "CakeStore.h"

using namespace std;

CakeStore::CakeStore()
{
    this->name = "";
    this->dateOfBirth = "";
    this->zipcode = 0;
    this->orderStatus = false;
    this->total = 0.0;
}


CakeStore::CakeStore(string name, string DOB, int zip)
{
    this->name = name;
    this->dateOfBirth = DOB;
    this->zipcode = zip;
    this->orderStatus = false;
    this->total = 0;
}

string CakeStore::GetName()
{
    return this->name;
}

void CakeStore::print()
{
    cout << this->name;
}

bool CakeStore::GetOrderStatus()
{
    return this->orderStatus;
}

void CakeStore::OrderCompleted()
{
    this->orderStatus = true;
}
