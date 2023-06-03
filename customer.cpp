#include "customer.h"
#include <algorithm>
using namespace std;

Customer::Customer(string firstName, string lastName, int id) {
  first_name = firstName;
  last_name = lastName;
  customerID = id;
}
// getters of last, first name and ID of the customrt 
int Customer::getCustomerID() const { return customerID; }

string Customer::getFirstName() const { return first_name; }

string Customer::getLastName() const { return last_name; }
// attached the borrwing moies type on the customer borrwed movie list 
void Customer::borrowMovie(char genre, int index) {
  borrowed[index] = genre;
}
// accept Transaction object as a parameter and add into customer transcation story.
void Customer::addHistory(Transaction *transaction) { history.push_back(transaction); }
// print out the all transaction hsitories of the customer 
void Customer::outputHistory() {

  cout << "History transactions for " << getFirstName() << " "
       << getLastName() << " #" << getCustomerID() << ":" << endl;
       // first check whether the customer has transactin history 
       //if not disply History is empty message on consule 
  if (history.empty()) {
    cout << "is empty" << endl;
    return;
  }
  // go through the vector and print out the all 
  //transcation histories of the customer 
  for (auto *transaction : history) {
    cout << *transaction << endl;
  }
}
// remove the return type of movie from the customer borrwed movie list 
void Customer::returnMovie(char genre, int index) {
  // find the specific movie by the key and erase from the map  
  if(borrowed.find(index)!= borrowed.end()){
    borrowed.erase(index);
    return; 
  }
}
  //this function determines if the customer is currently borrowing 
//a specific movie based on its genre and index. 
//It returns true if the movie is being borrowed and false otherwise.
bool Customer::currentlyBorrowed(char genre, int index) {
  return borrowed.find(index)!= borrowed.end();
}