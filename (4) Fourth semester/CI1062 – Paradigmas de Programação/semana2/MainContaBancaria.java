import java.util.Scanner;

public class MainContaBancaria {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String args[]) {
        ContaBancaria contas[] = new ContaBancaria[3];

        for (int i = 0; i < 3; i++) {
            System.out.println("Forneça nome e saldo: ");
            contas[i] = new ContaBancaria();
            contas[i].setNome(scanner.nextLine());
            contas[i].setSaldo(scanner.nextDouble());
            scanner.nextLine();
        }

        double sum = 0, max = -1, min = -1;
        String titularMenorSaldo = "None";

        for (int i = 0; i < 3; i++) {
            double saldo = contas[i].getSaldo();

            sum += saldo;

            if (saldo > max) 
                {max = saldo;}
            
            if (min == -1 || saldo < min) {
                min = saldo;
                titularMenorSaldo = contas[i].getNome();
            }
        }

        System.out.println("Total dos saldos, maior e nome do titular com menor saldo: ");
        System.out.println(sum + "\n" + max + "\n" + titularMenorSaldo);
    }
}