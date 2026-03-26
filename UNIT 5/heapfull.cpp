#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;

// ----------- CHAINING -----------
vector<int> chainTable[SIZE];

void insertChaining(int key) {
    int index = key % SIZE;
    chainTable[index].push_back(key);
}

void displayChaining() {
    cout << "\nChaining Table:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " -> ";
        for (int x : chainTable[i])
            cout << x << " ";
        cout << endl;
    }
}

// ----------- LINEAR PROBING -----------
int linearTable[SIZE];

void initLinear() {
    for (int i = 0; i < SIZE; i++)
        linearTable[i] = -1;
}

void insertLinear(int key) {
    int index = key % SIZE;

    while (linearTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    linearTable[index] = key;
}

void displayLinear() {
    cout << "\nLinear Probing Table:\n";
    for (int i = 0; i < SIZE; i++)
        cout << i << " -> " << linearTable[i] << endl;
}

// ----------- QUADRATIC PROBING -----------
int quadTable[SIZE];

void initQuad() {
    for (int i = 0; i < SIZE; i++)
        quadTable[i] = -1;
}

void insertQuadratic(int key) {
    int index = key % SIZE;
    int i = 1;

    while (quadTable[index] != -1) {
        index = (key % SIZE + i * i) % SIZE;
        i++;
    }

    quadTable[index] = key;
}

void displayQuad() {
    cout << "\nQuadratic Probing Table:\n";
    for (int i = 0; i < SIZE; i++)
        cout << i << " -> " << quadTable[i] << endl;
}

// ----------- DOUBLE HASHING -----------
int doubleTable[SIZE];

int hash2(int key) {
    return 7 - (key % 7); // second hash
}

void initDouble() {
    for (int i = 0; i < SIZE; i++)
        doubleTable[i] = -1;
}

void insertDouble(int key) {
    int index = key % SIZE;
    int step = hash2(key);
    int i = 0;

    while (doubleTable[(index + i * step) % SIZE] != -1) {
        i++;
    }

    doubleTable[(index + i * step) % SIZE] = key;
}

void displayDouble() {
    cout << "\nDouble Hashing Table:\n";
    for (int i = 0; i < SIZE; i++)
        cout << i << " -> " << doubleTable[i] << endl;
}

// ----------- MAIN -----------
int main() {
    int keys[] = {23, 33, 43, 13};

    // Chaining
    for (int k : keys) insertChaining(k);
    displayChaining();

    // Linear Probing
    initLinear();
    for (int k : keys) insertLinear(k);
    displayLinear();

    // Quadratic Probing
    initQuad();
    for (int k : keys) insertQuadratic(k);
    displayQuad();

    // Double Hashing
    initDouble();
    for (int k : keys) insertDouble(k);
    displayDouble();

    return 0;
}