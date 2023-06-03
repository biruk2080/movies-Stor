#ifndef Store_h
#define Store_h

#include "customer.h"
#include "hashtable.h"
#include "inventory.h"
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Store {
public:
  Store();

  void fillInventory(const string &fileName);
  void fillStoreWithCustomers(const string &fileName);
  void processTransactions(const string &fileName);

private:
  HashTable<int, Customer *> customers;
  Inventory *movies;
};
#endif /* Store_h */