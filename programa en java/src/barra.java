
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JProgressBar;


public class barra extends Thread{

    
    private JProgressBar barra1;
    private boolean avanzar;
    private boolean vive;
    
    public barra(JProgressBar barra1){
        this.barra1=barra1;
        avanzar=true;
        vive=true;
        
    }
    
    public void run(){
        while(vive){
            if(avanzar){
                barra1.setValue(barra1.getValue()+1);
                if(barra1.getValue()==100000){
                    vive=false;
                }
                
                    try {
                        Thread.sleep(5);
                    } catch (InterruptedException ex) {
                      
                    }
            }
        }
           
        
    }
    
    
    
    

    public JProgressBar getBarra1() {
        return barra1;
    }

    public void setBarra1(JProgressBar barra1) {
        this.barra1 = barra1;
    }

    public boolean isAvanzar() {
        return avanzar;
    }

    public void setAvanzar(boolean avanzar) {
        this.avanzar = avanzar;
    }

    public boolean isVive() {
        return vive;
    }

    public void setVive(boolean vive) {
        this.vive = vive;
    }
    
    
    
    
}
