#include <stdio.h>

void func_err() {
    // 실수는 필연적으로 오차가 존재한다.
    if (0.1 + 0.1 + 0.1 == 0.3)
        printf("true\n");
    else
        printf("false\n");
}

void func_put_double_to_longlong() {
    double a = 10000000000000001;
    double b = 10000000000000000;
    // double의 유효숫자 => 15
    // longlong의 유효숫자 => 19
    // 따라서 10^18 과 10^18 + 1을 구분할 수 없음.

    if (a == b)
        printf("error...\n");
    else
        printf("a != b\n");
}

void func_compare_real_number() {
    // 실수를 비교할때는 등호를 사용하면 안된다.
    // 오차범위내인지를 확인해야 한다.
    double a = 0.1 + 0.1 + 0.1;
    double b = 0.3;
    if (a == b) {
        printf("same??\n");
    }

    if (a - b <= 1e-12) {
        printf("same!!\n");
    }
}

int main()
{
    func_err();
    func_put_double_to_longlong();
    func_compare_real_number();

    return (0);
}