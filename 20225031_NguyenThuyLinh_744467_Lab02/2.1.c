//NguyenThuyLinh_20225031
//Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
#include<stdio.h>
#include<math.h>
//viết hàm tình cạnh huyền
float get_hypotenuse(float a, float b){
    return sqrt(a*a + b*b);
}
int main(){
    float a, b; scanf("%f %f", &a, &b);
    float z = get_hypotenuse(a,b);
    printf("z = %.2f", z);// lấy sau dấu phẩy 2 số
    return 0;
}
//NguyenThuyLinh_20225031
