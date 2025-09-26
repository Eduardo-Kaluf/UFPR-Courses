public abstract class Character implements Comparable<Character> {
    protected String name;

    protected Integer level;

    protected Integer strength;

    public Character () {};
    public Character (String name, Integer level, Integer strength) {
        this.setName(name);
        this.setLevel(level);
        this.setStrength(strength);
    };

    public void setName(String name) {
        if (name != null) {
            this.name = name;
        }
    }

    public String getName() {
        return this.name;
    }

    public void setLevel(Integer level) {
        if (level != null) {
            this.level = level;
        }
    }

    public Integer getLevel() {
        return this.level;
    }

    public void setStrength(Integer strength) {
        if (strength != null) {
            this.strength = strength;
        }
    }

    public Integer getStrenght() {
        return this.strength;
    }

    @Override
    public int compareTo(Character other) {
        if (other == null) {
            return 1;
        }
        else {
            return this.calcDamage().compareTo(other.calcDamage());
        }
    }

    public abstract Double calcDamage();
}