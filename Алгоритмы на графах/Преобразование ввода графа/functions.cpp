#include "functions.h"

pair<vector<string>, vector<pair<string, string>>> get_graph_info(string filename) {
    string line;
    bool flag = true;
    vector<string> tops;
    vector<pair<string, string>> linked_tops;
    pair<vector<string>, vector<pair<string, string>>> result;
    ifstream in(filename);

    if (in.is_open()) {
        while (getline(in, line)) {
            if (flag) {
                tops = get_tops(line);
                flag = false;
            }
            else linked_tops.push_back(get_linked_tops(line));
        }
    }
    in.close();
    result.first = tops;
    result.second = linked_tops;

    return result;

}

vector<string> get_tops(string line) {
    vector<string> result;
    stringstream data(line);
    string str;
    while (getline(data, str, ' '))
        result.push_back(str);
    return result;
}

pair<string, string> get_linked_tops(string line) {
    pair<string, string> linked_tops;
    bool flag = true;
    stringstream data(line);
    string str;
    while (getline(data, str, ' '))
        if (flag) {
            linked_tops.first = str;
            flag = false;
        } else linked_tops.second = str;
    return linked_tops;
}

bool is_the_top(string top, pair<string, string> linked_tops) {
    return (top == linked_tops.first || top == linked_tops.second);
}

void print_vector(vector<string> const& input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

void print_vector_of_pairs(vector<pair<string, string>> input) {
    for (int i = 0; i < input.size(); i++){
        cout << "(" << input[i].first << "," << input[i].second << ")" << " ";
    }
}


void graph_transformation_to_ls(string filename, string out_filename) {
    pair<vector<string>, vector<pair<string, string>>> graph_info = get_graph_info(filename);
    vector<string> tops = graph_info.first;
    vector<pair<string, string>> linked_tops = graph_info.second;

    string line;
    ofstream out;
    out.open(out_filename);
    if (out.is_open()) {
        for (int i = 0; i < tops.size(); ++i) {
            line = tops[i] + ": ";
            for (int j = 0; j < linked_tops.size(); ++j) {
                if ((tops[i] == linked_tops[j].first || tops[i] == linked_tops[j].second))
                    if (tops[i] == linked_tops[j].first) line += linked_tops[j].second + " ";
                    else line += linked_tops[j].first + " ";
            }
            line.pop_back();
            out << line << endl;
        }
    }
}
template<class T>
void print_matrix(vector<vector<T>> const& mat) {
    for (vector<T> row : mat)
    {
        for (T val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
void graph_transformation_to_mx(string filename, string out_filename) {
    pair<vector<string>, vector<pair<string, string>>> graph_info = get_graph_info(filename);
    vector<string> tops = graph_info.first;
    vector<pair<string, string>> linked_tops = graph_info.second;
    string line;
    ofstream out;
    int index;
    vector<vector<string>> matrix(tops.size(), vector<string> (tops.size(), "0"));

    out.open(out_filename);
    if (out.is_open()) {
        for (int i = 0; i < tops.size(); ++i) {
            for (int j = 0; j < linked_tops.size(); ++j) {
                if ((tops[i] == linked_tops[j].first || tops[i] == linked_tops[j].second))
                    if ((tops[i] == linked_tops[j].first)){
                        vector<string>::iterator it = find(tops.begin(), tops.end(), linked_tops[j].second);
                        index = distance(tops.begin(), it);
                        matrix[i][index] = "1";
                    }
                    else {
                        vector<string>::iterator it = find(tops.begin(), tops.end(), linked_tops[j].first);
                        index = distance(tops.begin(), it);
                        matrix[i][index] = "1";
                    }
            }
        }
    }

    for (vector<string> row : matrix) {
        line = "";
        for (string val : row) {
            line += val + " ";
        }
        line.pop_back();
        out << line << endl;
    }
}
