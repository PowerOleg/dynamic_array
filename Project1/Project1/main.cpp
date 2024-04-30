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

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	unsigned int actual_size = 0;
	unsigned int logical_size = 0;
	printf("¬ведите фактичеcкий размер массива: ");
	std::cin >> actual_size;
	printf("¬ведите логический размер массива: ");
	std::cin >> logical_size;
	if (logical_size > actual_size)
	{
		printf("ќшибка! Ћогический размер массива не может превышать фактический!\nBye\n");
		return 1;
	}

	int* arr = new int[actual_size];
	for (int i = 0; i < logical_size; i++)
	{
		printf("¬ведите arr[%d]: ", i);
		std::cin >> arr[i];
	}
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;
	return 0;
}