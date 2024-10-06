#include<iostream>
#include <cmath>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float calculateAreaMethod1() {
        return length * width;
    }

    float calculateAreaMethod2() {
        return fmax(length, width) * fmin(length, width);
    }

    float calculateAreaMethod3() {
        return pow(length * width, 0.5);
    }

    float calculateAreaMethod4() {
        return 2 * (length + width);
    }
};

int main() {
    float length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    Rectangle rectangle(length, width);

    float area1 = rectangle.calculateAreaMethod1();
    cout << "Area using method 1: " << area1 << endl;

    float area2 = rectangle.calculateAreaMethod2();
    cout << "Area using method 2: " << area2 << endl;

    float area3 = rectangle.calculateAreaMethod3();
    cout << "Area using method 3: " << area3 << endl;

    float area4 = rectangle.calculateAreaMethod4();
    cout << "Area using method 4: " << area4 << endl;

    return 0;
}

