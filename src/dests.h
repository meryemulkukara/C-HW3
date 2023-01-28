/*
 * dests.h
 *
 *  Created on: 9 Ara 2020
 *      Author: Ulku
 */
#ifndef DESTS_H_
#define DESTS_H_
#include "city.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


class dests
{

public:

	dests(){};
	virtual ~dests(){};
	void readTrucks(string fileName)
	{
		cout<<"i can";
	}

	city City_class;

	void getCityClass(string name)
	{
		City_class.add_node(name);
	}

			};

#endif /* DESTS_H_ */
