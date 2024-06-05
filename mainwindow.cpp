#### `mainwindow.cpp`

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , student("John Doe", 1) // Example student
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addSubjectButton_clicked() {
    QString subjectName = ui->subjectNameLineEdit->text();
    int marks = ui->marksLineEdit->text().toInt();

    student.addSubject(subjectName.toStdString(), marks);

    ui->subjectsListWidget->addItem(subjectName + ": " + QString::number(marks));

    ui->subjectNameLineEdit->clear();
    ui->marksLineEdit->clear();
}

void MainWindow::on_calculateButton_clicked() {
    int totalMarks = student.getTotalMarks();
    double averageMarks = student.getAverageMarks();

    ui->totalMarksLabel->setText("Total Marks: " + QString::number(totalMarks));
    ui->averageMarksLabel->setText("Average Marks: " + QString::number(averageMarks));
}
```
