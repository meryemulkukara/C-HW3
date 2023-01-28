/*
 * QueueNode.h
 *
 *  Created on: 15 Ara 2020
 *      Author: Ulku
 */

#ifndef QUEUENODE_H_
#define QUEUENODE_H_

template <class T>


class QueueNode {
public:
  QueueNode(const T& e1 = T(),const T& e2 = T(),const T& e3 = T(), QueueNode *n = NULL) :
      element1(e1),element2(e2),element3(e3), next(n) { }

  T element1;
  T element2;
  T element3;
  QueueNode *next;




};




#endif /* QUEUENODE_H_ */
