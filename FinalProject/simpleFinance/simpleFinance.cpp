#include "simpleFinance.h"

Finance::Finance()
{
    amountInBank = 0;
}

Finance::~Finance()
{
    if (myFinanceFile.open())
        myFinanceFile.close();
}

bool Finance::openFinanceFile(QString &Filename)
{
    myFinanceFile(Filename);
    if (!myFinanceFile.open(QFile::ReadWrite | QFile::Text))
    {
        qDebug() << "Error: Cannot Open File!";
        return false;
    }

    myFile.clear();

    QTextStream in(&myFinanceFile);
    myFile = in.readAll();

    if (myFile.isEmpty())
        return false;

    qDebug() << "File Loaded.";

    createLists();
    myFinanceFile.close();
    return true;
}

void Finance::createLists()
{
    // Read the file and input amount in bank, expenses,
    // income, goals
    QStringList splitFile;
    splitFile = myFile.split(QRegExp("\\n"), QString::SkipEmptyParts);
    qDebug << splitFile;
    for(int i = 0; i < splitFile.size(); i++)
    {
        if (splitFile.at(i).contains("Owner: "))
        {
            QStringList owner = splitFile.at(i).split(QRegExp("\<Owner: \>"), QString::SkipEmptyParts);
            qDebug << owner;
            // owner
        }
        else if (splitFile.at(i).contains("Amount In Bank: "))
        {
            QStringList amount = splitFile.at(i).split(QRegExp("\<Amount In Bank: \>"), QString::SkipEmptyParts);
            qDebug << amount;
            // amount
        }
        else if (splitFile.at(i).contains("Expense: "))
        {
            QStringList expense = splitFile.at(i).split(QRegExp("\<Expense: \>"), QString::SkipEmptyParts);
            qDebug << expense;
            // split expense into description, amount, date of expense
            // add expense to list
        }
        else if (splitFile.at(i).contains("Income: "))
        {
            QStringList income = splitFile.at(i).split(QRegExp("\<Income: \>"), QString::SkipEmptyParts);
            qDebug << income;
            // split income into description, amount, date of income
            // add income to list
        }
        else if (splitFile.at(i).contains("Goal: "))
        {
            QStringList goal = splitFile.at(i).split(QRegExp("\<Goal: \>"), QString::SkipEmptyParts);
            qDebug << goal;
            // split goal into description, amount, date of goal, amount saved
            // add goal to list
        }
    }
}

bool Finance::addExpense(QString desc, int amount, QString date)
{
    cashflow* nExpense = new cashflow;
    if (nExpense == NULL)
        return false;

    nExpense->amount = amount;
    nExpense->dateEntered = date;
    nExpense->description = desc;

    expenseList.append(nExpense);

    return true;
}

bool Finance::removeExpense(QString desc)
{
    for (int i = 0; i < expenseList.size(); i++)
    {
        if (expenseList.at(i)->description == desc)
        {
            expenseList.removeAt(i);
            return true;
        }
    }
    return false;
}

bool Finance::addIncome(QString desc, int amount, QString date)
{
    cashflow* nIncome = new cashflow;
    if (nIncome == NULL)
        return false;

    nIncome->amount= amount;
    nIncome->description = desc;
    nIncome->dateEntered = date;

    incomeList.append(nIncome);
    return true;
}

bool Finance::removeIncome(QString desc)
{
    for (int i = 0; i < incomeList.size(); i++)
    {
        if (incomeList.at(i)->description == desc)
        {
            incomeList.removeAt(i);
            return true;
        }
    }
    return false;
}

bool Finance::addGoal(QString desc, int amountToSave, int amountSaved, QDate endDate)
{
    goal* nGoal = new goal;
    if (nGoal == NULL)
        return false;

    nGoal->description = desc;
    nGoal->amountToGoal = amountToSave;
    nGoal->amountSaved = amountSaved;
    nGoal->endDate = endDate;

    goalList.append(nGoal);
    return true;
}

bool Finance::removeGoal(QString desc)
{
    for (int i = 0; i < goalList.size(); i++)
    {
        if(goalList.at(i)->description == desc)
        {
            goalList.removeAt(i);
            return true;
        }
    }
    return false;
}

bool Finance::modifyGoalAmount(QString desc, int amountCurrentlySaved)
{
    for (int i = 0; i < goalList.size(); i++)
    {
        if(goalList.at(i)->description == desc)
        {
            goalList.at(i)->amountSaved = amountCurrentlySaved;
            return true;
        }
    }
    return false;
}

bool Finance::modifyGoalDate(QString desc, QString newEnd)
{
    for (int i = 0; i < goalList.size(); i++)
    {
        if(goalList.at(i)->description = desc)
        {
            goalList.at(i)->endDate = newEnd;
            return true;
        }
    }
    return false;
}

void Finance::showGoals()
{
    for (int i = 0; i < goalList.size(); i++)
    {
        std::cout << "Goal " << i << ":" << std::endl;
        std::cout << "Description: " << goalList.at(i)->description.toStdString() << std::endl;
        std::cout << "Amount Currently Saved: $" << goalList.at(i)->amountSaved << std::endl;
        std::cout << "Goal Amount: $" << goalList.at(i)->amountToGoal << std::endl;
        std::cout << "End Date: " << goalList.at(i)->endDate.toStdString() << std::endl;
    }
}

void Finance::showExpenses()
{
    for (int i = 0; i < expenseList.size(); i++)
    {
        std::cout << "Expense " << i << ":" << std::endl;
        std::cout << "Description: " << expenseList.at(i)->description.toStdString() << std::endl;
        std::cout << "Amount: $" << expenseList.at(i)->amount << std::endl;
        std::cout << "Date of Expense: " << expenseList.at(i)->dateEntered << std::endl;
    }
}

void Finance::showIncomes()
{
    for (int i = 0; i < incomeList.size(); i++)
    {
        std::cout << "Expense " << i << ":" << std::endl;
        std::cout << "Description: " << incomeList.at(i)->description.toStdString() << std::endl;
        std::cout << "Amount: $" << incomeList.at(i)->amount << std::endl;
        std::cout << "Date of Income: " << incomeList.at(i)->dateEntered << std::endl;
    }
}


