import java.io.*;
import java.net.*;
/** Данный класс реализует взаимодействие сервера с одним  
клиентом, создавая для него поток и  завершая его, 
после получения от клиента сообщения о завершении сеанса работы
*/ 
public class ServerOneThread  extends Thread {
  private Socket socket;
  private BufferedReader in;
  private PrintWriter out;
  public ServerOneThread (Socket s) throws IOException {
    socket = s;// получение сокета для обмена данными
    in = new BufferedReader(
        new InputStreamReader(socket.getInputStream()));
    out = new PrintWriter(
        new BufferedWriter(new OutputStreamWriter(
            socket.getOutputStream())), true);
// Если какой либо, указанный выше класс выбросит исключение 
// вызывающая процедура ответственна за закрытие сокета
// В противном случае нить(поток) закроет его.
    start(); 
  }
  public void run() {
    try {
      out.println("Hello! Enter END to exit.");
      boolean done=true;
      while (done) {  
        String str = in.readLine();
        if (str.equals("BYE")) {
               out.println("close");
               done=false;
        Thread.currentThread().interrupt();
        } 
        else{
        System.out.println("Echoing: " + str);
        out.println("ECHO:"+str);}
      }
    } catch(IOException e) {
      System.err.println("IO Exception");
    } finally {
      try {
   System.out.println("closing...");
        socket.close();
      } catch(IOException e) {
        System.err.println("Socket not closed");
      }
    }
  }
}
   
