public class ContaBancaria {
    private String nome;
    private float saldo;
    private float limite;

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setSaldo(float saldo) {
        this.saldo = saldo;
    }

    public void setLimite(float limite) {
        this.limite = limite;
    }

    public String getNome() {
        return this.nome;
    }

    public float getSaldo() {
        return this.saldo;
    }

    public float getLimite() {
        return this.limite;
    }
}
