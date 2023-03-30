public class DaftarBelanja {
    // Attribut
    private Barang[] listBelanja;
    private int totalBelanja;
    private int max;

    // Constructor
    public DaftarBelanja(int max) {
        this.listBelanja = new Barang[max];
        this.totalBelanja = 0;
        this.max = max;
    }

    // Method
    public void belanja(int lorong, String keterangan) {
        if (this.totalBelanja < this.max) {
            String _nama = keterangan + " (lorong " + lorong + ")";
            this.listBelanja[this.totalBelanja] = new Barang(_nama, 1);
            this.totalBelanja += 1;
        }
    }

    public void belanja(int lorong, int qty, String keterangan) {
        if (this.totalBelanja < this.max) {
            String _nama = keterangan + " (lorong " + lorong + ")";
            this.listBelanja[this.totalBelanja] = new Barang(_nama, qty);
            this.totalBelanja += 1;
        }
    }

    public void belanja(String barang) {
        if (this.totalBelanja < this.max) {
            this.listBelanja[this.totalBelanja] = new Barang(barang, 1);
            this.totalBelanja += 1;
        }
    }

    public void belanja(String barang, int qty) {
        if (this.totalBelanja < this.max) {
            this.listBelanja[this.totalBelanja] = new Barang(barang, qty);
            this.totalBelanja += 1;
        }
    }

    public void print() {
        for(int i=0; i<this.totalBelanja; i++) {
            System.out.print(i+1);
            System.out.println(". " + this.listBelanja[i].toString());
        }
    }
}