public class Euclid {
  private static int findGcd(int a, int b) {
    if (a == 0 || b == 0)
      return 0;
    if (b > a)
      a = b;
    while (b != 0) {
      int r = a % b;
      a = b;
      b = r;
    }
    return a;
  }

  public static void main(String[] args) {
    assert(Euclid.findGcd(270, 192) == 6);
    assert(Euclid.findGcd(192, 270) == 6);
    assert(Euclid.findGcd(0,0) == 0);
    assert(Euclid.findGcd(0,6) == 0);
    assert(Euclid.findGcd(6,0) == 0);
  }
}