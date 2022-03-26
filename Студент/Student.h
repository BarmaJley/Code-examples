/*!
\file
\brief ������������ ���� � ��������� �������

������ ���� �������� � ���� ����������� ��������
�������, ������������ � ���������������� ���������
*/
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

const int count_s = 3; // ���������� ���������

/**
 * \brief �������� �����
 * \author Chaikin Vadim
 * \version 1.0
 * \date ���� 2021 ����
 */
class Student {
private:
	string name;
	int grade;
	int groupe;
	int* score;
public:
	/* ������������ */
	// ����������� �� ���������
	Student() {  
		name = "Blank Blank";
		grade = 0;
		groupe = 0;
		score = nullptr;
	};

	// ����������� � �����������
	Student(string name, int grade, int groupe, int* score) : name(name), grade(grade), groupe(groupe), score(score) {}

	// ����������� �����
	Student(const Student& other) : name(other.name), grade(other.grade), groupe(other.groupe) {
		score = new int[count_s];
		for (int i = 0; i < count_s; ++i)
			score[i] = other.score[i];
	}

	/* ���������� */ 
	~Student() {
		if (score) {
			delete[] score;
			score = nullptr;
		}
	}


	/* ������ */
	// �������
	string get_name() { return name; }
	int get_groupe() { return groupe; }
	int get_grade() { return grade; }
	int* get_score() { return score; }

	// �������
	void set_name(string name) { this->name = name; }
	void set_groupe(int groupe) { this->groupe = groupe; }
	void set_grade(int grade) { this->grade = grade; }
	void set_score(int subject, int score) { this->score[subject-1] = score; }
	
	// ���������� ������
	int convert_into_mark(int s) {
		if (score[s-1] < 60)
			return 2;
		else if (score[s-1] < 71)
			return 3;
		else if (score[s-1] < 85)
			return 4;
		else return 5;
	}

	// �������� ������� � ��������
	bool is_allowed(int s){ return score[s-1] >= 60; }

	/* ���������� �������� */
	Student& operator = (const Student& person) {
		if (score) delete[] score;

		score = new int[count_s];
		for (int i = 0; i < count_s; ++i)
			score[i] = person.score[i];

		name = person.name;
		grade = person.grade;
		groupe = person.groupe;

		return *this;
	};

	// �������� ���������
	bool operator==(Student const& other) {
		return name == other.name && grade == other.grade && groupe == other.groupe &&
			score[0] == other.score[0] && score[1] == other.score[1] && score[2] == other.score[2];
	}
	bool operator!=(const Student& other) {
		return !(*this == other);
	}
	bool operator>(const Student& other) {
		return score[0] + score[1] + score[2] > other.score[0] + other.score[1] + other.score[2];
	}
	bool operator>=(const Student& other) {
		return score[0] + score[1] + score[2] >= other.score[0] + other.score[1] + other.score[2];
	}
	bool operator<(const Student& other) {
		return score[0] + score[1] + score[2] < other.score[0] + other.score[1] + other.score[2];
	}
	bool operator<=(const Student& other) {
		return score[0] + score[1] + score[2] <= other.score[0] + other.score[1] + other.score[2];
	}


	/* �������� �����\������ */
	friend ostream& operator << (ostream& out, const Student& person);
	friend istream& operator >> (istream& in, const Student& person);

};

