#include <iostream>

using namespace std;

class Robot {
public:
    char *name = NULL;

    Robot(char *name) {
        int n = strlen(name);
        this->name = new char[n + 1];
        strncpy(this->name, name, n);
        this->name[n] = '\0';
        cout << "Constructing " << name << endl;
    }

    ~Robot() {
        cout << "Destructing " << name << endl;
        // it's a good practice to free memories allocated
        // for member variables in destructor
        delete name;
    }
};

void func() {
    Robot eve("Eve");
    cout << "func is about to return\n";
    // Automatically calls the destructor when a
    // statically allocated object is out of the
    // scope
}

int main() {
    Robot *wall_e = new Robot("Wall-e");
    func();
    // A dynamically allocated object is destructed
    // only when you explicitly delete it
    delete wall_e;
    cout << "main is about to return\n";
    return 0;
}
