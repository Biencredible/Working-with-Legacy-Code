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
// Dispatcher is created with Singleton ExternalRouter
void MessageRouter::route(Message* message)
{
    //...
    Dispatcher* dispatcher = ExternalRouter::instance()->getDispatcher();
    if(dispatcher != nullptr)
    {
        dispatcher->sendMessage(message);
    }
}

// ExternalRouter Singleton before any changes
class ExternalRouter
{
private:
    static ExternalRouter* _instance; // Instance is private

public:
    static ExternalRouter* instance(); // getter of instance is public
};

ExternalRouter* ExternalRouter::_instance = 0; // Das hier verstehe ich nicht. Externer Zugriff auf private Member?

ExternalRouter* ExternalRouter::instance()
{
    if(_instance == 0)
    {
        _instance = new ExternalRouter;
    }
    return _instance;
};

// Return value of instance() has to be changed
// Implement method to exchange instance
void ExternlRouter::setTestingInstance(ExternalRouter* newInstance)
{
    delete _instance;
    _instance = newInstance;
}
// Change constructor from private to protected.
// Create a subclass of ExternalRouter for testing purposes
class TestingExternalRouter : public TestingExternalRouter
{
public:
    virtual void Dispatcher* getDispatcher() const
    {
        return new FakeDispatcher;
    }
}

/* Now ExternlRouter::setTestingInstance() can be invoked with TestingExternalRouter instance as input parameter.
Afterwards the call of ExternalRouter::instance()->getDispatcher() in MessageRouter::route() will return the 
FakeDispatcher from TestingExternalRouter::instance()->getDispatcher().*/
