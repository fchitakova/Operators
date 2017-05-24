#include "BicyclePart.h"


BicyclePart::BicyclePart() :name(NULL), price(0.0), quality(1)
{}

BicyclePart::BicyclePart(char*n, double p, short q) : name(NULL)
{
	setName(n);
	price = p;
	quality = q;
}


BicyclePart::BicyclePart(const BicyclePart&b) :name(NULL)
{
	CopyFrom(b);
}

BicyclePart::~BicyclePart()
{
	delete[]name;
}

BicyclePart&BicyclePart::operator=(const BicyclePart&b)
{
	if (this != &b)
	{
		CopyFrom(b);
	}
	return*this;
}


void  BicyclePart::setName(const char*n)
{
	CopyName(name, n);
}

void BicyclePart::setPrice(double p)
{
	price = p;
}


void BicyclePart::setQuality(short q)
{
	quality = q;
}

void BicyclePart::CopyName(char*&dest, const char*source)
{
	if (!source)
	{
		return;
	}
	size_t size = strlen(source) + 1;
	name = new char[size];
 strcpy_s(name,size,source);
}

void BicyclePart::CopyFrom(const BicyclePart&b)
{
	CopyName(name, b.name);
	price = b.price;
	quality = b.quality;
}


bool operator==(const BicyclePart&p1, const BicyclePart&p2)
{
	return (strcmp(p1.getName(), p2.getName()) == NULL && p1.getPrice() == p2.getPrice() && p1.getQuiality() == p2.getQuiality());
}

bool operator!=(const BicyclePart&p1, const BicyclePart&p2)
{
	return (!(p1 == p2));
}