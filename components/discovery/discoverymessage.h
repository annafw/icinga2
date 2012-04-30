#ifndef DISCOVERYMESSAGE_H
#define DISCOVERYMESSAGE_H

namespace icinga
{

class DiscoveryMessage : public Message
{

public:
	DiscoveryMessage(void) : Message() { }
	DiscoveryMessage(const Message& message) : Message(message) { }

	inline bool GetIdentity(string *value) const
	{
		return GetPropertyString("identity", value);
	}

	inline void SetIdentity(const string& value)
	{
		SetPropertyString("identity", value);
	}

	inline bool GetSubscribes(Message *value) const
	{
		return GetPropertyMessage("subscribes", value);
	}

	inline void SetSubscribes(Message value)
	{
		SetPropertyMessage("subscribes", value);
	}

	inline bool GetProvides(Message *value) const
	{
		return GetPropertyMessage("provides", value);
	}

	inline void SetProvides(Message value)
	{
		SetPropertyMessage("provides", value);
	}
};

}

#endif /* SUBSCRIPTIONMESSAGE_H */
