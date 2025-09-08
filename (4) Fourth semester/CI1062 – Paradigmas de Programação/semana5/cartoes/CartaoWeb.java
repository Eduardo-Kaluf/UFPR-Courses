public abstract class CartaoWeb {
    protected String recipient;

    public CartaoWeb() {}
    public CartaoWeb(String recipient) {
        this.setRecipient(recipient);
    }

    public abstract String returnMessage(String sender);

    public void setRecipient(String recipient) {
        this.recipient = recipient;
    }

    public String getRecipient() {
        return this.recipient;
    }
}
