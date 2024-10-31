using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab06
{
    internal class Task02
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter The Number: ");
            int number  = Convert.ToInt32(Console.ReadLine());
            int orig = number;
            int revnum = 0;

            while (number > 0)
            {
                int remainder = number % 10;
                revnum = (revnum * 10) + remainder;
                number /= 10;
            }

            if (revnum == orig)
            {
                Console.WriteLine("The number is Palindrome");
            }
            else
            {
                Console.WriteLine("The number is not a Palindrome");
            }
        }
    }
}
