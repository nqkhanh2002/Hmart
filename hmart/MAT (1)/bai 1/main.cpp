// Header File
#include <iostream>
#include <fstream>
using namespace std;
// Thuật toán bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
    // i phần tử cuối cùng đã được sắp xếp
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                haveSwap = true; // Kiểm tra lần lặp này có swap không
            }
        }
        // Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
        if(haveSwap == false){
            break;
        }
    }
}
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    // Thao tác file
    ifstream FileIn;
    FileIn.open("input.txt", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\nFile khong ton tai";
		return 0; // kết thúc chương trình
	}

	int arr[100];
    int n;
    FileIn >> n; // đọc số nguyên dòng đầu tiên
	

	for (int i = 0; i < n; i++) {
        FileIn >> arr[i];
    }

	// Sap xep mang bang phuong phap bubble sort
	bubbleSort(arr, n);
	// Mang sau khi sap xep la
	cout << "Mang sau khi sap xep la : ";
	printArray(arr, n);
    // ghi dữ liệu lên file
	ofstream FileOut;
	FileOut.open("output.txt", ios_base::out);

    for (int i = 0; i < n; i++)
	{
	    FileOut << arr[i] << " ";
	}
    // đóng file
	FileIn.close(); 
    FileIn.close();
	return 0;
}