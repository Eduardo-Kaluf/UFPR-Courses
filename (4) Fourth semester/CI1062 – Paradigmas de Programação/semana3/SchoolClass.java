import java.util.List;
import java.util.ArrayList;


public class SchoolClass {
    private String code;
    private String professor;
    private List<Student> students;

    SchoolClass() {}

    SchoolClass(String code, String professor) {
        this.setCode(code);
        this.setProfessor(professor);
        this.students = new ArrayList<>();
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getCode() {
        return this.code;
    }

    public void setProfessor(String professor) {
        this.professor = professor;
    }

    public String getProfessor() {
        return this.professor;
    }

    public void addStudent(Student student) {
        this.students.add(student);
    }

    public List<Student> getStudents() {
        return this.students;
    }
}