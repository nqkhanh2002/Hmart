#include <iostream>
#include <fstream>
using namespace std;

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
int LeftOf( const int value, const node_t* root )
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
//    return value <= root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}

 
 
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
 
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}


int main()
{
	// đọc dữ liệu từ file
	ifstream FileIn;// khai báo ra lớp để đọc dữ liệu từ file
	FileIn.open("input.txt", ios_base::in);
	if (FileIn.fail() == true)
	{
		cout << "\nFile khong ton tai";
		system("pause");
		return 0; // kết thúc chương trình
	}
    // Tao cay tim kiem (BST)
    node_t* root = NULL;

	int arr[100];
	int i = 0;
	int dem = 0;
	// đọc mảng số nguyên từ file bằng cách kiểm tra nếu con trỏ chỉ vị chưa đến cuối file thì tiếp đọc
	while (!FileIn.eof()) // <=> !FileIn.eof(), FileIn.eof() == false
	{
		FileIn >> arr[i]; // đọc từng số nguyên có trong file
        root = Insert(root, arr[i]);
		i++;
		dem++;
	}
	
    printf("\nSap xep cay tang dan bang cach duyet cay theo thu tu giua (LNR) : ");
    InOrder(root);
 
	FileIn.close(); // đóng file
    free(root);
	return 0;
}