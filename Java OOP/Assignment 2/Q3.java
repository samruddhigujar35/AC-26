class Rectangle
{
    int length;
    int breadth;

    Rectangle(int length, int breadth)
    {
        this.length = length;
        this.breadth = breadth;
    }

    void area()
    {
        System.out.println("Area = " + length * breadth);
    }

    void perimeter()
    {
        System.out.println("Perimeter = "
                + 2 * (length + breadth));
    }
}


class Square extends Rectangle
{
    Square(int side)
    {
        super(side, side);
    }
}


class Main
{
    public static void main(String[] args)
    {
        Rectangle r = new Rectangle(5, 4);

        System.out.println("Rectangle:");
        r.area();
        r.perimeter();


        Square s = new Square(5);

        System.out.println("\nSquare:");
        s.area();
        s.perimeter();
    }
}
