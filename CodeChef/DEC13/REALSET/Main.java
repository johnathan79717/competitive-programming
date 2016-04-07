import java.util.*;
import java.math.*;
import java.io.*;

public class Main {

static class Complex {
  double real, imag;
  static Complex zero = new Complex(0, 0);
  Complex(double real, double imag) {
    this.real = real;
    this.imag = imag;
  }

  Complex(double real) {
    this.real = real;
    this.imag = 0.0;
  }

  Complex add(Complex b) {
    return new Complex(real + b.real, imag + b.imag);
  }

  Complex subtract(Complex b) {
    return new Complex(real - b.real, imag - b.imag);
  }

  Complex mul(Complex b) {
    return new Complex(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
  }
}

static class FFT {
  static Complex[] omega;
  static final int N = 65536;
  static int len;
  static void calOmega(){
    double unit = 2 * Math.PI / len;
    int n = len >> 1;
    omega = new Complex[n];
    for (int i = 0; i < n; ++ i) {
      double t = unit * i;
      omega[i] = new Complex(Math.cos( t ), Math.sin( t ));
    }
  }

  static void setLen(int len) {
    FFT.len = 1;
    while(FFT.len < len + 1)
      FFT.len <<= 1;
  }

  static Complex[] convert(Poly a) {
    Complex[] ret = new Complex[len];
    for(int i = 0; i <= a.deg; i++)
      ret[i] = new Complex(a.arr[i]);
    for(int i = a.deg + 1; i < len; i++)
      ret[i] = Complex.zero;
    return ret;
  }

  static void bitReverse(Complex a[]) {
    int i, j = 1, k;
    Complex t;
    for (i = 1; i < len; ++ i) {
      if (i < j) {
        t = a[j-1];
        a[j-1] = a[i-1];
        a[i-1] = t;
      }
      k = len >> 1;
      while (k < j) {
        j -= k;
        k >>= 1;
      }
      j += k;
    }
  }

  static void fft(Complex[] a, boolean inverse) {
    bitReverse( a );
  
    int s = len >> 1;
    int m, k, j;
    int up, t, step;
    int i1, i2;
    Complex tmp;

    if ( inverse ) {
      for (j = 0; j < s; ++ j)
        omega[j].imag = -omega[j].imag;
    }
    s = 1;
    for (m = 2; m <= len; m <<= 1) {
      up = m >> 1; t = len >> s;
      for (k = 0; k < len; k += m) {
        step = 0;
        for (j = 0; j < up; ++ j) {
          i1 = k + j;
          i2 = i1 + up;
          tmp = omega[step].mul(a[i2]);
          a[i2] = a[i1].subtract(tmp);
          a[i1] = a[i1].add(tmp);
          step += t;
        }
      }
      ++ s;
    }
    if ( inverse ) {
      for (j = 0; j < len; ++ j)
        a[j].real /= len;
    }
  }

  static void mul(Complex[] a, Complex[] b) {
    for (int i = 0; i < len; ++ i)
      a[i] = a[i].mul(b[i]);
  }
}

static class Poly {
  double[] arr;
  int deg;
  final static Poly zero;
  final static Poly one;
  final static double epsilon = 1e-9;
  static {
    zero = new Poly(-1);
    one = new Poly(0);
    one.arr[0] = 1.0;
  }
  static Poly monomial(int l) {
    Poly ret = new Poly(l);
    ret.arr[ret.deg] = 1;
    return ret;
  }
  Poly(int n) {
    if(n < 0)
      deg = Integer.MIN_VALUE;
    else {
      arr = new double[n + 1];
      deg = n;
    }
  }
  Poly(double[] arr) {
    deg = arr.length - 1;
    this.arr = arr;
    this.chomp();
  }

  Poly add(Poly b) {
    Poly ret = new Poly(Math.max(deg, b.deg));
    int i = 0;
    while(i <= deg && i <= b.deg) {
      ret.arr[i] = arr[i] + b.arr[i];
      i++;
    }
    while(i <= deg) {
      ret.arr[i] = arr[i];
      i++;
    }
    while(i <= b.deg) {
      ret.arr[i] = b.arr[i];
      i++;
    }
    return ret.chomp();
  }

