public class VipPassenger extends Passenger {

    VipPassenger() {}
    VipPassenger(String name, int flightNumber) {
        super(name, flightNumber);
    }

    public void dispatchBag() {
        System.out.println(this.name + " Dispatched a Large Bag");  
    }

    public void vipRoom() {
        System.out.println(this.name + " Entered a vip room");  
    }
}