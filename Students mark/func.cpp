#include "func.h"

/**
 * @brief ���������� ����� ������.
 * 
 * \param [in] str - �������� ������.
 * \return [int] - ����� ������.
 */
int len_chr(const char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

/**
 * @brief ���������� ���������� ���������� ����, ������ ������ � ������. 
 * 
 * \param [in] str - �������� ������. 
 * \return [in] - ���������� ���������� ����. 
 */
int max_count_in_row(char* str) {
	int i = 0;
	int leng = len_chr(str);
	int count = 0, max_count = count;

	while (i < leng) {
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' ||
			str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9') {
			count++;
		}
		else {
			if (count > max_count)
				max_count = count;
			count = 0;
		}
		i++;
	}
	if (count > max_count)
		max_count = count;

	return max_count;
}

/**
 * @brief ������ isalpha ��� ������� ����.
 * 
 * \param c - �������� ������.
 * \return [bool] - ���� ������� ����� - true, ����� - false.
 */
bool isRussianAlpha(const char c) {
	return (c >= '�' && c <= '�') || c == '�' || c == '�';
}


/**
 * @brief ���������� � �������� ����� �� ������� ���� ������ -- ���� ��� ����
 * @warning ���� ���� �� ���������� ����������� ����������.
 * 
 * \param [in] filename - ��� �����. 
 */
void letters_digits(string filename) {
	ifstream f(filename);
	string str, result = "";
	int count_alpha = 0, count_digit = 0;

	if (f.is_open()) {
		while (!f.eof()) {
			getline(f, str);
			count_alpha = count_digit = 0;
			for (int i = 0; i < str.size(); ++i) {
				if (isalpha(str[i]) || isRussianAlpha(str[i]))
					count_alpha++;
				if (isdigit(str[i]))
					count_digit++;
			}
			if (count_alpha > count_digit)
				result += "����\n";
			if (count_alpha < count_digit)
				result += "����\n";
			if (count_alpha == count_digit)
				result += '\n';
		}
		f.close();

		ofstream fwriter(filename);
		fwriter << result;
		fwriter.close();
	}
	else {
		throw 1;
	}
}




/**
 * @brief ������ ������ � ����.
 * 
 * @throw std::invalid_argument � ������ ������������� ����� �����.	
 * @param [in] filename - �������� �����.
 */
void write_to_file(string filename, int count) {
	fstream f(filename, ios::out | ios::trunc | ios::binary);
	student person;

	if (!f.is_open()) {
		cerr << "Can't open " << filename << "\n";
		exit(1);
	}

	for (int i = 1; i <= count; ++i) {
		person.id = i;
		cout << "Student �" << i << endl;
		cout << "Insert surname: ";
		cin >> person.name;
		cout << "Insert initials: ";
		cin >> person.initials;

		cout << "Insert point of 3 subjects: ";
		for (int k = 0; k < 3; ++k) {
			cin >> person.points[k];
		}
		cout << endl;
		f.write(reinterpret_cast<char*>(&person), sizeof(student));
	}

	f.close();
}
/**
 * @brief ������ ��������� �����.
 * 
 * @throw std::invalid_argument � ������ ������������� ����� �����.	
 * \param [in] filename - ��� �����.
 */
void print_from_file(string filename) {
	fstream file(filename, ios::in | ios::binary);

	if (!file.is_open()) {
		cerr << "Can't open " << filename << "\n";
		exit(1);
	}
	char* data = reinterpret_cast<char*>(new student);
	while (file.read(data, sizeof(student))) {
		student elem = *reinterpret_cast<student*>(data);
		cout << "Id: " << elem.id << " Surname: " << elem.name << " Initials: " << elem.initials;
		cout << " Points: ";
		for (int k : elem.points) {
			cout << " " << k;
		}
		cout << endl;
	}
	file.close();
	cout << endl;
}

/**
 * @brief ���������� ������ ��������� ���������� ���� �� ���� 2.
 * 
 * @throw std::invalid_argument � ������ ������������� ����� �����.	
 * \param [in] filename - �������� �����.
 * \return [student*] - ������ ���������.
 */
student* get_losers(string filename, size_t& size){

	fstream f(filename, ios::in | ios::binary);

	if (!f.is_open()) {
		cerr << "Can't open " << filename << "\n";
		exit(1);
	}

	f.seekg(0, SEEK_END);
	int length = f.tellg();
	f.seekg(0, SEEK_SET);
	student* students = new student[length / sizeof(student)];
	char* data = reinterpret_cast<char*>(new student);
	int i = 0;
	while (f.read(data, sizeof(student))) {
		student elem = *reinterpret_cast<student*>(data);
		if (elem.points[0] == 2 || elem.points[1] == 2 || elem.points[2] == 2) {
			students[i] = elem;
			i++;
		}
	}

	int n = 0;
	while (students[n].points[0] >= 2 && students[n].points[0] <= 5) n++;
	student* students1 = new student[n];
	for (int i = 0; i < n; i++) students1[i] = students[i];

	delete[] students;
	f.close();
	size = n;

	return students1;
}

/**
 * @brief ��������� 1 ������.
 * ��������� �� id, �������� ������� ����� subj �� ������ result.
 * 
 * @throw std::invalid_argument � ������ ������������� ����� �����.	
 * \param [in] filename - �������� �����.
 * \param [in] cid - id.
 * \param [in] subj - �������.
 * \param [in] result - ������.
 */
void make_sbd_happier(string filename, int cid, int subj, int result) {
	assert(subj < 3);
	fstream f(filename, ios::in | ios::out | ios::binary);

	if (!f.is_open()) {
		cerr << "Can't open " << filename << "\n";
		exit(1);
	}

	char* data = reinterpret_cast<char*>(new student);
	int line = 0;

	while (f.read(data, sizeof(student))) {
		student elem = *reinterpret_cast<student*>(data);
		if (elem.id == cid) {
			f.seekp(-static_cast<int>(sizeof(int) * (3 - subj)), ios::cur);
			f.write(reinterpret_cast<char*>(&result), sizeof(int));
			f.seekp(static_cast<int>(sizeof(int) * (3 - subj + 1)), ios::cur);
		}
	}
	f.close();
}

