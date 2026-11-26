using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int choice;

        do
        {
            Console.WriteLine("\n--- МОДУЛЬ 2. МАСИВИ ТА РЯДКИ ---");
            Console.WriteLine("1. Одновимірний і двовимірний масиви");
            Console.WriteLine("2. Сума елементів між мінімумом і максимумом");
            Console.WriteLine("3. Шифр Цезаря");
            Console.WriteLine("4. Операції над матрицями");
            Console.WriteLine("5. Обчислення виразу (+ і -)");
            Console.WriteLine("6. Велика літера на початку речень");
            Console.WriteLine("7. Перевірка тексту на неприпустимі слова");
            Console.WriteLine("0. Вихід");
            Console.Write("Ваш вибір: ");

            if (!int.TryParse(Console.ReadLine(), out choice))
            {
                Console.WriteLine("Помилка введення.");
                continue;
            }

            switch (choice)
            {
                case 1: Task1(); break;
                case 2: Task2(); break;
                case 3: Task3(); break;
                case 4: Task4(); break;
                case 5: Task5(); break;
                case 6: Task6(); break;
                case 7: Task7(); break;
                case 0: Console.WriteLine("Завершення програми."); break;
                default: Console.WriteLine("Неправильний пункт меню."); break;
            }
        } while (choice != 0);
    }

    static void Task1()
    {
        int[] A = new int[5];
        double[,] B = new double[3, 4];
        Random random = new Random();

        Console.WriteLine("Введіть 5 цілих чисел для масиву A:");
        for (int i = 0; i < A.Length; i++)
        {
            Console.Write("A[" + i + "] = ");
            A[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 4; j++)
                B[i, j] = Math.Round(random.NextDouble() * 20 - 10, 2);

        Console.WriteLine("Масив A:");
        for (int i = 0; i < A.Length; i++)
            Console.Write(A[i] + " ");
        Console.WriteLine();

        Console.WriteLine("Масив B:");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
                Console.Write(B[i, j] + "\t");
            Console.WriteLine();
        }

        double min = A[0];
        double max = A[0];
        double sum = 0;
        double product = 1;
        int evenSum = 0;
        double oddColumnsSum = 0;

        for (int i = 0; i < A.Length; i++)
        {
            if (A[i] < min) min = A[i];
            if (A[i] > max) max = A[i];
            sum += A[i];
            product *= A[i];
            if (A[i] % 2 == 0) evenSum += A[i];
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (B[i, j] < min) min = B[i, j];
                if (B[i, j] > max) max = B[i, j];
                sum += B[i, j];
                product *= B[i, j];
                if (j % 2 == 0) oddColumnsSum += B[i, j];
            }
        }

        Console.WriteLine("Максимальний елемент: " + max);
        Console.WriteLine("Мінімальний елемент: " + min);
        Console.WriteLine("Загальна сума: " + sum);
        Console.WriteLine("Загальний добуток: " + product);
        Console.WriteLine("Сума парних елементів A: " + evenSum);
        Console.WriteLine("Сума непарних стовпців B: " + oddColumnsSum);
    }

    static void Task2()
    {
        int[,] array = new int[5, 5];
        int[] numbers = new int[25];
        Random random = new Random();

        Console.WriteLine("Масив:");
        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                array[i, j] = random.Next(-100, 101);
                numbers[i * 5 + j] = array[i, j];
                Console.Write(array[i, j] + "\t");

                if (numbers[i * 5 + j] < numbers[minIndex]) minIndex = i * 5 + j;
                if (numbers[i * 5 + j] > numbers[maxIndex]) maxIndex = i * 5 + j;
            }
            Console.WriteLine();
        }

        int start = Math.Min(minIndex, maxIndex);
        int end = Math.Max(minIndex, maxIndex);
        int sum = 0;

        for (int i = start + 1; i < end; i++)
            sum += numbers[i];

        Console.WriteLine("Сума елементів між мінімальним і максимальним: " + sum);
    }

    static string Caesar(string text, int shift)
    {
        string english = "abcdefghijklmnopqrstuvwxyz";
        string ukrainian = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
        char[] result = text.ToCharArray();

        for (int i = 0; i < result.Length; i++)
        {
            string alphabet = char.IsUpper(result[i]) ? english.ToUpper() : english;
            int index = alphabet.IndexOf(result[i]);

            if (index >= 0)
            {
                result[i] = alphabet[(index + shift + alphabet.Length) % alphabet.Length];
                continue;
            }

            alphabet = char.IsUpper(result[i]) ? ukrainian.ToUpper() : ukrainian;
            index = alphabet.IndexOf(result[i]);

            if (index >= 0)
                result[i] = alphabet[(index + shift + alphabet.Length) % alphabet.Length];
        }

        return new string(result);
    }

    static void Task3()
    {
        Console.Write("Введіть текст: ");
        string text = Console.ReadLine();

        Console.Write("Введіть зсув: ");
        if (!int.TryParse(Console.ReadLine(), out int shift))
        {
            Console.WriteLine("Помилка введення.");
            return;
        }

        string encrypted = Caesar(text, shift);
        Console.WriteLine("Зашифрований текст: " + encrypted);
        Console.WriteLine("Розшифрований текст: " + Caesar(encrypted, -shift));
    }

    static double[,] ReadMatrix(int rows, int columns)
    {
        double[,] matrix = new double[rows, columns];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
            {
                Console.Write("Елемент [" + i + "," + j + "]: ");
                matrix[i, j] = double.Parse(Console.ReadLine());
            }

        return matrix;
    }

    static void PrintMatrix(double[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
                Console.Write(matrix[i, j] + "\t");
            Console.WriteLine();
        }
    }

    static void Task4()
    {
        Console.WriteLine("1. Множення матриці на число");
        Console.WriteLine("2. Додавання матриць");
        Console.WriteLine("3. Добуток матриць");
        Console.Write("Ваш вибір: ");

        if (!int.TryParse(Console.ReadLine(), out int choice) || choice < 1 || choice > 3)
        {
            Console.WriteLine("Неправильний вибір.");
            return;
        }

        if (choice == 1)
        {
            Console.Write("Кількість рядків: ");
            int rows = int.Parse(Console.ReadLine());
            Console.Write("Кількість стовпців: ");
            int columns = int.Parse(Console.ReadLine());
            double[,] a = ReadMatrix(rows, columns);

            Console.Write("Введіть число: ");
            double number = double.Parse(Console.ReadLine());

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < columns; j++)
                    a[i, j] *= number;

            PrintMatrix(a);
        }
        else
        {
            Console.Write("Рядки першої матриці: ");
            int r1 = int.Parse(Console.ReadLine());
            Console.Write("Стовпці першої матриці: ");
            int c1 = int.Parse(Console.ReadLine());
            double[,] a = ReadMatrix(r1, c1);

            Console.Write("Рядки другої матриці: ");
            int r2 = int.Parse(Console.ReadLine());
            Console.Write("Стовпці другої матриці: ");
            int c2 = int.Parse(Console.ReadLine());
            double[,] b = ReadMatrix(r2, c2);

            if (choice == 2)
            {
                if (r1 != r2 || c1 != c2)
                {
                    Console.WriteLine("Матриці повинні мати однаковий розмір.");
                    return;
                }

                double[,] result = new double[r1, c1];
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c1; j++)
                        result[i, j] = a[i, j] + b[i, j];

                PrintMatrix(result);
            }
            else
            {
                if (c1 != r2)
                {
                    Console.WriteLine("Кількість стовпців першої матриці має дорівнювати кількості рядків другої.");
                    return;
                }

                double[,] result = new double[r1, c2];
                for (int i = 0; i < r1; i++)
                    for (int j = 0; j < c2; j++)
                        for (int k = 0; k < c1; k++)
                            result[i, j] += a[i, k] * b[k, j];

                PrintMatrix(result);
            }
        }
    }

    static void Task5()
    {
        Console.Write("Введіть вираз (+ і -): ");
        string expression = Console.ReadLine().Replace(" ", "");
        string[] parts = expression.Split(new char[] { '+', '-' }, StringSplitOptions.RemoveEmptyEntries);

        if (parts.Length == 0)
        {
            Console.WriteLine("Неправильний вираз.");
            return;
        }

        try
        {
            int position = 0;
            double result = double.Parse(parts[0]);
            int index = expression.IndexOf(parts[0]) + parts[0].Length;

            while (index < expression.Length)
            {
                char operation = expression[index];
                index++;

                while (index < expression.Length && expression[index] == ' ')
                    index++;

                string number = "";
                while (index < expression.Length && (char.IsDigit(expression[index]) || expression[index] == '.'))
                {
                    number += expression[index];
                    index++;
                }

                double value = double.Parse(number);
                if (operation == '+') result += value;
                else if (operation == '-') result -= value;
            }

            Console.WriteLine("Результат: " + result);
        }
        catch
        {
            Console.WriteLine("Неправильний вираз.");
        }
    }

    static void Task6()
    {
        Console.Write("Введіть текст: ");
        string text = Console.ReadLine();
        char[] chars = text.ToCharArray();
        bool newSentence = true;

        for (int i = 0; i < chars.Length; i++)
        {
            if (newSentence && char.IsLetter(chars[i]))
            {
                chars[i] = char.ToUpper(chars[i]);
                newSentence = false;
            }

            if (chars[i] == '.' || chars[i] == '!' || chars[i] == '?')
                newSentence = true;
        }

        Console.WriteLine(new string(chars));
    }

    static void Task7()
    {
        Console.Write("Введіть текст: ");
        string text = Console.ReadLine();

        Console.Write("Введіть неприпустиме слово: ");
        string badWord = Console.ReadLine();

        if (string.IsNullOrWhiteSpace(badWord))
        {
            Console.WriteLine("Слово не може бути порожнім.");
            return;
        }

        int count = 0;
        string[] words = text.Split(' ');

        for (int i = 0; i < words.Length; i++)
        {
            string cleanWord = words[i].Trim(',', '.', '!', '?', ':', ';', '"', '\'', '(', ')');

            if (cleanWord.Equals(badWord, StringComparison.OrdinalIgnoreCase))
            {
                int start = words[i].IndexOf(cleanWord, StringComparison.OrdinalIgnoreCase);
                words[i] = words[i].Substring(0, start) + new string('*', cleanWord.Length) +
                           words[i].Substring(start + cleanWord.Length);
                count++;
            }
        }

        Console.WriteLine("Результат:");
        Console.WriteLine(string.Join(" ", words));
        Console.WriteLine("Кількість замін: " + count);
    }
}
