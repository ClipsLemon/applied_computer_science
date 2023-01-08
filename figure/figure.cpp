#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//class figure {
//protected:
//    double x, y;
//public:
//    figure() {
//        x = 0;
//        y = 0;
//    }
//    figure(double nx, double ny) {
//        x = nx;
//        y = ny;
//    }
//    void print() {
//        cout << "(" << x << ", " << y << ")" << endl;
//    }
//    double virtual area() = 0;
//    double virtual length() = 0;
//};
//class circle : public figure {
//protected:
//    double r;
//public:
//    circle(double nx, double ny, double nr) {
//        x = nx;
//        y = ny;
//        r = nr;
//    }
//    double area() {
//        return (4 * atan(1) * r * r);
//    }
//    double length() {
//        return (2 * 4 * atan(1) * r);
//    }
//
//};
//
//class square : public figure {
//protected:
//    double edge;
//public:
//    square(double nx, double ny, double nedge)
//    {
//        x = nx, y = ny, edge = nedge;
//    }
//    double area() {
//        return (x * y);
//    }
//    double length() {
//        return (4 * edge);
//    }
//
//    void print() {
//        cout << "(" << x << ", " << y << ")" << endl;
//        cout << "(" << x+edge << ", " << y << ")" << endl;
//        cout << "(" << x+edge << ", " << y+edge << ")" << endl;
//        cout << "(" << x << ", " << y+edge << ")" << endl;
//    }
//};

class point {
private:
    double x, y;
public:
    point() {
        x = 0;
        y = 0;
    }
    point(double nx, double ny) {
        //перегрузка конструктора, при наличии аргументов вызывается данный конструктор класса
        x = nx;
        y = ny;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    void setX(double nx) {
        x = nx;
    }
    void setY(double ny) {
        y = ny;
    }
    void printPoint() {
        cout << setprecision(2) << fixed << " (" << x << ", " << y << ")";
    }
};

class triangle // класс треугольника
{
protected: // защищенное создание координат треугольника
    double x1, x2, x3;
    double y1, y2, y3;
public:
    triangle() // конструктор класса
    {
        //x1 = nx1; x2 = nx2; x3 = nx3;
        //y1 = ny1; y2 = ny2; y3 = ny3;
    }

    void print() {        // вывод координат треугольника 
        cout << "The triangle's coordinates:" << endl;
        cout << "(" << x1 << ", " << y1 << ")" << endl;
        cout << "(" << x2 << ", " << y2 << ")" << endl;
        cout << "(" << x3 << ", " << y3 << ")" << endl;
    }

    double first_side() {  // возвращает длину первой стороны
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    double second_side() { // возвращает длину второй стороны
        return sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    }
    double third_side() {  // возвращает длину третьей стороны
        return sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    }
    double p() {           // возвращает полупериметр
        return ((first_side() + second_side() + third_side()) / 2);
    }

    double area() { // площадь по формуле Герона
        double onehalf_p = p();
        return sqrt(onehalf_p * (onehalf_p - first_side()) * (onehalf_p - second_side()) * (onehalf_p - third_side()));
    }

    double length() {
        return (p() * 2);
    }
};

int main() {
    //figure *p, *p2;
    //circle *c;
    //square *sq;
    /*p = new figure(2, 3);
    p -> print();*/
    //p2 = new circle(5, 6, 8);
    //c = new circle(2, 3, 4);
    //sq = new square(4, 5, 10);
    //p2->area();
    //cout << "Square coordinates:" << endl;
    //sq->print();
    //cout << "Square area: " << sq->area() << endl;
    //cout << "Square length: " << sq->length() << endl;

    triangle *fig = new triangle(1, 2, 5, 6, 1, 6);
    cout << "Area of triangle:" << fig->area() << endl;
    cout << "Length of triangle:" << fig->length() << endl;
    delete fig;
    return 0;


}//треугольник, принимает три пары чисел + длина и площадь
// потом добавить инкапсуляцию метода point для точек треугольника и квадрата
// изучи чисто виртуальные функции, private, public, protected class