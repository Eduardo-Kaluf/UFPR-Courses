public class Thesis extends LibraryItem {
    private String supervisor;

    public Thesis() {}
    public Thesis(int pubYear, String title, String supervisor) {
        super(pubYear, title);
        this.setSupervisor(supervisor);
    }

    public void setSupervisor(String supervisor) {
        if (supervisor != null) {
            this.supervisor = supervisor;
        }
    }

    public String getSupervisor() {
        return this.supervisor;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ", supervisor: " + this.supervisor;
    }
}
