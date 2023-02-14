//04. Encapsulate Global Reference

//=====================================================================================================================
// Problem Description
/*
Problematic dependencies on globals
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify global that should be encapsulated.
2. Create a class, that should be referenced from.
3. Copy global into the class.
4. Comment out the original declaration of the global
5. Declare a gloabal instance of the new class.
6. Lean on the Compiler to find all references of the old global.
7. Copy the name of the new global instance before every reference of the old global.
*/

//=====================================================================================================================
// Code Example
// File with globals to encapsulate
bool AGG230_activeframe[AGG230_SIZE];
bool AGG230_suspendedframe[AGG230_SIZE];

void AGGControler::suspend_frame()
{
    frame_copy(AGG230_suspendframe, AGG230_activeframe);
    clear(AGG230_activeframe);
    flush_frame_buffer();
}

void AGGControler::flush_frame_buffer()
{
    for(int n = 0; n < AGG230_SIZE; ++n)
    {
        AGG230_activeframe[n] = false;
        AGG230_suspendedframe[n] = false;
    }
}
// Create a new class
class Frame
{
public:
    // AGG230 as a constant
    enum { AGG230_SIZE = 256 };

    bool AGG230_activeframe[AGG230_SIZE];
    bool AGG230_suspendedframe[AGG230_SIZE];
};
// Declare global instance of new class, comment out the original declaration of the globals, opy the name of the new 
// global instance before every reference of the old global.
Frame frameForAGG230;
// bool AGG230_activeframe[AGG230_SIZE];
// bool AGG230_suspendedframe[AGG230_SIZE];
void AGGControler::suspend_frame()
{
    frame_copy(frameForAGG230.AGG230_suspendframe, frameForAGG230.AGG230_activeframe);
    clear(frameForAGG230.AGG230_activeframe);
    flush_frame_buffer();
}