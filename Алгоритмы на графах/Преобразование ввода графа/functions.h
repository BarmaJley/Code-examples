#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void graph_transformation_to_ls(string filename, string out_filename);
void graph_transformation_to_mx(string filename, string out_filename);

vector<string> get_tops(string line);
pair<string, string> get_linked_tops(string line);
vector<string> get_tops(string line);
