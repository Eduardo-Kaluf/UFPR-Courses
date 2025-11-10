public class Ticket {
    protected double price;

    public Ticket() {}
    public Ticket(double price) {
        this.setPrice(price);
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public double getPrice() {
        return this.price;
    }

    public void printTicket() {
        System.out.println(this.getPrice());
    }
}