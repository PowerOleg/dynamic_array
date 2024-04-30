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
	if (logical_size == 0 && arr[0] == '_')
	{
		
	}
}

void remove_dynamic_array_head(int *&arr, unsigned int* logical_size, unsigned int* actual_size)
{
	double actual_double = static_cast<double>(*actual_size) / 3.0;
	if ((*logical_size) - 1 > actual_double)
	{
		for (int i = 0, j = 1; i < (*logical_size) - 1; i++, j++)
		{
			arr[i] = arr[j];
		}
		arr[(*logical_size) - 1] = 0;
		(*logical_size)--;
	}
	else
	{
		int new_size = static_cast<int>(actual_double);
		if (new_size == 0)
		{
			(*logical_size) = 0;
			return;
		}
		else
		{
			int* new_arr = new int[new_size];
			for (int i = 0, j = 1; i < (*logical_size) - 1; i++, j++)
			{
				new_arr[i] = arr[j];									//��� ����� ������
			}
			(*logical_size)--;
			(*actual_size) = new_size;
			delete[] arr;
			arr = new_arr;
		}
		
	}

}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	unsigned int actual_size = 0;
	printf("������� �������c��� ������ �������: ");
	std::cin >> actual_size;
	unsigned int logical_size = 0;
	printf("������� ���������� ������ �������: ");
	std::cin >> logical_size;
	if (logical_size > actual_size)
	{
		printf("������! ���������� ������ ������� �� ����� ��������� �����������!\nBye\n");
		return 1;
	}

	int* arr = new int[actual_size];
	for (int i = 0; i < logical_size; i++)
	{
		printf("������� arr[%d]: ", i);
		std::cin >> arr[i];
	}
	printf("������������ ������: ");
	print_dynamic_array(arr, logical_size, actual_size);
	std::string is_delete = "���";
	while (true)
	{
		printf("\n������� ������ �������? ");
		std::cin >> is_delete;
		if (is_delete.length() == 3)
		{
			break;
		} 
		else if (is_delete.length() == 2)
		{
			if (logical_size == 0)
			{
				printf("���������� ������� ������ �������, ��� ��� ������ ������. �� ��������!");
				return 2;
			}
			remove_dynamic_array_head(arr, &logical_size, &actual_size);
			printf("������������ ������: ");
			print_dynamic_array(arr, logical_size, actual_size);
		}
		else
		{
			printf("\n�������� �� ��� ���");
		}
	}

	printf("�������! ��� ������: ");
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;
	return 0;
}