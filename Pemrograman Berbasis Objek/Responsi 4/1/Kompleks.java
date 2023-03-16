public class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    public Kompleks() {
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int _real, int _imaginer) {
        this.real = _real;
        this.imaginer = _imaginer;
        n_kompleks++;
    }

    public int getReal() {
        return this.real;
    }

    public int getImaginer(){
        return this.imaginer;        
    }

    public void setReal(int _real) {
        this.real = _real;
    }

    public void setImaginer(int _imaginer) {
        this.imaginer = _imaginer;
    }

    public Kompleks plus (Kompleks other) {
        int re = this.real + other.real;
        int im = this.imaginer + other.imaginer;
        return new Kompleks(re, im);
    }

    public Kompleks minus (Kompleks other) {
        int re = this.real - other.real;
        int im = this.imaginer - other.imaginer;
        return new Kompleks(re, im);
    }

    public Kompleks multiply (Kompleks other) {
        int re = (this.real * other.real) - (this.imaginer * other.imaginer);
        int im = (this.imaginer * other.real) + (this.real * other.imaginer);
        return new Kompleks(re, im);
    }

    public Kompleks multiply (int x) {
        int re = this.real * x;
        int im = this.imaginer * x;
        return new Kompleks(re, im);
    }

    public static int countKompleksInstance() {
        return n_kompleks;
    }

    public void print() {
        if (this.real != 0 || this.imaginer == 0) {
            System.out.print(this.real);
        } if (this.real != 0 && this.imaginer > 0) {
            System.out.print("+");
        } if (this.imaginer != 0) {
            if (this.imaginer == 1) {
                System.out.println("i");
            } else if (this.imaginer == -1) {
                System.out.println("-i");
            } else {
                System.out.println(this.imaginer + "i");
            }
        } else {
            System.out.println();
        }
    }
}