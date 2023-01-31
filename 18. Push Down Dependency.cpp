//18. Push Down Dependency

//=====================================================================================================================
// Problem Description
/*
Class has undesired dependencies, but methods that should be tested, don't reference any of those dependencies.
*/
//=====================================================================================================================
// Step by Step
/*
1. Try to compile class with dependency problems in test suite.
2. Identify dependencies that where problematic when building.
3. Create new child class with a name that expresses the special dependencies it contains.
4. Copy all members and methods that contain the undesired dependency into the new child class. Preserve signatures and 
    declare the functions in the parent class and make them abstract.
*/

//=====================================================================================================================
// Code Example
// Class with undesired dependencies
class OffMarkerTradeValidator : public OTradeValidator
{
private:
    Trade& trade;
    bool flag;

    void showMessage()
    {
        int status = AfxMessageBox(makeMessage(), MB_ABORTRETRYIGNORE);
        if (status == IDRETRY)
        {
            SubmitDialog dlg(this,"Press okay if this is a valid trade");
            dlg.DoModal();
            if (dlg.wasSubmitted())
            {
                g_dispatcher.undoLastSubmission();
                flag = true;
            }
        }
        else if (status == IDABORT)
        {
            flag = false;
        }
    }
public:
    OffMarkerTradeValidator(Trade& trade)
    : trade(trade), flag(false)

    bool isValid() const
    {
        if(inRange(trade.getDate()) && validDestination(trade.destination) && inHours(trade))
        {
            flag = true;
        }
        showMessage();
        return flag;
    }
    //...
}
// Classes after Push Down Dependencies
class OffMarkerTradeValidator : public TradeValidator
{
private:
    Trade& trade;
    bool flag;

    virtual void showMessage() = 0;

public:
    OffMarkerTradeValidator(Trade& trade)
    : trade(trade), flag(false)

    bool isValid() const
    {
        if(inRange(trade.getDate()) && validDestination(trade.destination) && inHours(trade))
        {
            flag = true;
        }
        showMessage();
        return flag;
    }
    //...
}

class WindowsOffMarkerTradeValidator : public OffMarkerTradeValidator
{
protected:

    virtual void showMessage()
    {
        int status = AfxMessageBox(makeMessage(), MB_ABORTRETRYIGNORE);
        if (status == IDRETRY)
        {
            SubmitDialog dlg(this,"Press okay if this is a valid trade");
            dlg.DoModal();
            if (dlg.wasSubmitted())
            {
                g_dispatcher.undoLastSubmission();
                flag = true;
            }
        }
        else if (status == IDABORT)
        {
            flag = false;
        }
    }
};

// Test class
class TestingOffMarkerTradeValidator : public OffMarkerTradeValidator
{
protected:

    virtual void showMessage() {}
};
    