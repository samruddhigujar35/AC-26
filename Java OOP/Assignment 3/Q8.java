import java.util.Scanner;

class ComplexNumber {

    private int number1;
    private int number2;

    // Setter
    public void setNumber1(int number1) {
        this.number1 = number1;
    }

    public void setNumber2(int number2) {
        this.number2 = number2;
    }

    // Getter
    public int getNumber1() {
        return number1;
    }

    public int getNumber2() {
        return number2;
    }

    // Compute multiplication
    public int computeComplexNumber() {
        return number1 * number2;
    }
}

class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ComplexNumber[] arr = new ComplexNumber[5];

        for (int i = 0; i < 5; i++) {

            arr[i] = new ComplexNumber();

            System.out.println("Enter number1:");
            int n1 = sc.nextInt();

            System.out.println("Enter number2:");
            int n2 = sc.nextInt();

            arr[i].setNumber1(n1);
            arr[i].setNumber2(n2);
        }

        System.out.println("Results:");

        for (int i = 0; i < 5; i++) {

            int result = arr[i].computeComplexNumber();

            System.out.println(
                arr[i].getNumber1() + " x " +
                arr[i].getNumber2() + " = " + result
            );
        }
    }
}
