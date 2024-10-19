#ifndef HANDLER_H
#define HANDLER_H

#include <QString>
#include <QStack>

class Handler {
public:
    // 构造函数，接收输入的表达式
    Handler(const QString & expression2);

    // 计算表达式的值
    double calculate();

private:
    QString expression2;

    // 私有辅助函数，用于解析和计算表达式
    bool IsOperator(QChar char1);
    int precedence(QChar operaoter1);
    double ApplyOperator(double left, double right, QChar operator1);
    double evaluate(const QString & expression3);
};

#endif // HANDLER_H
