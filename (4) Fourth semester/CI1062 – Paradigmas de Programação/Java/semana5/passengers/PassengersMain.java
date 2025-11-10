public class PassengersMain {
    public static void main(String args[]) {

        EconomicPassenger economicPassenger = new EconomicPassenger("Kaluf", 101); 
        VipPassenger vipPassenger = new VipPassenger("Shima", 120);

        economicPassenger.security();
        economicPassenger.checkIn();
        economicPassenger.dispatchBag();

        vipPassenger.security();
        vipPassenger.checkIn();
        vipPassenger.dispatchBag();
        vipPassenger.vipRoom();
    }
}