#ifndef JSONRPCENDPOINT_H
#define JSONRPCENDPOINT_H

namespace icinga
{

class I2_ICINGA_API JsonRpcEndpoint : public Endpoint
{
private:
	shared_ptr<SSL_CTX> m_SSLContext;
	string m_Address;
	JsonRpcClient::Ptr m_Client;
	map<string, Endpoint::Ptr> m_PendingCalls;
	Timer::Ptr m_ReconnectTimer;

	string m_PeerHostname;
	unsigned short m_PeerPort;

	int NewMessageHandler(const NewMessageEventArgs& nmea);
	int ClientClosedHandler(const EventArgs& ea);
	int ClientErrorHandler(const SocketErrorEventArgs& ea);
	int ClientReconnectHandler(const TimerEventArgs& ea);
	int VerifyCertificateHandler(const VerifyCertificateEventArgs& ea);

public:
	typedef shared_ptr<JsonRpcEndpoint> Ptr;
	typedef weak_ptr<JsonRpcEndpoint> WeakPtr;

	void Connect(string host, unsigned short port,
	    shared_ptr<SSL_CTX> sslContext);

	JsonRpcClient::Ptr GetClient(void);
	void SetClient(JsonRpcClient::Ptr client);

	void SetAddress(string address);
	virtual string GetAddress(void) const;

	virtual bool IsLocal(void) const;
	virtual bool IsConnected(void) const;

	virtual void ProcessRequest(Endpoint::Ptr sender, const JsonRpcRequest& message);
	virtual void ProcessResponse(Endpoint::Ptr sender, const JsonRpcResponse& message);

	virtual void Stop(void);
};

}

#endif /* JSONRPCENDPOINT_H */
