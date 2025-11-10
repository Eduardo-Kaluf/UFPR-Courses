public class Mage extends Character {

    public Mage () {};
    public Mage (String name, Integer level, Integer strength) {
        super(name, level, strength);
    };

    public Double calcDamage() {
        return this.strength * this.level + 15.0;
    }
}