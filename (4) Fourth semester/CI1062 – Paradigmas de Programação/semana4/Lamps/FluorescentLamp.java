public class FluorescentLamp extends Lamp {
    private int size;

    public FluorescentLamp() {}
    public FluorescentLamp(int size) {
        this.setSize(size);
    }

    public void setSize(int size) {
        if (size != 0) {
            this.size = size;
        }
    }

    public int getSize() {
        return this.size;
    }
}
