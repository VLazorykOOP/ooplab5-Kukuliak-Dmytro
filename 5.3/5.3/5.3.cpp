#include <iostream>
using namespace std;

class dot {
private:
    int x, y;

public:
    dot() : x(0), y(0) {}
    dot(int a, int b) : x(a), y(b) {}

    int get_x() const { return x; }
    int get_y() const { return y; }
    void set_x(int a) { x = a; }
    void set_y(int a) { y = a; }

    friend ostream& operator<<(ostream& os, const dot& a) {
        os << "Dot info:" << endl;
        os << "X: " << a.get_x() << endl;
        os << "Y: " << a.get_y() << endl;
        return os;
    }

    // Конструктор копіювання
    dot(const dot& other) : x(other.x), y(other.y) {
        cout << "dot copy constructor called" << endl;
    }

    // Оператор присвоювання
    dot& operator=(const dot& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        cout << "dot assignment operator called" << endl;
        return *this;
    }
};

class Cdot : public dot {
private:
    int R, G, B;

public:
    Cdot() {};
    Cdot(int a, int b, int c) : R(a), G(b), B(c), dot() {}
    Cdot(int a, int b, int c, int d, int e) : R(a), G(b), B(c), dot(c, d) {}
    Cdot(dot&& a) : dot(a) {
        a.set_x(0);
        a.set_y(0);
    }

    friend ostream& operator<<(ostream& os, const Cdot& a) {
        os << "Cdot info:" << endl;
        os << "X: " << a.get_x() << endl;
        os << "Y: " << a.get_y() << endl;
        os << "R: " << a.R << endl;
        os << "G: " << a.G << endl;
        os << "B: " << a.B << endl;
        return os;
    }

    // Конструктор копіювання для Cdot
    Cdot(const Cdot& other) : dot(other), R(other.R), G(other.G), B(other.B) {
        cout << "Cdot copy constructor called" << endl;
    }

    // Оператор присвоювання для Cdot
    Cdot& operator=(const Cdot& other) {
        if (this != &other) {
            static_cast<dot&>(*this) = other;
            R = other.R;
            G = other.G;
            B = other.B;
        }
        cout << "Cdot assignment operator called" << endl;
        return *this;
    }
};

int main() {
    dot test(5, 5);
    cout << test;

    // Тест конструктора копіювання та оператора присвоювання для dot
    dot test_copy(test);
    dot test_assign;
    test_assign = test;

    cout << "-----------" << endl;

    Cdot test1(std::move(test));
    cout << test1;

    // Перевірка, що значення dot змінено
    cout << test;

    // Тест конструктора копіювання та оператора присвоювання для Cdot
    Cdot test1_copy(test1);
    Cdot test1_assign;
    test1_assign = test1;

    return 0;
}
