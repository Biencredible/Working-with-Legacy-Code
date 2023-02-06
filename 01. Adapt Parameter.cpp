//01. Adapt Parameter

//=====================================================================================================================
// Problem Description
/*
Parameters of mehtod to test are hard to create.
*/
//=====================================================================================================================
// Step by Step
/*
1. Create new interface, that should be used in the method.
2. Create fake implementer of the interface
3. Create production implementer in the new interface.
4. Write simple test case, that gives the fake class to the method.
5. Implement necessary changes to be able to use the new parameter.
6. Execute test to verify that the method cane be tested with the fake.
*/

//=====================================================================================================================
// Code Example
// Class with a fnction with hard to create parameters
class ARMDispatcher
{
public: 
    void populate(HttpServeletRequest request)
    {
        String [] values = request.getParameterValues(pageStateName);
        if(values != null && values.length() > 0)
        {
            marketBindings.put(pageStateName getDateStamp(), values[0]);
        }
        //...
    }
    //...
};

// Encapsule parameters
class ARMDispatcher
{
public: 
    void populate(ParameterSource source)
    {
        String values = source.getParameterValues(pageStateName);
        if(values != null)
        {
            marketBindings.put(pageStateName getDateStamp(), values);
        }
        //...
    }
    //...
};

// Create Fake class that can be used in tests
class FakeParameterSource : ParameterSource
{
public:
    String value;
    String getParameterForName(String name)
    {
        return value;
    }
}

// Productions class:
class ServletParameterSource : ParameterSource
{
private:
    HttpServletParameter request;
public:
    ServletParameterSource(HttpServletRequest request)
    {
        this->request = request;
    }

    String getParameterValues(String name)
    {
        String [] values = request.getParameterValues(name);
        if (values == null || values.length() > 1)
        {

            return null;
        }
        return values[0];
    }
}
