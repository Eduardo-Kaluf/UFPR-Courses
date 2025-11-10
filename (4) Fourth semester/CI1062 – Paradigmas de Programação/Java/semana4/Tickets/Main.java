public class Main {
    public static void main(String args[]) {

        NormalTicket normalTicket = new NormalTicket(10);
        VipTicket vipTicket = new VipTicket(10, 20);
        Cabin cabin = new Cabin(10, 20, 30);

        normalTicket.printNormalTicket();
        vipTicket.printVipTicket();
        cabin.printCabin();

        NormalTicket normalTickets[] = new NormalTicket[25];
        VipTicket vipTickets[] = new VipTicket[25];
        Cabin cabins[] = new Cabin[25];

        for (int i = 0; i < 25; i++) {
            normalTickets[i] = new NormalTicket(i);
            vipTickets[i] = new VipTicket(i, i*i);
            cabins[i] = new Cabin(i, i*i, (i + 2) * i);
        }

        for (int i = 0; i < 25; i++) {
            normalTickets[i].printNormalTicket();
            vipTickets[i].printVipTicket();
            cabins[i].printCabin();
        }
    }
}