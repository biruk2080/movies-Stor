# Self-Evaluation

## Name(s): Mesgana Geletu and Biruk Geletu 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 1

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: -1

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: YES

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): YES

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: TODO(student)

invalid movie type: store.cpp createInventory()

invalid customer ID: store.cpp addCustomer();
 
invalid movie: store.cpp createInventory();

factory classes: TODO(student)

hashtable: TODO(student) (explain what the hashtable is used for)

container used for comedy movies: TODO(student)

function for sorting comedy movies: inventory.cpp

function where comedy movies are sorted: inventory.cpp

functions called when retrieving a comedy movie based on title and year: indexOfComedy() inventory.cpp

functions called for retrieving and printing customer history: outputHistory() customer.cpp

container used for customer history: Vector

functions called when borrowing a movie: borrowMovie()

explain borrowing a movie that does not exist: throws error for invalid input 

explain borrowing a movie that has 0 stock: 

explain returning a movie that customer has not checked out: TODO(student)

any static_cast or dynamic_cast used: TODO(student)


Q: Total points: 22 (max 25)