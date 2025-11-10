public class Visitor {
    private String name;
    private int age;
    private double money;

    Visitor(String name, int age, double money) {
        this.setName(name);
        this.setAge(age);
        this.setMoney(money);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public double getMoney() {
        return this.money;
    }

    public void buyTicket(double ticketPrice) {
        this.money -= ticketPrice;
    }
}