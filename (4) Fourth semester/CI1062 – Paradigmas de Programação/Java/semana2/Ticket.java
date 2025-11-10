public class Ticket {
    private String movieName;
    private int roomNumber;
    private double price;

    // Gonna start adding constructors
    public Ticket(String movieName, int roomNumber, double price) {
        this.setMovieName(movieName);
        this.setRoomNumber(roomNumber);
        this.setPrice(price);
    }

    public String getMovieName() {
        return this.movieName;
    }

    public void setMovieName(String movieName) {
        if (movieName != null)
            {this.movieName = movieName;}
    }

    public int getRoomNumber() {
        return this.roomNumber;
    }

    public void setRoomNumber(int roomNumber) {
        if (roomNumber > 0)
            {this.roomNumber = roomNumber;}
    }

    public double getPrice() {
        return this.price;
    }

    public void setPrice(double price) {
        if (price > 0)
            {this.price = price;}
    }

    @Override
    public String toString() {
        return getClass().getName() + " " +
            "Movie name: " + this.getMovieName() + " " +
            "Room number: " + this.getRoomNumber() + " " +
            "Price: " + this.getPrice(); 
    }
}