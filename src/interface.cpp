//
// Created by Den on 14.03.2023.
//

#include <iostream>

#include "CSharpHierarchy.h"

void sample(CSharpHierarchy& cSharpHierarchy) {
    cSharpHierarchy.createNamespace("A");

    std::vector<CSharpField> fields1;
    fields1.emplace_back("int a = 1;");
    fields1.emplace_back("int b = 2;");
    std::vector<CSharpMethod> methods1;
    methods1.emplace_back("void firstParentMethodOne();");
    methods1.emplace_back("void firstParentMethodTwo();");
    cSharpHierarchy.createClass("FirstParentClass", fields1, methods1, TYPE::BASE);
    cSharpHierarchy.addClassToNamespace("FirstParentClass", "A");

    std::vector<CSharpField> fields2;
    fields2.emplace_back("int c = 3;");
    fields2.emplace_back("int d = 4;");
    std::vector<CSharpMethod> methods2;
    methods2.emplace_back("void secondParentMethodOne();");
    methods2.emplace_back("void secondParentMethodTwo();");
    cSharpHierarchy.createClass("SecondParentClass", fields2, methods2, TYPE::BASE);
    cSharpHierarchy.addClassToNamespace("SecondParentClass", "A");

    std::vector<CSharpField> fields3;
    fields3.emplace_back("int e = 5;");
    fields3.emplace_back("int f = 6;");
    std::vector<CSharpMethod> methods3;
    methods3.emplace_back("void childMethod();");
    methods3.emplace_back("void childMethod();");
    cSharpHierarchy.createClass("ChildClass", fields3, methods3, TYPE::BASE);
    cSharpHierarchy.getClassByName("ChildClass")
    .setParentClass(cSharpHierarchy.getClassByName("SecondParentClass"));
    cSharpHierarchy.addClassToNamespace("ChildClass", "A");

    std::cout << cSharpHierarchy.getNamespaceByName("A").toString() << std::endl;
}

TYPE inputType() {
    char userChoice;
    TYPE type;
    std::cout << "Input csharpClassType a - abstruct, b - base, d - derived" << std::endl;
    std::cin >> userChoice;
    if (userChoice == 'a') {
        type = TYPE::ABSTRACT;
    } else if (userChoice == 'b') {
        type = TYPE::BASE;
    } else if (userChoice == 'd') {
        type == TYPE::DERIVED;
    } else {
        std::cout << "Error!" << std::endl;
    }
    return type;
}

std::vector<CSharpField> inputClassFields() {
    char userChoice;
    std::string field;
    std::vector<CSharpField> fields;
    while (true) {
        std::cout << "Input fields? y/n" << std::endl;
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::cout << "Input field" << std::endl;
            while (std::getline(std::cin, field)) {
                if (!field.empty()) {
                    break;
                }
            }
            fields.emplace_back(field);
        } else if (userChoice == 'n' && !fields.empty()) {
            break;
        } else {
            std::cout << "Input mismatch" << std::endl;
            break;
        }
    }
    return fields;
}

std::vector<CSharpMethod> inputClassMethods() {
    char userChoice;
    std::string method;
    std::vector<CSharpMethod> methods;
    while (true) {
        std::cout << "Input methods? y/n" << std::endl;
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::cout << "Input method" << std::endl;
            while (std::getline(std::cin, method)) {
                if (!method.empty()) {
                    break;
                }
            }
            methods.emplace_back(method);
        } else if (userChoice == 'n' && !methods.empty()) {
            break;
        } else {
            std::cout << "Input mismatch" << std::endl;
            break;
        }
    }
    return methods;
}

CSharpClass inputParents(const std::vector<CSharpClass> classes) {
    CSharpClass parentClass;
    char userChoice;
    if (classes.size() > 1) {
        std::cout << "Has parent class? y/n";
        std::cin >> userChoice;
        if (userChoice == 'y') {
            std::string parent_class_name;
            std::cout << "Type class name" << std::endl;
            while (std::getline(std::cin, parent_class_name)) {
                if (!parent_class_name.empty()) { break; }
            }
            for (CSharpClass cls : classes) {
                if (cls.getClassName() == parent_class_name) {
                    parentClass = cls;
                }
            }
        }
    }
    return parentClass;
}

void userInput(CSharpHierarchy& cSharpHierarchy) {
    int userChoice;
    while (true) {
        std::cout << "Choose action:\n"
                     "1 - Create namespace\n"
                     "2 - Create new class\n"
                     "3 - Update class\n"
                     "4 - Update namespace\n"
                     "5 - Delete class\n"
                     "6 - Delete namespace\n"
                     "7 - Show all classes\n"
                     "8 - Show all namespaces with its classes" << std::endl;
        std::cin >> userChoice;
        switch (userChoice) {
            case 1: {
                std::string namespaceName;
                std::cout << "Input namespace name" << std::endl;
                std::cin >> namespaceName;
                cSharpHierarchy.createNamespace(namespaceName);
                std::cout << "Completed!" << std::endl;
                break;
            }
            case 2: {
                // CSharpClass fields
                std::string className;
                std::string field;
                std::string method;
                // Future class that will be filled by user
                std::cout << "Input class name" << std::endl;
                std::cin >> className;
                TYPE type = inputType();
                std::vector<CSharpField> fields = inputClassFields();
                std::vector<CSharpMethod> methods = inputClassMethods();
                cSharpHierarchy.createClass(className, fields, methods, type);
                CSharpClass parent = inputParents(cSharpHierarchy.getClasses());
                cSharpHierarchy.addParents(cSharpHierarchy.getClassByName(className), parent.getClassName());
                if (cSharpHierarchy.getNamespaces().size() > 1) {
                    std::cout << "Would you like to add this class to namespace? y/n" << std::endl;
                    std::string namespaceName;
                    std::cin >> namespaceName;
                    if (namespaceName == "y") {
                        while (true) {
                            std::cout << "Input namespace name or type \"stop\" for cancel """ << std::endl;
                            std::cin >> namespaceName;
                            if (namespaceName == "stop") {
                                break;
                            }
                            cSharpHierarchy.addClassToNamespace(className, namespaceName);
                        }
                        break;
                    }
                }

                std::cout << "Class created!" << std::endl;
                break;
            }
            case 7: {
                std::cout << cSharpHierarchy.classesToString() << std::endl;
                break;
            }
            case 8: {
                std::cout << cSharpHierarchy.namespacesToString() << std::endl;
                break;
            }
            default: {
                std::cout << "Mismatch input" << std::endl;
                break;
            }
        }
    }
}

int main() {
    CSharpHierarchy cSharpHierarchy;
    std::cout << "1 - Sample\n2- User input\n" << std::endl;
    int user_choice = 0;
    std::cin >> user_choice;
    switch (user_choice) {
        case 1:
            sample(cSharpHierarchy);
            break;
        case 2:
            userInput(cSharpHierarchy);
            break;
        default:
            break;
    }
    return 0;
}
