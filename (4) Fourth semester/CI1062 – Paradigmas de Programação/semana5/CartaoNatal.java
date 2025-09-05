public class CartaoNatal extends CartaoWeb {
    
    public CartaoNatal() {}
    public CartaoNatal(String recipient) {
        super(recipient);
    }

    public String returnMessage(String sender) {
        return "Happy christmas day from" + sender;
    }
}
