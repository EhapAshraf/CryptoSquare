#include <iostream>
using namespace std;
#include "cipher.h"
int main(void)
{
    cipher c1 ("If man was meant to stay on the ground god would have given us roots");
    c1.squareCipher();
    c1.printEncodeMessage();
    c1.printRect();
    c1.printChuncks();
    
}