import java.util.Scanner;

public class MainTicket {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        Ticket tickets[] = new Ticket[5];

        for (int i = 0; i < 5; i++) {
            tickets[i] = new Ticket(scanner.nextLine(),
                                    scanner.nextInt(),
                                    scanner.nextDouble());
            scanner.nextLine();
        }

        double sum = 0;
        double max = -1;
        for (int i = 0; i < 5; i++) {
            System.out.println(tickets[i].toString());

            double price = tickets[i].getPrice();

            sum += price;

            if (price > max)
                {max = price;}
        }

        System.out.println("Sum and max: " + sum + " " + max);
        
        // Not going to do how many tickets were sold for each movie
    }
}