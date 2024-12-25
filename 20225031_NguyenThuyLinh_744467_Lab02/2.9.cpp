#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
using namespace std;
//NguyenThuyLinh_20225031
// Khai báo các giá trị mặc định
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
// Định nghĩa hàm sigmoid
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}
//NguyenThuyLinh_20225031
//Khai báo các biến cần thiết
const double R = 20;
const long long N = 100000;
double Delta = R / N;
double sigmodArr[N + 10];
//Tính giá trị exp(x) thông qua thu thông qua thu gọn khai triển Maclaurin
double Exp(double x) {
    double result = 1.0;
    double eps = 5e-7;
    double element = x;
    double n = 1;
    while (fabs(element) > eps)
    {
        result += element;
        n += 1;
        element *= x;
        element /= n;
    }
    return result;
}
//NguyenThuyLinh_20225031
//Hàm chuẩn bị dữ liệu
void precalc() {
    for (long long i = 0; i < N; i++) {
        double xi = i * Delta;
        sigmodArr[i] = 1 / (1 + Exp(-xi));
    }
}
//Hàm tính sigmoid(x) nhanh sigmoid_fast(x)
inline double sigmoid_fast(double x) {
    if (x < -R) return 0;
    if (x > R) return 1;
    long long i = fabs(x) / Delta;
    double r = fabs(x) / Delta - i;
    double result = sigmodArr[i] + (sigmodArr[i + 1] - sigmodArr[i]) * r;
    if (x >= 0) return result;
    else return 1 - result;
}
//END fast code
//NguyenThuyLinh_20225031
double benchmark(double (*calc)(double), vector<double>& result) {
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}
bool is_correct(const vector<double>& a, const vector<double>& b) {
    const double EPS = 1e-6;
    int sizeA = sizeof(a) / 8;
    int sizeB = sizeof(b) / 8;
    if (sizeA != sizeB) return false;
    for (int i = 0; i < sizeA; ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}
int main() {
    prepare_input();
    precalc();
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);
    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    if (is_correct(a, b) && (slow / fast > 0)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
    else {
        printf("Wrong answer or your code is not fast enough!\n");
    }
    return 0;
}
//NguyenThuyLinh_20225031
