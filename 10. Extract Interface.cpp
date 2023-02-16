// 10. Extract Interface

//=====================================================================================================================
// Problem Description
/*
A class that should be tested, depends on undesired objects.
*/
//=====================================================================================================================
// Step by Step
/*
1. Create a new interface with a new name.
2. Change the class from which the interface should be extracted in a way that it implements the interface. Compile.
3. CHange the location at which the object should be used, to use the interface.
4. Compile and add a method declaration for each missing method the compiler complains about.
*/

//=====================================================================================================================
// Code Example
// PaydayTransaction class should be tested, but depends on class TransactionLog. Create first Test case.
void testPayday()
{
    Transaction t = new PaydayTransaction(getTestingDatabase());
    t.run()

    assertEquals(getSampleCheck(12), getTestingDatabase().findCheck(12));
}
// For the code to work a TransactionLog has to be given. Create a yet non existing FakeTransactionLog
void testPayday()
{
    FakeTransactionLog aLog = new FakeTransactionLog();
    Transaction t = new PaydayTransaction(getTestingDatabase(), aLog);
    t.run()

    assertEquals(getSampleCheck(12), getTestingDatabase().findCheck(12));
}
// Create a new interface with a new name.
interface TransactionRecorder
{

}
// implement new interface in TransactionLog
public class TransactionLog implements TransactionRecorder
{
    // ...
}
// Create FakeTransactionLog as empty class
public class FakeTransactionLog implements TransactionRecorder
{}
// CHange the location at which the object should be used, to use the interface. Example:
public class PaydayTransaction extends transaction_safe{
    public PaydayTransaction(PayrollDatabase db, TransactionRecorder log)
    {
        super(db, log);
    }

    public void run()
    {
        for(Iterator it = db.getEmployess(); it.hasNext();)
        {
            Employee e = (Employee)it.next();
            if(e.isPayday(date))
            {
                e.pay();
            }
        }
        log.saveTransaction(this);
    }
}
// After compiling the Compiler will complain about saveTransaction(), thus it will be declared in TransactionRecorder
// and FakteTransactionRecorder
interface TransactionRecorder
{
    void saveTransaction(Transaction transaction);
}

public class FakeTransactionLog implements TransactionRecorder
{
    void saveTransaction(Transaction transaction)
    {}
}
