#ifndef BICYCLE_H
#define BICYCLE_H

#include "BicyclePart.h"

class Bicycle
{
public:
	Bicycle();
	Bicycle(char*b, BicyclePart*p, double pr, size_t n);
	Bicycle(const Bicycle&b);
	~Bicycle();
	bool operator()(const BicyclePart&tocheck)const;
	Bicycle&operator=(const Bicycle&b);
	Bicycle&operator+=(const BicyclePart&toadd);
	Bicycle operator+(const BicyclePart&toadd)const;
	Bicycle&operator-=(const BicyclePart&toremove);
	Bicycle operator-(const BicyclePart&toremove)const;
	bool operator==(const Bicycle&other);
	bool operator!=(const Bicycle&other);
	size_t getNumberOfParts()const { return numberOFparts; }
	double getPrice()const { return price; }
	BicyclePart*getParts()const { return parts; }
	BicyclePart*operator[](const char*z);
	operator double()const;
private:
	void Resize();
	void CopyFrom(const Bicycle&b);
private:
	char*brand;
	BicyclePart *parts;
	double price;
	size_t numberOFparts;
};


bool operator <  (const Bicycle& b1, const Bicycle& b2);
bool operator <= (const Bicycle& b1, const Bicycle& b2);
bool operator >  (const Bicycle& b1, const Bicycle& b2);
bool operator >= (const Bicycle& b1, const Bicycle& b2);


template <typename T>
void setNewValue(T*&dest, const T*source, size_t length)
{
	if (!source)
	{
		if (dest)
		delete[]dest;
		dest = NULL;
		return;
	}
	T*buffer = NULL;
	try
	{
		buffer = new T[length];
	}
	catch (std::bad_alloc&)
	{
		if (dest)
		delete[]dest;
		throw "Bad alloc caught!\n";
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = source[i];
	}
	if (dest)
	delete[]dest;
	dest = buffer;
}




#endif