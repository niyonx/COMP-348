public class Math101 {
    public static interface Callback<T> {
        void process(T notification);
    }

    public static void Divide(int a, int b,
                              Callback<Integer> onSuccess,
                              Callback<String> onError) {
        try {
            int result = a / b;
            onSuccess.process(result);
        } catch (Exception e) {
            onError.process(e.getMessage());
        }
    }
}