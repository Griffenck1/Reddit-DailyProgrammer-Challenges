import java.util.Scanner;

public class largestDigit {
    public static void main(String args[]) {
        int choice = -1;
        while(choice != 2) {
            System.out.println("===Main Menu===");
            System.out.println("1.Run program");
            System.out.println("2.Quit");
            Scanner choiceScanner = new Scanner(System.in);
            choice = Integer.parseInt(choiceScanner.nextLine());

            if(choice == 1) {
                System.out.println("Enter a number with 4 or fewer digits:");
                Scanner input = new Scanner(System.in);

                StringBuilder number =  new StringBuilder();
                number.append(input.nextLine());

                int largestDigit = -1;

                if(number.length() >= 2) {
                    while(number.length() < 4)
                    {
                        number.append("0");
                    }

                    for (int i = 0; i < number.length(); i++) {
                        String digit = number.substring(i, i + 1);
                        int currentDigit = Integer.parseInt(digit);
                        if (currentDigit > largestDigit) {
                            largestDigit = currentDigit;
                        }
                    }

                    System.out.print("largest_digit(");
                    System.out.print(number);
                    System.out.print(") -> ");
                    System.out.println(largestDigit);
                }
                else {
                    System.out.println("Please enter a number with at least 2 different digits");
                }
            }
            else if(choice != 2)
            {
                System.out.println("Please Enter a valid choice");
            }
        }
        System.out.println("Goodbye!");
    }
}
