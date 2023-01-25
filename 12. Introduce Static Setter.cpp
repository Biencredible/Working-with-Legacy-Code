//12. Introduce Static Setter

//=====================================================================================================================
// Problem Description
/*
Class that should tested, depends on global Singleton.
*/
//=====================================================================================================================
// Step by Step
/*
1. Reduce protection of the constructor to make it possible to create a fake, by creating a subclass of the singleton
2. Implement static setter in the singleton class. The setter should includea reference of the singleton class.
    The setter should destroy the singleton intance before setting the new object.
3. If the singleton has to access private or protected methods, a subclass should be created or the interface extracted 
    and to change the instance inside the singleton in a way that the its type matches the type of the interface it 
    references.
*/

//=====================================================================================================================
// Code Example
// Singleton class in which the router, returned by makeRouter can not be exchanged for testing purposes.
class RouterFactory
{
    static Router makeRouter()
    {
        return new EWNRouter();
    }
}