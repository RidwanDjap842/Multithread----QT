#include "qmythread.h"

void QMyThread::run()
{
    qDebug() << "Thread started";

    m_fStopped = false;

    while (!m_fStopped)
    {
        if (m_reset)
        {
            m_progress = 0;
            m_reset = false;
            emit progressUpdated(m_progress);
        }

        if (m_progress < 100)
        {
            m_progress++;
            emit progressUpdated(m_progress);
        }

        QThread::msleep(100);
    }
}

QMyThread::QMyThread(QObject *parent)
    : QThread(parent)
{
    m_fStopped = false;
    m_reset = false;
    m_progress = 0;
}

void QMyThread::stop()
{
    m_fStopped = true;
}

void QMyThread::reset()
{
    m_progress = 0;
    emit progressUpdated(0);
}
