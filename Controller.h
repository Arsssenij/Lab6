#pragma once
#include "Document.h"
#include "GraphicPrimitive.h"
#include <memory>

class Controller {
private:
    std::unique_ptr<Document> document;

public:
    Controller() : document(nullptr) {}

    void createNewDocument(int id) {
        document = std::make_unique<Document>(id);
    }

    void addPrimitiveToDocument(std::shared_ptr<GraphicPrimitive> primitive) {
        if (document) {
            document->addPrimitive(primitive);
        } else {
            std::cout << "No document to add primitives to." << std::endl;
        }
    }

    void removePrimitiveFromDocument(size_t index) {
        if (document) {
            document->removePrimitive(index);
        } else {
            std::cout << "No document to remove primitives from." << std::endl;
        }
    }

    void displayDocumentInfo() const {
        if (document) {
            document->logPrimitives();
        } else {
            std::cout << "No document to display." << std::endl;
        }
    }
};
