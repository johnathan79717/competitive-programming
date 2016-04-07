import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt(), cas = 1;
    while(T-- > 0) {
      String L = sc.next();
      long N = sc.nextLong(), num = 1;
      System.out.print("Case #");
      System.out.print(cas++);
      System.out.print(": ");
      N--;
      while(N / num >= L.length()) {
        num *= L.length();
        N -= num;
      }
      while(num > 0) {
        System.out.print(L.charAt((int)(N / num)));
        N %= num;
        num /= L.length();
      }
      System.out.println();
    }
  }
}