package model.ejercicio5;

public class Staff extends Persona{
    private static int contId;
    private int id;
    private Double salario;
    private String turno;

    public Staff(String dni, String name, String lastName, String email, String address, Double salario, String turno) {
        super(dni, name, lastName, email, address);
        this.salario = salario;
        this.turno = turno;
        this.id = contId;
        contId++;
    }

    public int getId() {
        return id;
    }

    public Double getSalario() {
        return salario;
    }

    public void setSalario(Double salario) {
        this.salario = salario;
    }

    public String getTurno() {
        return turno;
    }

    public void setTurno(String turno) {
        this.turno = turno;
    }
}
