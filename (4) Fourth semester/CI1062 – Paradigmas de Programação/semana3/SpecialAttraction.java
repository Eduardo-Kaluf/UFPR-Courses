public class SpecialAttraction {
    private String name;
    private int maxCapacity;
    private int activeUsers;

    SpecialAttraction(String name, int maxCapacity, int activeUsers) {
        this.setName(name);
        this.setMaxCapacity(maxCapacity);
        this.setActiveUsers(activeUsers);
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setMaxCapacity(int maxCapacity) {
        this.maxCapacity = maxCapacity;
    }

    public int getMaxCapacity() {
        return this.maxCapacity;
    }

    public void setActiveUsers(int activeUsers) {
        this.activeUsers = activeUsers;
    }

    public int getActiveUsers() {
        return this.activeUsers;
    }

    public boolean verifyMaxThreshold() {
        if (this.activeUsers > this.maxCapacity) {
            return true;
        }

        return false;
    }

    public void addPerson() {
        this.activeUsers += 1;
    }
}