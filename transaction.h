/*
This transaction class the main is responsibil to instantiate the overall information of 
the transcation. 
*/
#ifndef Transaction_h
#define Transaction_h
#include "movie.h"
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Transaction {
  // print aout all information about the transcation 
  friend ostream &operator<<(ostream &out, const Transaction &transaction) {
    out << transaction.action << "ed: " << transaction.movie_title << " by "
       << transaction.movie_director << ", " << transaction.movie_genre << endl;
    return out;
  }
public:
// constractor recive movie genre, title, director and transactionType as parameter 
  Transaction(char genre, string movieTitle, string movieDirector, char transactionType);
private:
// private member 
// movie type 
  string movie_genre;
  // movie title 
  string movie_title;
  // movie director
  string movie_director;
  // transaction type 
  string action;
};

#endif /* Transaction_h */