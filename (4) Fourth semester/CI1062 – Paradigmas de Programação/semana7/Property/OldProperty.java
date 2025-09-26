public class OldProperty extends Property {

    public OldProperty() {};
    public OldProperty(Address address, Double price) {
        super(address, price);
    }

    public Double calcPropertyValue() {
        return (this.price / 0.75);
    }
}