public class Cabin extends VipTicket {
    private double cabinExtra;

    public Cabin() {}
    public Cabin(double price, double aditionalValue, double cabinExtra) {
        super(price, aditionalValue);
        this.setCabinExtra(cabinExtra);
    }

    public void setCabinExtra(double cabinExtra) {
        this.cabinExtra = cabinExtra;
    }

    public double getCabinExtra() {
        return this.cabinExtra;
    }

    public double getCabinPrice() {
        return this.getVipPrice() + this.getCabinExtra();
    }

    public void printCabin() {
        System.out.println("Cabin Ticket");
        System.out.println(this.getCabinPrice());
    }
}
