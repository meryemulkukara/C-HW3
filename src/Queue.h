/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "QueueNode.h"


template <class T>
class Queue
{

public:
	string dequeued_name;
	string dequeued_power;
	Queue():dequeued_name(),dequeued_power(),frontPtr(NULL),backPtr(NULL), _size(0){};//default constructor
	~Queue(){//destructor
		while(!isEmpty())
			dequeue(); //backPtr and frontPtr are NULL at this point
	};
	bool isEmpty() const{
		return backPtr==NULL;
	};

	int size() const{
		return _size;
	};
	//Enqueue: Items are added to the back of the queue
	void enqueue(const T& newName,const T& newCity,const T& newPower){
		//create a newNode
		QueueNode<T> *newPtr=new QueueNode<T>;
		//set data portion of new node
		newPtr->element1=newName;
		newPtr->element2=newCity;
		newPtr->element3=newPower;
		newPtr->next=NULL;

		//insert the new node
		if(isEmpty())
			frontPtr=newPtr;
		else
			backPtr->next=newPtr;
		backPtr=newPtr;
		_size++;
	};
	//Dequeue: Items are removed from the front of the queue
	void dequeue(){
		if(isEmpty())
					cout<<"QueueException: empty queue, cannot dequeue";

				else{
					QueueNode<T> *tempPtr=frontPtr;
					dequeued_name=frontPtr->element1;
					dequeued_power=frontPtr->element2;
					if(frontPtr==backPtr)
					{
						frontPtr=NULL;
						backPtr=NULL;
					}
					else
						{frontPtr=frontPtr->next;}
					tempPtr->next=NULL;
					delete tempPtr;
					_size--;


				}
	};
	void getFront( T& queueTop){
		if (isEmpty())
    	      cout<<"QueueException: empty queue, cannot getFront";
    	else 	// queue is not empty; retrieve front
		{	T& name=frontPtr->element1;
    	    queueTop = name;

		}
	};
	void getFrontPower( T& queueTop){
			if (isEmpty())
	    	      cout<<"QueueException: empty queue, cannot getFront";
	    	else 	// queue is not empty; retrieve front
			{	T& power=frontPtr->element3;
	    	    queueTop = power;
			}
		};
private:
	QueueNode<T> *frontPtr;
	QueueNode<T> *backPtr;
	int _size;
};


#endif /* QUEUE_H_ */
