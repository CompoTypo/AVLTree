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
    AVLNode *leftPtr;
    AVLNode *rightPtr;

public:
    // AVLNode constructor
    // O(1)
    AVLNode(Book *book)
    {
        key = book->getISBN();
        value = book;
        height = 0;
        leftPtr = NULL;
        rightPtr = NULL;
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

    AVLNode *getLeftPtr()
    {
        return this->leftPtr;
    }

    AVLNode *getRightPtr()
    {
        return this->rightPtr;
    }

    void setData(Book *bookData)
    {
        this->value = bookData;
    }

    void setHeight(int newHeight)
    {
        this->height = newHeight;
    }

    void setLeftPtr(AVLNode *left)
    {
        this->leftPtr = left;
    }

    void setRightPtr(AVLNode *right)
    {
        this->rightPtr = right;
    }
};
#endif