import java.util.*;

public class occurence_5386{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        // Prompt the user to enter the number of elements
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt(); 

        // Create an array to store the numbers
        int[] numbers = new int[n];

        // Read the numbers from the user
        System.out.println("Enter " + n + " numbers:");
        for (int i = 0; i < n; i++) {
            numbers[i] = sc.nextInt(); 
        }

        // Create a HashMap to store the occurrences
        HashMap<Integer, Integer> occurrences = new HashMap<>();

        // Count occurrences of each number
        for (int i = 0; i < numbers.length; i++) {
            int num = numbers[i]; // Get the number at index i
            occurrences.put(num, occurrences.getOrDefault(num, 0) + 1); // Update the count
        }

        // Display the occurrences
        System.out.println("The number of their occurrences are:");
        for (Map.Entry<Integer, Integer> entry : occurrences.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }


        // Close the scanner
        sc.close(); 
    }

}