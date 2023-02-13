//02. Break Out Method Object

//=====================================================================================================================
// Problem Description
/*
Long and complicated method uses member variables and methods.
*/
//=====================================================================================================================
// Step by Step
/*
1. Create Class for the Code of the method
2. Create a constructor for the class und use preserve signatures to copy the argument sof the method. If the method 
    uses instance variables or methods, implement a reference to th eoriginal class as first argument for the 
    constructor.
3. Declare a member variable in the new class for each argument of the constructor.
4. Create an empty execution method (e.g. run(), execute()).
5. Copy the old body of the method into the execution method and apply lean on the compiler.
6. Remedy all errors, so that the method compiles. Use the reference to the original class if necessary.
7. Go to the old method and make it calling the method of the new class.
*/

//=====================================================================================================================
// Code Example
// class with long method.
class GDIBrush
{
public:
    void draw(vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection);
    // ...
private:
    void drawPoint(int x, int y, COLOR color);
};

void GDIBrush::draw(vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection)
{
    for(vector<points>::iterator it = renderingRoots.begin();
        it != renderingRoots.end(); ++it)
    {
        point p = *it;   
        // ...
        drawPoint(p.x, p.y, colors[n]);
    }
    // ...
}
// Create new class and create constructor with preserve signatures and a reference to the original class.
class Renderer
{
public:
    Renderer(GDIBrush* brush, vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection);
};
// Declare member variables for each argument of constructor.
class Renderer
{
private:
    GDIBrush* brush; 
    vector<point>& renderingRoots; 
    ColorMatrix& colors; 
    vector<point>& selection;

public:
    Renderer(GDIBrush* brush, vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection)
        : brush(brush), renderingRoots(renderingRoots), colors(colors), selection(selection)
    {}
};
// Create execution method named draw()
class Renderer
{
public:
    Renderer(GDIBrush* brush, vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection);
};
// Declare member variables for each argument of constructor.
class Renderer
{
private:
    GDIBrush* brush; 
    vector<point>& renderingRoots; 
    ColorMatrix& colors; 
    vector<point>& selection;

public:
    Renderer(GDIBrush* brush, vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection)
        : brush(brush), renderingRoots(renderingRoots), colors(colors), selection(selection)
    {}

    void draw();
};
// Copy body of old method into execution method.
void Renderer::draw()
{
    for(vector<points>::iterator it = renderingRoots.begin();
        it != renderingRoots.end(); ++it)
    {
        point p = *it;   
        // ...
        drawPoint(p.x, p.y, colors[n]);
    }
    // ...
}
// Make original method call the new execution method.
void GDIBrush::draw(vector<point>& renderingRoots, ColorMatrix& colors, vector<point>& selection)
{
    Renderer renderer(this, renderingRoots, colors, selection);
    renderer.draw();
}
