#include "classic.h"
#include "comedy.h"
#include "customer.h"
#include "drama.h"
#include "hashtable.h"
#include "inventory.h"
#include "movie.h"
#include "store.h"
#include "transaction.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

void testAllMovies() {
  cout << "Start testAlLMovies" << endl;
  // Comedy tests
  Comedy f(10, "Michael Moore", "Fahrenheit 911", 2001);
  Comedy f2(10, "Michael Moore", "Fahrenheit 911", 2001);
  Comedy f3(15, "Moore Michael", "Fahrenheit 451", 1995);
  assert(f.Stock() == 10);
  assert(f.Director() == "Michael Moore");
  assert(f.Title() == "Fahrenheit 911");
  assert(f.Year() == 2001);
  assert(f == f2);
  assert(!(f == f3));
  assert(f > f3);
  assert(f3 < f);
  // Drama tests
  Drama hamilton(3, "Thomas Kail", "Hamilton", 2020);
  Drama d(1, "Steven Caple Jr", "Creed II", 2018);
  d.set_stock(213);
  assert(d.Stock() == 213);
  assert(!(hamilton == d));
  assert(d.Director() == "Steven Caple Jr");
  assert(d.Title() == "Creed II");
  assert(d.Year() == 2018);
  assert(hamilton > d);
  // Classic tests
  Classic c(3, "Toru Hara", "My Neighbor Totoro", "satsuke", "mei", 1993, 5);
  assert(c.Stock() == 3);
  assert(c.Director() == "Toru Hara");
  assert(c.MajorActorFirstName() == "satsuke");
  assert(c.MajorActorLastName() == "mei");
  assert(c.Month() == 5);
  assert(c.Year() == 1993);
  Classic shrek(5, "Andrew Adamson", "Shrek", "Shrek", "the Ogre", 2001, 4);
  assert(!(shrek == c));
  assert(shrek == shrek);
  assert(c < shrek);
  assert(shrek > c);
  cout << "End test" << endl;
}

void testHashTable() {
  cout << "Start testHashTable" << endl;
  HashTable<int, string> h;
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;
  string sone = "one";
  string stwo = "two";
  string sthree = "three";
  string sfour = "four";
  h.put(one, sone);
  h.put(two, stwo);
  h.put(three, sthree);
  h.put(four, sfour);
  assert(h.get(one) == "one");
  assert(h.get(two) == "two");
  assert(h.indexOf(one) == 0);
  h.remove(four);
  assert(h.indexOf(four) == -1);
  h.clear();
  assert(h.isEmpty() == true);
  cout << "End testHashTable" << endl;
}

void testCustomers() {
  cout << "Start testCustomers" << endl;
  Customer *c = new Customer("OLD", "BOOMER", 0000);
  c->Borrow('C', 1);
  assert(c->CustomerID() == 0000);
  assert(c->LastName() == "BOOMER");
  assert(c->FirstName() == "OLD");
  assert(c->currentlyBorrowed('C', 1) == true);
  c->Return('C', 1);
  assert(c->currentlyBorrowed('C', 1) == false);
  cout << "End testCustomers" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store s;
  s.AddCustomer("data4customers.txt");
  s.CreateInventory("data4movies.txt");
  s.processTransactions("data4commands.txt");
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void pisanTest() {
  cout << "Start pisanTest" << endl;
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End pisanTest" << endl;
}
void testAll() {
  testAllMovies();
  testCustomers();
  testHashTable();
  testStoreFinal();
  pisanTest();
}