#include "dests.h"
#include "Queue.h"
#include "QueueNode.h"
#include "Stack.h"
#include "DoubleLinked.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
dests obj;
void readDests(string d);
void readTrucks(string t);
void readPackages(string p);
void readMissions(string m);
void writeResults(string r);
int main( int argc, char *argv[] )
{


		readDests(argv[1]);
		readPackages(argv[2]);
		readTrucks(argv[3]);
		readMissions(argv[4]);
		writeResults(argv[5]);


	return 0;

}
struct cityList{
	Stack<string> *packages;
	Queue<string> *trucks;
	string name;
	cityList *next;
};
cityList *headCityList;cityList *backCityList;cityList *newNodeCityList;cityList *Truck;cityList *Packages;cityList *Missions;cityList *Result;


void readDests(string fileName)
{		std::ifstream commands;
		commands.open(fileName,std::ifstream::in);
		string line;
		string last_call="";

		if(!commands.is_open()) //if it is not open the
		{
			cout<<"I can't read " <<fileName<<" file";
			exit(1); //system stop
				}
		else
		{	int i=0;
			vector < string > d;
			while(getline(commands,line)) //read file
				{
					string s=line;
					newNodeCityList= new cityList;
					newNodeCityList->name=s;
					newNodeCityList->trucks=new Queue<string>();
					newNodeCityList->packages=new Stack<string>();
					newNodeCityList->next=NULL;
					if(headCityList==NULL)
						headCityList=backCityList=newNodeCityList;
					else
					{
						backCityList->next=newNodeCityList;
						backCityList=newNodeCityList;
					}
					d.push_back(line);
					i++;
								}
			string dest[i];
			int j=0;
			for(auto it:d)
						{	dest[j]=it;j++;}//end of for loop
					}
		}


void tokenize(string &str, char delim, vector<string> &out)//split line space by space
{
	size_t start;
	size_t end = 0;
	int j=0;
	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
		j++;
	}
}

void readTrucks(string fileName)
{
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{	cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
		}
	else
	{
		while(getline(commands,line)) //read file
		{
			string truck[3];
			vector < string > v;
			char space=' ';
			tokenize(line,space,v);
			int i=0;
			for(auto it:v)
			{	truck[i]=it;i++;}//end of for loop
			Truck=headCityList;
			while(Truck->next!=NULL)
			{
				if(Truck->name==truck[1])
			{	Truck->trucks->enqueue(truck[0], truck[1], truck[2]);
				Truck=Truck->next;
				break;
			}
			else
			{
				Truck=Truck->next;
			}	};
			if(Truck->name==truck[1])
						{	Truck->trucks->enqueue(truck[0], truck[1], truck[2]);
							Truck=Truck->next;
						}
			//TrucksQueue.enqueue(truck[1], truck[0], truck[2]);
		}//end of while loop
	}//end of else
}//end of readTrucks method

//Stack <string> packageStack;
void readPackages(string fileName)
{
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else
	{	while(getline(commands,line)) //read file
		{
			string packages[2];
			vector < string > p;
			char space=' ';
			tokenize(line,space,p);
			int i=0;
			for(auto it:p)
			{	packages[i]=it;i++;
			}//end of for loop
			Packages=headCityList;
			while(Packages->next!=NULL)
			{
				if(Packages->name==packages[1])
			{		Packages->packages->push(packages[0], packages[1]);
					Packages=Packages->next;
					break;
			}
			else
			{
				Packages=Packages->next;
			}	};
			if(Packages->name==packages[1])
						{	Packages->packages->push(packages[0], packages[1]);
							Packages=Packages->next;
						}
			//packageStack.push(packages[0],packages[1]);
		}//end of while loop
	}//end of else
}//end of readPackages method


