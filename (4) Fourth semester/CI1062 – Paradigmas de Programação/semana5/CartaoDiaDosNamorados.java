public class CartaoDiaDosNamorados extends CartaoWeb {

    public CartaoDiaDosNamorados() {}
    public CartaoDiaDosNamorados(String recipient) {
        super(recipient);
    }

    public String returnMessage(String sender) {
        return "Happy valentine day from" + sender;
    }
}
