//05. Expose Static Method

//=====================================================================================================================
// Problem Description
/*
Class, that is problematic to instanciate has a non-static method (But does notuse members and methods of the class), 
that needs to be tested.
*/
//=====================================================================================================================
// Step by Step
/*
1. Write a test that invokes the method, which should be public and static.
2. Extract the body of the method into a static method. Use another name for the new method.
3. Compile
4. If errors occur because of the usage of members and methods of the class, try to make them static as well.
*/

//=====================================================================================================================
// Code Example
// Class with a Method to expose 
class RSCWorkflow
{
    // ...
public:
    void validate(Packet packet)
        throws InvalidFlowException
    {
        if(packet.getOriginator().equals("MIA")
            || packet.getLength() > MAX_LENGTH
            || !packet.hasValidCheckSum())
        {
            throw new InvalidFlowException();
        }
        // ...
    }
    // ...
};
// Because method does not use instance data, it can be a static function. Creat new function that is invoked by the old
// one.
class RSCWorkflow
{
    // ...
public:
    void validate(Packet packet)
        throws InvalidFlowException
    {
       validatePacket(packet);
    }

    static void validatePacket(Packet packet)
        throws InvalidFlowException
    {
        if(packet.getOriginator().equals("MIA")
            || packet.getLength() > MAX_LENGTH
            || !packet.hasValidCheckSum())
        {
            throw new InvalidFlowException();
        }
        // ...
    }
    // ...
};