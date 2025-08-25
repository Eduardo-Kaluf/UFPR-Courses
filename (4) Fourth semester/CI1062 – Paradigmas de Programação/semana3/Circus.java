public class Circus {
    public static void main(String args[]) {

        Toy toy1 = new Toy("Horses", 1.65, 5.00);
        Toy toy2 = new Toy("RussianMountain", 1.80, 12.5);

        SpecialAttraction specialAttraction = new SpecialAttraction("Specail", 5, 3);

        Visitor visitor1 = new Visitor("Kaluf", 47, 12.00);
        Visitor visitor2 = new Visitor("Marcelo", 51, 100.00);

        if (toy1.checkHeight(1.74)) {
            System.out.println("OK!");
        }

        specialAttraction.addPerson();

        if (specialAttraction.verifyMaxThreshold()) {
            System.out.println("MAX!");
        }

        System.out.println(visitor2.getMoney());
        visitor2.buyTicket(toy1.getPrice());
        System.out.println(visitor2.getMoney());

    }
}