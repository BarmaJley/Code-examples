import java.io.*;
import java.net.*;


  public class MultiServer {  
  static final int PORT = 8189;
  public static void main(String[] args)throws IOException {
    ServerSocket s = new ServerSocket(PORT);
    System.out.println("Server Started");
    try {
      while(true) {
// Останавливаем выполнение, до нового соединения:
        Socket socket = s.accept();
        try {
          new ServerOneThread(socket);
        } catch(IOException e) {
// Если неудача - закрываем сокет,
// в противном случае нить закроет его:
          socket.close();
        }
      }
    } finally {
        
      s.close();
    }
  }
}
