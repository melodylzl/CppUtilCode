#include "math_utils.h"

/**
 * @brief 浮点数大小相等比较
 * @param a 
 * @param b 
 * @return int 0 : 相等, 1 : a > b, -1 a < b 
 */
int MathUtils::compare(double a,double b){
    double difference = a - b;
    if (fabs(difference) <= 1E-6){
        return 0;
    }else if (difference > 0){
        return 1;
    }else{
        return -1;
    }
}

/**
 * @brief 返回[a,b]之间的随机数
 * @param a 
 * @param b 
 * @return int 
 */
int MathUtils::random(int a, int b){
    srand(time(0));
    return (rand() % (b-a+1))+ a;
}