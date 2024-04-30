#include <iostream>
#include <string>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int i = 0; i < logical_size; i++)
	{
		printf(std::to_string(arr[i]).c_str());
		printf(" ");
	}
	for (int i = logical_size; i < actual_size; i++)
	{
		printf("_");
		printf(" ");
	}
}

void append_to_dynamic_array(int* arr, unsigned int* logical_size, unsigned int actual_size, int value)
{
	if (*logical_size < actual_size)
	{
		arr[*logical_size] = value;
		(*logical_size)++;
	}
	else
	{

	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	unsigned int actual_size = 0;
	printf("Введите фактичеcкий размер массива: ");
	std::cin >> actual_size;
	unsigned int logical_size = 0;
	printf("Введите логический размер массива: ");
	std::cin >> logical_size;
	if (logical_size > actual_size)
	{
		printf("Ошибка! Логический размер массива не может превышать фактический!\nBye\n");
		return 1;
	}

	int* arr = new int[actual_size];
	for (int i = 0; i < logical_size; i++)
	{
		printf("Введите arr[%d]: ", i);
		std::cin >> arr[i];
	}
	printf("Динамический массив: ");
	print_dynamic_array(arr, logical_size, actual_size);
	int value_add = -1;
	while (true)
	{
		printf("\nВведите элемент для добавления: ");
		std::cin >> value_add;
		if (value_add == 0)
		{
			break;
		}
		append_to_dynamic_array(arr, &logical_size, actual_size, value_add);
		printf("Динамический массив: ");
		print_dynamic_array(arr, logical_size, actual_size);
	}
	
	printf("Спасибо! Ваш массив: ");
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;
	return 0;
}