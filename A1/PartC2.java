public class PartC2 {
    // Part B using lambda expression
    public static void main(String[] args) {
        Thread t = new Thread(() -> {
            for (int i = 1; i <= 100; i++) {
                System.out.println(i);
            }
        });
        new Thread(t).start();
        System.out.println("THE END");
    }
}
