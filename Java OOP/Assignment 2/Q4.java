class Shape
{
    void shapeMethod()
    {
        System.out.println("This is shape");
    }
}


class Rectangle extends Shape
{
    void rectangleMethod()
    {
        System.out.println("This is rectangular shape");
    }
}


class Circle extends Shape
{
    void circleMethod()
    {
        System.out.println("This is circular shape");
    }
}


class Square extends Rectangle
{
    void squareMethod()
    {
        System.out.println("Square is a rectangle");
    }
}


class Main
{
    public static void main(String[] args)
    {
        Square s = new Square();

        // Shape class method
        s.shapeMethod();

        // Rectangle class method
        s.rectangleMethod();

        // Square class method
        s.squareMethod();
    }
}
