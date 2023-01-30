//16. Primitivize Parameter

//=====================================================================================================================
// Problem Description
/*
Method or class of a method has complicated or highly dependend Parameter that can't be created
*/
//=====================================================================================================================
// Step by Step
/*
1. Create free function, that executes work, which would usually be executed inside the class. Use a temporary 
    representation.
2. Implement a function into the class, which creates the representation which delegates to the new function.
*/

//=====================================================================================================================
// Code Example
// Function bool Sequence::hasGapFor(Sequence& pattern) has to be tested, but Sequence has many undesired dependencies.
// Testcase for free function
TEST(hasGapFor, Sequence)
{
    vector<unsigned int> baseSequence;
    baseSequence.push_back(1);
    baseSequence.push_back(0);
    baseSequence.push_back(0);

    vector<unsigned int> pattern;
    pattern.push_back(1);
    pattern.push_back(2);

    CHECK(SequenceHasGapFor(baseSequence, pattern));
}

// Class method has to call new free function
bool Sequence::hasGapFor(Sequence& pattern) const
{
    vector<unsigned int> baseRepresentation = getDurationCopy();
    vector<unsigned int> patternRepresentation = pattern.getDurationCopy();
    return SequenceHasGapFor(baseRepresentation, patternRepresentation);
}