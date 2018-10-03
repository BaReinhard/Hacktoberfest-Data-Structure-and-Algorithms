using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BinarySearch
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numArray = new int[100];
            bool isNum = false;
            int sizeNum;

            Console.WriteLine("Enter the limit of array:");
            string sizeString = Console.ReadLine();
            isNum = Int32.TryParse(sizeString, out sizeNum);

            if (isNum)
            {

                Console.WriteLine("Enter array values (numeric only) in ascending order. ");

                for (int i = 0; i < sizeNum; i++)
                {

                    int tempValue;
                    string arrayItem = Console.ReadLine();
                    isNum = Int32.TryParse(arrayItem, out tempValue);

                    if (isNum)
                    {

                        numArray[i] = tempValue;
                    }
                    else
                    {

                        Console.WriteLine("You enters a non-numeric value!");
                        break;
                    }
                }

                Console.WriteLine("Enter search value (numeric only).");
                int searchNum;
                string searchString = Console.ReadLine();
                isNum = Int32.TryParse(searchString, out searchNum);

                if (isNum)
                {

                    int lowNum = 0;
                    int highNum = sizeNum - 1;

                    while (lowNum <= highNum)
                    {
                        int midNum = (lowNum + highNum) / 2;
                        if (searchNum < numArray[midNum])
                        {

                            highNum = midNum - 1;
                        }
                        else if (searchNum > numArray[midNum])
                        {
                            lowNum = midNum + 1;
                        }
                        else if (searchNum == numArray[midNum])
                        {

                            Console.WriteLine("Search successful");
                            Console.WriteLine("Value {0} found at location {1}\n", searchNum, midNum + 1);
                            Console.ReadLine();
                            return;
                        }
                    }

                    Console.WriteLine("Value {0} was not found \n", searchNum);
                    Console.ReadLine();
                    return;
                }
                else
                {

                    Console.WriteLine("Search value must be numeric!");
                    Console.ReadLine();
                    return;
                }
            }
            else
            {

                Console.WriteLine("You must enter a numeric value!");
                Console.ReadLine();
            }
            Console.ReadLine();
        }

    }
}
