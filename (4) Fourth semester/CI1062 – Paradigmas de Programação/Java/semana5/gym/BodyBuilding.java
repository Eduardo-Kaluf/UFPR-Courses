public class BodyBuilding extends Fitness {
    private int exerciceWeight;


    public BodyBuilding() {}
    public BodyBuilding(int exerciceWeight) {
        this.setExerciceWeight(exerciceWeight);
    }


    public void timeToExecute() {
        System.out.println("2 hours");
    }


    public int getExerciceWeight() {
        return this.exerciceWeight;
    }

    public void setExerciceWeight(int exerciceWeight) {
        this.exerciceWeight = exerciceWeight;
    }
}