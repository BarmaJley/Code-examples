#pragma once
#include <iostream>

using namespace std;

class Building {
protected:
	int floorsNumber;
	int roomsNumber;
	double totalArea;
public:
	Building(int floorsNumber = 0, int roomsNumber = 0, double totalArea = 0.0) :
		floorsNumber(floorsNumber), roomsNumber(roomsNumber), totalArea(totalArea) {}

	Building(const Building& copy) : floorsNumber(copy.floorsNumber), roomsNumber(copy.roomsNumber),
	totalArea(copy.totalArea) {}

	int getFloors() const { return floorsNumber; }
	int getRooms() const { return roomsNumber; }
	double getArea() const { return totalArea; }

	void setFloors(int floors) { floorsNumber = floors; }
	void setRooms(int rooms) { roomsNumber = rooms; }
	void setArea(double area) { totalArea = area; }

	Building& operator= (const Building& obj) {
		floorsNumber = obj.floorsNumber;
		roomsNumber = obj.roomsNumber;
		totalArea = obj.totalArea;

		return *this;
	}
	bool operator==(Building const& obj) {
		return floorsNumber == obj.floorsNumber &&
		roomsNumber == obj.roomsNumber &&
		totalArea == obj.totalArea;
	}
	bool operator!=(Building const& obj) {
		return !(*this == obj);
	}
	bool operator>(Building const& obj) {
		return totalArea > obj.totalArea;
	}
	bool operator>=(Building const& obj) {
		return totalArea >= obj.totalArea;
	}
	bool operator<(Building const& obj) {
		return totalArea < obj.totalArea;
	}
	bool operator<=(Building const& obj) {
		return totalArea <= obj.totalArea;
	}

	Building& operator--() {
		roomsNumber--;
		return *this;
	}
	Building operator--(int) {
		Building b = *this;
		roomsNumber--;
		return b;
	}
	friend std::ostream& operator<<(std::ostream& out, const Building& obj);
};

class BedBathRooms : public Building {
private:
	int bedroomsNumber;
	int bathroomsNumber;
public:
	BedBathRooms(int bedroomsNumber = 0, int bathroomsNumber = 0):
		bedroomsNumber(bedroomsNumber), bathroomsNumber(bathroomsNumber) {
		this->setRooms(bedroomsNumber + bathroomsNumber * 2);
		this->setFloors((bedroomsNumber + bathroomsNumber) / 10);
		this->setArea(bedroomsNumber * 18 + bathroomsNumber * 10 + bathroomsNumber * 20);
	}

	BedBathRooms(const BedBathRooms& copy) : bedroomsNumber(copy.bedroomsNumber), bathroomsNumber(copy.bathroomsNumber) {}

	int getBedrooms() const { return bedroomsNumber; }
	int getBathrooms() const { return bathroomsNumber; }

	void setBedrooms(int number) { bedroomsNumber = number; }
	void setBathrooms(int number) { bathroomsNumber = number; }

	BedBathRooms& operator=(const BedBathRooms& obj) {
		bedroomsNumber = obj.bedroomsNumber;
		bathroomsNumber = obj.bathroomsNumber;
		floorsNumber = obj.floorsNumber;
		roomsNumber = obj.roomsNumber;
		totalArea = obj.totalArea;

		return *this;
	}
	bool operator==(BedBathRooms const& obj) {
		return floorsNumber == obj.floorsNumber &&
			roomsNumber == obj.roomsNumber &&
			totalArea == obj.totalArea &&
			bedroomsNumber == obj.bedroomsNumber &&
			bathroomsNumber == obj.bathroomsNumber;
	}
	bool operator!=(BedBathRooms const& obj) {
		return !(*this == obj);
	}
	bool operator>(BedBathRooms  const& obj) {
		return totalArea > obj.totalArea;
	}
	bool operator>=(BedBathRooms  const& obj) {
		return totalArea >= obj.totalArea;
	}
	bool operator<(BedBathRooms  const& obj) {
		return totalArea < obj.totalArea;
	}
	bool operator<=(BedBathRooms  const& obj) {
		return totalArea <= obj.totalArea;
	}

	BedBathRooms& operator--() {
		bathroomsNumber--;
		return *this;
	}
	BedBathRooms operator--(int) {
		BedBathRooms b = *this;
		bathroomsNumber--;
		return b;
	}

	friend std::ostream& operator<<(std::ostream& out, const BedBathRooms& obj);
};

class ExtinguisherPhones : public Building {
private:
	int extinguishersNumber;
	int phonesNumber;
public:
	ExtinguisherPhones(int extinguishersNumber = 0, int phonesNumber = 0) :
		extinguishersNumber(extinguishersNumber),phonesNumber(phonesNumber) {
		this->setFloors(extinguishersNumber | phonesNumber / 3);
		this->setRooms(phonesNumber);
		this->setArea(extinguishersNumber * 83);
	}
	ExtinguisherPhones(const ExtinguisherPhones& copy) : extinguishersNumber(copy.extinguishersNumber),
		phonesNumber(copy.phonesNumber) {}

	int getExtinguishers() const { return extinguishersNumber; }
	int getPhones() const { return phonesNumber; }

	void setExtinguishers(int number) { extinguishersNumber = number; }
	void setPhones(int number) { phonesNumber = number; }

	ExtinguisherPhones& operator= (const ExtinguisherPhones& obj) {
		extinguishersNumber = obj.extinguishersNumber;
		phonesNumber = obj.phonesNumber;
		floorsNumber = obj.floorsNumber;
		roomsNumber = obj.roomsNumber;
		totalArea = obj.totalArea;

		return *this;
	}

	bool operator==(ExtinguisherPhones const& obj) {
		return floorsNumber == obj.floorsNumber &&
			roomsNumber == obj.roomsNumber &&
			totalArea == obj.totalArea &&
			extinguishersNumber == obj.extinguishersNumber &&
			phonesNumber == obj.phonesNumber;
	}
	bool operator!=(ExtinguisherPhones const& obj) {
		return !(*this == obj);
	}
	bool operator>(ExtinguisherPhones  const& obj) {
		return totalArea > obj.totalArea;
	}
	bool operator>=(ExtinguisherPhones  const& obj) {
		return totalArea >= obj.totalArea;
	}
	bool operator<(ExtinguisherPhones  const& obj) {
		return totalArea < obj.totalArea;
	}
	bool operator<=(ExtinguisherPhones  const& obj) {
		return totalArea <= obj.totalArea;
	}

	ExtinguisherPhones& operator--() {
		phonesNumber--;
		return *this;
	}
	ExtinguisherPhones operator--(int) {
		ExtinguisherPhones b = *this;
		phonesNumber--;
		return b;
	}

	friend std::ostream& operator<<(std::ostream& out, const ExtinguisherPhones& obj);
};
