#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "./AVLNode.hpp"
#include "./Book.hpp"
#include "./Table.hpp"

using namespace std;

class AVLTree {
    private:
        AVLNode* root;

        // runs O(1) since each insert has at most one recurrence
        // function inserts children randomly
        AVLNode* insertWithoutOrganization(Book *book, AVLNode *t) {
            int random = rand();
            if (t == NULL) {
                t = new AVLNode(book);
            } else if (random % 2 == 0) {
                t->setLPtr(insertWithoutOrganization(book, t->getLPtr()));
            } else if (random % 2 == 1) {
                t->setRPtr(insertWithoutOrganization(book, t->getRPtr()));
            }
            t->setHeight(max(t->getLPtr()->getHeight(), t->getRPtr()->getHeight()) + 1);
            return t;
        }

        // runs O(1) amortizing the recursive calls
        // function inserts children based on the key and checks for imbalances
        AVLNode* insert(Book *book, AVLNode *t) {
            if (t == NULL) {
                t = new AVLNode(book);
            } else if (book->getISBN() < t->getKey()) {
                t->setLPtr(insert(book, t->getLPtr()));
                if (t->getLPtr()->getHeight() - t->getRPtr()->getHeight() == 2) {
                    if(book->getISBN() < t->getLPtr()->getKey()) {
                        cout << "Imbalance occurred at inserting ISBN: " << book->getISBN() << "; Fixed in RIGHT rotation" << endl;
                        t = singleRightRotate(t);
                    } else {
                        cout << "Imbalance occurred at inserting ISBN: " << book->getISBN() << "; Fixed in RIGHT-LEFT rotation" << endl;
                        t = doubleRightRotate(t);
                    }
                }

            } else if (book->getISBN() > t->getKey()) {
                t->setRPtr(insert(book, t->getRPtr()));
                if (t->getRPtr()->getHeight() - t->getLPtr()->getHeight() == 2) {
                    if(book->getISBN() > t->getRPtr()->getKey()) {
                        cout << "Imbalance occurred at inserting ISBN: " << book->getISBN() << "; Fixed in LEFT rotation" << endl;
                        t = singleLeftRotate(t);
                    } else {
                        cout << "Imbalance occurred at inserting ISBN: " << book->getISBN() << "; Fixed in LEFT-RIGHT rotation" << endl;
                        t = doubleLeftRotate(t);
                    }
                }
            }

            t->setHeight(max(t->getLPtr()->getHeight(), t->getRPtr()->getHeight()) + 1);
            return t;
        }

        // amortized to O(1)
        // right rotation
        AVLNode* singleRightRotate(AVLNode* t) {
            AVLNode* u = t->getLPtr();
            t->setLPtr(u->getRPtr());
            u->setRPtr(t);
            t->setHeight(max(t->getLPtr()->getHeight(), t->getRPtr()->getHeight()) + 1);
            u->setHeight(max(u->getLPtr()->getHeight(), t->getHeight()) + 1);
            return u;
        }

        // amortized to O(1)
        // left rotation
        AVLNode* singleLeftRotate(AVLNode* t) {
            AVLNode* u = t->getRPtr();
            t->setRPtr(u->getLPtr());
            u->setLPtr(t);
            t->setHeight(max(t->getLPtr()->getHeight(), t->getRPtr()->getHeight()) + 1);
            u->setHeight(max(u->getRPtr()->getHeight(), t->getHeight()) + 1);
            return u;
        }

        // amortized to O(1)
        // left rotation then right, hence left-right
        AVLNode* doubleLeftRotate(AVLNode* t) {
            t->setRPtr(singleRightRotate(t->getRPtr()));
            return singleLeftRotate(t);
        }

        // amortized to O(1)
        // right rotation then left, hence right-left
        AVLNode* doubleRightRotate(AVLNode* t) {
            t->setLPtr(singleLeftRotate(t->getLPtr()));
            return singleRightRotate(t);
        }   

        // goes through all nodes so O(N)
        // displays the tree inorder from left to right, keys and height displayed
        void inorder(AVLNode* t) {
            if(t == NULL) {
                return;
            } else {
                inorder(t->getLPtr());
                cout << t->getKey() << " Height: " << t->getHeight() << endl;                
                inorder(t->getRPtr());
            }
        }

        // runs O(logN)
        // checks the balance of an entire tree
        bool isBalanced(AVLNode* root) {
            int Lh;
            int Rh;

            if (root == NULL) {
                return true;
            }

            Lh = root->getLPtr()->getHeight();
            Rh = root->getRPtr()->getHeight();

            if (abs(Lh - Rh) <= 1 && isBalanced(root->getLPtr()) && isBalanced(root->getRPtr())) {
                return true;
            } else {
                return false;
            }
        }

        // runs O(logN)
        // checks if the tree is searchable (IE, organized smallest to largest, left to right respectively)
        bool isBinarySearchable (string min, string max, AVLNode* node) {
        
            if (node == NULL) 
                return true;

            if (node->getKey() < min || node->getKey() > max) 
                return false;

            char lastChar = node->getKey()[node->getKey().length() - 1];
            char lastCharDec = lastChar - 1;
            char lastCharInc = lastChar + 1;

            string leftMax = node->getKey().substr(0, node->getKey().length() - 1) + lastCharDec;
            string rightMin = node->getKey().substr(0, node->getKey().length() - 1) + lastCharInc;
            
            return (isBinarySearchable(min, leftMax, node->getLPtr()) && isBinarySearchable(rightMin, max, node->getRPtr()));
        }

    public:
        // public functions are mainly helper functions and constructors

        AVLTree() {
            root = NULL;
        }

        // runs O(logN) total
        // normal AVL insert
        void insert(Book book) {
            root = insert(&book, root);
        }

        // runs O(logN) total
        // unorganized insert
        void insertWithoutOrganization(Book book) {
            root = insertWithoutOrganization(&book, root);
        }

        // takes O(N)
        // calls the inorder function
        void display() {
            inorder(root);
        }

        // total runs O(logN)
        // calls the isBalanced function
        bool isBalanced() {
            return isBalanced(root);
        }

        // total runs O(logN)
        // calls the isSearchable function
        bool isBinarySearchable(string min, string max) {
            return isBinarySearchable(min, max, root);
        }
};
#endif