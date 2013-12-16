import java.io.*;
public class reverseString {
    public static void main(String args[] ) throws Exception {
    	String reversedString = "";
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String inputString = reader.readLine();
        
        for (int i = 0; i < inputString.length(); i++){
        	reversedString = reversedString + inputString.charAt((inputString.length()-1)-i);
        	
        }
        System.out.println(reversedString);
    }
}