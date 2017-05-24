#ifndef BICYCLE_PART_H
#define BICYCLE_PART_H



#include <iostream>
#include <string>

const int MAX_LINELEN = 500;

class BicyclePart
{
public:
	BicyclePart();
	BicyclePart(char*, double, short);
	BicyclePart(const BicyclePart&);
	~BicyclePart();
	BicyclePart&operator=(const BicyclePart&);
	void setName(const char*);
	void setPrice(const double);
	void setQuality(const short);
	char* getName()const { return name; }
	short getQuiality()const { return quality; }
	double getPrice()const { return price; }
private:
	void CopyName(char*&, const char*);
	void CopyFrom(const BicyclePart&);
private:
	char*name;
	double price;
	short quality;
};

bool operator==(const BicyclePart&p1, const BicyclePart&p2);
bool operator!=(const BicyclePart&p1, const BicyclePart&p2);


#endif