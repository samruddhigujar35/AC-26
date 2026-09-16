class Employee
{
    double salary;
    int hours;

    void getInfo(double salary, int hours)
    {
        this.salary = salary;
        this.hours = hours;
    }

    void addSal()
    {
        if(salary < 500)
        {
            salary = salary + 10;
        }
    }

    void addWork()
    {
        if(hours > 6)
        {
            salary = salary + 5;
        }
    }

    void display()
    {
        System.out.println("Final Salary = $" + salary);
    }

    public static void main(String[] args)
    {
        Employee e = new Employee();

        e.getInfo(450, 8);

        e.addSal();

        e.addWork();

        e.display();
    }
}
