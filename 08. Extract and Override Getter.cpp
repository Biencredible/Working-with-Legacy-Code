// 08. Extract and Override Getter

//=====================================================================================================================
// Problem Description
/*
Instance variable needs to be exchanged
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify object that needs a Getter.
2. Extract complete logic that is necessarry to to create the object in a Getter.
3. Exchange all calls of the object with the Getter. Initialize the reference in all constructors with zero.
4. Implement the logic for the erst call of the getter. The object should be constructed and assigned to the reference, 
    if the reference is zero.
5. Create child class und override the getter to test alternative objects.
*/

//=====================================================================================================================
// Code Example
// Class with object that should be exchanged
//WorkflowEngine.h
class WorkflowEngine
{
private:
    TransactionManager *tm;
public:
    WorkflowEngine();
    //...
};
// WorkflowEngine.cpp
WorkflowEngine::WorkflowEngine()
{
    Reader reader = new ModelReader(AppConfiguration.getDryConfiguration());
    Persister persister = new XMLStore(AppConfiguration.getDryConfiguration());
    tm = new TransactionManager(reader, persister)
    // ...
}
// Extract complete logic that is necessarry to to create the object in a Getter.
//WorkflowEngine.h
class WorkflowEngine
{
private:
    TransactionManager *tm;
protected:
    TransactionManager* getTransactionManager() const;
public:
    WorkflowEngine();
    //...
};
// WorkflowEngine.cpp
WorkflowEngine::WorkflowEngine() : tm(0)
{
    Reader reader = new ModelReader(AppConfiguration.getDryConfiguration());
    Persister persister = new XMLStore(AppConfiguration.getDryConfiguration());
    tm = new TransactionManager(reader, persister)
    // ...
}

TransactionManager* WorkflowEngine::getTransactionManager() const
{
    if(tm==0)
    {
        Reader reader = new ModelReader(AppConfiguration.getDryConfiguration());
        Persister persister = new XMLStore(AppConfiguration.getDryConfiguration());
        tm = new TransactionManager(reader, persister)
    }
    return tm;
}
// At First create lazy getter (Also used in Singleton Desing Pattern)
Thing getThing()
{
    if(thing == null)
    {
        thing = new Thing();
    }
    return thing;
};
// This getter can be overridden in a child class and return another object.
class TestWorkflowEngine : public WorkflowEngine
{
public:
    TransactionManager* getTransactionManager()
    {
        return &transactionManager;
    }
    FakeTransactionManager transactionManager;
}
// Write a Test
TEST(transactionCount WorkflowEngine)
{
    auto_ptr<TestWorkFlowEngine> engine(new TestWorkflowEngine);
    engine.>run();
    LONGS_EQUAL(0, engine.>transactionManager.getTransactionCount());
}

}

