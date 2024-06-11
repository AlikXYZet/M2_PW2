#include <iostream>
#include <iomanip>



/* ---   Предварительное   --- */
/* Количество элементов массива:
* диапазон значений от 0 до 99 включительно
*/
#define SIZE 100

// Суммирование номеров элементов строки
int sum(std::string inString)
{
	int sum = 0;
	for (size_t i = 0; i < inString.length(); ++i)
		sum += inString[i];
	return sum;
}
// ---------------------------------------------------------------



/* ---   Хеш-функции   --- */
// «Хеш-функция», основанная на делении (модуле)
unsigned int hf_mod(std::string inString)
{
	/* unsigned -- для исключения отрицательного значения,
	*  например: ввод кирилицы
	*/
	unsigned int mod = sum(inString) % SIZE;
	return mod;
}

// «Хеш-функция», основанная на умножении
unsigned int hf_mul(std::string inString)
{
	/* unsigned -- для исключения отрицательного значения,
	*  например: ввод кирилицы
	*/
	unsigned int mul = fmod(sum(inString) * 0.618033, 1) * SIZE;
	return mul;
}
// ---------------------------------------------------------------



int main()
{
	// Консоль: Выравнивание по левому краю
	std::cout << std::setiosflags(std::ios::left);

	// Переменная вводимой информации
	std::string cInput;

	for (int8_t i = 0; i < 10; i++)
	{
		// Ввод
		std::cin >> cInput;

		// Вывод с фиксированной шириной поля
		std::cout << std::setw(3) << hf_mod(cInput) << "-- hf_mod();    ";
		std::cout << std::setw(3) << hf_mul(cInput) << "-- hf_mul()";
		std::cout << std::endl;
	}

	return 0;
}