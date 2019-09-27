public class PartD {
    // Part A using Anonymous class
    public static void main(String[] args) {
        Runnable myRunnable =
                new Runnable() {
                    public void run() {
                        for (int i = 1; i <= 100; i++) {
                            System.out.println(i);
                        }
                    }
                };
        myRunnable.run();
        System.out.println("THE END");
    }
}
