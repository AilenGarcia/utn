package model;

public class Electronics extends Product {
    private String chargerType;
    private int voltage;

    public Electronics(String name, Integer amount, Float price, String chargerType, int voltage) {
        super(name, amount, price);
        this.chargerType = chargerType;
        this.voltage = voltage;
    }

    public String getChargerType() {
        return chargerType;
    }

    public void setChargerType(String chargerType) {
        this.chargerType = chargerType;
    }

    public int getVoltage() {
        return voltage;
    }

    public void setVoltage(int voltage) {
        this.voltage = voltage;
    }

    @Override
    public String detalleDelProducto(){
        String texto = super.detalleDelProducto() + ",tipo de cargador: " + this.chargerType +", voltaje:  " + this.voltage;
        return texto;
    }
}
