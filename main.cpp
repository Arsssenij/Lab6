#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Document.h"
#include "GraphicPrimitive.h"
#include "Controller.h"

void printMenu() {
    std::cout << "\nВыберите действие:\n";
    std::cout << "1. Создать документ\n";
    std::cout << "2. Открыть документ\n";
    std::cout << "3. Удалить документ\n";
    std::cout << "4. Добавить примитив\n";
    std::cout << "5. Удалить примитив\n";
    std::cout << "6. Экспортировать примитив\n";
    std::cout << "7. Выход\n";
    std::cout << "Введите номер действия: ";
}

int main() {
    DocumentController controller;

    while (true) {
        printMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                controller.createDocument();
                break;
            case 2: {
                std::string name;
                std::cout << "Введите имя документа: ";
                std::cin >> name;
                controller.openDocument(name);
                break;
            }
            case 3: {
                std::string name;
                std::cout << "Введите имя документа: ";
                std::cin >> name;
                controller.removeDocument(name);
                break;
            }
            case 4: {
                std::string docName, type;
                std::cout << "Введите имя документа: ";
                std::cin >> docName;
                std::cout << "Введите тип примитива (rectangle, square, circle): ";
                std::cin >> type;
                controller.addPrimitive(docName, type);
                break;
            }
            case 5: {
                std::string docName, primitiveName, primitiveType;
                std::cout << "Введите имя документа: ";
                std::cin >> docName;
                std::cout << "Введите тип примитива: ";
                std::cin >> primitiveType;
                std::cout << "Введите имя примитива: ";
                std::cin >> primitiveName;
                controller.removePrimitive(docName, primitiveName, primitiveType);
                break;
            }
            case 6: {
                std::string sourceDoc, targetDoc, primitiveName, primitiveType;
                std::cout << "Введите имя исходного документа: ";
                std::cin >> sourceDoc;
                std::cout << "Введите имя целевого документа: ";
                std::cin >> targetDoc;
                std::cout << "Введите тип примитива: ";
                std::cin >> primitiveType;
                std::cout << "Введите имя примитива: ";
                std::cin >> primitiveName;
                controller.exportPrimitive(sourceDoc, targetDoc, primitiveName, primitiveType);
                break;
            }
            case 7:
                std::cout << "Выход\n";
                return 0;
            default:
                std::cout << "Некорректный выбор.\n";
        }
    }
}
