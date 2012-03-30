#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <RestApi.h> 
#include <ATwit.h> 
#include "tinyxml2.h"

//#pragma comment(lib, "./Debug/RestApi.lib")

using namespace std; 



void main(int argc, char* argv[])
{
	ATwit poop; 
	string queryUrl = "http://twitter.com/statuses/user_timeline.xml?id="; 
	if(argc!= 2)
	{
		cout<<"Error valad user name required!\n"<<"Use tweetPeek <username>"<<endl ; 
	}
	else
	{

		poop.getData(queryUrl+argv[1]); 
		poop.parseData(); 
		poop.PrintStatuses(); 
	}

}