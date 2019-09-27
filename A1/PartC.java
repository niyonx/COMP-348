public class PartC {
    // Part B using an anonymous class.
    public static void main(String[] args) {
        Thread t = new Thread() {
            public void run() {
                for (int i = 1; i <= 100; i++) {
                    System.out.println(i);
                }
            }
        };
        new Thread(t).start();
        System.out.println("THE END");
    }
} 