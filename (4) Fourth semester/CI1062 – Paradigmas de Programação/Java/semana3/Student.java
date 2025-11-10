public class Student {
    private String name;
    private String register;

    Student() {}

    Student(String name, String register) {
        this.setName(name);
        this.setRegister(register);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setRegister(String register) {
        this.register = register;
    }

    public String getRegister() {
        return this.register;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ": " + this.getName() + ", " + this.getRegister();
    }
}