#ifndef Comedy_h
#define Comedy_h

#include "movie.h"

class Comedy : public Movie {
public:
  Comedy(int stock, const string &director, const string &title, int year)
      : Movie(stock, title, director, year, 'F') { set_gener("Comedy"); }


  bool operator!=(const Movie& other) const { return !(*this == other); }

  bool operator==(const Movie& other) const override  {
    return Type() == other.Type() &&
           Director() == other.Director() &&
           Title() == other.Title() &&
           Year() == other.Year();
  }
  bool operator<(const Movie& other) const override {

    if (Title() != other.Title()) {
      return Title() < other.Title();
    }
  
    if (Year() != other.Year()) {
      return Year() < other.Year();
    }
    return false;
  }

  bool operator>(const Movie& other) const override{
    
    return !(*this < other) && (*this != other);
  }
};
#endif /* Comedy_h */