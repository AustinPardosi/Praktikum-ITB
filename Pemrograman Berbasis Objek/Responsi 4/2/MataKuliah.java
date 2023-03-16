import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    private float rating;

  public MataKuliah(String _nama, int _kodeJurusan, int _tahunPengambilan, float _rating) {
    this.nama = _nama;
    this.kodeJurusan = _kodeJurusan;
    this.tahunPengambilan = _tahunPengambilan;
    this.rating = _rating;
  }

  public String getNama() {
    return this.nama;
  }
  
  public int getKodeJurusan() {
    return this.kodeJurusan;
  }
  
  public int getTahunPengambilan() {
    return this.tahunPengambilan;
  }
  
  public float getRating() {
    return this.rating;
  }

  public int compareTo(MataKuliah m) {
    // compareTo mengembalikan:
    // 0 bila this sama dengan m
    // 1 bila this lebih dari m
    // -1 bila this kurang dari m
    if (this.rating == m.rating && this.kodeJurusan == m.kodeJurusan && this.tahunPengambilan == m.tahunPengambilan) {
      return 0;
    } else if ((this.kodeJurusan < m.kodeJurusan) || (this.kodeJurusan == m.kodeJurusan && this.tahunPengambilan < m.tahunPengambilan) || (this.kodeJurusan == m.kodeJurusan && this.tahunPengambilan == m.tahunPengambilan && this.rating < m.rating)) {
      return -1;
    } else {
      return 1;
    }
  }
}