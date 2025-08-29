public class Book extends LibraryItem {
    protected String publisher;

    public Book() {}
    public Book(int pubYear, String title, String publisher) {
        super(pubYear, title);
        this.setPublisher(publisher);
    }

    public void setPublisher(String publisher) {
        if (publisher != null) {
            this.publisher = publisher;
        }
    }

    public String getPublisher() {
        return this.publisher;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ", publisher: " + this.publisher;
    }
}
