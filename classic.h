#ifndef Classic_h
#define Classic_h
#include "movie.h"
#include <cassert>

class Classic : public Movie {
public:
  Classic(int stock, string const &director, string const &title,
          const string &majorActorFirstName, const string &majorActorLastName,
          int year, int month)
      : Movie(stock, title, director, year, 'C') {
    this->majorActorFirstName = majorActorFirstName;
    this->majorActorLastName = majorActorLastName;
    this->month = month;
    set_gener("Classic");
  }


  int Month() const { return month; }

  string MajorActorLastName() const { return this->majorActorLastName; }

  string MajorActorFirstName() const { return majorActorFirstName; }


bool operator!=(const Movie& other) const { return !(*this == other); }

bool operator==( const Movie& other) const override {
    const auto* that = dynamic_cast<const Classic*>(&other);
     if (!that) {
      return false;
    }
    return this->Director() == that->Director() &&
           this->Title() == that->Title() &&
           this->Year() == that->Year() &&
           this->month == that->Month() &&
           this->MajorActorFirstName() == that->MajorActorFirstName() &&
           this->MajorActorLastName() == that->MajorActorLastName();
  }

  bool operator<(const Movie& other) const override{
    const auto* that = dynamic_cast<const Classic*>(&other);
    if (!that) {
      return false;
    }
    if (this->Year() != that->Year()) {
      return this->Year() < other.Year();
    }
    if (this->Month() != that->Month()) {
      return this->Month() < that->Month();
    }
    if (this->MajorActorFirstName() != that->MajorActorFirstName()) {
      return this->MajorActorFirstName() < that->MajorActorFirstName();
    }
    if (this->MajorActorLastName() != that->MajorActorLastName()) {
      return this->MajorActorLastName() < that->MajorActorLastName();
    }
    return false;
  }

  bool operator>(const Movie& other) const override {
  
    return !(*this < other) && (*this != other);
  }

private:
  string majorActorFirstName;
  string majorActorLastName;
  int month;
};


#endif /* Classic_h */