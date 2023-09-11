#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Authors: Christine Alvarado  
 *          Crystina Callahan (A13070475)
 * TODO: Add more tests
 */
int main() {
  
    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(0);
    v.push_back(-10);
    v.push_back(-5);
    v.push_back(-20);
    v.push_back(-3);
    v.push_back(10);
    v.push_back(-7);

    /* Create an instance of BST holding int */
    BSTInt b;

    /* test the empty function */
    if ( !b.empty() ) {
      cout << "New bst returning not empty" << endl;
      return -1;
    }

    /* test the initial size */
    if ( b.size() ) {
      cout << "New bst returning a size of" << b.size() << endl;
      return -1;
    }

    /* test the initial height*/
    if ( b.height() ) {
      cout << "New bst returning a height of" << b.height() << endl;
      return -1;
    }
    
    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }



    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test height. */
    cout << "Height is: " << b.size() << endl;
    if(b.height() != 3) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test Empty on filled tree. */
    if ( b.empty() ) {
      cout << "filled bst returning empty" << endl;
      return -1;
    }
    
    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }


    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    //*
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    //std::cout << "139" << endl;
    auto vit = v.begin();
    //std::cout << "141" << endl;
    auto ven = v.end();
    //std::cout << "143" << endl;

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();
    //std::cout << "147" << endl;

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    //std::cout << "151" << endl;
    for(; vit != ven; ++vit) {
      //std::cout << "it is: " << *it << "en is : "<< *en  << endl;
        if(! (it != en) ) {
	  //std::cout << "in if" << std::endl;
	  //cout << *it << "," << *en << endl;
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << "at: " << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    //*/

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
