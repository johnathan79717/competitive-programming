import java.util.*;
import java.math.*;

class Turn implements Comparable<Turn> {
  int overtake;
  int normal;
  Double ratio;
  Turn(int o, int n) {
    overtake = o;
    normal = n;
    ratio = (overtake - 1) * normal / (double) (overtake * (normal - 1));
  }
  public int compareTo(Turn t) {
    return -ratio.compareTo(t.ratio);
  }
}

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    while(n-- > 0) {
      int r = sc.nextInt();
      int t = sc.nextInt();
      Turn[] turns = new Turn[t];
      for(int i = 0; i < t; i++)
        turns[i] = new Turn(sc.nextInt(), sc.nextInt());

      Arrays.sort(turns);
      BigInteger numerator = BigInteger.valueOf(1);
      BigInteger denominator = BigInteger.valueOf(1);
      for(int i = 0; i < r - 1; i++) {
        numerator = numerator.multiply(BigInteger.valueOf(turns[i].overtake - 1));
        denominator = denominator.multiply(BigInteger.valueOf(turns[i].overtake));
      }
      for(int i = r - 1; i < t; i++) {
        numerator = numerator.multiply(BigInteger.valueOf(turns[i].normal - 1));
        denominator = denominator.multiply(BigInteger.valueOf(turns[i].normal));
      }
      BigInteger d = numerator.gcd(denominator);
      System.out.print(numerator.divide(d));
      System.out.print('/');
      System.out.println(denominator.divide(d));
    }
  }
}