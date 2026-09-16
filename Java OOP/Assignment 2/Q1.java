class Parent
{
    void parentMethod()
    {
        System.out.println("This is parent class");
    }
}

class Child extends Parent
{
    void childMethod()
    {
        System.out.println("This is child class");
    }
}

class Main
{
    public static void main(String[] args)
    {
        Parent p = new Parent();

        Child c = new Child();

        // 1. Parent method using parent object
        p.parentMethod();

        // 2. Child method using child object
        c.childMethod();

        // 3. Parent method using child object
        c.parentMethod();
    }
}
