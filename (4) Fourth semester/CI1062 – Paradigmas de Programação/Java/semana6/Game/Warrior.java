public class Warrior extends Character {
    
    public Warrior () {};
    public Warrior (String name, Integer level, Integer strength) {
        super(name, level, strength);
    };


    public Double calcDamage() {
        return this.strength * this.level * 1.2;
    }
}