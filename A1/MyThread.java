public class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 100; i++) {
            System.out.println(i);
        }
    }
}

//MyThread p = new MyThread();
//p.start(); // starts a new thread and executes the run() method