// 07. Extract and Override Factory Method.

//=====================================================================================================================
// Problem Description
/*
Creation of a new object is implemented in a constructor. (Can't be used in C++)
*/
//=====================================================================================================================
// Step by Step
/*
1. IDentify creation of the object in the constructor.
2. Extract the complete logic for the creation into a factory method.
3. Create a testing child class to overwrite the factory method to avoid problematic dependencies in the subclass.
*/

//=====================================================================================================================
// Code Example
// Constructor with creates objects.
public class WorkflowEngine
{
    public WorkflowEngine()
    {
        Reader reader = new ModelReader(AppConfiguration.getDryConfiguration());
        Persister persister = new XMLStore(AppConfiguration.getDryConfiguration());
        this.tm = newTransactionManager(reader, persister)
    }
}
// Create the objects in another method
public class WorkflowEngine
{
    public WorkflowEngine()
    {
        this.tm = makeTransactionManager()
    }

    protected TransactionManager makeTransactionManager()
    {
        Reader reader = new ModelReader(AppConfiguration.getDryConfiguration());
        Persister persister = new XMLStore(AppConfiguration.getDryConfiguration());
        return newTransactionManager(reader, persister);
    }
}
// Override in test function
public class TestWorkflowEngine extends WorkflowEngine
{
    protected TransactionManager makeTransactionManager()
    {
        return new FakeTransactionManager();
    }
}