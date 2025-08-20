public class ContaBancaria {
    private String nome;
    private double saldo;
    private double limite;

    public void setNome(String nome) {
        if (nome != null) 
            {this.nome = nome;}
    }

    public void setSaldo(double saldo) {
        if (saldo >= 0)
            {this.saldo = saldo;}
    }

    public void setLimite(double limite) {
        if (limite <= saldo)
            {this.limite = limite;}
    }

    public String getNome() {
        return this.nome;
    }

    public double getSaldo() {
        return this.saldo;
    }

    public double getLimite() {
        return this.limite;
    }

    public void depositar(double quantia) {
        if (quantia > 0) {
            this.setSaldo(quantia + this.getSaldo());
            this.setLimite(this.getSaldo());
        }
    }

    public double sacar(double quantia) {
        if ((quantia > 0) && (quantia <= this.getLimite())) {
            this.setSaldo(this.getSaldo() - quantia);
            this.setLimite(this.getSaldo());

            return quantia;
        }

        return 0.0;
    }
}
