#ifndef SIMPLEFINANCE_H
#define SIMPLEFINANCE_H

#include <QFile>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QList>
#include <iostream>

struct goal
{
    QString description;
    int amountToGoal;
    int amountSaved;
    QString endDate;
};

struct cashflow
{
    QString description;
    int amount;
    QString dateEntered;
};

class Finance
{
public:
    Finance();
    ~Finance();

    bool openFinanceFile(QString &Filename);
    bool addExpense(QString desc, int amount, QString date);
    bool removeExpense(QString desc);
    bool addIncome(QString desc, int amount, QString date);
    bool removeIncome(QString desc);
    bool addGoal(QString desc, int amountToSave, int amountSaved, QDate endDate);
    bool removeGoal(QString desc);
    bool modifyGoalAmount(QString desc, int amountCurrentlySaved);
    bool modifyGoalDate(QString desc, QString newEnd);
    void createLists();
    void showGoals();
    void showExpenses();
    void showIncomes();

private:
    int amountInBank;
    QFile myFinanceFile;
    QString myFile;
    QString fileOwner;
    QString lastModified;
    QList<goal*> goalList;
    QList<cashflow*> incomeList;
    QList<cashflow*> expenseList;
};

#endif // SIMPLEFINANCE_H
