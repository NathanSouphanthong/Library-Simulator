//// *****************************************
//// Student Name: Nathan Souphanthong, Carl Lerdorf
//// Assignment 5
//// a5_main.cpp
////
//// I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
//// This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.
////
//// Project: Library and book using OOP
//// Purpose: Demonstrate understanding of classes and interfaces and simulate a library of books
////
////*********************************************
///*
//Used test_book_insertion() to test insertion by book title, author and
//date of publication or book object. Additionally tested the insertion of a duplicate
//
//Used test_book_removal() to test removal by title, author, and date of publication,
//or just by book object. Additionally tested the removal of a book that didn't exist
//(the name matched, but the author and date where wrong)
//
//Used library_test() to run test_book_insertion() and test_book_removal(), as well as
//test the library constructor that takes in a vector of books. Additionally tested
//the library's print method
//
//book_test() tested all constructors
//1. constructor with title, author, date
//2. constructor with title, author
//3. Constructor with title
//4. Non-paramtric constructor (default)
//
//Through process, getters and setters were also tested as well as
//the print() fun-n which printed all the attrributes of the books
//*/


#include <iostream>
#include "a5_library.hpp"
#include "a5_book.hpp"



using namespace std;

Library lib = Library();

void test_book_insertion(){
  cout << "TESTING BOOK INSERTION" << endl;
  cout << "---------------------------------" << endl;
  lib.insert("All Tomorrow's Parties", "William Gibson", "October 7, 1999");
  lib.insert("Snow Crash", "Neil Stephenson", "June 1992");
  lib.insert("Hitchiker's Guide to the Galaxy", "Douglas Adams", "October 12, 1979");
  lib.insert("Restaurant at the End of the Universe", "Douglas Adams", "October 1980");
  lib.insert("Live, the Universe, and Everything", "Douglas Adams", "1982");
  lib.insert("So Long and Thanks for all the Fish", "Douglas Adams", "1984");
  lib.insert("So Long and Thanks for all the Fish", "Douglas Adams", "1984"); //This should fail
  lib.insert("Mostly Harmless", "Douglas Adams", "1992");
  lib.insert(Book("And Another Thing", "Eoin Colfer", "October 12 2009"));
}

void test_book_removal(){
    cout << "TESTING BOOK REMOVAL" << endl;
  cout << "---------------------------------" << endl;
  lib.remove("Snow Crash", "Neil Stephenson", "June 1992");
  lib.remove(Book("All Tomorrow's Parties", "William Gibson", "October 7, 1999"));
  lib.remove("And Another Thing", "Elon Coffer", "Octuber 21 2090"); //This shouldn't work
}

void library_test(){


  test_book_insertion();
  cout << "TESTING LIBRARY PRINT\n";
  cout << "---------------------------------" << endl;
  lib.print();
  test_book_removal();
  cout << "TESTING LIBRARY PRINT AFTER REMOVALS\n";
  cout << "---------------------------------" << endl;
  lib.print();


  Library lib2 = Library(lib.get_books());
  cout << "TESTING LIBRARY PRINT FROM VECTOR CONSTRUCTOR\n";
  cout << "---------------------------------" << endl;
  lib2.print();
}

//MM/YYYY
void book_test(){
  //testing constructor with title, author, publication
  cout << "TESTING CONSTRUCTOR WITH TITLE, AUTHOR, DATE" << endl;
  cout << "---------------------------------" << endl;
  Book test_book1("testtitle1","testauthor1","testpubdate1");
  test_book1.print();
  cout << endl;

  //testing setters
  cout << "TESTING SETTERS" << endl;
  cout << "---------------------------------" << endl;
  test_book1.set_authors("changed_author");
  test_book1.set_date_of_publication("changed_date_of_pub");
  test_book1.set_book_title("changed_book_title");
  test_book1.print();
  cout << endl;

  //testing constructor with title, authors
    cout << "TESTING CONSTRUCTOR WITH TITLE AND AUTHORS" << endl;
      cout << "---------------------------------" << endl;
  Book test_book2("testtitle2","testauthor2");
   test_book2.print();
   cout << endl;

  // testing consturctor with title
  cout << "TESTING CONSTRUCTOR WITH TITLE" << endl;
    cout << "---------------------------------" << endl;
  Book test_book3("testtitle1");
  test_book3.print();
  cout << endl;

  //testing default constructor (no parameters)
  cout << "TESTING DEFAULT CONSTRUCTOR WITH NO PARAMETERS" << endl;
    cout << "---------------------------------" << endl;
  Book test_book4 = Book();
  test_book4.print();
  cout << endl;

//testing getters
cout << "TESTING GETTERS " << endl;
  cout << "---------------------------------" << endl;
  cout << test_book4.get_book_title() <<endl;
   cout << test_book4.get_authors() <<endl;
   cout << test_book4.get_date_of_publication() <<endl;
   cout << endl;
}

int main(){
  library_test();
  cout << endl;
  book_test();
}
