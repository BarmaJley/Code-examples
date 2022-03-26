#include "func.h"

int main() {
	setlocale(LC_ALL, "rus");

	cout << "1 task:" << endl;
	char str[MAX_LENGTH] = "asd1234hjk  dad 23 dfkl 12345 jk 1234567 jdadlakdj";
	char str1[MAX_LENGTH] = "1234567890";
	char str2[MAX_LENGTH] = "asjdadlakdj";
	cout << "String: " << str << " - maximum consecutive: " << max_count_in_row(str) << endl;
	cout << "String: " << str1 << " - maximum consecutive: " << max_count_in_row(str1) << endl;
	cout << "String: " << str2 << " - maximum consecutive: " << max_count_in_row(str2) << endl;
	cout << endl;


	cout << "2 task" << endl;
	string filename;
	cout << "Insert the name of the file: ";
	cin >> filename;


	try {
		letters_digits(filename);
		cout << "Success! Check the file!" << endl;
	}
	catch (int a) {
		switch (a) {
			case 1:
				cout << "Could not open file" << endl;
				break;
		}
	}
	
	cout << endl;
	cout << "3 task" << endl;
	cout << "Together with Nikolaev Evgeny ¹3" << endl;
	int count; size_t size = 0;

	cout << "Insert count of students: ";
	cin >> count;

	write_to_file("test_file.txt", count);

	cout << "List of all students: " << endl;
	print_from_file("test_file.txt");

	student* s = get_losers("test_file.txt", size);
	if (size != 0)
		cout << "List of student who have point 2: " << endl;

	for (int i = 0; i < size; ++i) {
		cout << "Id:" <<s[i].id << " Surname:" << s[i].name << " Initials: " << s[i].initials << " Points: ";
		for (int k : s[i].points) {
			cout << " " << k;
		}
		cout << endl;
	}
	cout << endl;

	int id, subj, mark;
	cout << "Insert id of student whose mark you want to change: ";
	cin >> id;
	cout << "Insert number of subject which you want to change(1-3): ";
	cin >> subj;
	cout << "Insert a new mark: ";
	cin >> mark;

	make_sbd_happier("test_file.txt", id, subj-1, mark);

	cout << "List after changing: " << endl;
	print_from_file("test_file.txt");
	
	
	return 0;
}