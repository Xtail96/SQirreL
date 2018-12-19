#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_hightlighter(new SqlSyntaxHighlighter(this))
{
    ui->setupUi(this);

    auto toolbar = ui->mainToolBar;
    toolbar->addAction(ui->actionTemplates);

    ui->templatesDockWidget->hide();

    // установка оформления statusBar
    ui->statusBar->setStyleSheet("background-color: #333; color: #33bb33");
    ui->statusBar->setFont(QFont("Consolas", 14));
    ui->statusBar->showMessage(tr("State: ready 0123456789"));

    m_hightlighter->setDocument(ui->requestTextEdit->document());
    m_hightlighter->setPattern();

    //Router& router = Router::getInstance();
    //ui->label->setText(router.getRepository()->helloString());

    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTemplates_triggered()
{
    if(ui->templatesDockWidget->isVisible())
    {
        ui->templatesDockWidget->hide();
    }
    else
    {
        ui->templatesDockWidget->show();
    }
}

void MainWindow::on_runToolButton_clicked()
{
    ui->responseTableWidget->clear();
    ui->responseTableWidget->setColumnCount(0);
    ui->responseTableWidget->setRowCount(0);

    Router& router = Router::getInstance();
    QString request = ui->requestTextEdit->toPlainText();
    QList<QSqlRecord> response = router.executeSQL(request);

    if(response.isEmpty())
    {
        return;
    }

    ui->responseTableWidget->setRowCount(response.length());
    QSqlRecord firstRecord = response.first();
    ui->responseTableWidget->setColumnCount(firstRecord.count());
    for(int columnIndex = 0; columnIndex < firstRecord.count(); columnIndex++)
    {
        ui->responseTableWidget->setHorizontalHeaderItem(columnIndex, new QTableWidgetItem(firstRecord.fieldName(columnIndex)));
    }


    int currentRow = 0;
    for(auto record : response)
    {
        for(int columnIndex = 0; columnIndex < record.count(); columnIndex++)
        {
            ui->responseTableWidget->setItem(currentRow, columnIndex, new QTableWidgetItem(record.value(columnIndex).toString()));
        }
        currentRow++;
    }


    ui->dbLineEdit->setText(router.getRepository()->getDBPath());

    //SELECT * FROM Hen
}

void MainWindow::on_clearToolButton_clicked()
{
    ui->requestTextEdit->clear();
}

void MainWindow::on_openLocalDatabaseToolButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Выберите файл базы данных", "", "*.db");
    Router& router = Router::getInstance();
    router.setDatabase(path, Repository::DB_TYPE::SQLite);
    ui->dbLineEdit->setText(router.getRepository()->getDBPath());
}
