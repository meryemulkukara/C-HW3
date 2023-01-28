/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/

#ifndef STACK_H_
#define STACK_H_
#include "StackNode.h"

template <typename T>
class Stack {
public:
	string dequeued_package;
	int size;
	Stack() :dequeued_package(),size(0), topPtr(NULL),_size(0) {}  	// default constructor
	~Stack(){//destructor
		while(!isEmpty())
			pop(); //backPtr and frontPtr are NULL at this point
	};
	bool isEmpty() const{
		   return topPtr == NULL;
		};


	//Push: Place item on top of the stack
	void push(const T& newName,const T& city_name){
		   // create a new node
		   StackNode<T> *newPtr = new StackNode<T>;

		   newPtr->element1 = newName; // insert the data
		   newPtr->element2 = newName; // insert the data

		   newPtr->next = topPtr; // link this node to the stack
		   topPtr = newPtr;               // update the stack top
		   _size++;
		   size++;
		}
;
	//Top: Take a look at the topmost item without removing it
	void getTop(T& stackTop) const{
		   if (isEmpty())
		      cout<<"StackException: stack empty on  topAndPop" ;
		   else {
			   stackTop = topPtr->element1;

		   }
		};
	//Pop: Remove item from the top of the stack
	void pop(){
		   if (isEmpty())
		      cout<<"StackException: stack empty on pop";
		   else {
			  _size--;
			  size--;
		      StackNode<T> *tmp = topPtr;
		      dequeued_package=topPtr->element1;
		      topPtr = topPtr->next; // update the stack top
		      delete tmp;
		   }
		};
private:
	StackNode<T> *topPtr;
	int _size;
};






#endif /* STACK_H_ */
