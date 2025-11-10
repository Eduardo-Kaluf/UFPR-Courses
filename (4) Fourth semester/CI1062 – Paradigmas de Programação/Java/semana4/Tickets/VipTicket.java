public class VipTicket extends Ticket {
    protected double aditionalValue;

    public VipTicket() {}
    public VipTicket(double price, double aditionalValue) {
        super(price);
        this.setAditionalValue(aditionalValue);
    }

    public void setAditionalValue(double aditionalValue) {
        this.aditionalValue = aditionalValue;
    }

    public double getAditionalValue() {
        return this.aditionalValue;
    }

    public double getVipPrice() {
        return this.getPrice() + this.getAditionalValue();
    }

    public void printVipTicket() {
        System.out.println("Vip Ticket");
        System.out.println(this.getVipPrice());
    }
}