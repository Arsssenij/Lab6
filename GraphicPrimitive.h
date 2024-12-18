#ifndef GRAPHICPRIMITIVE_H
#define GRAPHICPRIMITIVE_H

#include <string>
#include <sstream>

class Primitive {
public:
    Primitive(const std::string& name, const std::string& type) : name(name), type(type) {}

    std::string getName() const {
        return name;
    }

    virtual std::string getType() const {
        return type;
    }

    virtual ~Primitive() = default; //  деструктор производного класса,  компилятор сгенерирует реализацию по умолчанию для деструктора

    virtual void draw() = 0; //  виртуальный метод для отрисовки примитива
    virtual std::string get() const = 0; // виртуальный метод, возвращающий строку с описанием примитива

private:
    std::string name;
    std::string type;
};

class Rectangle : public Primitive {
public:
    Rectangle(const std::string& name, double width, double height) :
        Primitive(name, "rectangle"), width(width), height(height) {}

    void draw() override { //выводит описание прямоугольника
        std::cout << "Отрисовка прямоугольника " << getName() << " (стороны: " << width << ", " << height << ")" << std::endl;
    }
    double getWidth() const { return width; }

    std::string get() const override {//возвращает строку с описанием прямоугольника
        return "прямоугольника " + getName() + " (стороны: " + std::to_string(width) + ", " + std::to_string(height) + ")";
    }

private:
    double width;
    double height;
};

class Square : public Rectangle { // Наследуется от Rectangle
public:
    Square(const std::string& name, double side) : Rectangle(name, side, side) {} 

    void draw() override {
        std::cout << "Отрисовка квадрата " << getName() << " (сторона: " << getWidth() << ")" << std::endl; 
    }

    std::string get() const override {
        return "квадрата " + getName() + " (сторона: " + std::to_string(getWidth()) + ")";
    }

    std::string getType() const override { // Переопределяем метод getType
        return "square";
    }
};


class Circle : public Primitive {
public:
    Circle(const std::string& name, double radius) : Primitive(name, "circle"), radius(radius) {}
    void draw() override {
        std::cout << "Отрисовка круга " << getName() << " (радиус: " << radius << ")" << std::endl;
    }
    std::string get() const override {
        return "круга " + getName() + " (радиус: " + std::to_string(radius) + ")";
    }

private:
    double radius;
};


#endif