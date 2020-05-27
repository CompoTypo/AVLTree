#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Book
{
private:
    std::string isbn;
    std::string title;
    std::string authorLastName;

public:
    Book(std::vector<std::string> in)
    {
        if (in.size() == 3)
        {
            this->isbn = in[0];
            this->title = in[1];
            this->authorLastName = in[2];
        }
    }

    // constructor for the book
    // O(1)
    Book(std::string bookNum, std::string bookTitle, std::string authorName)
    {
        this->isbn = bookNum;
        this->title = bookTitle;
        this->authorLastName = authorName;
    }

    // getters only
    // O(1)
    std::string getISBN()
    {
        return isbn;
    }

    std::string getTitle()
    {
        return title;
    }

    std::string getAuthorLastName()
    {
        return authorLastName;
    }
};
#endif
