/*
 * StackNode.h
 *
 *  Created on: 16 Ara 2020
 *      Author: Ulku
 */

#ifndef STACKNODE_H_
#define STACKNODE_H_

template <class T>


class StackNode {
public:
  StackNode(const T& e1 = T(),const T& e2 = T(),const T& e3 = T(), StackNode *n = NULL) :
      element1(e1),element2(e2), next(n) { }

  T element1;
  T element2;
  StackNode *next;




};




#endif /* STACKNODE_H_ */
