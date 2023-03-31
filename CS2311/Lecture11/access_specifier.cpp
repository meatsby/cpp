#include <iostream>

using namespace std;

class Actress {
private:
    int age;
public:
    char name[255];
    Actress(char *name, int age):age(age) {
        strcpy(this->name, name);
    }
};

int main() {
    Actress actress("Alice", 25);

    cout << actress.name << endl; // allowed
    // cout << actress.age << endl; // NOT allowed

    // this is legal but ill-logical
    // the name of an actress object should NOT
    // be modified from outside
    strcpy(actress.name, "Eve"); // allowed

    return 0;
}
