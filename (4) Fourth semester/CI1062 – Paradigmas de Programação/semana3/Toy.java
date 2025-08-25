
public class Toy {
    private String name;
    private double minimumHeigth;
    private double price;

    Toy(String name, double minimumHeigth, double price) {
        this.setName(name);
        this.setMinimumHeight(minimumHeigth);
        this.setPrice(price);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setMinimumHeight(double minimumHeigth) {
        this.minimumHeigth = minimumHeigth;
    }

    public double getMinimumHeight() {
        return this.minimumHeigth;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public boolean checkHeight(double height) {
        if (height >= this.getMinimumHeight()) {
            return true;
        }

        return false;
    }
}
