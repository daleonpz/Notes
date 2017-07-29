


class Implementation
{
public:
	// constructor
	Implementation(int v)
	   : value(v)
	{
	}

	// set value to v
	void setValue(int v)
	{
	   value = v;
	}	
	
	// return value
	int getValue() const
	{
	   return value;
	}
private:
	int value;
};
