#include "functions.h"

int main(int argc, char* argv[]) {
    string input, ls, mx;

    if (argc > 1) {
        if (argc == 2) {
            input = argv[1];
            ls = "ls.txt";
            mx = "mx.txt";
        }
        else if (argc == 3) {
            input = argv[1];
            mx = argv[2];
            ls = "ls.txt";
        }
        else {
            input = argv[1];
            ls = argv[3];
            mx = argv[2];
        }

        graph_transformation_to_ls(input, ls);
        graph_transformation_to_mx(input, mx);

    }
    else
        cout << "Not arguments" << endl;
    
    return 0;
}