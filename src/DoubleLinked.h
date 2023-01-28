/*
 * DoubleLinked.h
 *
 *  Created on: 18 Ara 2020
 *      Author: Ulku
 */

#ifndef DOUBLELINKED_H_
#define DOUBLELINKED_H_

#include <iostream>
#include <string>
using namespace std;

class DoubleLinked {

struct Node
		{
		string name;
		int index;

		Node *next;
		Node *prev;

		};
private:
    Node* head;
    Node* tail;
    int counter;
    int data1;
    string data2;
public:
    string delete_value_name;

    Node*  create_node(int data1,string data2)
    {
        counter++;
        Node *temp;
        temp = new(struct Node);
        temp->index =data1;
        temp->name=data2;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    };
	DoubleLinked():head(NULL),tail(NULL),counter(),data1(),data2(), delete_value_name(){};
	~DoubleLinked(){};
	bool searchInsert(int data1)
	{
	    int pos = 0,i;
	    bool flag = false;
	    struct Node *s;
	    s = head;
	    for (i = 0;i < counter;i++)
	    {
	        pos++;
	        if (s->index == data1)
	        {
	            flag = true;
	            return flag;
	        }
	        s = s->next;
	    }
	    return false;
	}
void insert_last(int data1,string data2)
	{	if(!searchInsert(data1))
		{
	    struct Node *temp;
	    temp = create_node(data1,data2);
	    if (head == tail && head == NULL)
	    {
	        head = tail = temp;
	        head->next = tail->next = NULL;
	        head->prev = tail->prev = NULL;
	    }
	    else
	    {
	        tail->next = temp;
	        temp->prev = tail;
	        tail = temp;
	        head->prev = tail;
	        tail->next = head; }
		}
	else
			return ;
	}

void display()
{
    int i;
    Node *s;
    if (head == tail && head == NULL)
    {
        cout<<"The List is empty, nothing to display";
        return;
    }
    s = head;
    for (i = 0;i < counter-1;i++)
    {
        cout<<"User id: "<<s->index<<" User name: "<<s->name<<"   ";
        s = s->next;
    }
    cout<<"User id: "<<s->index<<" User name: "<<s->name<<"   ";

}

int searchDel(int data1)
{
    int pos = 0,i;
    bool flag = false;
    struct Node *s;
    if (head == tail && head == NULL)
    {
        cout<<"User "<<data1 <<" does not exits";
        return 0;
    }
    s = head;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->index == data1)
        {
            //cout<<"Element "<<data1<<" found at position: "<<pos<<endl;
            flag = true;
            return pos;
        }
        s = s->next;
    }
    if (!flag)
        {cout<<"User "<<data1<<" does not exit";
        int count=counter+1;
    	return count;
        }
    return pos;
}


void delete_pos(int data1)
{
    int pos=searchDel(data1);
	int i;
    Node *ptr, *s;


  if (counter < pos)
    {
        cout<<endl;
        return ;
    }
    s =head;
    if(pos == 1)
    {
        counter--;
        delete_value_name=s->name;
        tail->next = s->next;
        s->next->prev = tail;
        head = s->next;
       // cout<<"User "<<data1<<" has been deleted ";

        free(s);

        return;
    }
    for (i = 0;i < pos - 1;i++ )
    {
        s = s->next;
        ptr = s->prev;
    }
    delete_value_name=s->name;
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        tail = ptr;
    }
    counter--;
   // cout<<"User "<<data1<<" has been deleted ";
    free(s);
    return;

}
void delete_head_package()
{
	if(head!=NULL)
	{
		if(head->next==0)
		{
            Node* temp1 = head;
            delete_value_name=temp1->name;
            head = head->next;
            free(temp1);
            if(head != NULL)
              head->prev = NULL;
            return;
		}
		if(head->next != NULL)
		{	Node* temp = head->next;
		 	delete_value_name=temp->name;
		 	if(temp==tail)
		 	{
		 	 	tail=NULL;
		 	 	head->next=NULL;
		 	 	head->prev = NULL;
		 	 	free(temp);
		 	 	return;
        }
        head->next=temp->next;
        free(temp);
	}
      }

    }
	};
#endif /* DOUBLELINKED_H_ */
