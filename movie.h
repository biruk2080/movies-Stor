#ifndef Movie_h
#define Movie_h

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Movie {

  // Output stream to print out movies 
  friend ostream &operator<<(ostream &out, const Movie &other) {

    out << "Genre/Title: " <<other.gener<<", " + other.title
       << ", Director: " << other.director
       << ", Released: " << other.year << ", Stock: " << other.stock
       << " Currently being borrowed: " << other.Borrowed();
    return out;
  }

public:
  Movie(int stock, const string &title, const string &director, int year,
        char type) {
    this->stock = stock;
    this->title = title;
    this->director = director;
    this->borrowed = 0;
    this->year = year;
    this->type = type;
  }

  // Setters 

  void set_title(const string &title) { this->title = title; }

  void set_year(int year) { this->year = year; }

  void set_stock(int stock) { this->stock = stock; }

  void set_director(const string &director) { this->director = director; }

  void set_borrowed(int isBorrowed) { this->borrowed = isBorrowed; }

  void set_gener(string gener) { this-> gener = gener; };

  // Getters 

  string Title() const { return title; } 

  int Year() const { return year; }

  int Stock() const { return stock; }

  int Borrowed() const { return borrowed; }

  char Type() const { return type; }

  string Director() const { return director; }

  string Gener() const { return gener; };

  // operator overloads 

  virtual bool operator!=(const Movie& other) const = 0;

  virtual bool operator==(const Movie& other) const = 0;

  virtual bool operator<(const Movie& other) const = 0;

  virtual bool operator>(const Movie& other) const = 0;


private:
  string title;
  int stock;
  char type;
  int year;
  string director;
  int borrowed;
  string gener;
};

#endif /* Movie_h */