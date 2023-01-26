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
};

// Changes to make it possible
// Create Interface
class RouterServer
{
    Router makeRouter();
};

// make Router a member, that can be set by setter.
class RouterFactory
{
    RouterServer server;

    static Router makeRouter()
    {
        return server.makeRouter()
    }

    static setServer(RouterServer server)
    {
        this->server = server;
    }

    static RouterServer server = new RouterServer()
    {
        public RouterServer makeROuter() 
        {
            return new EWNRouter;
        }
    };
};

// In a Test suite the following can be done
void setUp()
{
    RouterServer.setServer(new Routerserver)
    {
        public RouterServer makeRouter()
        {
            return new FakeRouter();
        }
    }
}

