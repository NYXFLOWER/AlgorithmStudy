package sort;

public class QuitSort {
    static <T extends Comparable<T>> void sort(T[] array, int start, int end) {

        int idx = partition(array, start, end);
        if (end - start <= 1) return;

        if (idx - start > 1) sort(array, start, idx-1);    // sort the left part
        if (idx != end) sort(array, idx, end);      // sort the right part
    }

    private static <T extends Comparable<T>> int partition(T[] array, int start, int end) {
        T value = array[end];
        T tmp;

        for (; start < end; start++) {
            if (array[start].compareTo(value) > 0) {
                while (array[end].compareTo(value) > 0) end--;
                if (start > end) break;
                tmp = array[start];
                array[start] = array[end];
                array[end] = tmp;
            }
        }

        return start;
    }

    public static void main(String[] args) {
        Integer[] array = {8, 6, 7};

        for (int i : array) {
            System.out.print(i + " ");
        }

        QuitSort.sort(array, 0, array.length-1);

        System.out.println();
        for (int i : array) {
            System.out.print(i + " ");
        }
    }
}

