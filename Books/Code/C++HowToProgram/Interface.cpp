
// Implementation of class Interface--client receives this file only
// as precompiled object code, keeping the implementation hidden.
#include "Interface.h"
#include "Implementation.h"

// constructor
Interface::Interface( int v )
	: ptr ( new Implementation( v ) ) // initialize ptr to point to
	{				  // a new Implementation object
	// empty body
	} // end Interface constructor

// call Implementation's setValue function
void Interface::setValue( int v )
{
	ptr->setValue( v );
} // end function setValue

// call Implementation's getValue function
int Interface::getValue() const
{
	return ptr->getValue();
} // end function getValue

// destructor
Interface::~Interface()
{
	delete ptr;
} // end ~Interface destructor
