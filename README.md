Description
A local movie rental store wishes to automate their inventory tracking system. Currently there are three types of movies/videos (in DVD media) to be tracked:

Comedy (denoted as ‘F’ for funny)
Drama (denoted as ‘D’)
Classics (denoted as ‘C’)
Borrows and returns of items by customers are also to be tracked. Four types of actions are desired in the system:

Borrow (denoted as ‘B’): (stock – 1) for each item borrowed  
Return (denoted as ‘R’): (stock + 1) for each item returned
Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
History (denoted as ‘H’): outputs all the transactions of a customer 
 

I designed and implemented a program that initialize the contents of the inventory from a file (data4movies.txt), the customer list from another file (data4customers.txt), and then process an arbitrary sequence of commands from a third file (data4commands.txt).

Details
File formats and file details are as follows:

data4movies.txt:

The information about each movie is listed as follows: 

Comedy: F, Stock, Director, Title, Year it released 
Drama: D, Stock, Director, Title, Year it released
Classics: C, Stock, Director, Title, Major actor Release date
For example,

F, 10, Nora Ephron, You've Got Mail, 1998
D, 10, Steven Spielberg, Schindler's List, 1993
C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
C, 10, George Cukor, Holiday, Cary Grant 9 1938
Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
D, 10, Phillippe De Broca, King of Hearts, 1967

The information about each customer is listed as follows: 

Customer: CustomerID LastName FirstName 

The information about each command is listed as follows:

Inventory I
History H CustomerID
Borrow B CustomerID MediaType MovieType (movie sorting attributes)
Return R CustomerID MediaType MovieType (movie sorting attributes)
For example,

B 1234 D C 9 1938 Katherine Hepburn
B 1234 D F Pirates of the Caribbean, 2003
R 1234 D C 9 1938 Katherine Hepburn
B 1234 D D Steven Spielberg, Schindler's List
I
H 1234
X 1234 Z C 9 1938 Katherine Hepburn
B 1234 D Y 2 1971 Ruth Gordon
B 9999 D F Pirates of the Caribbean, 2003
B 1234 D C 2 1975 Blah Blah     


Design Documentation

UML Class diagram: I Used simple UML notation for class diagrams: arrow for inheritance (is‐a); line with diamond for composition (has‐a or part‐of). Composition (has‐a or part‐of) is a special kind of association. 

Class Interactions: Explanation of how classes interact (Show the program flow, the methods invoked, for standard Use Cases such as insert or borrow.). 

