#include "transaction.h"

Transaction::Transaction(char genre, string movieTitle, string movieDirector,
                         char transactionType) {
  // assign variable
  movie_title = movieTitle;
  movie_director = movieDirector;
  // check the movie type
  if (genre == 'F') {
    movie_genre = "Comedy";
  } else if (genre == 'D') {
    movie_genre = "Drama";
  } else if (genre == 'C') {
    movie_genre = "Classic";
  } else {
    cout << "invalid genre for transaction: " << genre << endl;
  }
  // check the transcation type
  if (transactionType == 'B') {
    action = "borrow";
  } else if (transactionType == 'R') {
    action = "return";
  } else {
    cout << "invalid transaction type for transaction: " << transactionType
         << endl;
  }
}