#include "store.h"

Store::Store() { movies = new Inventory(); }

void Store::CreateInventory(const string &fileName) {
  ifstream inFile(fileName);
  if (!inFile.is_open()) {
    cerr << "File not found: " << fileName << endl;
    return;
  }
  string line;
  while (getline(inFile, line) && !line.empty()) {
    istringstream parser(line);

    string genre;
    string director;
    string title;
    int stock = 0;
    int year = 0;
    int releaseMonth = 0;
    int releaseYear = 0;
    string majorActorFirstName;
    string majorActorLastName;

    getline(parser, genre, ',');
    if (!genre.empty() && genre[0] == ' ') {
      genre = genre.substr(1);
    }
    parser >> stock >> director >> title;

    if (genre == "F" || genre == "D") {
      parser >> year;
      if (genre == "F") {
        movies->addComedy(stock, director, title, year);
      } else if (genre == "D") {
        movies->addDrama(stock, director, title, year);
      }
    } else if (genre == "C") {
      parser >> majorActorFirstName >> majorActorLastName >> releaseMonth >>
          releaseYear;
      movies->addClassic(stock, director, title, majorActorFirstName,
                         majorActorLastName, releaseMonth, releaseYear);
    } else {
      cerr << "Invalid Movie Type found: " << genre << endl;
    }
  }

  movies->sortShelves();
  inFile.close();
}

void Store::AddCustomer(const string &fileName) {
  ifstream inFile(fileName);
  if (!inFile) {
    cerr << "File not found: " << fileName << endl;
    return;
  }
  string line;
  while (getline(inFile, line)) {
    istringstream iss(line);
    int customerID;
    string firstName;
    string lastName;
    Customer *newCustomer = new Customer(firstName, lastName, customerID);
    if (iss >> customerID >> firstName >> lastName) {
      if (customerID >= 1000 && customerID <= 9999 &&
          customers.indexOf(customerID) == -1) {
        customers.put(customerID, newCustomer);
      } else {
        cerr << "Invalid customer ID: " << customerID << endl;
      }
    } else {
      cerr << "Invalid input: " << line << endl;
    }
  }

  inFile.close();
}

