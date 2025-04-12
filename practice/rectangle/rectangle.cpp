/*1. Class and Object Implementation
Problem: Create a class Rectangle that has 
two private data members: length and width. 
The class should include:
A constructor to initialize these attributes.
A member function area() that returns the area of the rectangle.
A member function perimeter() that returns the perimeter of the rectangle.
Write a test program that creates multiple Rectangle objects and prints out their areas and perimeters.
Bonus: Add setters and getters for length and width, and ensure that negative values are not accepted.
*/
#include <iostream>
using namespace std;
class Rectangle {
    private:
        int length;
        int width;

    public:
        Rectangle (int length, int width){
            this->length = length;
            this->width = width;
        }
        int getLength(){
            return length;
        }

        int getWidth(){
            return width;
        }
        void setLength(int length){
            this->length = length;
        }

        void setWidth(int width){
            this->width = width;
        }
        int area(){
            return (length * width);
        }

        int perimeter(){
            return 2* (length + width);
        }

        void RectangleDetail(){
            cout << "Length: " << length <<", Width: " << width << endl;
            cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
        }
};

int main(){
    Rectangle rect(5, 10);

    rect.RectangleDetail();
    return 0;
}

