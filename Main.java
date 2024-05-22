package lib_io;
import lib_io.lib.Deflib_io;


public class Main{

  static {

    System.loadLibrary("MMOne");
  
  }

  public Main(){
  
  double n = 2;
  double L = 8;
  double M = 12;
  

  Deflib_io lib = new Deflib_io();
  double[] resultado = lib.calMmOne(n, L, M); 
    
  for (int i = 0; i < resultado.length; i++) {
            System.out.printf("Resultado %d: %.2f\n", i, resultado[i]);
    }

  }

  public static void main(String [] argumentos){
   
  new Main();  

  }



}
