import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> mTito = new HashMap<String, Integer>();
        Map<String, Integer> mWiwid = new HashMap<String, Integer>();

        for (String s : tito) {
            if (mTito.containsKey(s)) {
                mTito.put(s, mTito.get(s) + 1);
            } else {
                mTito.put(s, 1);
            }
        }

        for (String s : wiwid) {
            if (mWiwid.containsKey(s)) {
                mWiwid.put(s, mWiwid.get(s) + 1);
            } else {
                mWiwid.put(s, 1);
            }
        }

        for (Map.Entry<String, Integer> e : mWiwid.entrySet()) {
            if (mTito.containsKey(e.getKey())) {
                System.out.println(e.getKey());
            }
        }
    }
}