public class SelectedMonitor extends Monitor implements MonitorJobs {
    
    public SelectedMonitor() {};
    public SelectedMonitor(String name, Integer grr, String subject) {
        super(name, grr, subject);
    };

    @Override
    public void workSchedule() {
        System.out.println("SelectedMonitor Work Schedule");
    };

    @Override
    public void answerQuestions() {
        System.out.println("SelectedMonitor Answers");
    };

    public void sendReport() {
        System.out.println("SelectedMonitor Sending Report");
    };
}