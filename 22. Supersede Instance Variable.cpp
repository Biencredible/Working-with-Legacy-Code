//22. Supersede Instance Variable

//=====================================================================================================================
// Problem Description
/*
A Virtual Method in a constructor should be overridden
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify instance variable that should be exchanged.
2. Create a method named supersedeX, where X is the name of the variable to exchange.
3. Implement code into the method, that is necesarry to delete the current instance of the variable and to set it to the
    new value.
*/

//=====================================================================================================================
// Code Example
// Constructor with instance variable to exchange
BlendingPen::BlendingPen()
{
    setName("BlendingPen");
    m_param = ParameterFactory::createParameter("cm", "Fade", "Aspect Alter");
    m_param->addChoice("blend");
    m_param->addChoice("add");
    m_param->addChoice("filter");

    setParamByName("cm", "blend");
}
// create supersede method
void BlendingPen::supersedeParameter(Parameter* newParameter)
{
    delete m_param;
    m_param = newParameter;
}