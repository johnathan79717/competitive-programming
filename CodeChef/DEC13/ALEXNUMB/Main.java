import java.util.*;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    while(T-- > 0) {
      long n = sc.nextLong();
      while(n-- > 0) sc.next();
      System.out.println(n * (n-1) / 2);
    }
  }
} 