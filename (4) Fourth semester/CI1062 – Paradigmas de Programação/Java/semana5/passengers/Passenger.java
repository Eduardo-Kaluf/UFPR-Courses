public abstract class Passenger implements MandatoryActions {
    protected String name;
    protected int flightNumber;

    public Passenger() {}
    public Passenger(String name, int flightNumber) {
        this.setName(name);
        this.setFlightNumber(flightNumber);
    }

    public abstract void dispatchBag();

    public void checkIn() {
        System.out.println(this.name + " Checked");  
    }

    public void security() {
        System.out.println(this.name + " Passed Security");
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getFlightNumber() {
        return this.flightNumber;
    }

    public void setFlightNumber(int flightNumber) {
        this.flightNumber = flightNumber;
    }
}