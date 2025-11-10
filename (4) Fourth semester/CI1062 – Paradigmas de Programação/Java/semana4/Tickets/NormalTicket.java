public class NormalTicket extends Ticket {

    public NormalTicket() {}
    public NormalTicket(double price) {
        super(price);
    }

    public void printNormalTicket() {
        System.out.println("Normal Ticket");
        System.out.println(this.getPrice());
    }
}
