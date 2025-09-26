public class Archer extends Character {

    public Archer () {};
    public Archer (String name, Integer level, Integer strength) {
        super(name, level, strength);
    };


    public Double calcDamage() {
        return this.strength * this.level * 1.5 - 10;
    }
}