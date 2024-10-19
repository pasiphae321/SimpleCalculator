#include "Handler.h"
#include <stdexcept>

// 构造函数实现
Handler::Handler(const QString & expression2) : expression2(expression2) {}

// 计算表达式的主函数
double Handler::calculate() {
    return evaluate(this->expression2);
}

// 判断字符是否为操作符
bool Handler::IsOperator(QChar char1) {
    return char1 == '+' || char1 == '-' || char1 == '*' || char1 == '/' || char1 == '(' || char1 == ')';
}

// 运算符优先级
int Handler::precedence(QChar operator1) {
    if (operator1 == '+' || operator1 == '-') {
        return 1;
    }
    else if (operator1 == '*' || operator1 == '/') {
        return 2;
    }
    return 0;
}

// 根据操作符进行相应运算
double Handler::ApplyOperator(double left, double right, QChar operator1) {
    if (operator1 == '+') {
        return left + right;
    }
    else if (operator1 == '-') {
        return left - right;
    }
    else if (operator1 == '*') {
        return left * right;
    }
    else if (operator1 == '/') {
        if (right == 0) {
            throw std::runtime_error("division by zero");
        }
        return left / right;
    }
    else {
        throw std::invalid_argument("invalid operator");
    }
}

// 中缀表达式求值
double Handler::evaluate(const QString & expression3) {
    QStack<double> values;  // 存储操作数的栈
    QStack<QChar> operators;      // 存储操作符的栈

    for (int i = 0; i < expression3.length(); i++) {
        if (expression3[i].isDigit()) {
            // 处理多位数或小数
            QString number1;
            while (i < expression3.length() && (expression3[i].isDigit() || expression3[i] == '.')) {
                number1 += expression3[i];
                i++;
            }
            values.push(number1.toDouble());
            i--;  // 回退一步，因为外层循环会自增
        } else if (expression3[i] == '(') {
            operators.push(expression3[i]);
        } else if (expression3[i] == ')') {
            // 处理括号内的表达式
            while (!operators.isEmpty() && operators.top() != '(') {
                double value2 = values.pop();
                double value1 = values.pop();
                QChar operator1 = operators.pop();
                values.push(ApplyOperator(value1, value2, operator1));
            }
            operators.pop(); // 弹出 '('
        } else if (IsOperator(expression3[i])) {
            // 处理操作符并进行优先级判断
            while (!operators.isEmpty() && precedence(operators.top()) >= precedence(expression3[i])) {
                double value2 = values.pop();
                double value1 = values.pop();
                QChar operator1 = operators.pop();
                values.push(ApplyOperator(value1, value2, operator1));
            }
            operators.push(expression3[i]);
        }
    }

    // 处理剩余的操作符
    while (!operators.isEmpty()) {
        double value2 = values.pop();
        double value1 = values.pop();
        QChar operator1 = operators.pop();
        values.push(ApplyOperator(value1, value2, operator1));
    }

    return values.top(); // 返回最终的计算结果
}
