import java.io.*;
import java.net.*;
import java.util.*;

/**
 * This program implements a simple server that listens to port 8189 and echoes back all client
 * input.
 * @version 1.20 2004-08-03
 * @author Cay Horstmann
 */
public class EchoServer
{
    private ServerSocket s;
    private int port;
    private Socket incoming;
    public EchoServer( int p){
        port = p;
    }
   public  void connect(){
    try
      {
         // establish server socket
         s = new ServerSocket(port);
         System.out.println("Wait ...");
         // wait for client connection
          incoming = s.accept();
         try (InputStream inStream  = incoming.getInputStream();
             OutputStream outStream = incoming.getOutputStream())
            {
            Scanner in = new Scanner(inStream);
            PrintWriter out = new PrintWriter(outStream, true /* autoFlush */);

            out.println("Hello! Enter BYE to exit.");

            // echo client input
            boolean done = false;
            while (!done && in.hasNextLine())
            {
               String line = in.nextLine();
               System.out.println("klient tell-"+line);
               if (line.trim().equals("BYE")) {
                   done = true;
                   out.println("close");
               }
               else 
                    out.println("Echo: " + line);
            }
         }
         finally
         {
            incoming.close();
         }
      }
      catch (IOException e)
      {
         e.printStackTrace();
      }
   }
    public static void main(String[] args){
        EchoServer s = new EchoServer(8189);
        s.connect();
    }
}
