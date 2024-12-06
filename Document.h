#pragma once
#include "GraphicPrimitive.h"
#include <vector>
#include <memory>

class Document {
private:
    std::vector<std::shared_ptr<GraphicPrimitive>> primitives;
    int documentID;

public:
    Document(int id) : documentID(id) {
        std::cout << "Document #" << documentID << " created." << std::endl;
    }

    void addPrimitive(std::shared_ptr<GraphicPrimitive> primitive) {
        primitives.push_back(primitive);
        primitive->logInfo();
    }

    void removePrimitive(size_t index) {
        if (index < primitives.size()) {
            std::cout << "Removing primitive at index " << index << "." << std::endl;
            primitives.erase(primitives.begin() + index);
        } else {
            std::cout << "Invalid index for removal." << std::endl;
        }
    }

    void logPrimitives() const {
        std::cout << "Document #" << documentID << " contains the following primitives:" << std::endl;
        for (const auto& primitive : primitives) {
            primitive->logInfo();
        }
    }
};
