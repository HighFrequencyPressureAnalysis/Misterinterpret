#include "MessageBoxControler.h"


MessageBoxControler::MessageBoxControler()
{
}

MessageBoxControler::~MessageBoxControler()
{
}

void MessageBoxControler::showInformationMessageBox(const QString&content)
{
	QMessageBox::information(nullptr, "信息", content);
}

void MessageBoxControler::showWarningMessageBox(const QString&content)
{
	QMessageBox::warning(nullptr, "警告", content);
}

void MessageBoxControler::showCriticalMessageBox(const QString&content)
{
	QMessageBox::critical(nullptr, "错误", content);
}

bool MessageBoxControler::showQuestionMessageBox(const QString&content)
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(nullptr, "问题", content, QMessageBox::Yes | QMessageBox::No);
	bool isreply;
	if (reply == QMessageBox::Yes) {
		isreply = true;
	}
	else {
		isreply = false;
	}
	return isreply;
}

QString MessageBoxControler::showInputMessageBox(const QString&text1, const QString&text2)
{	
    QDialog dlg;
    dlg.setWindowTitle(text1); // 标题 100% 不乱码
    dlg.setFixedSize(350, 150);

    // 强制中文字体
    QFont font("Microsoft YaHei", 10);
    dlg.setFont(font);

    QVBoxLayout* layout = new QVBoxLayout(&dlg);
    QLineEdit* edit = new QLineEdit;
    edit->setFont(font);
    edit->setPlaceholderText(text2); // 提示文字 100% 不乱码

    QPushButton* btn = new QPushButton("确定");
    btn->setFont(font);

    layout->addWidget(edit);
    layout->addWidget(btn);

    // 点击确定关闭
    QObject::connect(btn, &QPushButton::clicked, &dlg, &QDialog::accept);

    if (dlg.exec() == QDialog::Accepted) {
        return edit->text(); // 返回输入内容
    }
    return "";
}

