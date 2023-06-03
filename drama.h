#ifndef Drama_h
#define Drama_h

#include "movie.h"

class Drama : public Movie {
public:
  Drama(int stock, const string &director, const string &title, int year)
      : Movie(stock, title, director, year, 'D') {}

  bool operator==(const Movie& other) const  {
    return Type() == other.Type() &&
           Director() == other.Director() &&
           Title() == other.Title() &&
           Year() == other.Year();
  }
  
  bool operator<(const Movie& other) const  {
    if (Director() != other.Director()) {
      return Director() < other.Director();
    }
    if (Title() != other.Title()) {
      return Title() < other.Title();
    }

    return false;
  }

  bool operator>(const Movie& other) const  {
    if (Director() != other.Director()) {
      return Director() > other.Director();
    }
    if (Title() != other.Title()) {
      return Title() > other.Title();
    }
    return false;
  }
};

#endif /* Drama_h */