void readMissions(string fileName)
{
	ifstream commands;
	commands.open(fileName,std::ifstream::in);
	string line;
	if(!commands.is_open()) //if it is not open the
	{
		cout<<"I can't read " <<fileName<<" file";
		exit(1); //system stop
	}
	else
	{	while(getline(commands,line)) //read file
		{	DoubleLinked doubleLinkedTruck;
			vector < string > m;
			char hyphen='-';
			tokenize(line,hyphen,m);
			vector<string> results;
			int i=0;
			for (auto words : m)
			{	stringstream  ss(words);
				string str;
				while (getline(ss, str, ',')) {
				    results.push_back(str);
				    i++; }
			}//end of for loop
			string missions[i];//string array for mission
			int j=0;
			for(auto it:results)
			{
				missions[j]=it;
				j++;
			}
			Missions=headCityList;
			string first_city_truck,truck_power;
			while(Missions->next!=NULL)
			{	if(Missions->name==missions[0])
				{
					Missions->trucks->dequeue();//delete truck
					first_city_truck=Missions->trucks->dequeued_name;//initialize truck name
					truck_power=Missions->trucks->dequeued_power;
					break;
				}
				else
				{
					Missions=Missions->next;
				}	//end of the else
			};//end of the while loop
			if(Missions->name==missions[0])
			{
				Missions->trucks->dequeue();
				first_city_truck=Missions->trucks->dequeued_name;
				truck_power=Missions->trucks->dequeued_power;
				}
			int truckIndex=253;//truck size must different package index
			int packageIndex=0;
			doubleLinkedTruck.insert_last(truckIndex, first_city_truck);
			int startingStationDeletion=stoi(missions[3]) ;
			int midwayStationDeletion=stoi(missions[4]);
			string package_name;
			for(int del=0;del<startingStationDeletion;del++)//first city
			{
				Missions->packages->pop();
				package_name=Missions->packages->dequeued_package;
				doubleLinkedTruck.insert_last(packageIndex, package_name);
				packageIndex++;
			}
			Missions=headCityList;
			while(Missions->next!=NULL)
			{
				if(Missions->name==missions[1])//second city
				{	for(int del=0;del<midwayStationDeletion;del++)
					{
						Missions->packages->pop();
						package_name=Missions->packages->dequeued_package;
						doubleLinkedTruck.insert_last(packageIndex, package_name);
						packageIndex++;
					}
					for(int del=5;del<i;del++)//Indices of cargo packages you must leave at the midway station
					{	string mid_city=Missions->name;
						int add_mid_package=stoi(missions[del]);//indices numbers
						doubleLinkedTruck.delete_pos(add_mid_package);//deleted desired indices from double linked list
						string package_name=doubleLinkedTruck.delete_value_name;//deleted package name
						Missions->packages->push(package_name, mid_city);//push package midway station package stack
						packageIndex--;
					}
					Missions=Missions->next;
						break;
				}
				else
				{
					Missions=Missions->next;
				}	//end of the else
			};//end of the while loop
			if(Missions->name==missions[1])//second city
			{	for(int del=0;del<midwayStationDeletion;del++)
				{
					Missions->packages->pop();
					package_name=Missions->packages->dequeued_package;
					doubleLinkedTruck.insert_last(packageIndex, package_name);
					packageIndex++;
					}
					for(int del=5;del<i;del++)//Indices of cargo packages you must leave at the midway station
					{	string mid_city=Missions->name;
						int add_mid_package=stoi(missions[del]);//indices numbers
						doubleLinkedTruck.delete_pos(add_mid_package);//deleted desired indices from double linked list
						string package_name=doubleLinkedTruck.delete_value_name;//deleted package name
						Missions->packages->push(package_name, mid_city);//push package midway station package stack
						packageIndex--;
					}
							}
			Missions=headCityList;
			while(Missions->next!=NULL)
			{
				if(Missions->name==missions[2])
				{
					string last_city=Missions->name;
					for(int del=0;del<packageIndex;del++)
					{
						doubleLinkedTruck.delete_head_package();//deleted last station packages from double linked list
						string package_name=doubleLinkedTruck.delete_value_name;//deleted package name
						Missions->packages->push(package_name, last_city);//push package last station package stack
					}
					doubleLinkedTruck.delete_head_package();//deleted last station truck from double linked list
					string truck_name=doubleLinkedTruck.delete_value_name;//deleted package name
					Missions->trucks->enqueue(truck_name, last_city, truck_power);//push truck last station truck queue
					Missions=Missions->next;
					break;

				}
				else
				{
					Missions=Missions->next;
				}	//end of the else
			};//end of the while loop
			if(Missions->name==missions[2])
			{	string last_city=Missions->name;
				for(int del=0;del<packageIndex;del++)
				{
					doubleLinkedTruck.delete_head_package();//deleted last station packages from double linked list
					string package_name=doubleLinkedTruck.delete_value_name;//deleted package name
					Missions->packages->push(package_name, last_city);//push package last station package stack
				}
				doubleLinkedTruck.delete_head_package();//deleted last station truck from double linked list
				string truck_name=doubleLinkedTruck.delete_value_name;//deleted truck name
				Missions->trucks->enqueue(truck_name, last_city,truck_power);//push truck last station truck queue
			}
			}//end of while loop
		}//end of else
}

void writeResults(string fileName)
{
	ofstream commands;
	commands.open(fileName,std::ifstream::out);
	  if (!commands.is_open())
	  {
		  cout << "Unable to open file";

	  }
	  else
	  {
		Result=headCityList;
		while(Result->next!=NULL)
		{
			commands<<Result->name<<endl;
			commands<<"Packages:"<<endl;
			while(Result->packages->size>0)
			{
				Result->packages->pop();
				commands<<Result->packages->dequeued_package<<endl;
			}
			commands<<"Trucks:"<<endl;
			while(Result->trucks->size()>0)
			{
				Result->trucks->dequeue();
				commands<<Result->trucks->dequeued_name<<endl;
			}
			commands<<"-------------"<<endl;
			Result=Result->next;
		}
		commands<<Result->name<<endl;
					commands<<"Packages:"<<endl;
					while(Result->packages->size>0)
					{
						Result->packages->pop();
						commands<<Result->packages->dequeued_package<<endl;
					}
					commands<<"Trucks:"<<endl;
					while(Result->trucks->size()>0)
					{
						Result->trucks->dequeue();
						commands<<Result->trucks->dequeued_name<<endl;
					}
					commands<<"-------------"<<endl;
	    commands.close();
	  }

}
