#include <iostream>
#include <string>

using namespace std;

struct Entity {
    int id;
    string name;
};

void sortEntities(Entity entities[], int N) {
    Entity temp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (entities[i].id > entities[j].id) {
                temp = entities[i];
                entities[i] = entities[j];
                entities[j] = temp;
            }
        }
    }
}

void sortalpha(Entity entities[], int N) {
    Entity temp;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (entities[i].name > entities[j].name) {
                temp = entities[i];
                entities[i] = entities[j];
                entities[j] = temp;
            }
        }
    }
}

void printEntities(Entity entities[], int N) {
    for (int i = 0; i < N; ++i) {
        cout << "ID: " << entities[i].id << ", Name: " << entities[i].name << endl;
    }
}

int main(int argc, char *argv[]) {
 
    int N = stoi(argv[1]);
    Entity entities[N];

    for (int i = 0; i < N; ++i) {
        entities[i].id = stoi(argv[2 + 2 * i]);
        entities[i].name = argv[3 + 2 * i];
    }

    sortEntities(entities, N);

    cout << "Entities sorted by ID:" << endl;
    printEntities(entities, N);

    sortalpha(entities, N);

    cout << "Entities sorted by Name (alphabetical order):" << endl;
    printEntities(entities, N);

    return 0;
}

