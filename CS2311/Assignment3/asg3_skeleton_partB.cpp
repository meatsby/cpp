#include<iostream>

using namespace std;

class Card {
private:
    char *color;
    int value;
    int number;

public:
    Card() {
        color = new char[10];
        value = 0;
        number = 0;
    }

    Card(char *color, int value, int number) : color(color), value(value), number(number) {};

    char *getColor() {
        return color;
    }

    int getVal() {
        return value;
    }

    int getNum() {
        return number;
    }

    void setValue(int v) {
        value = v;
    }

    bool compatible(Card &card) {
        return (strcmp(color, card.color) == 0 || number == card.number) && value != 0;
    }

    friend std::ostream &operator<<(std::ostream &out, Card &card) {
        out << card.color << card.number;
        return out;
    }

    friend bool operator==(Card &c1, Card &c2) {
        return c1.value == c2.value && c1.number == c2.number;
    }
};

void initSequence(Card *cardSeq, char colorName[][10], const int *num);

void printSequence(Card *cardSeq);

Card chooseCard(Card *cardSeq, Card previousCard) {
    for (int i = 0; i < 6; i++) {
        if (cardSeq[0].getVal() != 0) {
            cardSeq[0].setValue(0);
            return cardSeq[0];
        }
        if (cardSeq[i].getVal() == 0) {
            continue;
        }
        if (cardSeq[i].compatible(previousCard)) {
            cardSeq[i].setValue(0);
            return cardSeq[i];
        }
    }
    return *new Card();
}

// Add your code here.
int main() {
    char colorName[4][10] = {"Red", "Yellow", "Blue", "Green"};

    int input;
    cout << "Enter the seed for random number generation: ";
    cin >> input;

    // Add your code here.
    int *num = new int(input);
    Card cardSeq[6];
    initSequence(cardSeq, colorName, num);
    cout << "Your card sequence: ";
    printSequence(cardSeq);

    // Add your code here for computer operation.
    int *numc = new int(8);
    Card ComcardSeq[6];
    initSequence(ComcardSeq, colorName, numc);
    cout << "Computer's card sequence: ";
    printSequence(ComcardSeq);

    // Add your code here.
    Card previousCard = ComcardSeq[0];
    while (true) {
        Card c = chooseCard(ComcardSeq, previousCard);
        if (c == *new Card()) {
            cout << "Game ends. You win" << endl;
            return 0;
        }

        cout << "Game continues. Your remaining card(s): ";
        printSequence(cardSeq);

        int colIn, numIn;
        cout << "The computer plays " << c << ", please input two integers to represent the card you plan to play: ";
        cin >> colIn >> numIn;

        if (colIn == 0 && numIn == 0) {
            cout << "Game ends. you lose" << endl;
            return 0;
        }

        Card card = *new Card(colorName[colIn - 1], colIn, numIn);
        for (int i = 0; i < 6; i++) {
            if (card == cardSeq[i]) {
                cardSeq[i].setValue(0);
                previousCard = cardSeq[i];
                break;
            }
        }
    }
    return 0;
}

// Add your code here.
// You need to implement initSequence(Card* cardSeq, char colorName[][10], int* color, int* num) function.
void initSequence(Card *cardSeq, char colorName[][10], const int *num) {
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

    for (int i = 0; i < 6; i++) {
        char *c = colorName[cards[*num - 1][i] / 10 - 1];
        int v = cards[*num - 1][i] / 10;
        int n = cards[*num - 1][i] % 10;
        cardSeq[i] = *new Card(c, v, n);
    }
}

// Add your code here.
// You need to implement printSequence(Card* cardSeq) function.
void printSequence(Card *cardSeq) {
    for (int i = 0; i < 6; i++) {
        Card card = cardSeq[i];
        if (card.getVal() != 0) {
            cout << card << " ";
        }
    }
    cout << endl;
}
