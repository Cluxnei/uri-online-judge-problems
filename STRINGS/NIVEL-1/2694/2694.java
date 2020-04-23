import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int cases = scanner.nextInt();
        for(int i = 0; i < cases; i++) {
            int sum = 0;
            ArrayList<Character> numeros = new ArrayList<Character>();
            String line = scanner.next() + "a";
            for (char c : line.toCharArray()) {
                if (Character.isDigit(c)) {
                    numeros.add(c);
                } else if(!numeros.isEmpty()){
                    String numero = "";
                    for (char t : numeros) {
                        numero += String.valueOf(t);
                    }
                    sum += Integer.parseInt(numero);
                    numeros.clear();
                }
            }
            System.out.println(sum);
        }
    }
}
