//
// Created by Den on 12.03.2023.
//

#include "CSharpMethod.h"

CSharpMethod::CSharpMethod() { }

CSharpMethod::CSharpMethod(const std::string method) : method(method) {}

std::string CSharpMethod::get_method() {
    return method;
}

