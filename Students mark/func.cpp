#include "func.h"

/**
 * @brief Вычисление длины строки.
 * 
 * \param [in] str - исходная строка.
 * \return [int] - длина строки.
 */
int len_chr(const char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

/**
 * @brief Определяет наибольшее количество цифр, идущих подряд в строке. 
 * 
 * \param [in] str - исходная строка. 
 * \return [in] - наибольшее количество цифр. 
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
 * @brief Аналог isalpha для русских букв.
 * 
 * \param c - исходный символ.
 * \return [bool] - если русская буква - true, иначе - false.
 */
bool isRussianAlpha(const char c) {
	return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
}


/**
 * @brief Записывает в исходном файле по строчно чего больше -- цифр или букв
 * @warning Если файл не существует выбрасывает исключение.
 * 
 * \param [in] filename - имя файла. 
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
				result += "букв\n";
			if (count_alpha < count_digit)
				result += "цифр\n";
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
 * @brief Запись данных в файл.
 * 
 * @throw std::invalid_argument В случае неправильного имени файла.	
 * @param [in] filename - название файла.
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
		cout << "Student №" << i << endl;
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
 * @brief Печать бинарного файла.
 * 
 * @throw std::invalid_argument В случае неправильного имени файла.	
 * \param [in] filename - имя файла.
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
 * @brief Возвращает список студентов получивших хотя бы одну 2.
 * 
 * @throw std::invalid_argument В случае неправильного имени файла.	
 * \param [in] filename - название файла.
 * \return [student*] - список студентов.
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
 * @brief Изменение 1 оценки.
 * Изменение по id, изменить предмет номер subj на оценку result.
 * 
 * @throw std::invalid_argument В случае неправильного имени файла.	
 * \param [in] filename - название файла.
 * \param [in] cid - id.
 * \param [in] subj - предмет.
 * \param [in] result - оценка.
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

