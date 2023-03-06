#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char students[10][10] = {"James", "Iverson", "Wade", "Jordan", "George", "Curry", "Westbrook", "Durant", "Kobe",
                             "Harden"};
    char course[6][20] = {"Mathematics", "English", "Data structures", "C++ Programming", "Internet",
                          "Java Programming"};

    char stu_course[10][20];

    int seed;
    cout << "Enter the seed for random number generation: ";
    cin >> seed;
    srand(seed); // this sets the seed of random number generation

    // Randomly assign a course to a student
    for (int i = 0; i < 10; i++) {
        strcpy(stu_course[i], course[rand() % 6]);
        // You can use the following line to check the assigned course
        cout << students[i] << " registers " << stu_course[i] << endl;
    }

    cout << endl;


    // TODO: count the number of registrations for each course
    //	     print the course list in descending order according to the number of registrations
    //       print the registered students' names for each course and students' names should be sorted in ascending alphabetical order.

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j > i; j--) {
            if (strcmp(students[j - 1], students[j]) > 0) {
                char tmp[10];
                strcpy(tmp, students[j]);
                strcpy(students[j], students[j - 1]);
                strcpy(students[j - 1], tmp);
                char temp[20];
                strcpy(temp, stu_course[j]);
                strcpy(stu_course[j], stu_course[j - 1]);
                strcpy(stu_course[j - 1], temp);
            }
        }
    }
    cout << "Students' list:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << students[i] << endl;
    }

    cout << endl;


    int courseCount[6] = {0};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            if (strcmp(stu_course[i], course[j]) == 0) {
                courseCount[j]++;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 5; j > i; j--) {
            if (courseCount[j - 1] < courseCount[j]) {
                char temp[20];
                strcpy(temp, course[j]);
                strcpy(course[j], course[j - 1]);
                strcpy(course[j - 1], temp);
                int tmp = courseCount[j];
                courseCount[j] = courseCount[j - 1];
                courseCount[j - 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 6; i++) {
        int tmp = courseCount[i];
        if (tmp == 0) {
            cout << "Nobody registers " << course[i];
        } else if (tmp == 1) {
            cout << tmp << " student registers " << course[i] << ":";
        } else {
            cout << tmp << " students register " << course[i] << ":";
        }
        for (int j = 0; j < 10; j++) {
            if (strcmp(stu_course[j], course[i]) == 0) {
                cout << " " << students[j];
            }
        }
        cout << endl;
    }
    return 0;
}
