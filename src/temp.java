import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;

public class temp {
    static <T> void fromArrayToCollection(T[] a, Collection<T> c) {
        for (T o : a) {
            c.add(o); // Correct
        }
        System.out.println(c);

        c.addAll(Arrays.asList(a));
        System.out.println(c);
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");
        Object[] oa = new Object[3];
        System.out.println(oa[0]);
        Collection<Object> co = new ArrayList<Object>();
        fromArrayToCollection(oa, co);
        System.out.println(oa[0]);
    }
}