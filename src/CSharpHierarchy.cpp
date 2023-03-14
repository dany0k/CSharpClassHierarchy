//
// Created by Den on 14.03.2023.
//
#include <utility>
#include <iostream>
#include <vector>
#include <string>

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

void CSharpHierarchy::addParents(CSharpClass currClass, std::string parentClassName) {
    for (CSharpClass cls : cSharpClasses) {
        if (cls.getClassName() == parentClassName) {
            currClass.setParentClass(cls);
        }
    }
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

