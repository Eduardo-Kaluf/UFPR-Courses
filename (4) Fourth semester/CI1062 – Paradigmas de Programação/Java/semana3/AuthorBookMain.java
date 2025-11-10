public class AuthorBookMain {

    public static void main(String args[]) {

        Author author = new Author("Kaluf", "BR");
        Book book = new Book("Hello world", author);

        System.out.println(book.toString());
    }
}