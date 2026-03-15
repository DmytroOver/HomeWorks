#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>

class QLabel;
class QVBoxLayout;
class QGridLayout;
class QPushButton;

class CalculatorWindow final : public QMainWindow
{
    Q_OBJECT
public:
    explicit CalculatorWindow(QWidget* parent = nullptr);
    ~CalculatorWindow();

private slots:
    void onButtonClicked();

private:
    double m_acc = 0.0;
    QString m_pendingOp; // "+", "-", "*", "/"
    bool m_waitingForNewNumber = true;
    bool m_error = false;

    QWidget* m_central = nullptr;
    QLabel* m_display = nullptr;
    QVBoxLayout* m_rootLayout = nullptr;
    QGridLayout* m_grid = nullptr;

    QPushButton* makeButton(const QString& label, const QString& name, const int shortcut = 0) const;
    double currentValue() const;
    void setDisplayNumber(double v);
    void clearAll();
    void applyPendingOperation(double rhs);
    void inputDigit(const QString& d);
    void inputDot();
    void inputOp(const QString& op);
    void inputEquals();
    void inputBackspace();
};


#endif // CALCULATORWINDOW_H
