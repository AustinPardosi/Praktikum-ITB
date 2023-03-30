/**
 * Animal.java
 * [Jelaskan kegunaan class ini]
 * @author [13521084] [Austin Gabriel Pardosi]
 */

public abstract class Animal implements Comparable<Animal>{
    // Attribut
    protected int numberOfLegs;
    protected int children;

    // Method
    public int getNumberOfLegs() {
        return this.numberOfLegs;
    }

    public int getNumberOfChildren() {
        return this.children;
    }

    public void increaseChild(int inc) {
        this.children += inc;
    }

    abstract int getAnimalPower();

    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    public int compareTo(Animal other) {
        if (this.getAnimalPower() == other.getAnimalPower()) {
            return 0;
        } else if (this.getAnimalPower() > other.getAnimalPower()) {
            return 1;
        } else {
            return -1;
        }
    }
}