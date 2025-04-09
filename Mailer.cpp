#include <iostream>
#include <string>

using namespace std;
class ILogger {
public:
    virtual void Log(const string& logText) = 0;
    virtual ~ILogger() = default;
};

class FileLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Logging to file: " << logText << endl;
    }
};

class DatabaseLogger : public ILogger {
public:
    void Log(const string& logText) override {
        cout << "Logging to database: " << logText << endl;
    }
};

class SmtpMailer {
private:
    ILogger* logger;

public:
    SmtpMailer(ILogger* logger) : logger(logger) {}

    void SendMessage(const string& message) {
        cout << "Sending message: " << message << endl;
        logger->Log("Message sent: " + message);
    }
};

int main() {
    FileLogger fileLogger;
    DatabaseLogger dbLogger;

    SmtpMailer mailer1(&fileLogger);
    mailer1.SendMessage("Hello, World!");

    SmtpMailer mailer2(&dbLogger);
    mailer2.SendMessage("Goodbye, World!");

    return 0;
}
