//
// Created by Den on 13.03.2023.
//

#include "CSharpNamespace.h"

#include <utility>


CSharpNamespace::CSharpNamespace() = default;

std::string CSharpNamespace::getName() const {
    return name;
}

CSharpNamespace::CSharpNamespace(std::string name) : name(std::move(name)) {

}
