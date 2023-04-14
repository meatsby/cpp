#include <iostream>

using namespace std;

class Student {
protected:
    int sid;
public:
    Student(int sid = 0) : sid(sid) {}

    int getSid() {
        return sid;
    }
};

class TA : public Student {
protected:
    int courseid;
public:
    // To pass argument from child to parent, use initializer list
    TA(int sid = 0, int courseid = 0) : Student(sid), courseid(courseid) {}

    int getCourseId() {
        return courseid;
    }
};

int main() {
    int sid = 12345, courseid = 2311;
    TA bob(sid, courseid);
    cout << bob.getSid() << ": " << bob.getCourseId() << endl;
    return 0;
}