  Poly div(int m) {
    if(deg < m)
      return Poly.zero;
    Poly ret = new Poly(deg - m);
    for(int i = 0; i <= ret.deg; i++)
      ret.arr[i] = arr[i+m];
    return ret.chomp();
  }

  Poly mod(int l) {
    if(deg < l)
      return this;
    Poly ret = new Poly(l-1);
    for(int i = 0; i <= ret.deg; i++)
      ret.arr[i] = arr[i];
    return ret.chomp();
  }

  Poly mul(Poly bb) {
    if(deg < 0 || bb.deg < 0)
      return Poly.zero;
    FFT.setLen(deg + bb.deg);
    Complex[] a = FFT.convert(this), b = FFT.convert(bb);
    FFT.calOmega();
    FFT.fft(a, false);
    FFT.fft(b, false);
    FFT.mul(a, b);
    FFT.fft(a, true);
    Poly ret = new Poly(deg + bb.deg);
    for(int i = 0; i <= ret.deg; i++)
      ret.arr[i] = a[i].real;
    return ret.chomp();
  }

  Poly chomp() {
    int i;
    for(i = deg; i >= 0 && Math.abs(arr[i]) < epsilon; i--)
      deg--;
    if(i < 0)
      deg = Integer.MIN_VALUE;
    return this;
  }

  Poly reverse(int deg) {
    if(this.deg < 0) return this;
    Poly ret = new Poly(deg);
    for(int i = 0; i <= this.deg; i++)
      ret.arr[deg - i] = this.arr[i];
    return ret.chomp();
  }

  Poly invMod(int l2) {
    if(l2 % 2 == 1) {
      if(l2 == 1) {
        // Poly ret = new Poly(0);
        // ret.arr[0] = 1 / arr[0];
        // return ret;
        return Poly.one;
      }
      return invMod(l2 + 1).mod(l2);
    }
    int l = l2 / 2;
    Poly a = invMod(l);
    Poly h0 = this.mod(l);
    Poly h1 = this.div(l);
    Poly c = a.mul(h0).div(l);
    Poly b = a.neg().mul(h1.mul(a).mod(l).add(c)).mod(l);
    return a.add(monomial(l).mul(b));
  }

  Poly div(Poly g) {
    Poly f = this;
    if(f.deg < g.deg)
      return Poly.zero;
    Poly rf = f.reverse(f.deg), rg = g.reverse(g.deg);
    int mod = f.deg - g.deg + 1;
    Poly rg_inv = rg.invMod(mod);
    Poly rq = rg_inv.mul(rf).mod(mod);
    return rq.reverse(mod - 1);
  }

  Poly mod(Poly g) {
    Poly f = this;
    Poly q = f.div(g);
    return f.sub(g.mul(q)).chomp();
  }

  Poly neg() {
    if(deg < 0)
      return this;
    Poly ret = new Poly(deg);
    for(int i = 0; i <= deg; i++)
      ret.arr[i] = -arr[i];
    return ret.chomp();
  }

  Poly sub(Poly b) {
    return this.add(b.neg()).chomp();
  }

  void print() {
    if(deg < 0)
      System.out.println(0.0);
    else {
      System.out.print(arr[0]);
      for(int i = 1; i <= deg; i++) {
        System.out.print(arr[i] > 0 ? " + " : " - ");
        System.out.print(Math.abs(arr[i]));
        System.out.print("x^");
        System.out.print(i);
      }
      System.out.println();
    }
  }

  Poly div(double r) {
    Poly ret = new Poly(deg);
    for(int i = 0; i <= deg; i++)
      ret.arr[i] = arr[i] / r;
    return ret;
  }

  Poly monic() {
    if(deg < 0)
      return this;
    return this.div(arr[deg]);
  }

  double lc() {
    return arr[deg];
  }

