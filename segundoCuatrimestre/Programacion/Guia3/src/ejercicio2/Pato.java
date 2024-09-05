package ejercicio2;

public class Pato implements Acuatico, Volador {
     private Animal animal;
     private Estado estado;

    public Pato(Estado estado) {
        this.animal = Animal.PATO;
        this.estado = estado;
    }

    public String flotar(){
        return "El pato flota";
    }

    @Override
    public String nadar() {
        return "El pato nada";
    }

    @Override
    public String volar() {
        return "El pato vuela";
    }

    @Override
    public String comer() {
        return "El pato come";
    }

    @Override
    public String dormir() {
        return "El pato duerme";
    }

    @Override
    public String comunicarse() {
        return "El pato se comunica";
    }

    @Override
    public String sonido() {
        if(this.estado == Estado.FELICIDAD){
            return "El pato grazna feliz";
        }else{
            return  "El paso granza furioso";
        }
    }
}
