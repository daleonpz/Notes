
// Proxy class Interface
// Client sees this source code, but the source code does not reveal
// the data layout of class Implementation

class Implementation; // foward class declaration required by line 17

class Interface
{
public:
	Interface(int) ;
	void setValue(int); // same public interface as
	int getValue() const; // class Implementation has
	~Interface();
private:
	// requires previous forward declaration (line 6)
	Implementation *ptr;
};
