import java.util.Scanner;

public class LampMain {
    private static final Scanner scanner = new Scanner(System.in);
    
    public static void main(String args[]) {

        FluorescentLamp fluorescentLamp = new FluorescentLamp(25);
        LedLamp ledLamp = new LedLamp();

        String choice = scanner.nextLine();

        if (choice.equals("LED")) {
            ledLamp.switchState();
        }
        else if (choice.equals("FLUOR")) {
            fluorescentLamp.switchState();
        }

        System.out.println(ledLamp.isOn());
        System.out.println(fluorescentLamp.isOn());

    }
}
