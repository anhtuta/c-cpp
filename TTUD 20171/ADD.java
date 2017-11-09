

import java.util.Scanner;
import java.math.BigInteger;

public class ADD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        BigInteger c = a.add(b);
        
        System.out.println(c);
    }
}
