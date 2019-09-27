public class PartB {
    //    create a thread and execute in a separate thread.
    public static void main(String[] args) {
        MyThread p = new MyThread();
        new Thread(p).start();
        System.out.println("THE END");
    }
    // Now, THE END prints before 0 to 100
}
