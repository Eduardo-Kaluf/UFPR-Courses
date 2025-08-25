public class StudentSchoolClassMain {

    public static void main(String args[]) {
        Student sergio = new Student("Sergio", "123");
        Student kaluf  = new Student("Kaluf",  "456");
        Student shima  = new Student("Shima",  "987");

        SchoolClass schoolClass = new SchoolClass("CI - 1062", "Rachel");

        schoolClass.addStudent(sergio);
        schoolClass.addStudent(kaluf);
        schoolClass.addStudent(shima);

        System.out.println(schoolClass.getCode());
        System.out.println(schoolClass.getProfessor());

        schoolClass.getStudents().forEach(student -> {
            System.out.println(student.toString());
        });
    }
}