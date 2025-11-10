

public class Person {
    private String name;
    private int age;
    private int day;
    private int month;
    private int year;

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return this.age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void ajustDateOfBirth(int day, int month, int year) {
        if ((day > 0) && (day <= 31)) {
            this.day = day;
        }

        if ((month > 0) && (month <= 12)) {
            this.month = month;
        }

        // Really good verification
        // I mean, we shouldn't even store a date like this
        // So wathever 
        if (year > 0) {
            this.year = year;
        }
    }

    public void calculateAge(int currentDay, int currentMonth, int currentYear) {
        int age = currentYear - this.year;

        if (currentMonth < this.month) {
            this.setAge(age - 1);
            return;
        }

        if (currentMonth == this.month) {
            if (currentDay < this.day) {
                this.setAge(age - 1);
                return;
            }
        }

        this.setAge(age);
    }
}