//
// Created by Den on 13.03.2023.
//

#ifndef CSHARPCLASSHIERARCHY_CSHARPCLASS_H
#define CSHARPCLASSHIERARCHY_CSHARPCLASS_H

#include <vector>
#include <string>

#include "CSharpMethod.h"
#include "CSharpField.h"

enum class TYPE {
    BASE,
    DERIVED,
    ABSTRACT
};

class CSharpClass {
private:
    std::string csharpClassName;
    std::vector<CSharpField> fields;
    std::vector<CSharpMethod> methods;
    std::vector<CSharpClass> parentClasses;
    TYPE csharpClassType;
    void implementMethods();
public:
    CSharpClass();

    CSharpClass(std::string csharpClassName,
                TYPE type);

    CSharpClass(std::string csharpClassName,
                TYPE type,
                const std::vector<CSharpClass>& parentClasses);

    CSharpClass(std::string  csharpClassName,
                             std::vector<CSharpField> fields,
                             std::vector<CSharpMethod> methods,
                             TYPE type);

    std::string toString() const;

    void setClassName(std::string csharpClassName);

    void setParentClasses(std::vector<CSharpClass> parentClasses);

    void setParentClass(CSharpClass& parentClass);


    void setFields(std::vector<CSharpField> fields);

    void setMethods(std::vector<CSharpMethod> methods);

    void setType(TYPE type);

    const std::vector<CSharpClass> &getParentClasses() const;

    std::string getClassName() const;

};


#endif //CSHARPCLASSHIERARCHY_CSHARPCLASS_H
