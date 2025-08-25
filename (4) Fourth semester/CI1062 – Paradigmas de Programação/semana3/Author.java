public class Author {
    private String name;
    private String nationality;

    Author() {}

    Author(String name) {
        this.setName(name);
    }

    Author(String name, String nationality) {
        this.setName(name);
        this.setNationality(nationality);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    public String getNationality() {
        return this.nationality;
    }
}
