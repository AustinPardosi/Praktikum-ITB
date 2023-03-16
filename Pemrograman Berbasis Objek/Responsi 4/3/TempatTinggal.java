class TempatTinggal {
    protected int luas;
    protected double hargaBahanBangunan;

    public double hitungBiayaBangun() {
        return this.luas * this.hargaBahanBangunan;
    }

    public int getLuas() {
        return this.luas;
    }

    public double getHargaBahanBangunan() {
        return this.hargaBahanBangunan;
    }

    public void setLuas(int _luas) {
        this.luas = _luas;
    }

    public void setHargaBahanBangunan(double _hargaBahanBangunan) {
        this.hargaBahanBangunan = _hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal {
    public Rumah(int _luas, double _hargaBahanBangunan) {
        this.luas = _luas;
        this.hargaBahanBangunan = _hargaBahanBangunan;
    }

    public Rumah(int _lebar, int _panjang, double _hargaBahanBangunan) {
        this.luas = _lebar * _panjang;
        this.hargaBahanBangunan = _hargaBahanBangunan;
    }

    public double hitungBiayaBangun(double _biayaOrmas) {
        return this.luas * this.hargaBahanBangunan + _biayaOrmas;
    }

    public void setLuas(int _panjang, int _lebar) {
        this.luas = _panjang * _lebar;
    }
}

interface Kendaraan {
    public float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan {
    private float bensin;
    private float pemakaianBensin;

    public double hitungBiayaBangun() {
        return this.luas * this.hargaBahanBangunan * 3;
    }

    public float hitungJarakTempuh() {
        return bensin * pemakaianBensin;
    }

    public float getBensin() {
        return bensin;
    }

    public float getPemakaianBensin() {
        return pemakaianBensin;
    }

    public void setBensin(float _bensin) {
        this.bensin = _bensin;
    }

    public void setPemakaianBensin(float _pemakaianBensin) {
        this.pemakaianBensin = _pemakaianBensin;
    }
}