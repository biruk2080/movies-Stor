/*
This a customer class that store all information about the customer 
such as customer full name, Id, and a methods that operate transcation 
such as borrw,and return movie, print out transcation history and add transcation history mainly .  
it uses a vector data structure to store customer transcation history and movie borrowed. 
*/
#ifndef Customer_h
#define Customer_h
#include "transaction.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
class Customer {
  friend ostream &operator<<(ostream &os, const Customer &c) {
    os << c.getFirstName() << " " << c.getLastName() << " #"
       << c.getCustomerID();
    return os;
  }

public:
// constractor 
  Customer(string firstName, string lastName, int id);
// accept Transaction object as a parameter and add into customer transcation story.
  void addHistory(Transaction *transaction);
  // print out the all transaction hsitories of the customer 
  void outputHistory();
  // getters of last, first name and ID of the customrt 
  string getFirstName() const;
  string getLastName() const;
  int getCustomerID() const;
  //this function determines if the customer is currently borrowing 
//a specific movie based on its genre and index. 
//It returns true if the movie is being borrowed and false otherwise.
  bool currentlyBorrowed(char genre, int index);
  // setter
  // attached the borrwing moies type on the customer borrwed movie list 
  void borrowMovie(char genre, int index);
  // remove the return type of movie from the customer borrwed movie list 
  void returnMovie(char genre, int index);

private:
// private member variable 
// customer ID
  int customerID;
  // customer first name
  string first_name;
  // customer last name 
  string last_name;
  // keep track of the customer transaction history in avecor 
  vector<Transaction *> history;
  // Keep track of the movies currently being borrowed.
  //unorderd_map<pair<int, char>> borrowed; 
  unordered_map<int, char> borrowed; 
};

#endif /* Customer_h */