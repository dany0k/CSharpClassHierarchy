//
// Created by Den on 14.03.2023.
//
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <exception>

#include "CSharpHierarchy.h"
#include "./models/CSharpClass.h"
#include "./models/CSharpNamespace.h"

CSharpHierarchy::CSharpHierarchy() {
    std::vector<CSharpClass> cSharpClasses;
    std::vector<CSharpNamespace> cSharpNamespaces;
}

const std::vector<CSharpClass> &CSharpHierarchy::getClasses() const {
    return cSharpClasses;
}

void CSharpHierarchy::setClass(CSharpClass cSharpClass) {
    cSharpClasses.push_back(cSharpClass);
}

const std::vector<CSharpNamespace> &CSharpHierarchy::getNamespaces() const {
    return cSharpNamespaces;
}

void CSharpHierarchy::setNamespace(CSharpNamespace cSharpNamespace) {
    cSharpNamespaces.push_back(cSharpNamespace);
}


void CSharpHierarchy::createNamespace(std::string name) {
    CSharpNamespace cSharpNamespace(std::move(name));
    cSharpNamespaces.push_back(cSharpNamespace);
}

CSharpNamespace& CSharpHierarchy::getNamespaceByName(const std::string& cSharpNamespaceName) {
    for (CSharpNamespace& nsp: cSharpNamespaces) {
        if (nsp.getName() == cSharpNamespaceName) {
            return nsp;
        }
    }
}

void CSharpHierarchy::createClass(std::string name,
                                  std::vector<CSharpField> fields,
                                  std::vector<CSharpMethod> methods,
                                  TYPE type) {
    CSharpClass cSharpClass(std::move(name), std::move(fields), std::move(methods), type);
    cSharpClasses.push_back(cSharpClass);
}

void CSharpHierarchy::createClass(std::string name, TYPE type) {}

CSharpClass& CSharpHierarchy::getClassByName(const std::string& cSharpClassName) {
    for (CSharpClass& cls: cSharpClasses) {
        if (cls.getClassName() == cSharpClassName) {
            return cls;
        }
    }
}

int CSharpHierarchy::getNamespaceIdByName(std::string namespaceName) {
    for (int i = 0; i < cSharpNamespaces.size(); ++i) {
        if (cSharpNamespaces.at(i).getName() == namespaceName) {
            return i;
        }
    }
    return -1;
}

void CSharpHierarchy::addClassToNamespace(const std::string& className, const std::string& namespaceName) {
    CSharpClass cSharpClass = getClassByName(className);
    CSharpNamespace cSharpNamespace = getNamespaceByName(namespaceName);
    this->cSharpNamespaces.at(getNamespaceIdByName(namespaceName)).addClass(cSharpClass);
    cSharpNamespace.addClass(cSharpClass);
}

void CSharpHierarchy::addParents(CSharpClass& currClass, std::string parentClassName) {
    for (CSharpClass cls : cSharpClasses) {
        if (cls.getClassName() == parentClassName) {
            currClass.setParentClass(cls);
        }
    }
}

void CSharpHierarchy::deleteClassByName(std::string className) {
    for (int i = 0; i < cSharpClasses.size(); i++) {
        if (cSharpClasses.at(i).getClassName() == className) {
            cSharpClasses.erase(cSharpClasses.begin() + i);
            return;
        }
    }
    throw std::exception();
}
void CSharpHierarchy::deleteNamespaceByName(std::string namespaceName) {
    for (int i = 0; i < cSharpNamespaces.size(); i++) {
        if (cSharpNamespaces.at(i).getName() == namespaceName) {
            cSharpNamespaces.erase(cSharpNamespaces.begin() + i);
            return;
        }
    }
    throw std::exception();
}

void CSharpHierarchy::updateNamespaceByName(std::string namespaceName, std::string newNamespaceName) {
    for (CSharpNamespace& nsp: cSharpNamespaces) {
        if (nsp.getName() == namespaceName) {
            nsp.setName(newNamespaceName);
            return;
        }
    }
    throw std::exception();
}

std::string CSharpHierarchy::namespacesToString() {
    std::string res;
    for (CSharpNamespace nsp : cSharpNamespaces) {
        res.append(nsp.toString() + "\n");
    }
    return res;
}

std::string CSharpHierarchy::classesToString() {
    std::string res;
    for (CSharpClass cls : cSharpClasses) {
        res.append(cls.toString() + "\n");
    }
    return res;
}

void CSharpHierarchy::updateClassByName(std::string className, std::string newClassName,
                                        std::vector<CSharpField> fields,
                                        std::vector<CSharpMethod> methods,
                                        CSharpClass parent) {
    for (CSharpClass& cls: cSharpClasses) {
        if (cls.getClassName() == className) {
            if (!newClassName.empty()) {
                cls.setClassName(newClassName);
            }
            if (!fields.empty()) {
                cls.addFields(fields);
            }
            if (!methods.empty()) {
                cls.addMethods(methods);
            }
            if (!parent.getClassName().empty()) {
                cls.setParentClass(parent);
            }
        } else {
            throw std::exception();
        }
    }
}
