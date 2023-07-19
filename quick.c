#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) {int temp; temp = a; a = b; b = temp;}

int median_of_three(int *data, int left, int right)
{
	int center = (left + right) / 2;

	if (data[left] <= data[center])
	{
		if (data[center] <= data[right])
			return center;
		else if (data[right] <= data[left])
			return left;
	}
	else if (data[center] <= data[left])
	{
		if (data[left] <= data[right])
			return left;
		else if (data[right] <= data[center])
			return center;
	}

	return right;
}

void quick_sort_sub(int *data, int left, int right)
{
	int	left_index;
	int	right_index;
	int	pivot;

	left_index = left;
	right_index = right;
	pivot = data[median_of_three(data, left_index, right_index)];
	// printf("%d, ", median_of_three(data, left_index, right_index));
	while (left_index <= right_index)
	{
		while (data[left_index] < pivot)
			left_index++;
		while (pivot < data[right_index])
			right_index--;
		if (left_index <= right_index)
		{
			SWAP(data[left_index], data[right_index]);
			left_index++;
			right_index--;
		}
	}
	if (right_index > left)
		quick_sort_sub(data, left, right_index);
	if (left_index < right)
		quick_sort_sub(data, left_index, right);
}

void		quick_sort(int *data, int data_size)
{
	quick_sort_sub(data, 0, data_size - 1);
}

// int main()
// {
//     int data[] = {9, 4, 2, 7, 5, 1, 8, 3, 6, 11, 10, 13, 12};
//     int data_size = sizeof(data) / sizeof(data[0]);

//     quick_sort(data, data_size);

//     for (int i = 0; i < data_size; i++)
//     {
//         printf("%d ", data[i]);
//     }
//     printf("\n");

//     return 0;
// }

#define DATA_SIZE 10000

void generate_data(int *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = size - i;  // 降順にデータを生成
    }
}

void print_data(int *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[DATA_SIZE];

    // データ生成
    generate_data(data, DATA_SIZE);

    // printf("Before sorting:\n");
    // print_data(data, DATA_SIZE);

    // クイックソート
    quick_sort(data, DATA_SIZE);

    printf("\nAfter sorting:\n");
    print_data(data, DATA_SIZE);

    return 0;
}