#include <iostream>
#include <iomanip>

/* Количество элементов массива:
* диапазон значений от 0 до 99 включительно
*/
#define SIZE 100

// «Хеш-функция», основанная на делении
int hf_modulo(std::string inString)
{
	/* unsigned -- для исключения отрицательного значения,
	*  например: ввод кирилицы
	*/
	unsigned int mod = 0;

	for (size_t i = 0; i < inString.length(); ++i)
	{
		mod += inString[i];
	}

	mod %= SIZE;
	return mod;
}

int main()
{
	// Консоль: Выравнивание по левому краю
	std::cout << std::setiosflags(std::ios::left);

	// Переменная вводимой информации
	std::string cInput;

	for (int8_t i = 0; i < 5; i++)
	{
		// Ввод
		std::cin >> cInput;

		// Вывод с шириной поля
		std::cout << std::setw(4) << hf_modulo(cInput);
		std::cout << "-- hf_modulo()";
		std::cout << std::endl;
	}

	return 0;
}