#ifndef __SOCKET_H__
#define __SOCKET_H__

class CSocket
{
    public:
        CSocket();
        ~CSocket();

        static void InitializeSock();

        static bool Select(CSocket* socks[], int nSocksCount, long waitMilliseconds = -1);

        static int GetHostAddr(char* addr, uint32_t nLen);
        
        static int GetHostAddr(struct in_addr*& addr, int& count);

        bool Create(int nSockPort = 0, const char* pszSockAddr = NULL, int nType = SOCK_STREAM, int nReuseFlag = 0);

        bool Bind(int nSockPort, const char* pszSockAddr = NULL);

        bool Listen(int nConnectionBacklog = 5);

        bool Connect(int nHostPort, const char* pszHostAddr = NULL, int tryTimes = -1);

        bool Reconnect();

        bool Accept(CSocket* rConnectedSock, SOCKADDR* pAddr = NULL, int* pAddrLen = NULL); 

        int Recv(void* lpBuf, int nBufLen, int nFlags = MSG_EXPECTED);

        int Send(const void* lpBuf, int nBufLen, int nFlags = 0);

        bool ShutDown();

        int Close();

        int Close(uint32_t nSeconds);

        bool SetBlockMode(bool blocking = true);

        void SetSocket(int nSocketId);

        SOCKET GetHandle() const;

        bool IsOpen() const;

        const SOCKADDR_IN& GetAddr() const;

        bool IsBlocking();

        bool DataArrival(long waitMilliseconds = -1);

        bool IsSelected() const;

        bool IsClosed() const;

        bool IsConnected() const;

        int IsTimeOut(int nOutTime, int nFlag);

        char* GetHostIp();

        const char* GetLastErrMsg() const;

    private:
        void initaddr(int nSockPort, const char* pszSockAddr = NULL);
        void SetErrMsg(const char* fmt, ...);

    private:
        SOCKET m_hHandle;
        SOCKADDR_IN m_sin;

        bool m_bConnected;
        bool m_bSelected;

        char m_szLastErr[1024];
        time_t m_tBeginTime;

    public:
        static bool m_bInitialized;
};


#endif
