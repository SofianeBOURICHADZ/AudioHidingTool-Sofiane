#ifndef WINDOW_H
#define WINDOW_H

#include<QtWidgets/QMainWindow>
#include<QtWidgets/QLineEdit>
#include<QtWidgets/QTextEdit>
#include<QtWidgets/QPushButton>
#include<QtWidgets/QLabel>

class Window: public QMainWindow {
    Q_OBJECT
public:
        explicit Window(QWidget *parent = nullptr);
        bool selectIntialFile();
private slots:
    void handleEncrypt();
    void handleDecrypt();
    void changeFile();

private:
    QString m_currentFilePath;
    QLabel *m_fileLabel;
    QLineEdit *m_pwdInput;
    QLineEdit *m_keyInput;
    QLineEdit *m_codeInput;
    QTextEdit *m_textArea;

    QPushButton *m_btnEncrypt;
    QPushButton *m_btnDecrypt;
    QPushButton *m_btnChangeFile;

};

#endif //  WINDOW_H