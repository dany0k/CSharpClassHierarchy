//
// Created by Den on 12.03.2023.
//

#include <utility>
#include "CSharpField.h"

CSharpField::CSharpField() {}

CSharpField::CSharpField(std::string  field) : field(std::move(field)) {}

std::string CSharpField::getField() {
    return field;
}




