import java.util.Scanner;
import java.util.ArrayList;

public class MainEstudante {
    private static int sum = 0;
    private static int cookedOnes = 0;
    private static int semiCookedOnes = 0;
    private static int niceOnes = 0;
    private static int grade = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        ArrayList<Estudante> estudantes = new ArrayList<>();

        for (int i = 0; i < 5; i++) {
            Estudante estudante = new Estudante();
            estudante.setNota(scanner.nextInt());
            estudante.setNome(scanner.next());
            estudantes.add(estudante);
        }

        estudantes.forEach(estudante -> {
            grade = estudante.getNota();
            sum += grade;
            
            if (grade <= 40) {
                cookedOnes += 1;
            }
            else if (grade >= 70) {
                niceOnes += 1;
            }
            else {
                semiCookedOnes += 1;
            }
        });

        
        System.out.println(sum / 5);
        System.out.println(cookedOnes);
        System.out.println(semiCookedOnes);
        System.out.println(niceOnes);

        scanner.close();
    }
}