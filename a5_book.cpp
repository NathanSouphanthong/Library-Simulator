//
//  a5_book.cpp
//  Assignments
//
//  Created by Nathan Souphanthong on 2020-11-19.
//

#include <iostream>
#include "a5_book.hpp"
using namespace std;

Book:: Book(string new_book_title, string new_authors, string new_date_of_publication): book_title(new_book_title), authors(new_authors), date_of_publication(new_date_of_publication){
}

Book:: Book(string new_book_title, string new_authors) :book_title(new_book_title), authors(new_authors), date_of_publication("n/a") {
}

Book:: Book(string new_book_title):book_title(new_book_title), authors("n/a"), date_of_publication("n/a") {
}

Book:: Book() :book_title("n/a"), authors("n/a"), date_of_publication("n/a") {
}

void Book:: print(){
    cout << "The book title is: "  << book_title <<endl;
    cout << "The author(s): "  << authors <<endl;
    cout << "The date of publication is: "  << date_of_publication <<endl;
}

void Book:: set_book_title(string new_book_title){
    book_title = new_book_title;
}

string Book:: get_book_title(){
    return book_title;
}

void Book:: set_authors(string new_authors){
    authors = new_authors;
}

string Book:: get_authors(){
    return authors;
}
void Book:: set_date_of_publication(string new_date_of_publication){
    date_of_publication = new_date_of_publication;
}

string Book:: get_date_of_publication(){
    return date_of_publication;
}
