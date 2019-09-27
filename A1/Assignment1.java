public class Assignment1 {
    public static void main(String[] args) {
        Interface1 obj1 = () -> 5.5;

        Interface2 obj2 = (a) -> String.format("The number is %d", a);

        Interface3 obj3 = (int i, String s) -> i == Integer.parseInt(s);

        obj1.showMessage();
        obj2.showMessage(2);
        obj3.showMessage(4, "4");
    }
}