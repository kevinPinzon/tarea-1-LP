
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;


//HILO POR INTERFACE
public class hiloHora implements Runnable {

    
    private JLabel hora;
    public hiloHora(JLabel hora){
        this.hora=hora;
    }
    
    @Override
    public void run() {

        while(true){
        Date h= new Date();
        DateFormat f= new SimpleDateFormat("hh:mm:ss");
        hora.setText(f.format(h));
        try{
            Thread.sleep(50);
        } catch (InterruptedException ex) {
            
        }
    }
    }
    
    
}
