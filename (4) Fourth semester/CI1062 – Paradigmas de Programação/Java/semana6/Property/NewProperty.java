public class NewProperty extends Property {

    public NewProperty() {};
    public NewProperty(Address address, Double price) {
        super(address, price);
    }

    public Double calcPropertyValue() {
        return (this.price * 1.25);
    }
}
