/**
 * Elang.java
 * [Jelaskan kegunaan class ini]
 * @author [13521084] [Austin Gabriel Pardosi]
 */

public class Elang extends Animal {
    // Attribut
    private int basePower;
    private int jumlahTelur;

    // Constructor
    public Elang(int _basePower) {
        this.numberOfLegs = 2;
        this.jumlahTelur = 0;
        this.basePower = _basePower;
        this.children = 0;
    }

    // Method
    public int getJumlahTelur() {
        return this.jumlahTelur;
    }

    public void bertelur() {
        this.jumlahTelur++;
    }

    public int getAnimalPower() {
        return this.basePower * this.children - this.jumlahTelur;
    }
}