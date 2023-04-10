#include<iostream>
#include<cstring>

using namespace std;

class Card {
private:
    char *color;
    int value;
    int number;
public:
    Card();

    void setColor(char *n);

    void setValue(int v);

    void setNum(int num);

    char *getColor();

    int getVal();

    int getNum();
};

Card::Card() {
    color = new char[10];
    value = 0;
    number = 0;
}

void Card::setColor(char *n) {
    color = n;
}

void Card::setValue(int v) {
    value = v;
}

void Card::setNum(int num) {
    number = num;
}

char *Card::getColor() {
    return color;
}

int Card::getVal() {
    return value;
}

int Card::getNum() {
    return number;
}

// Add your code here.
// You need to implement these access functions and the default constructor in order to complete the class definition of Card.

// color is an pointer to color array, while num is an pointer to number array
void initSequence(Card *cardSeq, char colorName[][10], int *color, int *num);

void printSequence(Card *cardSeq);

int main() {
    char colorName[4][10] = {"Red", "Yellow", "Blue", "Green"};
    int color[4] = {1, 2, 3, 4};
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    Card cardSeq[6];

    initSequence(cardSeq, colorName, color, num);
    printSequence(cardSeq);
    return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.
void initSequence(Card *cardSeq, char colorName[][10], int *color, int *num) {
    int cards[][6] = {{29, 35, 22, 31, 33, 23},
                      {23, 33, 14, 38, 22, 22},
                      {16, 32, 47, 35, 21, 21},
                      {49, 49, 21, 43, 19, 29},
                      {32, 46, 13, 41, 17, 38},
                      {35, 45, 37, 18, 16, 37},
                      {28, 43, 21, 15, 45, 36},
                      {11, 49, 44, 23, 43, 35},
                      {15, 47, 36, 21, 32, 34},
                      {47, 16, 29, 37, 31, 33},
                      {31, 14, 43, 35, 38, 32},
                      {24, 11, 36, 42, 27, 31},
                      {26, 19, 18, 49, 26, 39},
                      {19, 17, 43, 46, 15, 38},
                      {43, 15, 26, 14, 14, 47},
                      {36, 23, 19, 12, 42, 46},
                      {38, 21, 42, 29, 41, 45},
                      {22, 28, 25, 26, 49, 44},
                      {15, 27, 18, 34, 38, 43},
                      {47, 24, 31, 32, 37, 42}};

    int seed;
    cout << "Enter the seed for random number generation:";
    cin >> seed;

    for (int i = 0; i < 6; i++) {
        Card *card = new Card();
        card->setColor(colorName[cards[seed - 1][i] / 10 - 1]);
        card->setNum(cards[seed - 1][i] % 10);
        cardSeq[i] = *card;
    }
}

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.
void printSequence(Card *cardSeq) {
    for (int i = 0; i < 6; i++) {
        cout << cardSeq->getColor() << cardSeq->getNum() << " ";
        cardSeq++;
    }
}
