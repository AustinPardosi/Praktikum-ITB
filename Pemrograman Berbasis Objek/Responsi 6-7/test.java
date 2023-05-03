public class test {
    public static void main(String[] args) {
        Mahasiswa austin = new Mahasiswa(13521084, 3.3);
        Mahasiswa gabriel = new Mahasiswa(16521084, 3.8);

        MahasiswaDecoder hacker = new MahasiswaDecoder(austin);
        try {
            System.out.println(hacker.getIPK());
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
