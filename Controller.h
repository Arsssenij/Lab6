#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <unordered_map>
#include "Document.h"

class DocumentController {
public:
    void createDocument() {
        std::cout << "Введите имя нового документа: ";
        std::string name;
        std::cin >> name;
        if (documents.find(name) != documents.end()) {
            std::cout << "Документ с таким именем уже существует." << std::endl;
            return;
        }
        documents[name] = std::make_shared<Document>(name);
        std::cout << "Создан документ " << name << std::endl;
    }

    void openDocument(const std::string& name) {
        auto it = documents.find(name);
        if (it != documents.end()) {
            std::cout << "Открыт документ " << name << std::endl;
            it->second->drawAllPrimitives();
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

    void addPrimitive(const std::string& documentName, const std::string& type) {
        auto it = documents.find(documentName);
        if (it != documents.end()) {
            std::cout << "Введите имя примитива: ";
            std::string name;
            std::cin >> name;

            if (type == "rectangle") {
                double width, height;
                std::cout << "Введите ширину: ";
                std::cin >> width;
                std::cout << "Введите высоту: ";
                std::cin >> height;
                it->second->addPrimitive(std::make_shared<Rectangle>(name, width, height));
            } else if (type == "square") {
                double side;
                std::cout << "Введите длину стороны: ";
                std::cin >> side;
                it->second->addPrimitive(std::make_shared<Square>(name, side));
            } else if (type == "circle") {
                double radius;
                std::cout << "Введите радиус: ";
                std::cin >> radius;
                it->second->addPrimitive(std::make_shared<Circle>(name, radius));
            } else {
                std::cout << "Неподдерживаемый тип примитива.\n";
            }
        } else {
            std::cout << "Документ не найден.\n";
        }
    }

    void removePrimitive(const std::string& documentName, const std::string& primitiveName, const std::string& primitiveType) {
        auto it = documents.find(documentName);
        if (it != documents.end()) {
            it->second->removePrimitive(primitiveName, primitiveType);
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

    void exportPrimitive(const std::string& sourceDocName, const std::string& targetDocName, const std::string& primitiveName, const std::string& primitiveType) {
    auto sourceIt = std::find_if(documents.begin(), documents.end(), [&](const auto& pair) {
        return pair.second->getName() == sourceDocName;
    });

    if (sourceIt == documents.end()) {
        std::cout << "Исходный документ не найден." << std::endl;
        return;
    }

    auto targetIt = std::find_if(documents.begin(), documents.end(), [&](const auto& pair) {
        return pair.second->getName() == targetDocName;
    });

    if (targetIt == documents.end()) {
        std::cout << "Целевой документ не найден." << std::endl;
        return;
    }

    auto primitive = sourceIt->second->findPrimitive(primitiveName, primitiveType);
    if (!primitive) {
        std::cout << "Примитив не найден в исходном документе." << std::endl;
        return;
    }

    targetIt->second->addPrimitive(primitive);
    std::cout << "Примитив " << primitive->getName() << " экспортирован из " << sourceDocName << " в " << targetDocName << std::endl;
}


    void removeDocument(const std::string& name) {
        auto it = documents.find(name);
        if (it != documents.end()) {
            std::cout << "Удаление документа '" << name << "' и всех содержащихся примитивов:" << std::endl;
            it->second->deleteAllPrimitives();
            documents.erase(it);
        } else {
            std::cout << "Документ не найден." << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Document>> documents;
};

#endif
