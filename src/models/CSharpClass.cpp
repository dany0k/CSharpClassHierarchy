//
// Created by Den on 13.03.2023.
//

#include "CSharpClass.h"

#include <utility>

CSharpClass::CSharpClass() = default;

CSharpClass::CSharpClass(const std::string csharpClassName, CSharpNamespace csharpClassNamespace, TYPE type) :
        csharpClassName(csharpClassName),
        csharpClassNamespace(std::move(csharpClassNamespace)),
        csharpClassType(type) { }

CSharpClass::CSharpClass(const std::string csharpClassName,
                         CSharpNamespace csharpClassNamespace,
                         TYPE type,
                         const std::vector<CSharpClass>& parentClasses) :
        csharpClassName(csharpClassName),
        csharpClassNamespace(std::move(csharpClassNamespace)),
        csharpClassType(type),
        parentClasses(parentClasses) {
    if (!parentClasses.empty() && type != TYPE::ABSTRACT) {
        implementMethods();
    }
}

std::string CSharpClass::toString() const {
    std::string res;
    res.append("CSharpClassName: " + csharpClassName + "\n");
    for (const CSharpClass &cls: parentClasses) {
        res.append("Parent class: " + cls.csharpClassName + "\n");
    }
    res.append("CSharpClassType: ");
    if (csharpClassType == TYPE::ABSTRACT) {
        res.append("abstract\n");
    } else {
        res.append("common\n");
    }
    res.append("CSharpNamespace: " + csharpClassNamespace.getName() + "\n");
    for (CSharpField fld: fields) {
        res.append("CSharpField: " + fld.getField() + "\n");
    }
    for (CSharpMethod mtd: methods) {
        res.append("CSharpMethod: " + mtd.get_method() + "\n");
    }
    return res;
}

void CSharpClass::implementMethods() {
    for (const CSharpClass &cls: parentClasses) {
        for (const CSharpMethod &method: cls.methods) {
            this->methods.emplace_back(method);
        }
    }
}


void CSharpClass::setClassName(const std::string className) {
    CSharpClass::csharpClassName = className;
}

void CSharpClass::setParentClasses(const std::vector<CSharpClass> parentClasses) {
    implementMethods();
    CSharpClass::parentClasses = parentClasses;
}

void CSharpClass::setParentClass(CSharpClass parentClass) {
    this->parentClasses.emplace_back(parentClass);
    if (csharpClassType != TYPE::ABSTRACT) {
        implementMethods();
    }
}

void CSharpClass::setNameSpace(const CSharpNamespace nameSpace) {
    CSharpClass::csharpClassNamespace = nameSpace;
}

void CSharpClass::setFields(const std::vector<CSharpField> fields) {
    CSharpClass::fields = fields;
}

void CSharpClass::setMethods(const std::vector<CSharpMethod> methods) {
    CSharpClass::methods = methods;
}

void CSharpClass::setType(TYPE type) {
    CSharpClass::csharpClassType = type;
}

std::string CSharpClass::getClassName() const {
    return csharpClassName;
}


