package ejercicio2;

public class Pez implements Acuatico{
    private Animal animal;
    private Estado estado;

    public Pez(Estado estado) {
        this.animal = Animal.PEZ;
        this.estado = estado;
    }

    public String remolinos(){
        return "El pez hace remolinos";
    }

    @Override
    public String comer() {
        return "El pez come";
    }

    @Override
    public String dormir() {
        return "El pez duerme";
    }

    @Override
    public String comunicarse() {
        return "El pez se comunica";
    }

    @Override
    public String sonido() {
        if(this.estado == Estado.FELICIDAD){
            return "El pez hace burbujitas";
        }else{
            return  "El pez se escapa";
        }
    }

    @Override
    public String nadar() {
        return "El pez nada en las profundidades";
    }
}
