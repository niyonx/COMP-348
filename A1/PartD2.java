public class PartD2 {
    // part A using lambda expressions
    public static void main(String[] args) {
        Runnable obj = () -> {
            for (int i = 1; i <= 100; i++) {
                System.out.println(i);
            }
        };
        obj.run();
        System.out.println("THE END");
    }
}
