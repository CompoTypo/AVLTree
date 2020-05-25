#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <iostream>
#include <string>
#include "./Book.hpp"

class AVLNode
{
private:
    int height;
    std::string key;
    Book *value;
    AVLNode *lPtr;
    AVLNode *rPtr;

public:
    // AVLNode constructor
    // O(1)
    AVLNode(Book *book)
    {
        key = book->getISBN();
        value = book;
        height = 0;
        lPtr = NULL;
        rPtr = NULL;
    }

    // Getters and setters below
    // O(1) for all
    std::string getKey()
    {
        return this->key;
    }

    Book *getValue()
    {
        return this->value;
    }

    int getHeight()
    {
        if (this == NULL)
            return -1;
        else
            return this->height;
    }

    AVLNode *getLPtr()
    {
        return this->lPtr;
    }

    AVLNode *getRPtr()
    {
        return this->rPtr;
    }

    void setData(Book *bookData)
    {
        this->value = bookData;
    }

    void setHeight(int newHeight)
    {
        this->height = newHeight;
    }

    void setLPtr(AVLNode *left)
    {
        this->lPtr = left;
    }

    void setRPtr(AVLNode *right)
    {
        this->rPtr = right;
    }
};
#endif