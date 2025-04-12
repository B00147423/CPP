#include <iostream>
#include <cmath>  // For mathematical functions like sqrt()

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double area() const = 0;

    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape {
    private:
        double radius;

    public:
        // Constructor to initialize the radius
        Circle(double r) : radius(r) {}

        // Override the area function to compute the area of a circle
        double area() const override {
            return M_PI * radius * radius;  // Area of a circle (πr²)
        }
};

class Triangle : public Shape{
    public: 
        int height;
        int base;

    public:
        Triangle(double b, double h) : base(b), height(h) {}

        double area() const override {
            return (base * height) / 2.0; 
        }
};

class Square: public Shape{
    public :
        double side;

    public:
        Square(double side) :side(side) {}

        double area() const override{
            return side * side; 
        }
    
};

int main() {
    // Create an array of Shape* pointers
    Shape* shapes[3];

    // Add different shapes to the array
    shapes[0] = new Circle(5.0);       // Circle with radius 5
    shapes[1] = new Triangle(10.0, 8.0);  // Triangle with base 10 and height 8
    shapes[2] = new Square(6.0);       // Square with side 6

    // Calculate and output the area of each shape using polymorphism
    for (int i = 0; i < 3; ++i) {
        std::cout << "Area of shape " << (i + 1) << ": " << shapes[i]->area() << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}