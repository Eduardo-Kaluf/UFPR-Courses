public class Book {
    private String title;
    private Author author;

    Book() {}

    Book(String title) {
        this.setTitle(title);
    }

    Book(String title, Author author) {
        this.setTitle(title);
        this.setAuthor(author);
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    public void setAuthor(Author author) {
        this.author = author;
    }

    public Author getAuthor() {
        return this.author;
    }

    @Override
    public String toString() {
        return (getClass().getName() + ": \n" +
                this.getTitle() + "\n" +
                this.getAuthor().getName() + "\n" +
                this.getAuthor().getNationality());
    }

}