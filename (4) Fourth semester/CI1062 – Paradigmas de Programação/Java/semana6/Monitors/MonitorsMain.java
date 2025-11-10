public class MonitorsMain {
    public static void main(String args[]) {

        Monitor monitors[] =  new Monitor[2];

        monitors[0] = new PetMonitor("Sergio", 1234, "Math");
        monitors[1] = new SelectedMonitor("Shima", 2233, "English");


        if (monitors[0] instanceof PetMonitor) {
            PetMonitor p = (PetMonitor) monitors[0];
            p.workSchedule();
        }

        if (monitors[1] instanceof SelectedMonitor) {
            SelectedMonitor s = (SelectedMonitor) monitors[1];
            s.workSchedule();
            s.sendReport();
        }
    }
}