//06. Extract and Override Call

//=====================================================================================================================
// Problem Description
/*
Dependencies are locally limited, so just one function call has to be exchanged.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify the call, that should be extracted. Search for the declaration and copy its method signature.
2. Create a new method with that signature in the current class.
3. Copy the call of the new method and exchange the call of the old function.
4. Create a test child class undaoverwrite hte new method.
*/

//=====================================================================================================================
// Code Example
// class with function formstyles() to exchange
class PageLayout
{
private: 
    int id = 0;
    List styles;
    private StyleTemplate template;
    // ...
protected:
    void rebindStyles() 
    {
        styles = StyleMaster.formStyles(template, id);
        // ...
    }
    // ...
}
// Extract function
class PageLayout
{
private: 
    int id = 0;
    List styles;
    private StyleTemplate template;
    // ...
protected:
    void rebindStyles() 
    {
        styles = formStyles(template, id);
        // ...
    }

    List formStyles(StyleTemplate template, int id)
    {
        return StyleMaster.formStyles(template, id);
    }
    // ...
}
// Overwrite in test child class
class TestingPageLayout : PageLayout
{
protected:
    List formStyles(StyleTemplate template, int id)
    {
        return new ArrayList();
    }
};