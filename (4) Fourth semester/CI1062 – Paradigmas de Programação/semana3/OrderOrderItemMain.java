public class OrderOrderItemMain {


    public static void main(String args[]) {

        OrderItem pizza = new OrderItem("Pizza", 35);
        OrderItem juice = new OrderItem("Juice", 8);

        Order order = new Order(101);

        order.addItem(pizza);
        order.addItem(juice);

        order.printOrder();
        
    }
}