void Store::processTransactions(const string &fileName) {
  ifstream inFile(fileName);
  string line;
  if (!inFile) {
    cerr << "File not found" << endl;
  }

  while (!inFile.eof()) {
    getline(inFile, line);
    if (line.empty()) {
      break;
    }

    istringstream parse(line);
    string command;
    parse >> command;

    if (command == "B") {
      string iDasString;
      string media;
      string genre;
      parse >> iDasString;
      parse >> media;
      int customerID = stoi(iDasString);
      if (media == "D") {
        parse >> genre;
        if (genre == "F") {
          int year;
          string title;
          string currToken;
          vector<string> tokens;
          while (getline(parse, currToken, ',')) {
            if (currToken[0] == ' ') {
              currToken.erase(0, 1);
            }
            tokens.push_back(currToken);
          }
          title = tokens[0];
          year = stoi(tokens[1]);
          int index = movies->indexOfComedy(title, year);
          if (index == -1) {
            cerr << "Comedy Movie not found: " << title << " " << year << endl;
          } else {
            if (customers.indexOf(customerID) != -1) {
              bool borrowed = movies->borrowMovie(genre, index);
              if (borrowed) { 
                              
                const auto *c = movies->getComedyMovie(index);
                Transaction *t =
                    new Transaction('F', c->Title(), c->Director(), 'B');
                customers.get(customerID)->Borrow('F', index);
                customers.get(customerID)
                    ->addHistory(t); 
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else if (genre == "D") { 
          string director;
          string title;
          string currToken;
          vector<string> tokens;
          while (getline(parse, currToken, ',')) {
            if (currToken[0] == ' ') {
              currToken.erase(0, 1); 
            }
            tokens.push_back(currToken);
          }
          director = tokens[0];
          title = tokens[1];
          int index = movies->indexOfDrama(director, title);
          if (index == -1) {
            cerr << "Drama Movie not found: " << director << " " << title
                 << endl;
          } else {
            if (customers.indexOf(customerID) != -1) {
              bool borrowed = movies->borrowMovie(genre, index);
              if (borrowed) { 
                             
                const auto *d = movies->getDramaMovie(index);
                Transaction *t =
                    new Transaction('D', d->Title(), d->Director(), 'B');
                customers.get(customerID)->Borrow('D', index);
                customers.get(customerID)
                    ->addHistory(t); 
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else if (genre == "C") { 
          string majorActorFirstName;
          string majorActorLastName;
          int month;
          int year;
          parse >> month >> year;
          parse >> majorActorFirstName >> majorActorLastName;
          int index = movies->indexOfClassic(month, year, majorActorFirstName,
                                             majorActorLastName);
          if (index == -1) {
            cerr << "Classic Movie not found: " << month << " " << year << " "
                 << majorActorFirstName << " " << majorActorLastName << endl;
          } else {
            if (customers.indexOf(customerID) != -1) {
              bool borrowed = movies->borrowMovie(genre, index);
              if (borrowed) { 
                              
                const auto *c = movies->getClassicMovie(index);
                Transaction *t =
                    new Transaction('C', c->Title(), c->Director(), 'B');
                customers.get(customerID)->Borrow('C', index);
                customers.get(customerID)
                    ->addHistory(t); 
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else {
          cerr << "Invalid genre: " << genre << endl;
        }
      } else {
        cerr << "Invalid media type: " << media << endl;
      }
    } else if (command == "H") {
      int customerID;
      parse >> customerID;
      customers.get(customerID)->outputHistory();
      cout << endl;
    } else if (command == "I") {
      cout << *movies << endl;
    } else if (command == "R") {
      string iDasString;
      string media;
      string genre;
      parse >> iDasString;
      parse >> media;
      int customerID = stoi(iDasString);
      if (media == "D") { 
        parse >> genre;
        if (genre == "F") { 
          int year;
          string title;
          string currToken;
          vector<string> tokens;
          while (getline(parse, currToken, ',')) {
            if (currToken[0] == ' ') {
              currToken.erase(0, 1); 
            }
            tokens.push_back(currToken);
          }
          title = tokens[0];
          year = stoi(tokens[1]);
          int index = movies->indexOfComedy(title, year);
          if (index == -1) {
            cerr << "Comedy Movie not found: " << title << " " << year << endl;
          } else {
            const auto *c = movies->getComedyMovie(index);
            if (customers.indexOf(customerID) != -1) {
              if (customers.get(customerID)->currentlyBorrowed('F', index)) {
                movies->returnMovie(genre, index);
                Transaction *t =
                    new Transaction('F', c->Title(), c->Director(), 'R');
                customers.get(customerID)->Return('F', index);
                customers.get(customerID)
                    ->addHistory(t);
              } else {
                cerr << customers.get(customerID)->FirstName() << " "
                     << customers.get(customerID)->LastName()
                     << " tried to return a comedy movie they never borrowed: "
                     << c->Title() << "by " << c->Director() << endl;
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else if (genre == "D") { 
          string director;
          string title;
          string currToken;
          vector<string> tokens;
          while (getline(parse, currToken, ',')) {
            if (currToken[0] == ' ') {
              currToken.erase(0, 1);
            }
            tokens.push_back(currToken);
          }
          director = tokens[0];
          title = tokens[1];
          int index = movies->indexOfDrama(director, title);
          if (index == -1) {
            cerr << "Drama Movie not found: " << director << " " << title
                 << endl;
          } else {
            const auto *d = movies->getDramaMovie(index);
            if (customers.indexOf(customerID) != -1) {
              if (customers.get(customerID)->currentlyBorrowed('D', index)) {
                movies->returnMovie(genre, index);
                Transaction *t =
                    new Transaction('D', d->Title(), d->Director(), 'R');
                customers.get(customerID)->Return('D', index);
                customers.get(customerID)
                    ->addHistory(t); 
              } else {
                cerr << customers.get(customerID)->FirstName() << " "
                     << customers.get(customerID)->LastName()
                     << " tried to return a drama movie they never borrowed: "
                     << d->Title() << "by " << d->Director() << endl;
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else if (genre == "C") { 
          string majorActorFirstName;
          string majorActorLastName;
          int month;
          int year;
          parse >> month >> year;
          parse >> majorActorFirstName >> majorActorLastName;
          int index = movies->indexOfClassic(month, year, majorActorFirstName,
                                             majorActorLastName);
          if (index == -1) {
            cerr << "Classic Movie not found: " << month << " " << year << " "
                 << majorActorFirstName << " " << majorActorLastName << endl;
          } else {
            const auto *c = movies->getClassicMovie(index);
            if (customers.indexOf(customerID) != -1) {
              if (customers.get(customerID)->currentlyBorrowed('C', index)) {
                movies->returnMovie(genre, index);
                Transaction *t =
                    new Transaction('C', c->Title(), c->Director(), 'R');
                customers.get(customerID)->Return('D', index);
                customers.get(customerID)
                    ->addHistory(t); 
              } else {
                cerr << customers.get(customerID)->FirstName() << " "
                     << customers.get(customerID)->LastName()
                     << " tried to return a classic movie they never borrowed: "
                     << c->Title() << "by " << c->Director() << endl;
              }
            } else {
              cerr << "Customer not found : " << customerID << endl;
            }
          }
        } else {
          cerr << "Invalid movie type " << genre << endl;
        }
      } else {
        cerr << "Invalid media type: " << media << endl;
      }
    } else {
      cerr << "Invalid command:  " << command << endl;
    }
  }
}