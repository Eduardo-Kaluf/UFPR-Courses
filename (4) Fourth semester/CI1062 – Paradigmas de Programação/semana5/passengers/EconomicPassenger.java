public class EconomicPassenger extends Passenger {

    EconomicPassenger() {}
    EconomicPassenger(String name, int flightNumber) {
        super(name, flightNumber);
    }

    public void dispatchBag() {
        System.out.println(this.name + " Dispatched a Small Bag");  
    }
}