import java.io.*;
import java.net.*;
import java.util.*;

public class UDPEchoServer {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        DatagramSocket ds = new DatagramSocket();
        InetAddress ip = InetAddress.getLocalHost();
        byte buf[] = null;
        while (true) {
            System.out.println("Enter message for Client");
            String input = sc.nextLine();
            buf = input.getBytes();
            DatagramPacket DpSend = new DatagramPacket(buf, buf.length, ip, 1234);
            ds.send(DpSend);
            if (input.equals("bye"))
                break;
        }
    }
}
