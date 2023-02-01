//20. Replace Global Reference with Getter

//=====================================================================================================================
// Problem Description
/*
A Class depends on global variables.
*/
//=====================================================================================================================
// Step by Step
/*
1. Identify global reference that should be exchanged.
2. Write a getter for the global reference inside the class.
3. Replace all references with of the global component with the getter.
4. Create a test child class and overwrite the getter.
*/

//=====================================================================================================================
// Code Example
// Class with global reference
class RegisterSale
{
public:
    void addItem(Barcode code)
    {
        Item newItem = Inventory.getInventory().itemFromBarcode(code);
        items.add(newItem);
    }
    //...
}

// Write a getter for global Inventory reference
class RegisterSale
{
public:
    void addItem(Barcode code)
    {
        Item newItem = Inventory.getInventory().itemFromBarcode(code);
        items.add(newItem);
    }
    
protected:
    Inventory getInventory()
    {
        return Inventory.getInventory();
    }
    //...
}

// exchange every call of the global reference with the getter
class RegisterSale
{
public:
    void addItem(Barcode code)
    {
        Item newItem = getInventory().itemFromBarcode(code);
        items.add(newItem);
    }
    
protected:
    Inventory getInventory()
    {
        return Inventory.getInventory();
    }
    //...
}
// Create a child class of Inventory that can be used for testing
class FakeInventory : FakeInventory
{
public:
    Item itemForBarcode(Barcode code)
    {
        //...
    }
    //...
}
// Create Tests for class
class TestingRegisterSale : RegisterSale
{
    Inventory inventory = new FakeInventory();
    protected Inventory getInventory()
    {
        return inventory;
    }
}