#include "StdAfx.h"
#include "ATwit.h"


ATwit::ATwit(void)
{

	curl = curl_easy_init();

	
}


void  ATwit::getData(string URL)
{
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer); 
		curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);  
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);  
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);  
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &theXML);  

		result = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	if (result != CURLE_OK)  
     {  
		cout << "Error: [" << result << "] - " << errorBuffer;  
        exit(-1);  
     }  
}

void ATwit::parseData()
{
	tweetsRetrived.clear(); 
	userData.Parse(theXML.c_str());

	///const char *title;// = userData.FirstChildElement(userData.RootElement()->Name())->FirstChildElement()->Name(); 
	string check = userData.RootElement()->Name(); 
	if(check == "hash")
	{
		cout<<"No user by that name"<<endl; 
		exit(0); 
	}
	tinyxml2::XMLNode *status; 
	status = userData.FirstChildElement(userData.RootElement()->Name())->FirstChildElement(); 
	while(status != NULL)
	{
		tweetData temp; 
		temp.Time = status->FirstChildElement("created_at")->GetText(); 
		temp.Tweet = status->FirstChildElement("text")->GetText();
		temp.UserName = status->FirstChildElement("user")->FirstChildElement("name")->GetText(); 

		tweetsRetrived.push_back(temp); 

		status = status->NextSiblingElement();
	}
}

void ATwit::PrintStatuses()
{
		vector <tweetData>::iterator tweetsItor; 

		for(tweetsItor = tweetsRetrived.end()-1; tweetsItor > tweetsRetrived.begin(); tweetsItor--)
		{
			cout<<tweetsItor->UserName<<": "<<tweetsItor->Tweet<<"\n"<<tweetsItor->Time<<endl; 
		}

}
int ATwit::writer(char *data, size_t size, size_t nmemb,std::string *buffer)  
{  
  // What we will return  
  int result = 0;  
  
  // Is there anything in the buffer?  
  if (buffer != NULL)  
  {  
    // Append the data to the buffer  
    buffer->append(data, size * nmemb);  
  
    // How much did we write?  
    result = size * nmemb;  
  }  
  
  return result;  
}  

