using System;
using System.Globalization;

class Program
{
    static void Main()
    {
        int choice;

        do
        {
            Console.WriteLine("\n--- МОДУЛЬ 1. C# ---");
            Console.WriteLine("1. Fizz Buzz");
            Console.WriteLine("2. Відсоток від числа");
            Console.WriteLine("3. Створення числа з чотирьох цифр");
            Console.WriteLine("4. Обмін цифр шестизначного числа");
            Console.WriteLine("5. Сезон і день тижня");
            Console.WriteLine("6. Переведення температури");
            Console.WriteLine("7. Парні числа в діапазоні");
            Console.WriteLine("0. Вихід");
            Console.Write("Ваш вибір: ");

            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Помилка введення.");
                continue;
            }

            switch (choice)
            {
                case 1:
                    Task1();
                    break;
                case 2:
                    Task2();
                    break;
                case 3:
                    Task3();
                    break;
                case 4:
                    Task4();
                    break;
                case 5:
                    Task5();
                    break;
                case 6:
                    Task6();
                    break;
                case 7:
                    Task7();
                    break;
                case 0:
                    Console.WriteLine("Завершення програми.");
                    break;
                default:
                    Console.WriteLine("Неправильний пункт меню.");
                    break;
            }
        } while (choice != 0);
    }

    static void Task1()
    {
        Console.Write("Введіть число від 1 до 100: ");
        if (!int.TryParse(Console.ReadLine(), out int number) || number < 1 || number > 100)
        {
            Console.WriteLine("Помилка: число має бути від 1 до 100.");
        }
        else if (number % 3 == 0 && number % 5 == 0)
        {
            Console.WriteLine("Fizz Buzz");
        }
        else if (number % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (number % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
        {
            Console.WriteLine(number);
        }
    }

    static void Task2()
    {
        Console.Write("Введіть число: ");
        if (!double.TryParse(Console.ReadLine(), out double number))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        Console.Write("Введіть відсоток: ");
        if (!double.TryParse(Console.ReadLine(), out double percent))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        Console.WriteLine("Результат: " + (number * percent / 100));
    }

    static void Task3()
    {
        Console.Write("Введіть першу цифру: ");
        if (!int.TryParse(Console.ReadLine(), out int a) || a < 0 || a > 9)
        {
            Console.WriteLine("Потрібно ввести одну цифру.");
            return;
        }

        Console.Write("Введіть другу цифру: ");
        if (!int.TryParse(Console.ReadLine(), out int b) || b < 0 || b > 9)
        {
            Console.WriteLine("Потрібно ввести одну цифру.");
            return;
        }

        Console.Write("Введіть третю цифру: ");
        if (!int.TryParse(Console.ReadLine(), out int c) || c < 0 || c > 9)
        {
            Console.WriteLine("Потрібно ввести одну цифру.");
            return;
        }

        Console.Write("Введіть четверту цифру: ");
        if (!int.TryParse(Console.ReadLine(), out int d) || d < 0 || d > 9)
        {
            Console.WriteLine("Потрібно ввести одну цифру.");
            return;
        }

        Console.WriteLine("Число: " + (a * 1000 + b * 100 + c * 10 + d));
    }

    static void Task4()
    {
        Console.Write("Введіть шестизначне число: ");
        string number = Console.ReadLine();

        if (number.Length != 6 || !long.TryParse(number, out _))
        {
            Console.WriteLine("Помилка: потрібно ввести шестизначне число.");
            return;
        }

        Console.Write("Введіть перший номер розряду (1-6): ");
        if (!int.TryParse(Console.ReadLine(), out int first) || first < 1 || first > 6)
        {
            Console.WriteLine("Неправильний номер розряду.");
            return;
        }

        Console.Write("Введіть другий номер розряду (1-6): ");
        if (!int.TryParse(Console.ReadLine(), out int second) || second < 1 || second > 6)
        {
            Console.WriteLine("Неправильний номер розряду.");
            return;
        }

        char[] digits = number.ToCharArray();
        char temp = digits[first - 1];
        digits[first - 1] = digits[second - 1];
        digits[second - 1] = temp;

        Console.WriteLine("Результат: " + new string(digits));
    }

    static void Task5()
    {
        Console.Write("Введіть дату у форматі дд.мм.рррр: ");
        string input = Console.ReadLine();

        if (!DateTime.TryParseExact(input, "dd.MM.yyyy", CultureInfo.InvariantCulture,
            DateTimeStyles.None, out DateTime date))
        {
            Console.WriteLine("Неправильна дата.");
            return;
        }

        string season;
        if (date.Month == 12 || date.Month == 1 || date.Month == 2)
            season = "Winter";
        else if (date.Month >= 3 && date.Month <= 5)
            season = "Spring";
        else if (date.Month >= 6 && date.Month <= 8)
            season = "Summer";
        else
            season = "Autumn";

        Console.WriteLine(season + " " + date.DayOfWeek);
    }

    static void Task6()
    {
        Console.WriteLine("1. Фаренгейт у Цельсій");
        Console.WriteLine("2. Цельсій у Фаренгейт");
        Console.Write("Ваш вибір: ");

        if (!int.TryParse(Console.ReadLine(), out int choice) || (choice != 1 && choice != 2))
        {
            Console.WriteLine("Неправильний вибір.");
            return;
        }

        Console.Write("Введіть температуру: ");
        if (!double.TryParse(Console.ReadLine(), out double temperature))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        if (choice == 1)
            Console.WriteLine("Температура: " + ((temperature - 32) * 5 / 9) + " °C");
        else
            Console.WriteLine("Температура: " + (temperature * 9 / 5 + 32) + " °F");
    }

    static void Task7()
    {
        Console.Write("Введіть перше число: ");
        if (!int.TryParse(Console.ReadLine(), out int first))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        Console.Write("Введіть друге число: ");
        if (!int.TryParse(Console.ReadLine(), out int second))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        if (first > second)
        {
            int temp = first;
            first = second;
            second = temp;
        }

        Console.WriteLine("Парні числа в діапазоні:");
        for (int i = first; i <= second; i++)
        {
            if (i % 2 == 0)
                Console.Write(i + " ");
        }
        Console.WriteLine();
    }
}
