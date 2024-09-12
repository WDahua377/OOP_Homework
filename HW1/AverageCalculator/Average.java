import java.io.*;
import java.text.NumberFormat;
import java.util.Scanner;

public class Average {
    public static void main(String args[]) {
        double average = 0;
        String input;
        int sum = 0, number = 0, flag = 0, score = 0;
        //number is the number of scores read
        //flag is used to record whether it is the first calculation
        Scanner sc = new Scanner(System.in);

        while(true){       //Program will keep calculating, unless the input is "-1"
        if(flag == 0){
            System.out.println("Please input the score : ");      //first time
        }
        else{
            System.out.println("Please input the score of next set : ");
        }

        input = sc.next();  //input the score

         if(input.equals("-1")){      //when input is "-1", calculate the average
            if(number == 0){    //if there is no input
                flag = 1;
                System.out.println("Average score is : 0.0");
            }
            else{
                average = (float)sum/number;
                System.out.println("Average score is : "+average);
                sum = 0;         // Initialize number and sum to 0 before starting.
                number = 0;
                flag = 1;       //and change the flag to 1 to indicate that it is not the first calculation after
            }
        }

        else{
            for(int i = 0; i < input.length();i++){     //check if input is legal
                    if( !Character.isDigit(input.charAt(i)) ){       //The isdigit() function checks whether a character is numeric character (0-9) or not.
                        System.out.println("illegal input, ending the program...");
                        System.exit(0);     //if it is not integer, which means that it is illegal, end program.
                        }
                    }
            try{    //try to get number out of string
                NumberFormat n = NumberFormat.getNumberInstance();
                score = n.parse(input).intValue(); 
                }catch(java.text.ParseException e) {
                  }
            if(score >= 0 && score <= 100){     //Then check is score is 0~100
                sum += score;      // Add new score into sum
                number++;
                }
            else{       //score > 100 or score < 0
                System.out.println("illegal input, ending the program...");
                System.exit(0);
                }
            }
        }
    }   // end main
}   // end of class Add

