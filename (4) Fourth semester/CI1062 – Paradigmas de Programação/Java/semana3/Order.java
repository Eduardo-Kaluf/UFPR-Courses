import java.util.List;
import java.util.ArrayList;


public class Order {
    private int number;
    private List<OrderItem> items;

    Order() {}

    Order(int number) {
        this.setNumber(number);
        this.items = new ArrayList<>();
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public int getNumber() {
        return this.number;
    }

    public void addItem(OrderItem item) {
        this.items.add(item);
    }

    public float totalPrice() {
        float total = 0;

        for (OrderItem item : this.items) {
            total += item.getPrice();
        }
        return total;
    }

    public void printOrder() {
        System.out.println("Order #" + this.getNumber());
        
        int i = 1;

        for (OrderItem item : this.items) {
            System.out.println(i + " - " + item.getItemName() + " ($" + item.getPrice() + ")");
            i += 1;

        }
        System.out.println("Total $" + this.totalPrice());
    }
}