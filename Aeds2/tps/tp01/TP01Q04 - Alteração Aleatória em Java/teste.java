import java.util.Random;

public class teste {
    public static void main(String[] args) {
        Random gerador = new Random();
        gerador.setSeed(3);
        int x =  0;
        x = ('a' + (Math.abs(gerador.nextInt()) % 26));
        System.out.println((char)x);

    }
}
