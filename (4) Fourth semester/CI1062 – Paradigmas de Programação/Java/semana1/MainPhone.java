import java.util.Scanner;

public class MainPhone {
    private static final Scanner scanner = new Scanner(System.in);


    public static void main(String args[]) {

        Phone[] phones = new Phone[5];

        for (int i = 0; i < 5; i++) {
            Phone phone = new Phone();
        
            System.out.println("Provide Number, country code and area code");
            phone.setNumber(scanner.nextInt());
            phone.setCountryCode(scanner.nextInt());
            phone.setAreaCode(scanner.nextInt());

            phones[i] = phone;
        }


        for (int i = 0; i < 5; i++) {
            System.out.println(phones[i].toString());
        }
    }
}