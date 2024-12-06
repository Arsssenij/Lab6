#pragma once
#include <iostream>
#include <memory>

class GraphicPrimitive {
public:
    virtual ~GraphicPrimitive() = default;

    virtual void draw() const = 0;
    virtual void logInfo() const = 0;
};

class Rectangle : public GraphicPrimitive {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle." << std::endl;
    }

    void logInfo() const override {
        std::cout << "Rectangle created." << std::endl;
    }
};

class Circle : public GraphicPrimitive {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    void logInfo() const override {
        std::cout << "Circle created." << std::endl;
    }
};

class Line : public GraphicPrimitive {
public:
    void draw() const override {
        std::cout << "Drawing a line." << std::endl;
    }

    void logInfo() const override {
        std::cout << "Line created." << std::endl;
    }
};
