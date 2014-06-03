#include "socket.h"

CSocket::CSocket()
{
    m_bConnected = false;
    m_bSelected = false;
    m_hHandle = 0;
    memset(m_szLastErr, '\0', sizeof(m_szLastErr));
    time(&m_tBeginTime);
}

CSocket::~Csocket()
{
    try
    {
        int nRet = Close();
        if (0 != nRet)
        {
        }
    }
    catch(...)
    {

    }
}

void CSocket::SetSocket(int nSocketId)
{
    m_hHandle = nSocketId;
    m_bConnected = true;
}

SOCKET CSocket::GetHandle() const
{
    return m_hHandle;
}

bool CSocket::IsOpen() const
{
    return m_hHandle != 0;
}

const SOCKADDR_IN& CSocket::GetAddr() const
{
    return m_sin;
}

bool CSocket::IsSelected() const
{
    return m_bSelected;
}

bool CSocket::IsClosed() const

{
    return !m_bConnected;
}

bool CSocket::IsConnected() const
{
    return m_bConnected;
}

const char* CSocket::GetLastErrMsg() const
{
    return m_szLastErr;
}

int CSocket::IsTimeOut(int nOutTime, int nFlag)
{
    int nStat = 0;
    time_t nowtim;

    time(&nowtim);
    if ((nowtim - m_tBeginTime >= nOutTime) && nFlag == 0)
    {
        nStat = 1;
    }

    if (nFlag > 0)
    {
        m_tBeginTime = nowtim;
    }

    return nStat;
}

void CSocket::initaddr(int nSockPort, const char* pszSockAddr)
{
    memset(&m_sin, 0, sizeof(struct sockaddr_in);
    
}
