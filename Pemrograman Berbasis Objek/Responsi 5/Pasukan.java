import java.util.*;

class Pasukan {
    private List<Integer> list;
    private int n;

    public Pasukan (List<Integer> list, int n) {
        this.list = list;
        this.n = n;
    }

    public void reset () {
        this.list.clear();
        for (int i = 0; i < this.n; i++) {
            this.list.add(0);
        }
    }

    public long get (int idx) {
        reset();
        long start = Util.getTime();
        Integer val = this.list.get(idx);
        long finish = Util.getTime();
        return finish - start;
    }

    public long del (int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i = 0; i < t; i++) {
            this.list.remove(idx);
        }
        long finish = Util.getTime();
        return finish - start;
    }
}
