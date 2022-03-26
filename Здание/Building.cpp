#include "Building.h"


std::ostream& operator<<(std::ostream& out, const Building& obj) {
	
	out << "Building has " << obj.floorsNumber << " floors\n" 
		<< "Building has " << obj.roomsNumber << " rooms\n"
		<< "Total area of the building is " << obj.totalArea << " m^2" << endl;
	
	return out;
}

std::ostream& operator<<(std::ostream& out, const BedBathRooms& obj) {
	out << "Building has " << obj.getFloors() << " floors\n"
		<< "Building has " << obj.getRooms() << " rooms\n"
		<< "Building has " << obj.getBedrooms() << " bedrooms\n"
		<< "Building has " << obj.getBathrooms() << " bathrooms\n"
		<< "Total area of the building is " << obj.getArea() << " m^2" << endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, const ExtinguisherPhones& obj) {
	out << "Building has " << obj.getFloors() << " floors\n"
		<< "Building has " << obj.getRooms() << " rooms\n"
		<< "Building has " << obj.getExtinguishers() << " extinguishers\n"
		<< "Building has " << obj.getPhones() << " phones\n"
		<< "Total area of the building is " << obj.getArea() << " m^2" << endl;
	return out;
}