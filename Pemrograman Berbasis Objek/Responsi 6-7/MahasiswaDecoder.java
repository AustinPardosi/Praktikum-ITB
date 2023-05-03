import java.lang.reflect.*;
import java.util.List;

public class MahasiswaDecoder {
    private Mahasiswa target;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.target = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method addMatkul = this.target.getClass().getDeclaredMethod("addMatkul", String.class);
        addMatkul.setAccessible(true);
        addMatkul.invoke(target, name);
    }

    public int getNIM() throws Exception {
        Field NIM = this.target.getClass().getDeclaredField("NIM");
        NIM.setAccessible(true);
        return NIM.getInt(this.target);
    }

    public double getIPK() throws Exception {
        Field IPK = this.target.getClass().getDeclaredField("IPK");
        IPK.setAccessible(true);
        return IPK.getDouble(this.target);
    }

}

