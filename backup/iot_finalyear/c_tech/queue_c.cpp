#include<iostream>
#include<QTextStream>
int main()
{
    QTextStream out(stdout);
    QString s = "like";
    s.append("chess");
    s.prepend("I");
    out<<s;
    return 0;
}
