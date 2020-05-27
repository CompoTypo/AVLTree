#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "./AVLNode.hpp"
#include "./AVLTree.hpp"
#include "./Book.hpp"
#include "./Table.hpp"

// for loop runs O(N)
string findMin(Table<Book> books)
{ // find min key of entire vector of books
    string min = "99999999999999999999";
    for (int i = 0; i < books.size(); i++)
        if (books.getRow(i).getISBN() < min)
            min = books.getRow(i).getISBN();
    return min;
}

// for loop runs O(N)
string findMax(Table<Book> books)
{ // find max key of entire vector of books
    string max = "0";
    for (int i = 0; i < books.size(); i++)
        if (books.getRow(i).getISBN() > max)
            max = books.getRow(i).getISBN();
    return max;
}

void testTree(AVLTree<Book> tr, Table<Book> ta)
{
    // runtime is O(N)
    bool balanced = tr.isBalanced(); // check if tree is balanced

    // runtime is O(n) * O(n) * O(logN) = O(N^2logN)
    bool bSTSearchable = tr.isBinarySearchable(findMin(ta), findMax(ta)); // check if tree is searchable through divide and conquer

    if (balanced)
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is NOT balanced" << endl;

    if (bSTSearchable)
        cout << "Tree is searchable" << endl;
    else
        cout << "Tree is NOT searchable" << endl;

    if (balanced && bSTSearchable)
        cout << "Tree is an AVL tree" << endl;
    else
        cout << "Tree is NOT an AVL tree" << endl;

    cout << "Heres the tree inorder" << endl;
    tr.display();
}

// function runs O(N) * O(1) = O(N)
AVLTree<Book> insertBooks(Table<Book> books)
{
    AVLTree<Book> bookTree; // init an avl tree

    // for loop runs O(N)
    for (int i = 0; i < books.size(); i++)
    { // loop through the vector of books
        Book b = books.getRow(i);
        bookTree.insert(b.getISBN(), b); // and properly insert it into the tree
    }
    bookTree.display(); // displays the tree inorder
    cout << "AVL tree completed" << endl
         << endl;

    testTree(bookTree, books);
    return bookTree;
}

// worst case runtime is O(N^2logN)
// fill a random binary tree
AVLTree<Book> createRBTRandomly(Table<Book> books)
{
    cout << "Creating an RBT" << endl;
    AVLTree<Book> unorganizedTree; // init an avl tree

    // for loop runs O(N)
    for (int i = 0; i < books.size(); i++)
    { // loop through the vector of books
        Book b = books.getRow(i);
        unorganizedTree.insertWithoutOrganization(b.getISBN(), b); // and properly insert it into the tree
    }

    testTree(unorganizedTree, books);
    return unorganizedTree; // dispaly tree in order
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "ERR: Format$ ./avl.o <file.ssv>" << std::endl;
        exit(1);
    }
    fstream inFile;

    inFile.open(argv[1]);                      // open a file
    Table<Book> t = Table<Book>(inFile, true); // read file and load it into a vector
    inFile.close();                            // close the file

    AVLTree<Book> goodTree = insertBooks(t);      // create the AVL for part 1
    AVLTree<Book> badTree = createRBTRandomly(t); // create an unorganized tree for part 2
}
