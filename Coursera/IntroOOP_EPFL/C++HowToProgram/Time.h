

// Member functions are defined in Time.cpp


// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time{
public: 
	Time(); // constructor Time
	void setTime(int, int, int); // set hour, minute and second
	void printUniversal ()const; // print time in universal-time format
	void printStandard () const; // print time in standard-time format
private:
	int hour;
	int minute;
	int second;
}; // end class Time

#endif
