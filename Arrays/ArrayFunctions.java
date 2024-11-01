package Arrays;

import java.util.*;

public class ArrayFunctions {

    // Linear Search for a key in a String array.
    public static int linearSearch(String[] numbers, String key) {
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i].equals(key)) {
                return i;
            }
        }
        return -1;
    }

    // Finds the largest element in an integer array.
    public static int largest(int[] numbers) {
        int largest = Integer.MIN_VALUE;
        for (int num : numbers) {
            if (num > largest) {
                largest = num;
            }
        }
        return largest;
    }

    // Binary Search for a key in a sorted integer array.
    public static int binarySearch(int[] numbers, int key) {
        int start = 0, end = numbers.length - 1;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (numbers[mid] == key) {
                return mid;
            } else if (numbers[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    // Reverses an integer array in-place.
    public static void reverseArray(int[] numbers) {
        int first = 0, last = numbers.length - 1;
        while (first < last) {
            int temp = numbers[last];
            numbers[last] = numbers[first];
            numbers[first] = temp;

            first++;
            last--;
        }
    }

    // Prints all unique pairs of elements in an integer array.
    public static void printPairs(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i + 1; j < numbers.length; j++) {
                System.out.print("(" + numbers[i] + "," + numbers[j] + ")");
            }
            System.out.println();
        }
    }

    // Finds the maximum sum of subarrays using brute force approach.
    public static void subArrayMaxSum(int[] numbers) {
        int totalSubarrays = 0;
        int maxSum = Integer.MIN_VALUE;

        for (int i = 0; i < numbers.length; i++) {
            int start = i;
            for (int j = i; j < numbers.length; j++) {
                int end = j;
                int sum = 0;

                for (int k = start; k <= end; k++) {
                    System.out.print(numbers[k] + " ");
                    sum += numbers[k];
                }
                if (sum > maxSum) maxSum = sum;
                System.out.println("Sum: " + sum);
                totalSubarrays++;
            }
        }

        System.out.println("Total number of subarrays: " + totalSubarrays);
        System.out.println("Maximum subarray sum: " + maxSum);
    }

    // Calculates the maximum subarray sum using prefix sums.
    public static void prefixSumMax(int[] numbers) {
        int maxSum = Integer.MIN_VALUE;
        int[] prefix = new int[numbers.length];
        prefix[0] = numbers[0];

        // Calculate prefix array
        for (int i = 1; i < numbers.length; i++) {
            prefix[i] = prefix[i - 1] + numbers[i];
        }

        // Calculate max subarray sum using prefix sums
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i; j < numbers.length; j++) {
                int currSum = (i == 0) ? prefix[j] : prefix[j] - prefix[i - 1];
                maxSum = Math.max(maxSum, currSum);
            }
        }
        System.out.println("Maximum subarray sum (prefix method): " + maxSum);
    }

    // Finds the maximum sum of subarrays using Kadane's algorithm.
    public static void kadaneMaxSum(int[] numbers) {
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;

        for (int num : numbers) {
            currSum += num;
            if (currSum < 0) {
                currSum = 0;
            }
            maxSum = Math.max(maxSum, currSum);
        }
        System.out.println("Maximum subarray sum (Kadane's algorithm): " + maxSum);
    }

    public static void main(String[] args) {
        // Initialize Scanner for user input
        @SuppressWarnings({"unused", "resource"})
        Scanner sc = new Scanner(System.in);

        // Sample data
        int[] numbers = {-2, -3, 4, -1, 5, 4, -3, 8};
        String[] menu = {"Dosa", "Paratha", "Idli", "Sambar", "Vada", "Bondas"};
        int key = 102;

        // Call the functions as needed, uncomment the section below for specific functionality
        /*
        int index = binarySearch(numbers, key);
        System.out.println("Index of the number: " + (index == -1 ? "Not found" : index));

        int largest = largest(numbers);
        System.out.println("Largest number: " + largest);

        reverseArray(numbers);
        System.out.println("Reversed array: " + Arrays.toString(numbers));

        printPairs(numbers);
        
        subArrayMaxSum(numbers);

        prefixSumMax(numbers);

        kadaneMaxSum(numbers);
        */
    }
}
