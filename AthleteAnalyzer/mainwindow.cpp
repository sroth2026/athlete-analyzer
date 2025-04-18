#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"
#include "core/golf_analyzer.hpp"
#include "QString"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_analyzeButton_clicked() {
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Open Golf CSV",
        "",
        "CSV Files (*.csv)"
    );

    if (filePath.isEmpty()) {
        QMessageBox::information(this, "Info", "No file selected.");
        return;
    }


    GolfAnalyzer analyzer;
    bool loaded = analyzer.loadCSV(filePath.toStdString());

    if (!loaded) {
        QMessageBox::critical(this, "Error", "Failed to load CSV.");
        return;
    }

    ui->carryLabel->setText("Carry Distance: " + QString::number(analyzer.averageCarry()) + " yds");
    ui->clubSpeedLabel->setText("Club Speed: " + QString::number(analyzer.averageSpeed()) + " mph");
    ui->launchAngleLabel->setText("Launch Angle Std Dev: " + QString::number(analyzer.launchConsistency(), 'f', 2) + "°");

}
