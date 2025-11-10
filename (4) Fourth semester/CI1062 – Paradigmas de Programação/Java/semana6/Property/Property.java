public abstract class Property {
    protected Address address;
    protected Double price;

    public Property() {};
    public Property(Address address, Double price) {
        this.setAddress(address);
        this.setPrice(price);
    };

    public void setAddress(Address address) {
        if (address != null) {
            this.address = address;
        }
    }

    public Address getAddress() {
        return this.address;
    }

    public void setPrice(Double price) {
        if (price != null) {
            this.price = price;
        }
    }

    public Double getPrice() {
        return this.price;
    }

    public abstract Double calcPropertyValue();
}
