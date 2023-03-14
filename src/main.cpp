//#include <iostream>
//#include <vector>
//#include <string>
//
//#include "./models/CSharpMethod.h"
//#include "./models/CSharpField.h"
//#include "./models/CSharpNamespace.h"
//#include "./models/CSharpClass.h"
//
////void create_sample() {
////    CSharpNamespace aNamespace("A");
////    CSharpClass firstParentClass(std::string("FirstParentClass"), TYPE::BASE);
////    std::vector<CSharpMethod> firstClassMethods;
////    firstClassMethods.emplace_back("void firstParentMethodSample();");
////    firstParentClass.setMethods(firstClassMethods);
////    std::vector<CSharpField> firstClassFields;
////    firstClassFields.emplace_back("int a = 2;");
////    firstClassFields.emplace_back("int b = 4;");
////    firstParentClass.setFields(firstClassFields);
////
////    CSharpClass secondParentClass(std::string("SecondParentClass"), TYPE::BASE);
////    std::vector<CSharpMethod> secondClassMethods;
////    secondClassMethods.emplace_back("void secondParentMethodSample();");
////    secondParentClass.setMethods(secondClassMethods);
////    std::vector<CSharpField> secondClassFields;
////    secondClassFields.emplace_back("int c = 6;");
////    secondClassFields.emplace_back("int d = 8;");
////    secondParentClass.setFields(secondClassFields);
////
////    CSharpClass childClass(std::string("childClass"), TYPE::DERIVED);
////    std::vector<CSharpMethod> childClassMethods;
////    childClassMethods.emplace_back("void childMethodSample();");
////    childClass.setMethods(childClassMethods);
////    std::vector<CSharpField> childClassFields;
////    childClassFields.emplace_back("int child1 = 54;");
////    childClassFields.emplace_back("int child2 = 55;");
////    childClass.setFields(childClassFields);
////    childClass.setParentClass(firstParentClass);
////    childClass.setParentClass(secondParentClass);
////
////    std::cout << firstParentClass.toString() << std::endl;
////    std::cout << secondParentClass.toString() << std::endl;
////    std::cout << childClass.toString() << std::endl;
////}
//
//void createSample() {
//    CSharpNamespace aNamespace("A");
//    CSharpClass firstParentClass(std::string("FirstParentClass"), TYPE::BASE);
//    std::vector<CSharpMethod> firstClassMethods;
//    firstClassMethods.emplace_back("void firstParentMethodSample();");
//    firstParentClass.setMethods(firstClassMethods);
//    std::vector<CSharpField> firstClassFields;
//    firstClassFields.emplace_back("int a = 2;");
//    firstClassFields.emplace_back("int b = 4;");
//    firstParentClass.setFields(firstClassFields);
//
//    CSharpClass secondParentClass(std::string("SecondParentClass"), TYPE::BASE);
//    std::vector<CSharpMethod> secondClassMethods;
//    secondClassMethods.emplace_back("void secondParentMethodSample();");
//    secondParentClass.setMethods(secondClassMethods);
//    std::vector<CSharpField> secondClassFields;
//    secondClassFields.emplace_back("int c = 6;");
//    secondClassFields.emplace_back("int d = 8;");
//    secondParentClass.setFields(secondClassFields);
//    aNamespace.addClass(secondParentClass);
//    aNamespace.addClass(firstParentClass);
//    std::cout << aNamespace.toString() << std::endl;
//}
//
//std::vector<CSharpField> inputClassFields() {
//    char userChoice;
//    std::string field;
//    std::vector<CSharpField> fields;
//    while (true) {
//        std::cout << "Input fields? y/n" << std::endl;
//        std::cin >> userChoice;
//        if (userChoice == 'y') {
//            std::cout << "Input field" << std::endl;
//            while (std::getline(std::cin, field)) {
//                if (!field.empty()) {
//                    break;
//                }
//            }
//            fields.emplace_back(field);
//        } else if (userChoice == 'n' && !fields.empty()) {
//            break;
//        } else {
//            std::cout << "Input mismatch" << std::endl;
//            break;
//        }
//    }
//    return fields;
//}
//
//std::vector<CSharpMethod> inputClassMethods() {
//    char userChoice;
//    std::string method;
//    std::vector<CSharpMethod> methods;
//    while (true) {
//        std::cout << "Input methods? y/n" << std::endl;
//        std::cin >> userChoice;
//        if (userChoice == 'y') {
//            std::cout << "Input method" << std::endl;
//            while (std::getline(std::cin, method)) {
//                if (!method.empty()) {
//                    break;
//                }
//            }
//            methods.emplace_back(method);
//        } else if (userChoice == 'n' && !methods.empty()) {
//            break;
//        } else {
//            std::cout << "Input mismatch" << std::endl;
//            break;
//        }
//    }
//    return methods;
//}
//
//TYPE inputType() {
//    char userChoice;
//    TYPE type;
//    std::cout << "Input csharpClassType a - abstruct, b - base, d - derived" << std::endl;
//    std::cin >> userChoice;
//    if (userChoice == 'a') {
//        type = TYPE::ABSTRACT;
//    } else if (userChoice == 'b') {
//        type = TYPE::BASE;
//    } else if (userChoice == 'd') {
//        type == TYPE::DERIVED;
//    } else {
//        std::cout << "Error!" << std::endl;
//    }
//    return type;
//}
//
//CSharpClass inputParents(const std::vector<CSharpClass> classes) {
//    CSharpClass parentClass;
//    char userChoice;
//    if (!classes.empty()) {
//        std::cout << "Has parent class? y/n";
//        std::cin >> userChoice;
//        if (userChoice == 'y') {
//            std::string parent_class_name;
//            std::cout << "Type class name" << std::endl;
//            while (std::getline(std::cin, parent_class_name)) {
//                if (!parent_class_name.empty()) { break; }
//            }
//            for (CSharpClass cls : classes) {
//                if (cls.getClassName() == parent_class_name) {
//                    parentClass = cls;
//                }
//            }
//        }
//    }
//    return parentClass;
//}
//
//void showClasses(std::vector<CSharpClass> classes) {
//    if (classes.empty()) {
//        std::cout << "No classes" << std::endl;
//        return;
//    }
//    for (CSharpClass cls: classes) {
//        std::cout << cls.toString() << std::endl;
//    }
//}
//
//void showNamespaces(std::vector<CSharpNamespace> namespaces) {
//    if (namespaces.empty()) {
//        std::cout << "No namespaces" << std::endl;
//        return;
//    }
//    for (CSharpNamespace ns: namespaces) {
//        std::cout << ns.toString() << std::endl;
//    }
//}
//
//void userInput() {
//    int userChoice;
//    std::vector<CSharpClass> classes;
//    std::vector<CSharpNamespace> namespaces;
//    TYPE type;
//    while (true) {
//        std::cout << "Choose action:\n"
//                     "1 - Create namespace\n"
//                     "2 - Create new class\n"
//                     "3 - Show classes\n"
//                     "4 - Show all namespaces with its classes" << std::endl;
//        std::cin >> userChoice;
//        switch (userChoice) {
//            case 1: {
//                std::string namespaceName;
//                std::cout << "Input namespace name" << std::endl;
//                std::cin >> namespaceName;
//                namespaces.emplace_back(namespaceName);
//                std::cout << "Completed!" << std::endl;
//                break;
//            }
//            case 2: {
//                // CSharpClass fields
//                std::string className;
//                std::string field;
//                std::string method;
//                // Future class that will be filled by user
//                std::cout << "Input class name" << std::endl;
//                std::cin >> className;
//                type = inputType();
//                CSharpClass currClass(className, type);
//                std::vector<CSharpField> fields = inputClassFields();
//                currClass.setFields(fields);
//                std::vector<CSharpMethod> methods = inputClassMethods();
//                currClass.setMethods(methods);
//                CSharpClass parent = inputParents(classes);
//                currClass.setParentClass(parent);
//                std::cout << "Would you like to add this class to namespace? y/n" << std::endl;
//                std::string namespaceName;
//                std::cin >> namespaceName;
//                if (namespaceName == "y") {
//                    while (true) {
//                        std::cout << "Input namespace name or type \"stop\" for cancel """ << std::endl;
//                        std::cin >> namespaceName;
//                        if (namespaceName == "stop") {
//                            break;
//                        }
//                        for (CSharpNamespace& ns: namespaces) {
//                            if (ns.getName() == namespaceName) {
//                                std::cout << "HERE" << std::endl;
//                                ns.addClass(currClass);
//                                break;
//                            } else {
//                                std::cout << "No such namespace" << std::endl;
//                            }
//                        }
//                        break;
//                    }
//                }
//                std::cout << "Class created!" << std::endl;
//                classes.emplace_back(currClass);
//                break;
//            }
//            case 3: {
//                showClasses(classes);
//                break;
//            }
//            case 4: {
//                showNamespaces(namespaces);
//                break;
//            }
//            default: {
//                std::cout << "Mismatch input" << std::endl;
//                break;
//            }
//        }
//    }
//}
//
//void interface() {
//    std::cout << "1 - Sample\n2- User input\n" << std::endl;
//    int user_choice = 0;
//    std::cin >> user_choice;
//    switch (user_choice) {
//        case 1:
//            createSample();
//            break;
//        case 2:
//            userInput();
//            break;
//        default:
//            break;
//    }
//}
//
//int main() {
//    interface();
//    return 0;
//}