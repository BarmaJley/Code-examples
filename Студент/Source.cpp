#include <iostream>
#include "Student.h"

using namespace std;

int main() {
	int* points1 = new int[count_s]{ 59, 45, 58 };
	int* points2 = new int[count_s]{ 100, 85, 92 };
	int* points3 = new int[count_s]{ 75, 74, 64 };
	int* points4 = new int[count_s]{ 59, 60, 58 };

	Student s1("Daria Ivanitskaya", 2, 4, points1),
		s2("Alexander Pavlenko", 2, 1, points2),
		s3("Vadim Chaikin", 2, 2, points3), 
		s4("Kostuk Dmitriy", 2, 2, points4);

	
	Student* AMI = new Student[4]{ s1, s2, s3, s4 };

	// Список студентов с указанием вычисленных оценок
	cout << "list of students with calculated mark: " << endl;
	for (int i = 0; i < 4; ++i) {
		cout << AMI[i] << "Marks = " << AMI[i].convert_into_mark(1) << ", " << AMI[i].convert_into_mark(2) << ", " << AMI[i].convert_into_mark(3) << endl;
		cout << endl;
	}

	// Список студентов, не допущенных к экзаменам по всем 3 предметам.
	cout << "List of not admitted students: " << endl;
	for (int i = 0; i < 4; ++i) {
		if (!AMI[i].is_allowed(1) && !AMI[i].is_allowed(2) && !AMI[i].is_allowed(3))
			cout << AMI[i];
	}

	delete[] AMI;

	return 0;
}
