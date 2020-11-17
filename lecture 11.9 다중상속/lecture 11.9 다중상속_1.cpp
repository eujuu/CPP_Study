#include <iostream>
using namespace std;
// 다중상속

class USBDevice {
private:
	long m_id;
public:
	USBDevice(long id)
		:m_id(id)
	{}

	long getID() { return m_id; }
	void plugAndPlay() {}
};

class NetworkDevice {
private:
	long m_id;
public:
	NetworkDevice(long id) 
		: m_id(id)
	{}
	long getID() { return m_id; }
	void networking(){}
};
//다중상속
class USBNetworkDevice : public USBDevice, public NetworkDevice {
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}
};

int main() {

	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay(); //중복되는 함수는..?

	//my_device.getID(); //중복된 함수로 인한 ambiguous
	//해결방법
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

}