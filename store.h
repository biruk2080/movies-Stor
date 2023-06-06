/*
this is Store class of movie object, the main responsibility of this class is 
read the movies inventory, customer information and trnasaction information 
from the file and process accordingly. 
*/
#ifndef Store_h
#define Store_h
#include "customer.h"
#include "hashtable.h"
#include "inventory.h"
#include "movie.h"
#include "transaction.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Store {
public:
  Store();
// read the movies data file and store in the inventory 
//by using Inventory object refaerance and pass the parametrs. 
  void CreateInventory(const string &fileName);
// read the customer data file and store in hashTable
  void AddCustomer(const string &fileName);
// read the transcation data from the file 
  void processTransactions(const string &fileName);

private:
// store the customer obbject 
  HashTable<int, Customer*> customers;
// referance to the inventory object 
  Inventory *movies;
};
#endif /* Store_h */