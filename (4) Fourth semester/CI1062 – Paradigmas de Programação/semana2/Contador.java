public class Contador {
    private int counter;


    public int getCounter() {
        return this.counter;
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    public void zeroCounter() {
        this.counter = 0;
    }

    public void incCounter() {
        this.counter += 1;
    }

    public void decCounter() {
        if (this.counter >= 1)
            {this.counter -= 1;}
    }
}

// Classes como Lista... 