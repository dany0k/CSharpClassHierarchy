//
// Created by Den on 13.03.2023.
//

#ifndef CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H
#define CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H

#include <string>
#include <vector>

class CSharpNamespace {
private:
    std::string name;
public:
    CSharpNamespace();
    CSharpNamespace(std::string  name);
    std::string getName() const;

};

#endif //CSHARPCLASSHIERARCHY_CSHARPNAMESPACE_H
