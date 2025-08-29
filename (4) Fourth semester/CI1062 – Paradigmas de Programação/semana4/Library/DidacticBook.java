public class DidacticBook extends Book {
    private String discipline;

    public DidacticBook() {}
    public DidacticBook(int pubYear, String title, String publisher, String discipline) {
        super(pubYear, title, publisher);
        this.setPublisher(discipline);
    }

    public void setDiscipline(String discipline) {
        if (discipline != null) {
            this.discipline = discipline;
        }
    }

    public String getDiscipline() {
        return this.discipline;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ", discipline: " + this.discipline;
    }
}
