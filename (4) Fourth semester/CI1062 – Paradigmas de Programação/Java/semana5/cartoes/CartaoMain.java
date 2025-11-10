public class CartaoMain {
    public static void main(String args[]) {

        CartaoWeb cartoes[] = new CartaoWeb[4];
        cartoes[0] = new CartaoAniversario("Sergio");
        cartoes[1] = new CartaoNatal("Kaluf");
        cartoes[2] = new CartaoDiaDosNamorados("Shima");

        for (int i = 0; i < 3; i++) {
            System.out.println(cartoes[i].returnMessage(" Grandma"));
        }
    }
}