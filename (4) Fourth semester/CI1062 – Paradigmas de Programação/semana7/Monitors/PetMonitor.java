public class PetMonitor extends Monitor implements MonitorJobs {

    public PetMonitor() {};
    public PetMonitor(String name, Integer grr, String subject) {
        super(name, grr, subject);
    };

    @Override
    public void workSchedule() {
        System.out.println("PetMonitor Work Schedule");
    };

    @Override
    public void answerQuestions() {
        System.out.println("PetMonitor Answers");
    };
}