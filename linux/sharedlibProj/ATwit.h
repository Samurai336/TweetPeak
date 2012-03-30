#pragma once

#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string> 
#include <curl/curl.h>
#include "tinyxml2.h"
#include <vector> 

using namespace std;



struct tweetData
{
	string UserName; 
	string Tweet; 
	string Time; 

}; 






class ATwit
{
	public:
		ATwit(void);
		void getData(string URL);
		void parseData();
		void PrintStatuses();

		static int writer(char *data, size_t size, size_t nmemb,std::string *buffer);   
		
	private: 
		CURL *curl;
		CURLcode  result; 
		string theXML; 
		tinyxml2::XMLDocument userData;
		vector <tweetData> tweetsRetrived; 

		
		

};


