import java.util.Scanner;

public class descendingOrder {
    public static void main(String args[]) {
        int choice = -1;
        while(choice != 2) {
            System.out.println("===Main Menu===");
            System.out.println("1.Run program");
            System.out.println("2.Quit");
            Scanner choiceScanner = new Scanner(System.in);
            choice = Integer.parseInt(choiceScanner.nextLine());

            if(choice == 1) {
                System.out.println("Enter a number with 2 to 4 digits:");
                Scanner input = new Scanner(System.in);

                StringBuilder number =  new StringBuilder();
                StringBuilder numberDescending;

                number.append(input.nextLine());

                if(number.length() >= 2) {
                    while(number.length() < 4)
                    {
                        number.append("0");
                    }

                    numberDescending = new StringBuilder(number);


                    boolean solved = false;

                    while(!solved) {
                        solved = true;
                        for(int i = 0; i < numberDescending.length() - 1; i++) {
                            if(Integer.parseInt(numberDescending.substring(i, i+1)) <
                                    Integer.parseInt(numberDescending.substring(i+1, i+2)))
                            {
                                solved = false;
                                char temp = numberDescending.charAt(i);
                                numberDescending.setCharAt(i, numberDescending.charAt(i+1));
                                numberDescending.setCharAt(i+1, temp);
                            }
                        }
                    }

                    System.out.print("desc_digits(");
                    System.out.print(number);
                    System.out.print(") -> ");
                    System.out.println(numberDescending);
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