/**
 * Gajah.java
 * [Jelaskan kegunaan class ini]
 * @author [13521084] [Austin Gabriel Pardosi]
 */

public class Gajah extends Animal {
    // Attribut
    private int basePower;
    private int age;

    // Constructor
    public Gajah(int _basePower, int _age) {
        this.numberOfLegs = 4;
        this.basePower = _basePower;
        this.age = _age;
        this.children = 0;
    }

    // Method
    public int getAge() {
        return this.age;
    }

    public int getAnimalPower() {
        return 3 * (this.basePower + this.age + this.children);
    }
}