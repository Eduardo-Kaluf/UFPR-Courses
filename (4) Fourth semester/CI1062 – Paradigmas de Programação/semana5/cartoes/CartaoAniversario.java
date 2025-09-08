public class CartaoAniversario extends CartaoWeb {
    
    public CartaoAniversario() {}
    public CartaoAniversario(String recipient) {
        super(recipient);
    }

    public String returnMessage(String sender) {
        return "Happy birthday from" + sender;
    }
}
