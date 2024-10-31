using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab06
{
    internal class task3
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter The String to Reverse: ");
            string arr = Console.ReadLine();
            char[] str = arr.ToCharArray();
            Array.Reverse(str);
            string pew = new string(str);
            Console.WriteLine("The Reversed String is " + pew);
        }
    }
}
