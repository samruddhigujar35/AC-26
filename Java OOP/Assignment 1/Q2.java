class Triangle
{
    double a;
    double b;
    double c;

    Triangle(double a, double b, double c)
    {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    double perimeter()
    {
        return a + b + c;
    }

    double area()
    {
        double s = perimeter() / 2;

        return Math.sqrt(s * (s-a) * (s-b) * (s-c));
    }

    public static void main(String[] args)
    {
        Triangle t = new Triangle(3, 4, 5);

        System.out.println("Area = " + t.area());
        System.out.println("Perimeter = " + t.perimeter());
    }
}
