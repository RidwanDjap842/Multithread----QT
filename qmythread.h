#ifndef QMYTHREAD_H
#define QMYTHREAD_H

#include <QThread>
#include <QDebug>
#include <atomic>

class QMyThread : public QThread
{
    Q_OBJECT

public:
    explicit QMyThread(QObject *parent = nullptr);

    void stop();
    void reset();

signals:
    void progressUpdated(int value);

protected:
    void run() override;

private:
    std::atomic_bool m_fStopped{false};
    std::atomic_bool m_reset{false};
    int m_progress = 0;
};

#endif
