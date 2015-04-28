/*
	Justin Liang
	Started 6:26PM, October 13th 2013
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct item
{
	string name; //0
	string cat; //1
	int att; //2
	string stat; //3
	int percentstat; //4
	string other; //5
	double price; //6
	string username; //7
	string sold; //8
	int date; //9
	int fm; //10
};

//Global variables
map<string, vector<item> > itemList; //Map of all the items currently in the database
vector<item> targetVector; //Target vector used for searchiing
bool foundItem; //Checks to see if item was found using specified search query

//Copy items in itemList to target vector
void copyMapToTargetVector()
{
	targetVector.clear();
	for(map<string, vector<item> >::iterator it = itemList.begin(); it!= itemList.end(); it++)
	{
		for(int i = 0; i < it->second.size(); i++)
		{
			targetVector.push_back(it->second[i]);
		}
	}
}

//Prints all items in vector
void printVector(vector<item> x)
{
	cout << endl;
	for(int i = 0; i < x.size(); i++)
	{
		cout << x[i].name << "/";
		cout << x[i].cat << "/";
		cout << x[i].att << "/";
		cout << x[i].stat << "/";
		cout << x[i].percentstat << "/";
		cout << x[i].other << "/";
		cout << x[i].price << "/";
		cout << x[i].username << "/";
		cout << x[i].sold << "/";
		cout << x[i].date << "/";
		cout << x[i].fm << "/" << endl;
	}
}

//Find an item by name in targetVector
void searchByName(string x)
{
	foundItem = false;
	vector<item> tempVector; //temporary vector to store items with specified query
	for(int i = 0; i < targetVector.size(); i++) //iterate through the vector
	{
		std::size_t found = (targetVector[i].name).find(x);
		if(found != string::npos) //if string x is same as targetVector[i].name
		{
			tempVector.push_back(targetVector[i]); //push targetVector[i] into tempVector
			foundItem = true;
		}
	}

	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item name " << x << " not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}	
}

//Find an item by category in targetVector
void searchByCat(string x)
{
	foundItem = false;
	vector<item> tempVector;
	for(int i = 0; i < targetVector.size(); i++)
	{
		std::size_t found = (targetVector[i].cat).find(x);
		if(found != string::npos)
		{
			tempVector.push_back(targetVector[i]);
			foundItem = true;
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item category " << x << " not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}	
}

void searchByAtt(int lb, int ub)
{
	foundItem = false;
	vector<item> tempVector;
	for(int i = 0; i < targetVector.size(); i++)
	{
		if(targetVector[i].att >= lb && targetVector[i].att <= ub)
		{
			tempVector.push_back(targetVector[i]);
			foundItem = true;
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item with specified att range not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}
}

void searchByStat(string x, int lb, int ub)
{
	foundItem = false;
	vector<item> tempVector;
	for(int i = 0; i < targetVector.size(); i++)
	{
		std::size_t found = (targetVector[i].stat).find(x);
		if(found != string::npos)
		{
			if(targetVector[i].percentstat >= lb && targetVector[i].percentstat <= ub)
			{
				tempVector.push_back(targetVector[i]);
				foundItem = true;
			}
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item with specified percent stat range not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}	
}

void searchByPrice(int lb, int ub)
{
	foundItem = false;
	vector<item> tempVector;
	for(int i = 0; i < targetVector.size(); i++)
	{
		if(targetVector[i].price >= lb && targetVector[i].price <= ub)
		{
			tempVector.push_back(targetVector[i]);
			foundItem = true;
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item with specified price range not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}
}

void searchByUsername(string x)
{
	foundItem = false;
	vector<item> tempVector; //temporary vector to store items with specified query
	for(int i = 0; i < targetVector.size(); i++) //iterate through the vector
	{
		std::size_t found = (targetVector[i].username).find(x);
		if(found != string::npos) //if string x is same as targetVector[i].name
		{
			tempVector.push_back(targetVector[i]); //push targetVector[i] into tempVector
			foundItem = true;
		}
	}

	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Username not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}
}

void searchBySold(string x)
{
	foundItem = false;
	vector<item> tempVector; //temporary vector to store items with specified query
	for(int i = 0; i < targetVector.size(); i++) //iterate through the vector
	{
		std::size_t found = (targetVector[i].sold).find(x);
		if(found != string::npos) //if string x is same as targetVector[i].name
		{
			tempVector.push_back(targetVector[i]); //push targetVector[i] into tempVector
			foundItem = true;
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Incorrect entry. Please enter 'sold' or 'unsold'" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}
}

void searchByDate(int lb, int ub)
{
	foundItem = false;
	vector<item> tempVector;
	for(int i = 0; i < targetVector.size(); i++)
	{
		if(targetVector[i].date >= lb && targetVector[i].date <= ub)
		{
			tempVector.push_back(targetVector[i]);
			foundItem = true;
		}
	}
	if(tempVector.size() == 0) //If tempVector has size of 0, item does not exist
	{
		cout << "Item with specified date range not found" << endl;
	}
	else //Otherwise print it and update targetVector
	{
		printVector(tempVector);
		targetVector = tempVector; 
	}
}

double computeMean(vector<item> x)
{
	double sum = 0;
	for(int i = 0; i < x.size(); i++)
	{
		sum = sum + x[i].price;
	}
	return sum/x.size();
}

double computeStandardDeviation(vector<item> x)
{
	double mean = computeMean(x);
	double e = 0;
	for(int i = 0; i < x.size(); i++)
	{
		e = e + (x[i].price-mean)*(x[i].price-mean);
		return sqrt(e/x.size());
	}
}

int main(int argc, char *argv[])
{
	ifstream datafile;
	datafile.open("data.txt");
	if(datafile.is_open())
	{
		while(datafile.good())
		{
			//Get line from data
			string line;
			string array [11];
			int index = 0;
			int start = 0;
			int end = 0;
			//Put each feature into an array
			getline(datafile, line);			
			for(int i = 0; i < line.length(); i++)
			{
				if(line.at(i) == '/')
				{
					end = i;
					array[index] = line.substr(start,end-start);
					start = i+1;
					index++;
				}
			}

			//Create a new item, assign array values to item features
			item tempItem;
			tempItem.name = array[0];
			tempItem.cat = array[1];
			tempItem.att = atoi(array[2].c_str());
			if(tempItem.att == -1) //If ATT feature on item is -1, it means item is clean. Assign clean/zero values to next 3 feature
			{
				tempItem.stat = "CLEAN";
				tempItem.percentstat = 0;
				tempItem.other = "CLEAN";
				tempItem.price = (double)atof(array[3].c_str());
				tempItem.username = array[4];
				tempItem.sold = array[5];
				tempItem.date = atoi(array[6].c_str());
				tempItem.fm = atoi(array[7].c_str());
			}
			else
			{
				tempItem.stat = array[3];
				tempItem.percentstat = atoi(array[4].c_str());
				tempItem.other = array[5];
				int tempprice = atof(array[6].c_str());
				tempItem.price = tempprice;
				tempItem.username = array[7];
				tempItem.sold = array[8];
				tempItem.date = atoi(array[9].c_str());
				tempItem.fm = atoi(array[10].c_str());
			}

			//If item does not exist, create a vector corresponding to that item in map
			if(itemList.find(tempItem.name) == itemList.end())
			{
				vector<item> tempVector;
				tempVector.push_back(tempItem);
				itemList[tempItem.name] = tempVector;
			}

			//Else, add item to vector in map
			else
			{
				itemList[tempItem.name].push_back(tempItem);
			}
		}
	}

	string input;
	int lb, ub;
	//Prompt user
	do
	{
		copyMapToTargetVector();
		cout << endl;
		cout << "Welcome" << endl;
		cout << "1. View items" << endl;
		cout << "2. Start a new search" << endl;
		cout << "0. Exit" << endl;
		cout << "Please enter a numerical value: ";
		cin >> input;
		cout << endl;

		if(input == "0")
		{
			break;
		}

		if(input == "1")
		{
			printVector(targetVector);
		}

		bool refineSearch = false;
		if(input == "2")
		{			
			do
			{
				cout << "You can search for these following features:" << endl;
				cout << "1. NAME: search item by keyword" << endl;
				cout << "2. CATEGORY: search item by category of item" << endl;
				cout << "3. ATT: search item by item's attack" << endl;
				cout << "4. STAT: search item by its main stat" << endl;
				cout << "5. PRICE: search item by price range" << endl;
				cout << "6. USERNAME: search item by its seller's username" << endl;
				cout << "7. SOLD: specify sold or unsold items" << endl;
				cout << "8. DATE: search by date range. format is yymmdd" << endl;
				cout << "Enter a search category: ";
				cin >> input;
				if(input == "1")
				{
					cout << "Enter a keyword: ";
					cin >> input;
					searchByName(input);
				}
				if(input == "2")
				{
					cout << "Enter a category: ";
					cin >> input;
					searchByCat(input);
				}
				if(input == "3")
				{
					cout << "NOTE: USE -1 AS LOWER BOUND TO INCLUDE CLEAN ITEMS IN SEARCH QUERY" << endl;
					cout << "Enter lower bound of att: ";
					cin >> lb;
					cout << "Enter upper bound of att: ";
					cin >> ub;
					searchByAtt(lb, ub);
				}
				if(input == "4")
				{
					cout << "Enter main stat of item: ";
					cin >> input;
					cout << "Enter lower bound of percent stat: ";
					cin >> lb;
					cout << "Enter upper bound of percent stat: ";
					cin >> ub;
					searchByStat(input, lb, ub);
				}
				if(input == "5")
				{
					cout << "Enter lower bound of price: ";
					cin >> lb;
					cout << "Enter upper bound of price: ";
					cin >> ub;
					searchByPrice(lb, ub);
				}
				if(input == "6")
				{
					cout << "Enter username: ";
					cin >> input;
					searchByUsername(input);
				}
				if(input == "7")
				{
					cout << "Enter sold/unsold status of item: ";
					cin >> input;
					searchBySold(input);
				}
				if(input == "8")
				{
					cout << "Enter lower bound of date (yymmdd): ";
					cin >> lb;
					cout << "Enter upper bound of date (yymmdd): ";
					cin >> ub;
					searchByDate(lb, ub);
				}
				if(foundItem == false)
					break;
				cout << "Mean of prices of data set: " << computeMean(targetVector) << endl;
				cout << "Standard deviation of prices of datat set: " << computeStandardDeviation(targetVector) << endl;

				//Prompt user to refine search on given targetVector
				cout << "Would you like to refine your search? Y/N: ";
				cin >> input;

				if(input == "Y" || input == "y")
				{
					refineSearch = true;
				}
				else
				{
					refineSearch = false;
					break;
				}
				cout << endl;
			}while(refineSearch = true);			
		}		
	}while(input != "0");
}