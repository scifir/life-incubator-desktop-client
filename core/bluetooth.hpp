#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_CORE_BLUETOOTH_HPP
#define LIFE_INCUBATOR_DESKTOP_CLIENT_CORE_BLUETOOTH_HPP

#include <iostream>
#include <string>
#include <vector>

#include <windows.h>
#include <bluetoothapis.h>
#include <bthsdpdef.h>
#include <BluetoothAPIs.h>

namespace life_incubator
{
	struct BluetoothDeviceInfo {
		std::wstring name;
		BLUETOOTH_ADDRESS address;
	};

	std::vector<BluetoothDeviceInfo> ListBluetoothDevices();
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_CORE_BLUETOOTH_HPP