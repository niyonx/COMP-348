public class PartA implements Runnable {
    //  Implements the Runnable interface and prints numbers
    //  from 1 to 100.
    public void run() {
        for (int i = 1; i <= 100; i++) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        PartA obj = new PartA();
        obj.run();
        System.out.println("THE END");
    }
}
