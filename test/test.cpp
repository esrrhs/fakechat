#include "libhole.h"

#define MAX_NIC 3

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "arg : MyPort DstIp DstPort\n";
		return -1;
	}

	int srcPort = atoi(argv[1]);
	std::string dstIp = argv[2];
	int dstPort = atoi(argv[3]);

	initNetwork();

	StunAddress4 stunServerAddr;
	bool ret = stunParseServerName("stun.schlund.de", stunServerAddr);
	if (!ret)
	{
		cout << "stunParseServerName Fail\n";
		return -1;
	}

	StunAddress4 mappedAddr;
	int fd = stunOpenSocket(stunServerAddr, &mappedAddr,
		srcPort, 0,
		false);

	cout << "stunOpenSocket OK " << mappedAddr;

	char data[100];
	int i = 0;
	while (1)
	{
		in_addr tmp;
		tmp.S_un.S_addr = htonl(mappedAddr.addr);
		sprintf(data, "this is from %s %d %d", inet_ntoa(tmp), mappedAddr.port, i);

		unsigned long a = inet_addr(dstIp.c_str());
		int ip = ntohl( a );
		sendMessage(fd, data, strlen(data), ip, dstPort, false);

		i++;
	}

	closesocket(fd);

	char c;
	cin>>c;
	return 0;
}

