public class Time {
    private int hours;
    private int minutes;

    public int getHours() {
        return this.hours;
    }

    public int getMinutes() {
        return this.minutes;
    }

    public void setHours(int hours) {
        if (hours >= 0 && hours <= 24)
            {this.hours = hours;}
    }

    public void setMinutes(int minutes) {
        if (minutes >= 0 && minutes <= 60)
            {this.minutes = minutes;}
    }

    public boolean anterior(int h, int m) {
        if (!posterior(h, m) && !equals(h, m)) {
            return true;
        }

        return false;
    }
    
    public boolean posterior(int h, int m) {
        if (h > this.getHours() || this.equals(h, m) && m > this.getMinutes()) {
            return true;
        }
    
        return false;
    }
    
    public boolean equals(int h, int m) {
        if (h == this.getHours() && m == this.getMinutes()) {
            return true;
        }

        return false;
    }

    @Override
    public String toString() {
        return getClass().getName() + " " +
            this.getHours() + ":" + this.getMinutes();
    }
}