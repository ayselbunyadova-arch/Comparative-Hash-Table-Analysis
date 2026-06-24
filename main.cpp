#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int TABLE_SIZE = 10;

// ---------------- CHAINING ----------------

class ChainingHashTable {
private:
    vector<list<int>> table;

public:
    ChainingHashTable() {
        table.resize(TABLE_SIZE);
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void display() {
        cout << "\nSeparate Chaining:\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";

            for (int value : table[i]) {
                cout << value << " -> ";
            }

            cout << "NULL\n";
        }
    }
};

// ---------------- LINEAR PROBING ----------------

class LinearProbingHashTable {
private:
    int table[TABLE_SIZE];

public:
    LinearProbingHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = key;
    }

    void display() {
        cout << "\nLinear Probing:\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

// ---------------- DOUBLE HASHING ----------------

class DoubleHashingHashTable {
private:
    int table[TABLE_SIZE];

public:
    DoubleHashingHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = -1;
    }

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

    void insert(int key) {
        int index = hash1(key);

        if (table[index] == -1) {
            table[index] = key;
            return;
        }

        int step = hash2(key);

        while (table[index] != -1) {
            index = (index + step) % TABLE_SIZE;
        }

        table[index] = key;
    }

    void display() {
        cout << "\nDouble Hashing:\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

// ---------------- MAIN ----------------

int main() {

    int data[] = {15, 25, 35, 45, 55, 65};

    ChainingHashTable chaining;
    LinearProbingHashTable linear;
    DoubleHashingHashTable doubleHash;

    for (int value : data) {
        chaining.insert(value);
        linear.insert(value);
        doubleHash.insert(value);
    }

    chaining.display();
    linear.display();
    doubleHash.display();

    return 0;
}
