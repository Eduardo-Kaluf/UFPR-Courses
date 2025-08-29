public class LibraryMain {
    public static void main(String args[]) {

        Book book = new Book(1000, "BOOK", "SHIMA");
        DidacticBook didacticBook = new DidacticBook(1500, "DIDACTICBOOK", "SERGIO", "THE WITCHER");
        DigitalMedia digitalMedia = new DigitalMedia(2000, "DIGITALMEDIA", "MP3");
        LibraryItem libraryItem = new LibraryItem(2015, "LIBRARYITEM");
        Thesis thesis = new Thesis(80, "THESIS", "FULBER");
    
        // We did not learn Collectors yet;
        int max = book.getPubYear();
        if (didacticBook.getPubYear() > max) {
            max = didacticBook.getPubYear();
        }
        if (digitalMedia.getPubYear() > max) {
            max = digitalMedia.getPubYear();
        }
        if (libraryItem.getPubYear() > max) {
            max = libraryItem.getPubYear();
        }
        if (thesis.getPubYear() > max) {
            max = thesis.getPubYear();
        }

        System.out.println(max);

    }
}
