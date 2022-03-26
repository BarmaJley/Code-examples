#include "Student.h"

ostream& operator << (ostream& out, const Student& person) {
    out <<  person.name << " is a student of the " << person.grade << ((person.grade % 10 > 3) ? "th" : (person.grade % 10 == 2) ? "nd" : (person.grade % 10 == 1) ? "st" : "") 
        << " year of studying, " << person.groupe << ((person.groupe % 10 > 3) ? "th" : (person.groupe % 10 == 2) ? "nd" : (person.groupe % 10 == 1) ? "st" : "")
        << " groupe, score: "<< person.score[0] << " | " << person.score[1] << " | " << person.score[2] << endl;
    return out;
    
};

istream& operator >> (istream& in, Student& person) {
    string name;
    int course, groupe;
    int* score = new int[count_s];
    
    cout << "Insert student's name: ";
    in >> name;

    cout << "Course: ";
    in >> course;

    cout << "Groupe: ";
    in >> groupe;

    cout << "Student's score: ";
    for (int i = 0; i < count_s; ++i)
        in >> score[i];

    person = Student(name, course, groupe, score);
    
    return in;
};