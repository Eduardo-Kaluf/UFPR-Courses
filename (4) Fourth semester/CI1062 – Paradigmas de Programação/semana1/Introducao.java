import java.util.Scanner;


public class Introducao {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        int option;

        while (true) {
            option = this.scanner.nextInt();

            switch (option) {
                case 1:
                    this.oddEven(this.scanner.nextInt());
                    break;
                case 2:
                    this.sumMultipleOfThree();
                    break;
                case 3:
                    int result = this.mathFunction(this.scanner.nextInt());
                    System.out.println("The function result was: " + result);                    
                    break;
                case 4:
                    this.imc();
                    break;
                default:
                    System.exit(0);
            }
        }   
    }

    private void oddEven(int x) {
        if ((x % 2) == 0)
            {System.out.println("Its Even");}
        else
            {System.out.println("Its Odd");}
    }

    private void sumMultipleOfThree() {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i * 3;
        }

        System.out.println("The sum is " + sum);
    }

    private int mathFunction(int x) {
        if (x < 0) {
            throw new IllegalArgumentException;
        }

        if (x < 5)
            {return x;}
    
        if (x < 10)
            {return 2 * x + 1;}
    
        return x - 3;
    }

    private void imc() {
        double weight;
        double height;
        int count = 0;

        weight = this.scanner.nextDouble();
        height = this.scanner.nextDouble();

        while (weight != -1 && height != -1) {
            double formulaResult = weight / (height * height);
            boolean formulaResult = formulaResult > 25;  
        
            if (isAboveWeight) {
                count += 1;
                System.out.println("There is a total of " + count + " people abovoe weight");
            }

            weight = this.scanner.nextDouble();
            height = this.scanner.nextDouble();
        }
    }
}