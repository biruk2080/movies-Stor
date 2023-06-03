#include "inventory.h"
#include <algorithm>
using namespace std;
#include <iostream>
void Inventory::addComedy(int stock, const string &director, const string &title, int releaseYear) {
  // get the index of the movie by calling indexOfComedy method 
  int index = indexOfComedy(title, releaseYear);
  // check the movie is existed 
  if(index > -1){
    auto *movie = getComedyMovie(index);
    // update movie stock
    movie->set_stock(stock + movie->Stock());                         
   return;
  }
  // if the movie is new, add into the comedy movie list 
  auto *fun = new Comedy(stock, director, title, releaseYear);
  comedies.push_back(fun);
}
//This method is responsible for adding a drama movie to the inventory.
void Inventory::addDrama(int stock, const string &director, const string &title, int releaseYear) {
// get the index of the movie by calling indexOfDrama method 
  int index = indexOfDrama(director,title);
  // check the movie is existed 
  if(index > -1){
    auto *movie = getDramaMovie(index);
    // update movie stock
    movie->set_stock(stock + movie->Stock());                         
   return;
  }
  
   // if the movie is new, add into the movie inventory  
   auto *drama = new Drama(stock, director, title, releaseYear);
  dramas.push_back(drama);
}
//This method is responsible for adding a classic movie to the inventory.
void Inventory::addClassic(int stock, const string &director,
                           const string &title,
                           const string &majorActorFirstName,
                           const string &majorActorLastName, int releaseMonth,
                           int releaseYear) {
  // get the index of the movie by calling indexOfClassic method                           
  int index = indexOfClassic(releaseMonth,releaseYear,majorActorFirstName,majorActorLastName);
  if(index > -1){
    // update movie stock
    auto *movie = getClassicMovie(index);
    movie->set_stock(stock + movie->Stock());                         
   return;
  }
  // if the movie is new, add into the movie inventory 
  auto *classic = new Classic(stock, director, title, majorActorFirstName,
                        majorActorLastName, releaseYear, releaseMonth);
  classics.push_back(classic);
}
// this method recive movie type and index on the inventory vector 
// then update the stock of the movie accordingly by checking genrer type 
//display the messgae for invalid type of movie 
bool Inventory::borrowMovie(const string &type, int index) {
  // check the movie gener 
  if (type == "F") {
    // get the stock of the movie 
    int stock = comedies[index]->Stock();
    // check to make sure there is avialbale stock to rent 
    if (stock - 1 < 0) {
      cout << "Out of stock " << comedies[index]->Title() << endl;
      return false;
    }
    // decrease the stock and increase the number of borrow movie
    comedies[index]->set_stock(stock - 1);
    comedies[index]->set_borrowed(comedies[index]->Borrowed() + 1);
    return true;
  }
  // check the movie gener 
  if (type == "D") {
    // get the stock of the movie 
    int stock = dramas[index]->Stock();
    // check to make sure there is avialbale stock to rent 
    if (stock - 1 < 0) {
      cout << "Out of stock " << dramas[index]->Title()
           << endl;
      return false;
    }
    // decrease the stock and increase the number of borrow movie
    dramas[index]->set_stock(stock - 1);
    dramas[index]->set_borrowed(dramas[index]->Borrowed() + 1);
    return true;
  }
  // check the movie gener
  if (type == "C") {
    // get the stock of the movie 
    int stock = classics[index]->Stock();
    // check to make sure there is avialbale stock to rent 
    if (stock - 1 < 0) {
      cout << "Out of stock " << classics[index]->Title()
           << endl;
      return false;
    }
    // decrease the stock and increase the number of borrow movie
    classics[index]->set_stock(stock - 1);
    classics[index]->set_borrowed(classics[index]->Borrowed() + 1);
    return true;
  }
// display the messgae for invalid type of movie 
  cout << "Invalid Type: " << type << endl;
  return false;
}
// this method recive movie type and index on the inventory vector 
// then update the stock of the movie accordingly 
//display the messgae for invalid type of movie 
void Inventory::returnMovie(const string &type, int index) {
  // check the movie gener
  if (type == "F") {
    // get the stock of the movie 
    int stock = comedies[index]->Stock();
     // increase the stock and decrease the number of borrow movie
    comedies[index]->set_stock(stock + 1);
    comedies[index]->set_borrowed(comedies[index]->Borrowed() - 1);
  } else if (type == "D") {
    // get the stock of the movie 
    int stock = dramas[index]->Stock();
      // increase the stock and decrease the number of borrow movie
    dramas[index]->set_stock(stock + 1);
    dramas[index]->set_borrowed(dramas[index]->Borrowed() - 1);
  } else if (type == "C") {
    // get the stock of the movie 
    int stock = classics[index]->Stock();
    // increase the stock and decrease the number of borrow movie
    classics[index]->set_stock(stock + 1);
    classics[index]->set_borrowed(classics[index]->Borrowed() - 1);
  } else {
    // display the messgae for invalid type of movie 
    cout << "Invalid Type: " << type << endl;
  }
}
// return index of comedy movie in vector.
int Inventory::indexOfComedy(const string &title, int releaseYear) {
  for (int i = 0; i < comedies.size(); i++) {
    // check the the movie is exist, if it's return the index
    if (comedies[i]->Title() == title &&
        comedies[i]->Year() == releaseYear) {
      return i;
    }
  }
  // Not found
  return -1; 
}

