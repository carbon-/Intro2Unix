#ifndef SIMPLEFINANCE_H
#define SIMPLEFINANCE_H

#include <QFile>
#include <QDate>
#include <QTime>
#include <QString>
#include <QList>

struct goal
{
    QString description;
    int amountToGoal;
    int amountSaved;
    QDate endDate;
};


class Finance
{
public:
    Finance();
    ~Finance();

    openFinanceFile(/*Open File*/);
    addExpense(QString desc, int amount);
    addIncome(QString desc, int amount);
    addGoal(QString desc, int amount, QDate endDate);
    removeGoal(QString desc);
    modifyGoal(int amountCurrentlySaved);

private:
    int amountInBank;
    QFile myFinanceFile;
    QList<goal> GoalList;
};

#endif // SIMPLEFINANCE_H
