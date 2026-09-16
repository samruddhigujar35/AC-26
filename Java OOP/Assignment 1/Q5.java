class Employee
{
    String name;
    int year;
    double salary;
    String address;

    Employee(String name, int year, double salary, String address)
    {
        this.name = name;
        this.year = year;
        this.salary = salary;
        this.address = address;
    }

    void display()
    {
        System.out.println(name + "\t"
                + year + "\t"
                + salary + "\t"
                + address);
    }

    public static void main(String[] args)
    {
        Employee e1 = new Employee(
                "Robert", 1994, 50000, "64C-WallsStreat");

        Employee e2 = new Employee(
                "Sam", 2000, 60000, "68D-WallsStreat");

        Employee e3 = new Employee(
                "John", 1999, 55000, "26B-WallsStreat");

        System.out.println("Name\tYear\tSalary\tAddress");

        e1.display();
        e2.display();
        e3.display();
    }
}