// Index of drama movie in vector.
int Inventory::indexOfDrama(const string &director, const string &title) {
  for (int i = 0; i < dramas.size(); i++) {
    if (dramas[i]->Director() == director &&
        dramas[i]->Title() == title) {
      return i;
    }
  }
  // Not found
  return -1; 
}
// return index of classic movie in vector.
int Inventory::indexOfClassic(const int &releaseMonth, const int &releaseYear,
                              const string &majorActorFirstName,
                              const string &majorActorLastName) {
  for (int i = 0; i < classics.size(); i++) {
    if (classics[i]->MajorActorFirstName() == majorActorFirstName &&
        classics[i]->MajorActorLastName() == majorActorLastName &&
        classics[i]->Month() == releaseMonth &&
        classics[i]->Year() == releaseYear) {
      return i;
    }
  }
  // Not found.
  return -1; 
}
// returen the pointer referance of the classic movie by 
//checking the movie exist on inventory 
Comedy *Inventory::getComedyMovie(const int &index) {
  if ( index < 0 || index > comedies.size()) {
    cout << "Invalid Index: " << index << endl;
    return nullptr;
  }
  return comedies[index];
}
// returen the pointer referance of the classic movie by 
//checking the movie exist on inventory 
Drama *Inventory::getDramaMovie(const int &index) {
  if (index < 0 || index > dramas.size() ) {
    cout << "Invalid Index: " << index << endl;
    return nullptr;
  }
  return dramas[index];
}
// returen the pointer referance of the classic movie by 
//checking the movie exist on inventory 
Classic *Inventory::getClassicMovie(const int &index) {
  if ( index < 0 || index > classics.size()) {
    cout << "Invalid Index: " << index << endl;
    return nullptr;
  }
  return classics[index];
}
  // sort comeddy movie by comparing the two movie and return bool
bool Inventory::sortComedy(Comedy *fun1, Comedy *fun2) { return (fun1<fun2); }
  // sort drama movie by comparing the two movie 
bool Inventory::sortDrama(Drama *drama1, Drama *drama2) { return (drama1 < drama2); }
  // sort classic movie by comparing the two movie 
bool Inventory::sortClassic(Classic *clasic1, Classic *clasic2) {
  return (clasic1 < clasic2);
}
void Inventory::sortShelves() {
  sort(comedies.begin(), comedies.end(), sortComedy);
  sort(dramas.begin(), dramas.end(), sortDrama);
  sort(classics.begin(), classics.end(), sortClassic);
}