public class Address {
    protected String street;
    protected Integer num;
    protected String district;
    protected String city;
    protected String state;

    public Address() {};
    public Address(String street, Integer num, String district, String city, String state) {
        this.setStreet(street);
        this.setNum(num);
        this.setDistrict(district);
        this.setCity(city);
        this.setState(state);
    };

    public void setStreet(String street) {
        if (street != null) {
            this.street = street;
        }
    }

    public String getStreet() {
        return this.street;
    }

    public void setNum(Integer num) {
        if (num != null) {
            this.num = num;
        }
    }

    public Integer getNum() {
        return this.num;
    }

    public void setDistrict(String district) {
        if (district != null) {
            this.district = district;
        }
    }

    public String getDistrict() {
        return this.district;
    }

    public void setCity(String city) {
        if (city != null) {
            this.city = city;
        }
    }

    public String getCity() {
        return this.city;
    }

    public void setState(String state) {
        if (state != null) {
            this.state = state;
        }
    }

    public String getState() {
        return this.state;
    }
}