#include <iostream>
#include <cmath>

using namespace std;

class Pair {
private:
    int a, b;

public:
    Pair() {}
    Pair(int x, int y) : a(x), b(y) {}

    void set_a(int x) { a = x; }
    void set_b(int y) { b = y; }
    int get_a() const { return a; }
    int get_b() const { return b; }
};

class Rectangle : public Pair {
private:
    int area, perimeter;

public:
    Rectangle() : area(0), perimeter(0) {}
    Rectangle(int a, int b) : Pair(a, b), area(a* b), perimeter(2 * (a + b)) {}

    void set_area(int a) { area = a; }
    void set_perimeter(int p) { perimeter = p; }
    int get_area() const { return area; }
    int get_perimeter() const { return perimeter; }

    friend ostream& operator<<(ostream& os, const Rectangle& rect) {
        os << "Rectangle info:" << endl;
        os << "a: " << rect.get_a() << endl;
        os << "b: " << rect.get_b() << endl;
        os << "Area: " << rect.get_area() << endl;
        os << "Perimeter: " << rect.get_perimeter() << endl<< endl;
        return os;
    }

    int S() const { return get_a() * get_b(); }
    int P() const { return 2 * (get_a() + get_b()); }
};

class Parallelogram : public Pair {
private:
    int area, perimeter;
    double Fi;

public:
    Parallelogram() : area(0), perimeter(0), Fi(0) {}
    Parallelogram(int a, int b, int fi) : Pair(a, b), Fi(fi * 3.14 / 180.0) {}

    void set_area(int a) { area = a; }
    void set_perimeter(int p) { perimeter = p; }
    void set_fi(int a) { Fi = a; }
    int get_area() const { return area; }
    int get_perimeter() const { return perimeter; }
    double get_fi() const { return Fi; }

    int S()  { return get_a() * get_b() * sin(Fi); }
    int P()  { return 2 * (get_a() + get_b()); }

    friend ostream& operator<<(ostream& os, const Parallelogram rect) {
        os << "Parallelogram info:" << endl;
        os << "a: " << rect.get_a() << endl;
        os << "b: " << rect.get_b() << endl;
        os << "Fi: " << rect.get_fi()/3.14*180.0 << endl;
        os << "Area: " << rect.get_area() << endl;
        os << "Perimeter: " << rect.get_perimeter() << endl<< endl;
        
        return os;
    }
};
class Rhombus :public Parallelogram {
public:
    Rhombus() {};
    Rhombus(int a, int fi):Parallelogram(a, a, fi) {};
};
class Square : public Rhombus {
public:
    Square() {};
    Square(int a, int fi):Rhombus(a,fi) {};
};

int main() {
    Rectangle test(4, 5);
    test.set_area(test.S());
    test.set_perimeter(test.P());
    cout << test;
    Parallelogram test1(4, 5, 30);
    test1.set_area(test1.S());
    test1.set_perimeter(test1.P());
    cout << test1;
    Rhombus test2(4,30);
    test2.set_area(test2.S());
    test2.set_perimeter(test2.P());
    cout << test2;  
    Square test3(5,90);
    test3.Rhombus::set_area(test3.Rhombus::S());
    test3.Rhombus::set_perimeter(test3.Rhombus::P());
    cout << test3;
    return 0;
}
