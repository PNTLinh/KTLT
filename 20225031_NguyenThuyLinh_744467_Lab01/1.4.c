//Nguyễn Thùy Linh_20225031
//Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng
//trả về số lượng số chẵn trong mảng
int counteven(int* arr, int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0) count++;// nếu là số chẵn thì tăng biến count
    }
    return count;
}
