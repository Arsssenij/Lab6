#include "Controller.h"
#include "GraphicPrimitive.h"

int main() {
    Controller controller;

    // Создаем новый документ
    controller.createNewDocument(1);

    // Добавляем примитивы
    controller.addPrimitiveToDocument(std::make_shared<Rectangle>());
    controller.addPrimitiveToDocument(std::make_shared<Circle>());
    controller.addPrimitiveToDocument(std::make_shared<Line>());

    // Отображаем информацию о документе
    controller.displayDocumentInfo();

    // Удаляем примитив
    controller.removePrimitiveFromDocument(1);

    // Отображаем информацию снова
    controller.displayDocumentInfo();

    return 0;
}
