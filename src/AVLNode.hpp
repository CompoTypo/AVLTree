#ifndef AVLNODE_HPP
#define AVLNODE_HPP

#include <iostream>
#include <string>
#include "./Book.hpp"

template <class T>
class AVLNode
{
private:
    std::string key;
    int height;
    T *value;
    AVLNode *lPtr;
    AVLNode *rPtr;

public:
    // AVLNode constructor
    // Param 1, key
    // Param 2, template type
    // O(1)
    AVLNode(std::string k, T *item)
    {
        key = k;
        value = item;
        height = 0;
        lPtr = NULL;
        rPtr = NULL;
    }

    // Getters and setters below
    // O(1) for all
    std::string getKey()
    {
        return key;
    }


    T *getValue()
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

    AVLNode<T> *getLPtr()
    {
        return this->lPtr;
    }

    AVLNode<T> *getRPtr()
    {
        return this->rPtr;
    }

    void setValue(T *bookData)
    {
        this->value = bookData;
    }

    void setHeight(int newHeight)
    {
        this->height = newHeight;
    }

    void setLPtr(AVLNode<T> *left)
    {
        this->lPtr = left;
    }

    void setRPtr(AVLNode<T> *right)
    {
        this->rPtr = right;
    }
};
#endif