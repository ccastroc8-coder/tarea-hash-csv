public class Estudiante {

    int student_id;
    String full_name;
    String career;
    int semester;
    double gpa;
    int skill_score;

    public Estudiante(
            int student_id,
            String full_name,
            String career,
            int semester,
            double gpa,
            int skill_score
    ) {

        this.student_id = student_id;
        this.full_name = full_name;
        this.career = career;
        this.semester = semester;
        this.gpa = gpa;
        this.skill_score = skill_score;

    }

    @Override
    public String toString() {

        return "ID: " + student_id +
               "\nNombre: " + full_name +
               "\nCarrera: " + career +
               "\nSemestre: " + semester +
               "\nGPA: " + gpa +
               "\nSkill Score: " + skill_score;

    }

}