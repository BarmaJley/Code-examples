#include "Building.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	Building b(10, 39, 738);
	BedBathRooms b1(13, 18);
	ExtinguisherPhones b2(8, 82);

	cout << "|------------------------------------------------|\n" << endl;
	cout << "Creation of the building: " << endl;
	cout << b;
	cout << "\n|------------------------------------------------|\n" << endl;

	cout << "Creation of the building + bedrooms & bathrooms: " << endl;
	cout << b1;
	cout << "\n|------------------------------------------------|\n" << endl;

	cout << "Creation of the building + phones + extinguishers: " << endl;
	cout << b2;
	cout << "\n|------------------------------------------------|" << endl;


	return 0;
}
