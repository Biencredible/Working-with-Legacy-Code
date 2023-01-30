//14. Parameterize Method

//=====================================================================================================================
// Problem Description
/*
Inside a method an new object is created and has to be exchanged.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify method that should be parameterized and copy it.
2. Implement an input parameter in the copied method for the object that should be exchanged. Remove the creation 
    of the object inside of the method and assign the new input parameter to the local variable of the method.
3. Remove the body of the old method and call the new method. As input parameter for the new method 
    generate a new object.
*/

//=====================================================================================================================
// Code Example
// Method in which a new object is created that should be exchanged.
void TestCase::run()
{
    delete m_result; m_result = 0;
    m_result = new TestResult;
    try
    {
        setUp();
        runTest(m_result);
    }
    catch(exception& e)
    {
        result->addFailure(e, this);
    }
    tearDown();
}

// Copy method and implement input parameter
void TestCase::run(TestResult* result)
{
    delete m_result;
    m_result = result;
    try
    {
        setUp();
        runTest(m_result);
    }
    catch(exception& e)
    {
        result->addFailure(e, this);
    }
    tearDown();
}

// old signature cann be kept if necessary.
void TestCase::run()
{
   run(new TestResult);
}
