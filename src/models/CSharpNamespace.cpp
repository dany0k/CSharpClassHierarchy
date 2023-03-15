//
// Created by Den on 13.03.2023.
//

#include <exception>
#include <utility>
#include "CSharpNamespace.h"

CSharpNamespace::CSharpNamespace() = default;

std::string CSharpNamespace::getName() const {
    return name;
}

CSharpNamespace::CSharpNamespace(std::string name) : name(std::move(name)) {}
CSharpNamespace::CSharpNamespace(std::string name, CSharpClass childClass) :
    name(std::move(name)) {
    this->classes.emplace_back(childClass);
}

void CSharpNamespace::addClass(CSharpClass childClass) {
    this->classes.push_back(childClass);
}

std::vector<CSharpClass>& CSharpNamespace::getClasses() {
    return classes;
}

void CSharpNamespace::setName(std::string namespaceName) {
    this->name = std::move(namespaceName);
}

