//23. Template Redefintion

//=====================================================================================================================
// Problem Description
/*
Alternative method to remove dependencies to interface- and implementation inheritance
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify the function that should be exchanged in the class that should be tested.
2. Change the calss to a template class, parameterize with the variables which need to be exchanged and copy the bodies 
    into the header files.
3. Give another name to the template.
4. Implement typdef instruction in which the template is defined with the original arguments and class name
5. Include the template definition into the test file and instanciate the template with a new type that should replace
    the original types.
*/

//=====================================================================================================================
// Code Example
// Class with undesired member type that should be exchanged.
// AsyncReceptionPort.h
class AsyncReceptionPort
{
private:
    CSocket m_socket;
    Packet m_packet;
    int m_segementSize;
    //...
public:
    AsyncRespetionPort();
    void Run();
    //...
};
// AsynchReceptionPort.cpp
void AsyncReceptionPort::Run()
{
    for(int n = 0; n < m_segmentSize; ++n)
    {
        int bufferSize = m_bufferMax;
        if (n = m_segmentSize -1)
            bufferSize = m_remainingSize;
        m_socket.receive(m_receiveBuffer, bufferSIze);
        m_packet.mark();
        m_packet.append(m_receiveBuffer.bufferSize);
        m_packet.pack()
    }
    m_packet.finalize();
}

// Creating Template
// AsyncReceptionPort.h
template<typename SOCKET> class AsyncReceptionPortImpl
{
private:
    SOCKET m_socket;
    Packet m_packet;
    int m_segementSize;
    //...
public:
    AsyncRespetionPortImpl();
    void Run();
    //...
};
// AsynchReceptionPort.cpp
template<typename SOCKET> 
void AsyncReceptionPortImpl<SOCKET>::Run()
{
    for(int n = 0; n < m_segmentSize; ++n)
    {
        int bufferSize = m_bufferMax;
        if (n = m_segmentSize -1)
            bufferSize = m_remainingSize;
        m_socket.receive(m_receiveBuffer, bufferSIze);
        m_packet.mark();
        m_packet.append(m_receiveBuffer.bufferSize);
        m_packet.pack()
    }
    m_packet.finalize();
}

typedef AsyncReceptionPortImpl <CSocket> AsyncReceptionPort

// Create Test Socket
// TestAsynchReceptionPort.cpp
#include "AsyncReceptionPort.h"
class FakeSocket
{
public:
    void receive(char*, int size) { /* ... */ }
};

TEST(Run, AsyncReceptionPort)
{
    AsyncReceptionPortImpl<FakeSocket> port;
}