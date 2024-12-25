//Nguyễn Thùy Linh_20225031
//Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. 
//Nếu mảng rỗng hãy trả về NULL.
#include <cstddef>
double* maximum(double* a, int n) {
    double *max;
    max = a;
    if ( a == NULL) return NULL;// kiểm tra xem mảng có rỗng không
    for (int i = 0; i < n; i++){
        if (*(a+i)>*max) max=(a+i);// tìm phần tử lớn nhất bằng cách duyệt mảng
    }
    return max;
}