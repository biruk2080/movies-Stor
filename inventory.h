/*
this inventory class that store all inventory of each movies using vector 
the class has methods that manage borrow,return movies and update the stock 
of each movies.  
*/
#ifndef Inventory_h
#define Inventory_h
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "hashtable.h"
#include "movie.h"
#include <utility>
using namespace std;

class Inventory {
  // Prints out all three genres movie shelves.
  friend ostream &operator<<(ostream &out, const Inventory &inventory) {
    out << "Comedy Shelf: " << endl;
    for (auto *comedy : inventory.comedies) {
      out << *comedy << endl;
    }
    out << "Drama Shelf: " << endl;
    for (auto *drama : inventory.dramas) {
      out << *drama << endl;
    }
    out << "Classic Shelf: " << endl;
    for (auto *classic : inventory.classics) {
      out << *classic << endl;
    }
    return out;
  }

public:
  friend class Store;

  bool borrowMovie(const string &type, int index);
// this method recive movie type and index on the inventory vector 
// then update the stock of the movie accordingly 
//display the messgae for invalid type of movie 
  void returnMovie(const string &type, int index);

  // return index of comedy movie in vector.
  int indexOfComedy(const string &title, int releaseYear);

  // return index of drama movie in vector.
  int indexOfDrama(const string &director, const string &title);

  // return index of classic movie in vector.
  int indexOfClassic(const int &releaseMonth, const int &releaseYear,
                     const string &majorActorFirstName,
                     const string &majorActorLastName);
// returen the pointer referance of the comedy movie by 
//checking the movie exist on inventory 
  Comedy *getComedyMovie(const int &index);
// returen the pointer referance of the drama movie by 
//checking the movie exist on inventory 
  Drama *getDramaMovie(const int &index);
  // returen the pointer referance of the classic movie by 
//checking the movie exist on inventory 
  Classic *getClassicMovie(const int &index); 

  void sortShelves();
  //This method is responsible for adding a comedy movie to the inventory.
  void addComedy(int stock, const string &director, const string &title,
                 int releaseYear);
//This method is responsible for adding a drama movie to the inventory.
  void addDrama(int stock, const string &director, const string &title,
                int releaseYear);
//This method is responsible for adding a classic movie to the inventory.
  void addClassic(int stock, const string &director, const string &title,
                  const string &majorActorFirstName,
                  const string &majorActorLastName, int releaseMonth,
                  int releaseYear);

private:
// store inventory of comedy movie 
  vector<Comedy *> comedies;
// store inventory of comedy movie 
  vector<Drama *> dramas;
  // store inventory of classic movie
  vector<Classic *> classics;
  // sort comedy movie by comparing the two movie 
  static bool sortComedy(Comedy *fun1, Comedy *fun2);
  // sort classic movie by comparing the two movie 
  static bool sortDrama(Drama *drama1, Drama *drama2);
  // sort classicy movie by comparing the two movie 
  static bool sortClassic(Classic *clasic1, Classic *clasic2);
};
#endif /* Inventory_h */