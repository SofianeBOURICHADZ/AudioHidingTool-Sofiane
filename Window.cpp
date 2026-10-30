#include "Window.h"
#include "Back.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtCore/QFileInfo>

Window::Window(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Encrypt files inside audio");
    resize(1024,1024);

    QWidget *centralWidget = new QWidget(this);
    QBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *fileRow = new QHBoxLayout();
    m_fileLabel = new QLabel("Loaded File: None", this);
    m_fileLabel->setStyleSheet("font-weight: bold; font-size: 13px;");
    m_btnChangeFile = new QPushButton("Load Different File", this);
    fileRow->addWidget(m_fileLabel);
    fileRow->addWidget(m_btnChangeFile);
    mainLayout->addLayout(fileRow);

    QFormLayout *formLayout = new QFormLayout();
    m_pwdInput = new QLineEdit(this);
    m_pwdInput->setPlaceholderText("Set or enter your file password...");
    m_pwdInput->setEchoMode(QLineEdit::Password);

    m_keyInput = new QLineEdit(this);
    m_keyInput->setPlaceholderText("Generated automatically on encrypt / ENter to decrypt");

    m_codeInput = new QLineEdit(this);
    m_codeInput->setPlaceholderText("Generated Numerical Code / Enter to decrypt");

    formLayout->addRow("1. Password (User):", m_pwdInput);
    formLayout->addRow("2. Key (Program Generated):", m_keyInput);
    formLayout->addRow("3. Code (Numerical):", m_codeInput);
    mainLayout->addLayout(formLayout);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    m_btnEncrypt = new QPushButton("Encrypt and hide message", this);
    m_btnDecrypt = new QPushButton("Decrypt Message", this);
    btnLayout->addWidget(m_btnEncrypt);
    btnLayout->addWidget(m_btnDecrypt);
    mainLayout->addLayout(btnLayout);

    m_textArea = new QTextEdit(this);
    m_textArea->setPlaceholderText("Type secret message to hide OR extracted result will display here...");
    mainLayout->addWidget(m_textArea);

    setCentralWidget(centralWidget);

    connect(m_btnChangeFile, &QPushButton::clicked, this, &Window::changeFile);
    connect(m_btnEncrypt, &QPushButton::clicked, this, &Window::handleEncrypt);
    connect(m_btnDecrypt, &QPushButton::clicked, this, &Window::handleDecrypt);
    
}

