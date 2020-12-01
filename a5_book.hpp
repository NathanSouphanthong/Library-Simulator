//
//  a5_book.hpp
//  Assignments
//
//  Created by Nathan Souphanthong on 2020-11-19.
//

#ifndef a5_book_hpp
#define a5_book_hpp


#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

class Book{
    string book_title, authors, date_of_publication;
    
public:
    Book(string new_book_title, string new_authors, string new_date_of_publication);
    Book(string new_book_title, string new_authors);
    Book(string new_book_title);
    Book();
    
    
    void print();
    
    //getters and setters
    void set_book_title(string new_book_title);
    string get_book_title();
    
    void set_authors(string new_authors);
    string get_authors();
    
    void set_date_of_publication(string new_date_of_publication);
    string get_date_of_publication();
    
};


#endif /* a5_book_hpp */
