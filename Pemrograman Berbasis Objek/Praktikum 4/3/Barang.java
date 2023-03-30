public class Barang {
    // Attribut
    private String nama;
    private int amount;

    // Constructor
    public Barang(String _nama, int _amount) {
        this.nama = _nama;
        this.amount = _amount;
    }

    public String toString() {
        return this.amount + " " + this.nama;
    }
}