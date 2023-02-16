// 09. Extract Implementer

//=====================================================================================================================
// Problem Description
/*
Implementer of class should be extracted
*/
//=====================================================================================================================
// Step by Step
/*
1. Copy Declaration of source class and give new class another name.
2. Remove all public member and methods from the source class to make it an interface.
3. Turn all non-public methods into abstract methods. If C++, make sure that they can not be overriden by non-virtual 
    functions.
4. Check if all files need to be included into the interface file. Usually, many can be removed. Lean on the Compiler to 
    find those files. 
5. Change new class in a way that it implements the new interface.
6. Compile the new class and check if all method signatures are implemented in the interface.
7. Compile the rest of the system to localize all instances of the source class and exchange it with the new class.
8. Compile and test the code.
*/

//=====================================================================================================================
// Code Example
// Class that should be changed into an interface
// ModelNode.h
class ModelNode
{
private:
    list<ModelNode*> m_interioNodes;
    list<ModelNode*> m_exteriorNodes;
    double m_weight;
    void createSpanningLinks();

public:
    void addExteriorNode(ModelNode* newNode);
    void addInternalNode(ModelNode* newNode);
    void colorize();
    // ...
};
// Copy class into another header wit another name
// ProductionModelNode.h
class ProductionModelNode
{
private:
    list<ModelNode*> m_interioNodes;
    list<ModelNode*> m_exteriorNodes;
    double m_weight;
    void createSpanningLinks();

public:
    void addExteriorNode(ModelNode* newNode);
    void addInternalNode(ModelNode* newNode);
    void colorize();
    // ...
};
// Remove all public member and methods from the source class to make it an interface. Turn all non-public methods into 
// abstract methods. Create an abstracr destructor.
// ModelNode.h
class ModelNode
{
public:
    virtual ~ModelNode() = 0
    virtual void addExteriorNode(ModelNode* newNode) = 0;
    virtual void addInternalNode(ModelNode* newNode) = 0;
    virtual void colorize() = 0;
    // ...
};
// ModelNode.cpp
ModelNode::~ModelNode() {}
// Make new class a child class of interface
// ProductionModelNode.h
#include "ModelNode.h"
class ProductionModelNode : public ModelNode
{
private:
    list<ModelNode*> m_interioNodes;
    list<ModelNode*> m_exteriorNodes;
    double m_weight;
    void createSpanningLinks();

public:
    void addExteriorNode(ModelNode* newNode);
    void addInternalNode(ModelNode* newNode);
    void colorize();
    // ...
};