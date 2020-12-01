//
//  a5_library.hpp
//  Assignment 5
//
//  Created by Nathan Souphanthong, Carl Lerdorf on 2020-11-19.
//

#ifndef a5_library_hpp
#define a5_library_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include "a5_book.hpp"

using namespace std;

class Library {
    vector<Book> books; //the bookshelf

    public:
        Library(vector<Book> books); Library(); //Constructors
        void print();
        bool insert(Book book);
        bool insert(string title, string authors, string publication_date);
        bool remove(Book book);
        bool remove(string title, string authors, string publication_date);
    vector<Book> get_books();

    private:
        bool compare(Book a, Book b);
        int locate(string name);
    int locate(string name, string authors, string publication_date);

        
};

#endif /* a5_library_hpp */
