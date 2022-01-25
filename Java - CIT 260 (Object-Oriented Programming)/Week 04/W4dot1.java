package Week04;

import java.util.Scanner;

public class W4dot1 {

    public static void main(String[] args) {
        // Introduce program to the user
        System.out.println("This program converts a hexadecimal digit into a four digit binary number.");

        // Get their hexadecimal number and convert it
        int userNumber;
        String hexInput = "";
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a hexadecimal number: ");
        try {
            hexInput = input.next();

            // Ensure we only received one digit
            if (hexInput.length() > 1)
                throw new Exception();

            userNumber = Integer.parseInt(hexInput, 16);
        }
        catch (Exception e) {
            System.out.format("%n%s is not a valid hexadecimal digit.%nGoodbye.", hexInput);
            return;
        }

        // Pad and display the binary value
        String binaryOutput = String.format("%4s", Integer.toBinaryString(userNumber)).replace(" ", "0");
        System.out.format("%nThe binary value is %s.%nGoodbye.", binaryOutput);
    }
}
