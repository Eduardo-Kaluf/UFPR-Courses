public class GymMain {
    public static void main(String args[]) {

        Boxing boxing = new Boxing();
        MuayThai muayThai = new MuayThai();

        Spinning spinning = new Spinning(20);
        BodyBuilding bodyBuilding = new BodyBuilding(80);

        boxing.strategy();
        boxing.rules();
        boxing.objectives();

        muayThai.strategy();
        muayThai.rules();
        muayThai.objectives();

        System.out.println(spinning.getBikeResistence());
        spinning.timeToExecute();
        spinning.rules();
        spinning.objectives();

        System.out.println(bodyBuilding.getExerciceWeight());
        bodyBuilding.timeToExecute();
        bodyBuilding.rules();
        bodyBuilding.objectives();
    }
}