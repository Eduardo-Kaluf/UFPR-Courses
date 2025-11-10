public class DigitalMedia extends LibraryItem {
    private String format;

    public DigitalMedia() {}
    public DigitalMedia(int pubYear, String title, String format) {
        super(pubYear, title);
        this.setFormat(format);
    }

    public void setFormat(String format) {
        if (format != null) {
            this.format = format;
        }
    }

    public String getFormat() {
        return this.format;
    }

    @Override
    public String toString() {
        return this.getClass().getName() + ", format: " + this.format;
    }
}
