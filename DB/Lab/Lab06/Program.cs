using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab06
{
    internal class Program
    {
        public static long Factorial(int n)
        {
            if (n == 0 || n == 1)
                return 1;
            return n * Factorial(n - 1);
        }

        public static bool IsPrime(int num)
        {
            if (num <= 1)
                return false;
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("\n--- Calculator Menu ---");
                Console.WriteLine("1. Addition");
                Console.WriteLine("2. Subtraction");
                Console.WriteLine("3. Multiplication");
                Console.WriteLine("4. Division");
                Console.WriteLine("5. Modular Division");
                Console.WriteLine("6. Prime Number Check");
                Console.WriteLine("7. Factorial (Recursive)");
                Console.WriteLine("8. Square Root");
                Console.WriteLine("9. Exit");
                Console.Write("Select an option: ");
                int option = Convert.ToInt32(Console.ReadLine());

                if (option == 9)
                    break;

                switch (option)
                {
                    case 1:
                        Console.Write("Enter first number: ");
                        int addNum1 = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter second number: ");
                        int addNum2 = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine($"Result: {addNum1 + addNum2}");
                        break;

                    case 2:
                        Console.Write("Enter first number: ");
                        int subNum1 = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter second number: ");
                        int subNum2 = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine($"Result: {subNum1 - subNum2}");
                        break;

                    case 3:
                        Console.Write("Enter first number: ");
                        int mulNum1 = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter second number: ");
                        int mulNum2 = Convert.ToInt32(Console.ReadLine());
                        Console.WriteLine($"Result: {mulNum1 * mulNum2}");
                        break;

                    case 4:
                        Console.Write("Enter numerator: ");
                        int divNum1 = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter denominator: ");
                        int divNum2 = Convert.ToInt32(Console.ReadLine());
                        if (divNum2 != 0)
                            Console.WriteLine($"Result: {divNum1 / divNum2}");
                        else
                            Console.WriteLine("Cannot divide by zero!");
                        break;

                    case 5:
                        Console.Write("Enter first number: ");
                        int modNum1 = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Enter second number: ");
                        int modNum2 = Convert.ToInt32(Console.ReadLine());
                        if (modNum2 != 0)
                            Console.WriteLine($"Result: {modNum1 % modNum2}");
                        else
                            Console.WriteLine("Cannot perform modulus by zero!");
                        break;

                    case 6:
                        Console.Write("Enter number to check for prime: ");
                        int primeNum = Convert.ToInt32(Console.ReadLine());
                        bool isPrime = IsPrime(primeNum);
                        if (isPrime)
                            Console.WriteLine($"{primeNum} is a prime number.");
                        else
                            Console.WriteLine($"{primeNum} is not a prime number.");
                        break;

                    case 7:
                        Console.Write("Enter number to find factorial: ");
                        int factNum = Convert.ToInt32(Console.ReadLine());
                        if (factNum >= 0)
                            Console.WriteLine($"Factorial of {factNum} is {Factorial(factNum)}.");
                        else
                            Console.WriteLine("Factorial is not defined for negative numbers.");
                        break;

                    case 8:
                        Console.Write("Enter number to find square root: ");
                        int sqrtNum = Convert.ToInt32(Console.ReadLine());
                        if (sqrtNum >= 0)
                            Console.WriteLine($"Square root of {sqrtNum} is {Math.Sqrt(sqrtNum)}.");
                        else
                            Console.WriteLine("Square root is not defined for negative numbers.");
                        break;

                    default:
                        Console.WriteLine("Invalid option! Please try again.");
                        break;
                }

            }
        }
    }
}
