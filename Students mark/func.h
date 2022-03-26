#pragma once
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_LENGTH = 250;

int max_count_in_row(char* str);
void letters_digits(string filename);

struct student {
	string name;
	string initials;
	int id;
	int points[3];
};
void write_to_file(string filename, int count);
void print_from_file(string filename);
student* get_losers(string filename, size_t& size);
void make_sbd_happier(string filename, int id, int subj, int result);


