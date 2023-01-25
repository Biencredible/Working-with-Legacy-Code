//11. Introduce Instance Delegator

//=====================================================================================================================
// Problem Description
/*
Static Methods only cause problems if the contain dependencies, which are problematic to test.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify Static Method, that is hard to test.
2. Create an Instance Method (Delegator) in the corresponding class. Use "Preserve Signatures" and delegate inside of 
    the Instance Method to the Static Method.
3. Search for locations which uses the static method inside of the class which should be tested. 
    Use "15. Parameterize Method" or another dependency revoking technique to provide Intances at the locations at 
    which the Static Method has been used.
4. Replace the problematic call of the Static Method with the call of the Delegator of the Instance.
*/

//=====================================================================================================================
// Code Example
// Class with only static methods.
class BankingServices
{
    static void updateAccountBalance(int userID, Money amount)
    {
        // ...
    }

    // ...
};

// Added method, which calls static study.
class BankingServices
{
    static void updateAccountBalance(int userID, Money amount)
    {
        // ...
    }

    void updateBalance (int userID, Money amount)
    {
        updateAccountBalance(userID, amount);
    } 

    // ...
};


// Class with a method that calls static method from other class
class SomeClass
{
    public void someMethod()
    {
        // ...
        BankingServices.updateAccountBalance(id, sum);
    }
};

// is changed to
class SomeClass
{
    public void someMethod(BankingServices services)
    {
        // ...
        services.updateBalance(id, sum)
    }
};