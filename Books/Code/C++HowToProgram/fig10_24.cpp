// pre compiled using 
// g++ -x c++-header -o Implementation.h.gch -c Interface.cpp
#include <iostream>
#include "Interface.h" 
using namespace std;

int main()
{
	Interface i(5); // create Interface object
	
	cout << "Interface contains: " << i.getValue()
	    << " before setValue" << endl;

	i.setValue(10);

	cout << "Interface contains: " << i.getValue()
	  << " after setValue" << endl;
}
