public class PropertyMain {
    public static void main(String args[]) {

        Property properties[] = new Property[200];

        Address newFakeAddress = new Address("Manoel Ribas", 125, "Merces", "Curitiba", "PR");
        Address oldFakeAddress = new Address("ParolinStreet", 2000, "Parolin", "Curitiba", "PR");

        for (int i = 0; i < 200; i++) {
            if (i % 2 == 0) {
                properties[i] = new NewProperty(newFakeAddress, i * 12.5);
            }
            else {
                properties[i] = new OldProperty(oldFakeAddress, i * 12.5);
            }

            System.out.println(properties[i].calcPropertyValue());
        }
    }
}

// Polimorfismo utilizado:
// Inclusão em properties, temos um array de Property que recebe NewProperty e OldProperty
// Temos nesse mesmo caso Upcast acontecendo (coerção)
