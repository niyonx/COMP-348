public class Math101Main {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        Math101.Callback<Integer> obj = (result) -> System.out.println("The result of " + a + "/" + b + " is " + result);

        int c = 3;
        int d = 0;
        Math101.Callback<String> obj2 = (message) -> System.out.println("Error occured: " + message);

        Math101.Divide(a, b, obj, obj2);
        Math101.Divide(c, d, obj, obj2);
    }
}
