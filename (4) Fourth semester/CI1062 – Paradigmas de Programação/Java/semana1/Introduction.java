import java.util.Scanner;


public class Introduction {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        int option;

        while (true) {
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    oddEven(scanner.nextInt());
                    break;
                case 2:
                    sumMultipleOfThree();
                    break;
                case 3:
                    int result = mathFunction(scanner.nextInt());
                    System.out.println("The function result was: " + result);                    
                    break;
                case 4:
                    imc();
                    break;
                default:
                    System.exit(0);
            }
        }   
    }

    private static void oddEven(int x) {
        if ((x % 2) == 0)
            {System.out.println("Its Even");}
        else
            {System.out.println("Its Odd");}
    }

    private static void sumMultipleOfThree() {
        int sum = 0;
        for (int i = 1; i <= 10; i++) {
            sum += i * 3;
        }

        System.out.println("The sum is " + sum);
    }

    private static int mathFunction(int x) {
        if (x < 0) {
            throw new IllegalArgumentException();
        }

        if (x < 5)
            {return x;}
    
        if (x < 10)
            {return 2 * x + 1;}
    
        return x - 3;
    }

    private static void imc() {
        double weight;
        double height;
        int count = 0;

        weight = scanner.nextDouble();
        height = scanner.nextDouble();

        while (weight != -1 && height != -1) {
            double formulaResult = weight / (height * height);
            boolean isAboveWeight = formulaResult > 25;  
        
            if (isAboveWeight) {
                count += 1;
                System.out.println("There is a total of " + count + " people abovoe weight");
            }

            weight = scanner.nextDouble();
            height = scanner.nextDouble();
        }
    }
}