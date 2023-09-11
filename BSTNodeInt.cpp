#include "BSTNodeInt.h"

#include <iomanip>
#include <iostream>

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
BSTNodeInt::BSTNodeInt(int d) : left(0), right(0), parent(0), data(d) {} 


/** Overload operator<< to print a BSTNode's fields to an ostream. */
std::ostream & operator<<(std::ostream& stm, const BSTNodeInt & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

/** Print the node */
void BSTNodeInt::print(){
  if (left){
    std::cout << "Left is: " << left->data;
  } else {
    std::cout << "Left is null";
  }
  std::cout << "\t";
  
  if (right){
    std::cout << "Right is: " << right->data;
  } else {
    std::cout << "Right is null";
  }
  std::cout << "\t";

  
  if (parent){
    std::cout << "parent is: " << parent->data;
  } else {
    std::cout << "Parent is root";
  }
  std::cout << "\t";
  
  std::cout << "Data is: " << data << std::endl;
}
