#include <iostream>
using namespace std;
#include "cipher.h"
#include<cmath>
#include <algorithm>


	void cipher::normalizeText()
	{
		//remove spaces
		     sentances.erase(std::remove_if(sentances.begin(), sentances.end(), ::isspace), sentances.end());
		
		//convert all string to lowercase
    transform(sentances.begin(), sentances.end(), sentances.begin(), ::tolower);
	}
	void cipher::calcDim(const size_t length)
	{
		int d1 = static_cast<int>(sqrt(static_cast<double>(length)));
		if ((d1 * d1) >= length)
    {
        c = d1;
        r = d1;
    }
    else if ((d1 * (d1+1)) >= length)
    {
        c = d1 + 1;
        r = d1;
    }
    else
    {
        c = d1 + 1;
        r = d1 + 1;
    }
}

	
	void cipher::splitString()
	{
		messageQueue.clear();
		for(int i=0;i<r;i++)
		{
			messageQueue.push_back(sentances.substr((i*c),c));	
		}
	}
	void cipher::spaceAdd(const int NoOfSpaces)
	{
		for(int i=0;i<NoOfSpaces;i++)
		{
			sentances+=" ";
		}
	}
	void cipher::encodeMessage()
	{
		 encoddedMessage.erase();
    for (int i=0; i<c; i++)
    {
        for (int j=0; j<r; j++)
        {
            if (messageQueue.at(j).at(i)==' ')
            {
                continue;
            }
            encoddedMessage += messageQueue.at(j).at(i);
        }
    }
	}
	void cipher::splitChuncks()
	{
	string temp;
    finalEncodedMessage.erase();
    messageQueueChuncks.clear();
    for (int i=0; i<c; i++)
    {
        for (int j=0; j<r; j++)
        {
            temp += messageQueue.at(j).at(i);
        }
        messageQueueChuncks.push_back(temp);
        finalEncodedMessage += (temp + " ");
        temp.erase();
    }
	}
	
	cipher::cipher(): r{0},c{0}
	{
		 this->sentances.erase();
	}
	cipher::cipher(string sentances): r{0}, c{0}
	{
		this->sentances=sentances;
	}
	
	void cipher::squareCipher()
	{
		//remove all spaces and convert letters to lowercase
		normalizeText();
		
		//calculate length of r,c
		calcDim(sentances.length());
		
		//calculate needed spaces then add space to the sentances
		spaceAdd((r*c)-static_cast<int>(sentances.length()));
		 // Split string into rectangle or r * c
    splitString();
    
    // Encode Message
    encodeMessage();
    
    // Split Chuncks
    splitChuncks();
	}
	void cipher::printEncodeMessage()
	{
	cout << "------------------------------------" << endl;
    cout << "Encoded Message" << endl;
    cout << encoddedMessage << endl;
    cout << "------------------------------------" << endl;
	}
	void cipher::printRect()
	{
	cout << "------------------------------------" << endl;
    for (auto s : messageQueue)
    {
        cout << s << endl;
    }
    cout << "------------------------------------" << endl;
	}

	void cipher::printChuncks()
	{
	cout << "------------------------------------" << endl;
    cout << finalEncodedMessage << endl;
    cout << "------------------------------------" << endl;
	}