#include <iostream>
#include <cmath>
#include <vector>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

//Circle
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}

    void draw() const override {
        int r = radius;
        for (int y = -r; y <= r; y++) {
            for (int x = -r; x <= r; x++) {
                if (x * x + y * y <= r * r)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << "\n";
        }
    }

    double area() const override {
        return 3.1415 * radius * radius;
    }
};

// Square 
class Square : public Shape {
    int side;
public:
    Square(int s) : side(s) {}

    void draw() const override {
        for (int y = 0; y < side; y++) {
            for (int x = 0; x < side; x++)
                std::cout << "*";
            std::cout << "\n";
        }
    }

    double area() const override {
        return side * side;
    }
};

// Rectangle 
class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}

    void draw() const override {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                std::cout << "*";
            std::cout << "\n";
        }
    }

    double area() const override {
        return width * height;
    }
};

// Triangle 
class Triangle : public Shape {
    int height;
public:
    Triangle(int h) : height(h) {}

    void draw() const override {
        for (int y = 1; y <= height; y++) {
            for (int x = 0; x < y; x++)
                std::cout << "*";
            std::cout << "\n";
        }
    }

    double area() const override {
        return 0.5 * height * height;
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::make_unique<Circle>(6));
    shapes.push_back(std::make_unique<Square>(5));
    shapes.push_back(std::make_unique<Rectangle>(10, 3));
    shapes.push_back(std::make_unique<Triangle>(7));

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Square: " << shape->area() << "\n\n";
    }

    return 0;
}
