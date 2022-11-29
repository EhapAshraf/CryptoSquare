#ifndef cipher_hpp
#define cipher_hpp
#include <iostream>
using namespace std;
#include <vector>

class cipher{
	private:
	//Atributes
	string sentances;
	string encoddedMessage;
	string finalEncodedMessage;
	int c;
	int r;
	vector<string> messageQueue;
	vector<string> messageQueueChuncks;
	
	//Methods
	void normalizeText();
	void calcDim(const size_t length);
	void splitString();
	void spaceAdd(const int NoOfSpaces);
	void encodeMessage();
	void splitChuncks();
	
	public:
	cipher();
	cipher(string sentances);
	
	void squareCipher();
	void printEncodeMessage();
	void printRect();
	void printChuncks();
	
};

#endif
