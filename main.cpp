#include <iostream>
#include "Bicycle.h"

int main()
{
 
	BicyclePart parts[3];
	parts[0].setName("dinamo");
	parts[0].setPrice(5.0);
	parts[0].setQuality(1);
	parts[1].setName("kormilo");
	parts[1].setPrice(3.14);
	parts[1].setQuality(1);
	parts[2].setName("ramka");
	parts[2].setPrice(8.25);
	parts[2].setQuality(3);
	Bicycle b1("cycle", parts, 24.585, 3);
	BicyclePart*ptr=b1["dinamo"];
    std::cout<<ptr->getPrice();
	return 0;
}