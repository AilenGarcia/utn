package model;

public class CuentaBancaria {
    private static int IDCuenta = 0;
    private int ID;
    private String nombre;
    private Double balance;

    public CuentaBancaria(String nombre, Double balance) {
        this.nombre = nombre;
        this.balance = balance;
        ID = IDCuenta;
        IDCuenta++;
    }

    public Double credito(Double deposito){
        balance+= deposito;
        return balance;
    }

    public Double debito(Double sustraccion){
        if(balance>sustraccion){
            balance-=sustraccion;
        }else{
            System.out.println("No se puede realizar la operacion. FONDOS INSUFICIENTES");
        }
        return balance;
    }
    @Override
    public String toString(){
        return "Cuenta bancaria "+ID+" perteneciente a "+nombre+" tiene $"+balance;
    }

}
