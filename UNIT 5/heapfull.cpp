#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;

// ----------- CHAINING -----------
vector<int> chainTable[SIZE];

void insertChaining(int key) {
    // insert with chaining
    int index = key % SIZE;
    // compute hash index
    chainTable[index].push_back(key);
    // add to vector at index
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
    // insert with linear probing
    int index = key % SIZE;
    // start at hash index
    while (linearTable[index] != -1) {
        index = (index + 1) % SIZE;
        // probe next slot
    }
    linearTable[index] = key;
    // place when empty
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
    // insert with quadratic probing
    int index = key % SIZE;
    // start at hash index
    int i = 1;
    while (quadTable[index] != -1) {
        index = (key % SIZE + i * i) % SIZE;
        // probe with i*i
        i++;
    }
    quadTable[index] = key;
    // place when empty
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
    // insert with double hashing
    int index = key % SIZE;
    // primary hash
    int step = hash2(key);
    // secondary hash
    int i = 0;
    while (doubleTable[(index + i * step) % SIZE] != -1) {
        i++;
        // probe with step
    }
    doubleTable[(index + i * step) % SIZE] = key;
    // place when empty
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