public class MainPerson {
    public static void main(String args[]) {

        Person grace = new Person();
        Person ada = new Person();

        grace.setName("Grace Hopper");
        grace.ajustDateOfBirth(9, 12, 1906);
        grace.calculateAge(20, 8, 2025);

        ada.setName("Ada Lovelace");
        ada.ajustDateOfBirth(10, 12, 1815);
        ada.calculateAge(20, 8, 2025);

        System.out.println(grace.getName() + " would have " + grace.getAge());
        System.out.println(ada.getName() + " would have " + ada.getAge());
    }
}