#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Starting to blend the juice..." << endl;
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Starting to grind the juice..." << endl;
        this_thread::sleep_for(chrono::seconds(4));
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
public:
    void makeJuice() {
        Blend blend;
        Grind grind;
        blend.blendJuice();
        grind.grindJuice();
    }
};

int main() {
    JuiceMaker juiceMaker;
    cout << "Juice making process started!" << endl;
    juiceMaker.makeJuice();
    cout << "Juice making process finished!" << endl;
    return 0;
}

