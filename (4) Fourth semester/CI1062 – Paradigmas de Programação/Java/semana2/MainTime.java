import java.util.Scanner;

public class MainTime {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        Time time1 = new Time();
        Time time2 = new Time();

        time1.setHours(scanner.nextInt());
        time1.setMinutes(scanner.nextInt());

        time2.setHours(scanner.nextInt());
        time2.setMinutes(scanner.nextInt());

        System.out.println(time1.toString());
        System.out.println(time2.toString());

        if (time1.posterior(time2.getHours(), time2.getMinutes())) {
            System.out.println("1 é posterior a 2");
        }
        else if (time1.equals(time2.getHours(), time2.getMinutes())) {
            System.out.println("1 é igual a 2");
        }
        else {
            System.out.println("1 é anterior a 2");
        }
    }
}