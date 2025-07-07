#include "./bluetooth.hpp"

#include <iostream>
#include <string>
#include <vector>

#pragma comment(lib, "Bthprops.lib")

namespace life_incubator
{
	std::vector<BluetoothDeviceInfo> ListBluetoothDevices()
	{
		std::vector<BluetoothDeviceInfo> devices;
	
		BLUETOOTH_DEVICE_SEARCH_PARAMS searchParams = {
			sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS),
			1, // return authenticated
			1, // return remembered
			1, // return unknown
			1, // return connected
			1, // issue query
			15, // timeout (in seconds)
			NULL
		};
	
		BLUETOOTH_DEVICE_INFO deviceInfo = { sizeof(BLUETOOTH_DEVICE_INFO) };
	
		HBLUETOOTH_DEVICE_FIND hFind = BluetoothFindFirstDevice(&searchParams, &deviceInfo);
	
		if (hFind != NULL) {
			do {
				devices.push_back({ deviceInfo.szName, deviceInfo.Address });
			} while (BluetoothFindNextDevice(hFind, &deviceInfo));
	
			BluetoothFindDeviceClose(hFind);
		}
	
		return devices;
	}
}