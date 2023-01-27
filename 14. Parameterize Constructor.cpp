//14. Parameterize Constructor

//=====================================================================================================================
// Problem Description
/*
Inside a constructor an new object is created and has to be exchanged.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify constructor that should be parameterized and copy it.
2. Implement an input parameter in the copied constructor for the object that should be exchanged. Remove the creation 
    of the object inside of the constructor and assign the new input parameter to the member variable of the class.
3. Remove the body of the old constructor and call the new constructor. As input parameter for the new constructor 
    generate a new object.
*/

//=====================================================================================================================
// Code Example
// Constructor in which a new object is created that should be exchanged.
class MailChecker
{
public:
    MailChecker (int checkPeriodSeconds)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }
    //...
};

// Copy the constructor
class MailChecker
{
public:
    MailChecker (int checkPeriodSeconds)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }

    MailChecker (int checkPeriodSeconds)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }
    //...
};

// Implement an input parameter in the copied constructor for the object that should be exchanged. 
class MailChecker
{
public:
    MailChecker (int checkPeriodSeconds)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }

    MailChecker (int checkPeriodSeconds, MailReceiver receiver)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }
    //...
};

// exchange the creation of the object inside the copied constructor with the input parameter
class MailChecker
{
public:
    MailChecker (int checkPeriodSeconds)
    {
        this->receiver = new MailReceiver();
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }

    MailChecker (int checkPeriodSeconds, MailReceiver receiver)
    {
        this->receiver = receiver;
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }
    //...
};

/* Remove the body of the old constructor and call the new constructor. As input parameter for the new constructor 
   generate a new object.*/

class MailChecker
{
public:
    MailChecker (int checkPeriodSeconds)
    {
        this(checkPeriodSeconds, new MailReceiver)    ;
    }

    MailChecker (int checkPeriodSeconds, MailReceiver receiver)
    {
        this->receiver = receiver;
        this->checkPeriodsSeconds = checkPeriodSeconds;      
    }
    //...
};
