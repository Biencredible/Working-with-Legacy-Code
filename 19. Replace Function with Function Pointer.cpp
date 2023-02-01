//19. Replace Function with Function Pointer

//=====================================================================================================================
// Problem Description
/*
A Function has undesired dependencies and should be completely exchangeable
*/
//=====================================================================================================================
// Step by Step
/*
1. Search for declaration of function, that should be exchanged.
2. Create a function pointer with the same name for every function declaration.
3. Rename the original function declarations.
4. Initialise the pointers to the adresses of the old functions.
5. Execute Build to find bodys of original functions and rename them to the new name.
*/

//=====================================================================================================================
// Code Example
//Function to exchange
struct receive_record* db_retreive(time_stamp search_time);

//Search for the declaration of the function
void db_store( struct receive_record *record, struct time_stamp receive_time);

// Declare function pointer with the same name
void db_store( struct receive_record *record, struct time_stamp receive_time);
void (*db_store)( struct receive_record *record, struct time_stamp receive_time);

// Rename original function
void db_store_production( struct receive_record *record, struct time_stamp receive_time);
void (*db_store)( struct receive_record *record, struct time_stamp receive_time);

// Initialise pointer to function in a source file
//main.cpp
extern void db_store_production( struct receive_record *record, struct time_stamp receive_time);
void initializeEnvironment() 
{
    db_store = db_store_production;
    //...
}

int main(int ac, char** av)
{
    initializeEnvironment();
    //... 
}