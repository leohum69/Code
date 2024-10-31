using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab06
{
    internal class Task04
    {
        public static int CustomASCIIValue(char ch)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                return 26 - (ch - 'A');
            }
            return -1; 
        }

      
        public static bool IsSuperString(string input)
        {
        
            input = input.ToUpper();

            Dictionary<char, int> frequency = new Dictionary<char, int>();

       
            foreach (char ch in input)
            {
                if (ch >= 'A' && ch <= 'Z')
                {
                    if (frequency.ContainsKey(ch))
                        frequency[ch]++;
                    else
                        frequency[ch] = 1;
                }
            }

            
            foreach (var item in frequency)
            {
                char character = item.Key;
                int charFrequency = item.Value;
                int customValue = CustomASCIIValue(character);

                if (charFrequency != customValue)
                {
                    return false; 
                }
            }

            return true; 
        }

        static void Main(string[] args)
        {
            Console.Write("Enter a string: ");
            string input = Console.ReadLine();

            // Check if the input is a SUPER STRING
            if (IsSuperString(input))
            {
                Console.WriteLine("The string is a SUPER STRING.");
            }
            else
            {
                Console.WriteLine("The string is NOT a SUPER STRING.");
            }
        }
    }
}
