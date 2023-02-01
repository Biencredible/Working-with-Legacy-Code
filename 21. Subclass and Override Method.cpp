//21. Subclass and Override Method

//=====================================================================================================================
// Problem Description
/*
Class that should be tested has a method with undesired dependencies
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify the deendency that you want to isolate. Try to find the smallest amount of methods you need to override to 
    meet your goal.
2. Make every method able to be overridden (virtual)
3. If necessary change visibility of methods, so that they can be overridden (protected).
4. Create a child class that overrides the methods and build the test suite to see if it compiles.
*/

//=====================================================================================================================
// Code Example
// Class with undesired dependencies
class MessageForwarder
{
private:
    Message createForwardMessage( Session session, Message message)
        throws MessagingException, IOException{
        MimeMessage forward = new MimeMessage(session);
        forward.setForm(getFromAddress(message));
        forward.setReplyTo(newAddress[] { new InternetAddress(listAddress)});
        //...
        return forward;
    }
    //...
};

// Make function virtual and protected, so it cna be overridden
// Create child class for overriding and testing
class TestingMessageForwarder : MessageForwarder
{
protected:
    Message createForwardMessage( Session session, Message message)
    {
        Message forward = new FakeMessage(message);
        
        return forward;
    }
    //...
};