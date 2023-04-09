#include<iostream>
#include<cstring>

using namespace std;

class Card {
private:
    char *color;
    int value;
    int number;
public:
    Card(char *color, int value, int number) : color(color), value(value), number(number) {};

    void setColor(char *n);

    void setValue(int v);

    void setNum(int num);

    char *getColor();

    int getVal();

    int getNum();
};

// Add your code here.
// You need to implement these access functions and the default constructor in order to complete the class definition of Card.

// color is an pointer to color array, while num is an pointer to number array
void initSequence(Card *cardSeq, char colorName[][10], int *color, int *num);

void printSequence(Card *cardSeq);

int main() {
    int seed;
    cout << "Enter the seed for random number generation:" << endl;
    cin >> seed;

    initSequence(cardSeq, colorName, color, num);
    printSequence(cardSeq);
    return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.
void initSequence(Card *cardSeq, char colorName[][10], int *color, int *num) {

}

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.
void printSequence(Card *cardSeq) {

}
