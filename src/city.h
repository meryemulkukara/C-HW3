/*
 * city.h
 *
 *  Created on: 10 Ara 2020
 *      Author: Ulku
 */

#ifndef CITY_H_
#define CITY_H_
#include <iostream>
using namespace std;
class city{

struct Node
	{
	string data;
	Node* next;
	};

private:
    Node *head,*tail;
public:
    city()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(string n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
            cout<<" \n tail->data "<<tail->data<<endl;
        }
    }
};







#endif /* CITY_H_ */
