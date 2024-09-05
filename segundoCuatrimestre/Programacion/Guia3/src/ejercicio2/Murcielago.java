package ejercicio2;

public class Murcielago implements Volador{
    private Animal animal;
    private Estado estado;

    public Murcielago(Estado estado) {
        this.animal = Animal.MUERCIELAGO;
        this.estado = estado;
    }
    public String cazar(){
        return "El murcielago caza";
    }
    public String colgar(){
        return "El muerciela esta colgado en una cueva";
    }

    @Override
    public String volar() {
        return "El murcielago vuela";
    }

    @Override
    public String comer() {
        cazar();
        return "El murcielago come";
    }

    @Override
    public String dormir() {
        colgar();
        return "Ahora el muercielago duerme";
    }

    @Override
    public String comunicarse() {
        return "El muercielago se comunica";
    }

    @Override
    public String sonido() {
        if(this.estado == Estado.FELICIDAD){
            return "El murcielago canta";
        }else{
            return  "El murcielago grita";
        }
    }
}
