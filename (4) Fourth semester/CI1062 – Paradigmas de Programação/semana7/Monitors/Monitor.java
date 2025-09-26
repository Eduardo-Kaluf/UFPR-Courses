public class Monitor {
    protected String name;
    protected Integer grr;
    protected String subject;

    public Monitor() {};
    public Monitor(String name, Integer grr, String subject) {
        this.setName(name);
        this.setGrr(grr);
        this.setSubject(subject);
    };

    public void setName(String name) {
        if (name != null) {
            this.name = name;
        }
    }

    public String getName() {
        return this.name;
    }

    public void setGrr(Integer grr) {
        if (grr != null) {
            this.grr = grr;
        }
    }

    public Integer getGrr() {
        return this.grr;
    }

    public void setSubject(String subject) {
        if (subject != null) {
            this.subject = subject;
        }
    }

    public String getSubject() {
        return this.subject;
    }
}
