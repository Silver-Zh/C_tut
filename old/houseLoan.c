#include <stdio.h>
#include <math.h>

int main()
{
    float price, area, yir, mir;
    float interest, loan;
    float ave_repay, down_payment;
    float total_price, total_repay;
    int ratio, time;

    printf("请输入单价 元/平方:");
    scanf("%f", &price);
    printf("请输入面积：");
    scanf("%f", &area);
    printf("请输入按揭成数：");
    scanf("%d", &ratio);
    printf("请输入按揭年数：");
    scanf("%d", &time);
    printf("请输入当前基准年利率：");
    scanf("%f", &yir);

    mir = yir / 100 / 12;
    time = time * 12;
    total_price = price * area;
    down_payment = total_price * (1 - ratio / 10.0);
    loan = total_price * (ratio / 10.0);
    ave_repay = loan * mir * pow((1 + mir), time) / (pow((1 + mir), time) - 1);
    interest = ave_repay * time - loan;
    total_repay = loan + interest;

    printf("报告结果\n");
    printf("房款总额：%.2f元\n", total_price);
    printf("首期付款：%.2f元\n", down_payment);
    printf("贷款总额：%.2f元\n", loan);
    printf("还款总额：%.2f元\n", total_repay);
    printf("支付利息：%.2f元\n", interest);
    printf("月均还款：%.2f元\n", ave_repay);

    return 0;
}