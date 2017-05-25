#include "Bicycle.h"

Bicycle::Bicycle() :brand(NULL), parts(NULL), price(0.0), numberOFparts(0) {}

Bicycle::Bicycle(char*b, BicyclePart*p, double pr, size_t n) : brand(NULL), parts(NULL)
{
	numberOFparts = n;
	setNewValue(brand, b,strlen(b)+1);
	setNewValue(parts, p,numberOFparts);
	for (size_t i = 0; i < numberOFparts; ++i)
	{
		price += p[i].getPrice();
	}
	price *= 1.5;
}

Bicycle::Bicycle(const Bicycle&b)
{
	CopyFrom(b);
}


Bicycle::~Bicycle()
{
	if (brand)
	delete[]brand;
	if (parts)
	delete[]parts;
}


void Bicycle::CopyFrom(const Bicycle&b)
{
	numberOFparts = b.numberOFparts;
	setNewValue(brand, b.brand, strlen(b.brand) + 1);
	setNewValue(parts, b.parts, numberOFparts);
	price = b.price;
}

bool Bicycle::operator()(const BicyclePart&tocheck)const
{
	
	for (size_t i = 0; i < numberOFparts; ++i)
	{
		if (parts[i] == tocheck)
			return true;
	}
	return false;
}

Bicycle& Bicycle::operator=(const Bicycle&b)
{
	if (this != &b)
	{
		CopyFrom(b);
	}
	return *this;
}


Bicycle& Bicycle::operator+=(const BicyclePart&toadd)
{
	if ((*this)(toadd)) //if bicycle has this part not adding anything
		return *this;
	Resize(); //else resizing array of parts
	if (numberOFparts % 2)
	{

		parts[(numberOFparts / 2) + 1] = toadd; //adding new part
	}
	else
	{
		parts[(numberOFparts / 2) + 2] = toadd;
	}
	price /= 1.5; //modifying price
	price += toadd.getPrice();
	price *= 1.5;
	return *this;
}


Bicycle Bicycle::operator+(const BicyclePart&toadd)const
{
	Bicycle n(*this);
	n += toadd;
	return n;
}

Bicycle&Bicycle::operator-=(const BicyclePart&toremove)
{
	if ((*this)(toremove))
	{
		for (size_t i = 0; i < numberOFparts; ++i)
		{
			if (parts[i] == toremove)
			{
				std::swap(parts[numberOFparts - 1], parts[i]);
				--numberOFparts;
				break;
			}
		}
		return*this;
	}
	return *this;
}

Bicycle Bicycle::operator-(const BicyclePart&toremove)const
{
	Bicycle n(*this);
	n -= toremove;
	return n;
}
bool Bicycle::operator==(const Bicycle&other)const
{
	if (strcmp(brand, other.brand) == NULL && price == other.price)
		return true;
	return false;
}

bool Bicycle::operator!=(const Bicycle&other)const
{
	return !(*this == other);
}

void Bicycle::Resize()
{
	int oldNumberOfParts = numberOFparts;
	numberOFparts = 2 * numberOFparts;
	BicyclePart*buffer = new BicyclePart[numberOFparts];
	for (int i = 0; i < oldNumberOfParts; ++i)
	{
		buffer[i] = parts[i];
	}
	delete[]parts;
	parts = buffer;
}


BicyclePart*Bicycle::operator[](const char*z)
{
	BicyclePart*ptr = NULL;
	for (size_t i = 0; i < numberOFparts; ++i)
	{
		if (strcmp(parts[i].getName(),z)==NULL)
		{
			ptr = &parts[i];
			break;
		}
	}
	return ptr;
}

Bicycle::operator double()const
{
	return (*this).getPrice();
}

bool operator <  (const Bicycle& b1, const Bicycle& b2)
{
	int countOfFirst = 0, countOfSecond = 0;
	for (size_t i = 0; i<b1.getNumberOfParts(); ++i)
	{
		if (b1.getParts()[i].getQuiality() == 1)
			++countOfFirst;
	}
	for (size_t i = 0; i<b2.getNumberOfParts(); ++i)
	{
		if (b2.getParts()[i].getQuiality() == 1)
			++countOfSecond;
	}
	return countOfFirst<countOfSecond;

}

bool operator <= (const Bicycle& b1, const Bicycle& b2)
{
	int countOfFirst = 0, countOfSecond = 0;
	bool flag = 0;
	for (size_t i = 0; i<b1.getNumberOfParts(); ++i)
	{
		if (b1.getParts()[i].getQuiality() == 1)
			++countOfFirst;
	}
	for (size_t i = 0; i<b2.getNumberOfParts(); ++i)
	{
		if (b2.getParts()[i].getQuiality() == 1)
			++countOfSecond;
	}
	flag = (countOfFirst == countOfSecond);
	return flag || b1<b2;
}

bool operator >(const Bicycle& b1, const Bicycle& b2)
{
	return !(b1 < b2);
}
bool operator >= (const Bicycle& b1, const Bicycle& b2)
{
	return !(b1<b2) && !(b1 <= b2) && !(b1>b2);
}

