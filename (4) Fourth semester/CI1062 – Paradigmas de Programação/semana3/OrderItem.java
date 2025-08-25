public class OrderItem {
    private String itemName;
    private float price;


    OrderItem() {}

    OrderItem(String itemName, float price) {
        this.setItemName(itemName);
        this.setPrice(price);
    }

    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    public String getItemName() {
        return this.itemName;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public float getPrice() {
        return this.price;
    }
}