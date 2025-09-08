public class Spinning extends Fitness {
    private int bikeResistence;


    public Spinning() {};
    public Spinning(int bikeResistence) {
        this.setBikeResistence(bikeResistence);
    }


    public void timeToExecute() {
        System.out.println("1 hour");
    }


    public int getBikeResistence() {
        return this.bikeResistence;
    }

    public void setBikeResistence(int bikeResistence) {
        this.bikeResistence = bikeResistence;
    }
}