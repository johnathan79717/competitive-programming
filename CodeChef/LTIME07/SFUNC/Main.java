import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long n = sc.nextLong();
    int K = sc.nextInt();
    BigInteger M = sc.nextBigInteger();
    long tmp = n, phi = n, a = 1;
    for(long p = 2; p * p <= tmp; p++) {
      if(tmp % p == 0) {
        while(tmp % p == 0) tmp /= p;
        phi = phi / p * (p - 1);
        a *= (1 - p);
      }
    }
    if(tmp > 1) {
      phi = phi / tmp * (tmp - 1);
      a *= 1 - tmp;
    }
    BigInteger N = BigInteger.valueOf(n);
    BigInteger A = BigInteger.valueOf(a);
    BigInteger PHI = BigInteger.valueOf(phi);
    BigInteger ans = BigInteger.valueOf(0);
    // System.out.println(n);
    // System.out.println(a);
    // System.out.println(long);
    if(K == 1) {
      ans = PHI.multiply(N).divide(BigInteger.valueOf(2));
    } else if(K == 2) {
      ans = BigInteger.valueOf(2).multiply(N).multiply(N).multiply(PHI).add(N.multiply(A)).divide(BigInteger.valueOf(6));
    } else {
      ans = N.multiply(PHI).add(A).multiply(N).multiply(N).divide(BigInteger.valueOf(4));
    }
    // System.out.println(ans);
    System.out.println(ans.mod(M).add(M).mod(M));
  }
}