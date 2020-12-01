//
//  a5_library.cpp
//  Assignment 5
//
//  Created by Nathan Souphanthong, Carl Lerdorf on 2020-11-19.
// Purpose: Library object that stores a vector of books

#include "a5_book.hpp"
#include "a5_library.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// bool compare(Book a, Book b) {
//     return a.get_book_title() < b.get_book_title();
// }

Library::Library(vector<Book> books) {
    this->books = books;
    //sort(this->books.begin(), this->books.end(), compare);
  
sort(books.begin(), books.end(), [this](Book a, Book b) {
    return a.get_book_title() < b.get_book_title(); });
}

Library::Library() {

}

void Library::print() {
    for(Book b : books){ b.print(); cout << endl;}
}

vector<Book> Library:: get_books() {
  return books;
}

bool Library:: compare(Book a, Book b) {
  return a.get_book_title() < b.get_book_title();
}

bool Library::insert(Book book) {
    if (books.size() > 0) {
        for (int i = 1; i < books.size(); i++) {
            if (books[i].get_book_title() == book.get_book_title()) {
                return false;
            }
            if (compare(books[i - 1], book) && compare(book, books[i])) {
                books.insert(books.begin() + i, book);
                return true;
            }
        }
    }
    books.push_back(book);
    return true;
}


bool Library::insert(string title, string authors, string publication_date) {
    return insert(Book(title, authors, publication_date));
}

bool Library::remove(Book book) {
    int i = locate(book.get_book_title(), book.get_authors(), book.get_date_of_publication());
    if (i != -1) {
        books.erase(books.begin() + i);
        return true;
    }
    return false;
}

bool Library::remove(string title, string authors, string publication_date) {
    return remove(Book(title, authors, publication_date));
}

int Library::locate(string name) {
    int max = books.size();
    int dir = 1;
    if (books[(int)(max * 0.5)].get_book_title() > name) dir = -1;
    for (int i = (int)(0.5 * max); i >= 0 && i < max; i += dir) {
        if (name == books[i].get_book_title())
            return i;
    }
    return -1;
}

int Library::locate(string name, string authors, string publication_date) {
    int max = books.size();
    int dir = 1;
    if (books[(int)(max * 0.5)].get_book_title() > name) dir = -1;
    for (int i = (int)(0.5 * max); i >= 0 && i < max; i += dir) {
        if (name == books[i].get_book_title() && authors == books[i].get_authors() && publication_date == books[i].get_date_of_publication())
            return i;
    }
    return -1;
}


