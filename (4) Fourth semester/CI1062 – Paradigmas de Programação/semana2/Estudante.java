public class Estudante {
    private String nome;
    private int nota;

    public void setNome(String nome) {
        if (nome != null)
            {this.nome = nome;}
    }

    public void setNota(int nota) {
        if (nota >= 0 && nota <= 100)
            {this.nota = nota;}
    }

    public String getNome() {
        return this.nome;
    }

    public int getNota() {
        return this.nota;
    }
}