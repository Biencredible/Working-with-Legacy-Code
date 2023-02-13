//03. Definition Completion

//=====================================================================================================================
// Problem Description
/*
A Method that is declared in a Header file, should use another definition for test purposes.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify the class with the definition that should be exchanged.
2. If necessarry, move body of function from the header file to the source file.
3. include the header file in the test file.
4. verify that the source files that correspond to the header files are not part of the test build.
5. compile to find missing methods.
6. Implement function definitions until the code compiles.
*/

//=====================================================================================================================
// Code Example
// Class with method that should be exchanged
class CLateBindingDispatchDriver : public CDispatchDriver
{
public:
    CLateBindingDispatchDriver();
    virtual ~CLateBindingDispatchDriver();

    ROOTID GetROOTID(int d) const;

    void BindName(int id, OLECHAR FAR* name);
    // ...

private:
    CArray<ROOTID, ROOTID&> rootids;
};
// Include Header file into test file and create alternative definitions.
#include "LateBindingDispatchDriver.h"

CLateBindingDispatchDriver::CLateBindingDispatchDriver() {}

CLateBindingDispatchDriver::~CLateBindingDispatchDriver() {}

ROOTID GetROOTID(int d) const { return ROOTID(-1); } 

void BindName(int id, OLECHAR FAR* name) {}

TEST(AddOrder, BOMTreeCtrl)
{
    CLateBindingDispatchDriver driver; CBOMTreeCtrl ctrl(&driver);
    ctrl.AddOrder(COrderFactory::makeDefault()); LONGS_EQUAL(1, ctrl.OrderCount());
}
