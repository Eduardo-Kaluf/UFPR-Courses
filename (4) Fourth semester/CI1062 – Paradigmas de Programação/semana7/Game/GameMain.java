import java.util.TreeSet;

public class GameMain {
    public static void main(String args[]) {

        TreeSet<Character> characters = new TreeSet<>();
        Character archer = new Archer("Kaluf", 5, 10);
        Character warrior = new Warrior("Shima", 3, 20);
        Character mage = new Mage("Sergio", 2, 5);

        characters.add(archer);
        characters.add(warrior);
        characters.add(mage);

        for (Character character : characters) {
            System.out.println(character.name);
            System.out.println(character.calcDamage());
        }
    }
}