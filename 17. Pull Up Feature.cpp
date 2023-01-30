//17. Pull Up Feature

//=====================================================================================================================
// Problem Description
/*
Class has undesired dependencies, but methods that should be tested, don't reference any of those dependencies.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify methods that should be moved to a parent class.
2. Create abstract parent class of the class that contains the methods to be tested.
3. Copy methods into the parent class and compile the code.
4. Copy every missing reference, which the compiler prompts, into the new parent class.
5. When both class compile successfully, create a child class of the abstract class and use the methods that are needed
    for testing.
*/

//=====================================================================================================================
// Code Example
// Interestet in testing getDeadTime(), but don't want to implement updateScheduleItem() because of dependencies to 
// database
class Scheduler
{
private: 
    List item;
    void validate(ScheduleItem item)
    {
        //...
        // Invokes from Database
    }

public:
    void updateScheduleItem(ScheduleItem item)
    {
        //...
        validate(item);
        //...
    }

    int getDeadTime() 
    {
        //...
        if(notShared(item))
        {
            clockTime();
        }
        //...
        if(/*...*/)
            //...
        else
            getStandardFinish();
    }

};

// Move method to test into a parent class. Scheduler looks like the following
class Scheduler : public SchedulingServices
{
private: 
    List item;
    void validate(ScheduleItem item)
    {
        //...
        // Invokes from Database
    }

public:
    void updateScheduleItem(ScheduleItem item)
    {
        //...
        validate(item);
        //...
    }
}

// Abstract Parent class
class SchedulingServices
{
protected:
    virtual bool notShared(SchedulingItem)
    {
        //...
    }

    virtual int getClockTime()
    {
        //...
    }

    virtual int getStandardFinish()
    {
        //...
    }

public:

    virtual int getDeadTime()
    {
        //...
    }
};

// Create testing subclass
class TestingSchedulingServices : public SchedulingServices
{
public:
    TestingSchedulingServices() {}

    void addItem(ScheduleItem item)
    {
        items.add(item);
    }
};

class SchedulingServicesTests : public TestCase
{
public:
    void testGetDeadTime()
    {
        TestingSchedulingServices services = new TestingSchedulingServices();
        services.addItem(new ScheduleItem("a", 10, 20, ScheduleItem.BASIC));
        assertEquals(2, services.getDeadTime());
    }
    //...
};