  Matrix hgcd(Poly b) {
    // assume a, b are monic
    Poly a = this;
    int m = (a.deg + 1) / 2;
    if(b.deg < m)
      return Matrix.identity;
    Poly a0 = a.div(m), b0 = b.div(m); // a0, b0 monic
    Matrix R = a0.hgcd(b0);
    Vector ab1 = R.mul(new Vector(a, b));
    Poly a1 = ab1.fst, b1 = ab1.snd;
    if(b1.deg < m)
      return R;
    R.a00 = R.a00.div(a1.lc());
    R.a01 = R.a01.div(a1.lc());
    a1 = a1.monic();
    R.a10 = R.a10.div(b1.lc());
    R.a11 = R.a11.div(b1.lc());
    b1 = b1.monic();
    Poly q = a1.div(b1);
    Matrix Q = new Matrix(Poly.zero, Poly.one, Poly.one, q.neg());
    Poly c = b1, d = a1.sub(b1.mul(q)); // c monic
    if(d.deg >= 0) {
      Q.a10 = Q.a10.div(d.lc());
      Q.a11 = Q.a11.div(d.lc());
      d = d.monic();
    }
    int l = c.deg, k = 2 * m - l;
    Poly c0 = c.div(k), d0 = d.div(k);
    Matrix S = c0.hgcd(d0);
    return S.mul(Q).mul(R);
  }

  Poly gcd(Poly b) {
    Poly a = this;
    a = a.monic();
    b = b.mod(a);
    if(b.deg < 0)
      return a;
    b = b.monic();
    Matrix Q = a.hgcd(b);
    Vector v = Q.mul(new Vector(a, b));
    a = v.fst; b = v.snd;
    if(b.deg < 0)
      return a;
    return b.gcd(a.mod(b)).chomp();
  }
}

static class Matrix {
  static final Matrix identity = new Matrix(Poly.one, Poly.zero, Poly.zero, Poly.one);
  Poly a00, a01, a10, a11;
  int det;
  Matrix(Poly a00, Poly a01, Poly a10, Poly a11) {
    this.a00 = a00;
    this.a01 = a01;
    this.a10 = a10;
    this.a11 = a11;
  }

  Vector mul(Vector c) {
    return new Vector(a00.mul(c.fst).add(a01.mul(c.snd)), a10.mul(c.fst).add(a11.mul(c.snd)));
  }

  Matrix mul(Matrix m) {
    return new Matrix(a00.mul(m.a00).add(a01.mul(m.a10)),
                      a00.mul(m.a01).add(a01.mul(m.a11)),
                      a10.mul(m.a00).add(a11.mul(m.a10)),
                      a10.mul(m.a01).add(a11.mul(m.a11)));
  }
}

static class Vector {
  public Poly fst, snd;
  Vector(Poly fst, Poly snd) {
    this.fst = fst;
    this.snd = snd;
  }
}

  static void solve() {
    BufferedReader reader = null;
    try {
      // Scanner sc = new Scanner(System.in);
      File file = new File("in2");
      reader = new BufferedReader(new FileReader(file));
      String text = null;
      // int T = sc.nextInt();
      text = reader.readLine();
      int T = Integer.parseInt(text);
      while(T-- > 0) {
        // int N = sc.nextInt();
        text = reader.readLine();
        int N = Integer.parseInt(text);
        Poly a = new Poly(N-1), b = new Poly(N);
        for(int i = 0; i < N; i++) {
          // int A = sc.nextInt();
          text = reader.readLine();
          int A = Integer.parseInt(text);
          a.arr[i] = A;
          if(A != 0)
            a.deg = i;
          b.arr[i] = 0;
        }
        a.chomp();
        b.arr[0] = -1;
        b.arr[N] = 1;
        System.out.println(b.gcd(a).deg > 0 ? "YES" : "NO");
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        if (reader != null)
            reader.close();
      } catch (IOException e) {
      }
    }
  }

  public static void main(String[] args) {
    // double[] c = {-166.66877268681014, 191.98707244019567, -643.8604231249392, 584.3870360999675, -686.1778002948417 };
    // double[] d = {1.0078078252995386, -0.24292879232889897, -1.3306299239214636, 0.015695075291898397 };
    // Poly c0 = new Poly(c);
    // Poly d0 = new Poly(d);
    // c0.gcd(d0).print();
    solve();
  }
}