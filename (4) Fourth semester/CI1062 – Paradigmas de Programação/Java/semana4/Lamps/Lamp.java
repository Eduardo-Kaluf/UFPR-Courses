public class Lamp {
    protected boolean on;

    public Lamp() {}

    public void switchState() {
        this.on = !this.on;
    }

    public boolean isOn() {
        return this.on;
    }
}
