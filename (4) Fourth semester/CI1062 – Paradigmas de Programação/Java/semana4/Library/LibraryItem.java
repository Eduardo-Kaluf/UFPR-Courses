public class LibraryItem {
    protected int pubYear;
    protected String title;

    public LibraryItem() {}
    public LibraryItem(int pubYear, String title) {
        this.setPubYear(pubYear);
        this.setTitle(title);
    }

    public void setTitle(String title) {
        if (title != null) {
            this.title = title;
        }
    }

    public String getTitle() {
        return this.title;
    }

    public void setPubYear(int pubYear) {
        if (pubYear > 0 && pubYear < 2020) {
            this.pubYear = pubYear;
        }
    }

    public int getPubYear() {
        return this.pubYear;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ", pubYear: " + this.pubYear + ", title: " + this.title;
    }
}