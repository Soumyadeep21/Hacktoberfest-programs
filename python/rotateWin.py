"""
Copyright (c) 2020-2020, Yifei Ding
SPDX-License-Identifier: Apache-2.0

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.

You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
either express or implied.

See the License for the specific language governing permissions and limitations under the License.
"""

import json
import pywintypes
import win32api
import win32con


# useful doc https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/


class Monitor:
    """
    Object containing the configuration and adapter, display data of a monitor.
    """

    def __init__(self, adapter: win32api.PyDISPLAY_DEVICEType,
                 device: win32api.PyDISPLAY_DEVICEType = None,
                 config: pywintypes.DEVMODEWType = None):
        self.adapter = adapter
        if device is not None:
            self.device = device
        else:
            self.device = win32api.EnumDisplayDevices(adapter.DeviceName, 0)  # Device is just for readability
        if config is not None:
            self.config = config
        else:
            self.config = win32api.EnumDisplaySettingsEx(adapter.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def __str__(self) -> str:
        return self.get_device_string()

    # def __eq__(self, other):
    #     """
    #     Compare two monitor object, return false when Device and Adapter doesn't match with the input
    #     :param other: another monitor object
    #     :return: true if they are the same (regardless of the config)
    #     """
    #     # TODO: compare two monitor

    @classmethod
    def from_dict(cls, monitor_dict: dict):
        """

        :param monitor_dict:
        :return:
        """
        adapter = win32api.PyDISPLAY_DEVICEType()
        device = win32api.PyDISPLAY_DEVICEType()
        config = pywintypes.DEVMODEWType()

        adapter.DeviceID = monitor_dict["adapter"]["DeviceID"]
        adapter.DeviceKey = monitor_dict["adapter"]["DeviceKey"]
        adapter.DeviceName = monitor_dict["adapter"]["DeviceName"]
        adapter.DeviceString = monitor_dict["adapter"]["DeviceString"]
        adapter.Size = monitor_dict["adapter"]["Size"]
        adapter.StateFlags = monitor_dict["adapter"]["StateFlags"]

        device.DeviceID = monitor_dict["device"]["DeviceID"]
        device.DeviceKey = monitor_dict["device"]["DeviceKey"]
        device.DeviceName = monitor_dict["device"]["DeviceName"]
        device.DeviceString = monitor_dict["device"]["DeviceString"]
        device.Size = monitor_dict["device"]["Size"]
        device.StateFlags = monitor_dict["device"]["StateFlags"]

        config.BitsPerPel = monitor_dict["config"]["BitsPerPel"]
        config.Collate = monitor_dict["config"]["Collate"]
        config.Color = monitor_dict["config"]["Color"]
        config.Copies = monitor_dict["config"]["Copies"]
        config.DefaultSource = monitor_dict["config"]["DefaultSource"]
        config.DeviceName = monitor_dict["config"]["DeviceName"]
        config.DisplayFixedOutput = monitor_dict["config"]["DisplayFixedOutput"]
        config.DisplayFlags = monitor_dict["config"]["DisplayFlags"]
        config.DisplayFrequency = monitor_dict["config"]["DisplayFrequency"]
        config.DisplayOrientation = monitor_dict["config"]["DisplayOrientation"]
        config.DitherType = monitor_dict["config"]["DitherType"]
        config.DriverData = monitor_dict["config"]["DriverData"]
        config.DriverExtra = monitor_dict["config"]["DriverExtra"]
        config.DriverVersion = monitor_dict["config"]["DriverVersion"]
        config.Duplex = monitor_dict["config"]["Duplex"]
        config.Fields = monitor_dict["config"]["Fields"]
        config.FormName = monitor_dict["config"]["FormName"]
        config.ICMIntent = monitor_dict["config"]["ICMIntent"]
        config.ICMMethod = monitor_dict["config"]["ICMMethod"]
        config.LogPixels = monitor_dict["config"]["LogPixels"]
        config.MediaType = monitor_dict["config"]["MediaType"]
        config.Nup = monitor_dict["config"]["Nup"]
        config.Orientation = monitor_dict["config"]["Orientation"]
        config.PanningHeight = monitor_dict["config"]["PanningHeight"]
        config.PanningWidth = monitor_dict["config"]["PanningWidth"]
        config.PaperLength = monitor_dict["config"]["PaperLength"]
        config.PaperSize = monitor_dict["config"]["PaperSize"]
        config.PaperWidth = monitor_dict["config"]["PaperWidth"]
        config.PelsHeight = monitor_dict["config"]["PelsHeight"]
        config.PelsWidth = monitor_dict["config"]["PelsWidth"]
        config.Position_x = monitor_dict["config"]["Position_x"]
        config.Position_y = monitor_dict["config"]["Position_y"]
        config.PrintQuality = monitor_dict["config"]["PrintQuality"]
        config.Reserved1 = monitor_dict["config"]["Reserved1"]
        config.Reserved2 = monitor_dict["config"]["Reserved2"]
        config.Scale = monitor_dict["config"]["Scale"]
        config.Size = monitor_dict["config"]["Size"]
        config.SpecVersion = monitor_dict["config"]["SpecVersion"]
        config.TTOption = monitor_dict["config"]["TTOption"]
        config.YResolution = monitor_dict["config"]["YResolution"]
        return cls(adapter, device, config)

    @classmethod
    def from_json(cls, filepath: str):
        with open(filepath, 'r') as file:
            return cls.from_dict(json.load(file))

    def update_config(self):
        """
        This function call win32 api to get the current config
        """
        self.config = win32api.EnumDisplaySettingsEx(self.adapter.DeviceName, win32con.ENUM_CURRENT_SETTINGS)

    def apply_config(self) -> int:
        """
        apply the config changes to windows.
        :return: successful when it return 0
        """
        return win32api.ChangeDisplaySettingsEx(self.adapter.DeviceName, self.config)

    def to_dict(self) -> dict:
        """
        Convert the monitor object to a dict object containing the same data
        :return: dict
        """
        dict_monitor: dict = {
            "adapter": {
                "DeviceID": self.adapter.DeviceID,
                "DeviceKey": self.adapter.DeviceKey,
                "DeviceName": self.adapter.DeviceName,
                "DeviceString": self.adapter.DeviceString,
                "Size": self.adapter.Size,
                "StateFlags": self.adapter.StateFlags
            },
            "device": {
                "DeviceID": self.device.DeviceID,
                "DeviceKey": self.device.DeviceKey,
                "DeviceName": self.device.DeviceName,
                "DeviceString": self.device.DeviceString,
                "Size": self.device.Size,
                "StateFlags": self.device.StateFlags
            },
            "config": {
                "BitsPerPel": self.config.BitsPerPel,
                "Collate": self.config.Collate,
                "Color": self.config.Color,
                "Copies": self.config.Copies,
                "DefaultSource": self.config.DefaultSource,
                "DeviceName": self.config.DeviceName,
                "DisplayFixedOutput": self.config.DisplayFixedOutput,
                "DisplayFlags": self.config.DisplayFlags,
                "DisplayFrequency": self.config.DisplayFrequency,
                "DisplayOrientation": self.config.DisplayOrientation,
                "DitherType": self.config.DitherType,
                "DriverData": self.config.DriverData,
                "DriverExtra": self.config.DriverExtra,
                "DriverVersion": self.config.DriverVersion,
                "Duplex": self.config.Duplex,
                "Fields": self.config.Fields,
                "FormName": self.config.FormName,
                "ICMIntent": self.config.ICMIntent,
                "ICMMethod": self.config.ICMMethod,
                "LogPixels": self.config.LogPixels,
                "MediaType": self.config.MediaType,
                "Nup": self.config.Nup,
                "Orientation": self.config.Orientation,
                "PanningHeight": self.config.PanningHeight,
                "PanningWidth": self.config.PanningWidth,
                "PaperLength": self.config.PaperLength,
                "PaperSize": self.config.PaperSize,
                "PaperWidth": self.config.PaperWidth,
                "PelsHeight": self.config.PelsHeight,
                "PelsWidth": self.config.PelsWidth,
                "Position_x": self.config.Position_x,
                "Position_y": self.config.Position_y,
                "PrintQuality": self.config.PrintQuality,
                "Reserved1": self.config.Reserved1,
                "Reserved2": self.config.Reserved2,
                "Scale": self.config.Scale,
                "Size": self.config.Size,
                "SpecVersion": self.config.SpecVersion,
                "TTOption": self.config.TTOption,
                "YResolution": self.config.YResolution
            }
        }
        return dict_monitor

    def to_json(self, filepath: str):
        """
        Export the entire Monitor object to a json file described in the filepath
        :param filepath: the file path including .json for storing a Monitor object
        """
        with open(filepath, 'w') as file:
            json.dump(self.to_dict(), file, ensure_ascii=False, indent=4)

    def replace_config(self, config: pywintypes.DEVMODEWType):
        """
        replace the config of the current monitor object with a config from another monitor object
        :param config: pywintypes.DEVMODEWType, no compatibility check
        """
        self.config = config

    def get_device_id(self) -> str:
        """
        return the DeviceID of this object
        :return: string of Device ID
        """
        return self.device.DeviceID

    def get_device_key(self) -> str:
        """
        return the DeviceKey of this object NOTE: DeviceKey Would Change!
        :return: string of DeviceKey
        """
        return self.adapter.DeviceKey

    def get_device_string(self) -> str:
        """
        return the DeviceString of this object
        :return: string of DeviceString
        """
        return self.device.DeviceString

    def swap_pels(self):
        """
        Swap the vertical and horizontal pixel count
        """
        self.config.PelsHeight, self.config.PelsWidth = self.config.PelsWidth, self.config.PelsHeight

    def rotation_default(self):
        """
        Set rotation to 0 degree
        """
        if self.config.DisplayOrientation == win32con.DMDO_90 or \
                self.config.DisplayOrientation == win32con.DMDO_270:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_DEFAULT
        self.apply_config()

    def rotation_90(self):
        """
        Set monitor rotation to 90 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_180 or \
                self.config.DisplayOrientation == win32con.DMDO_DEFAULT:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_90
        self.apply_config()

    def rotation_180(self):
        """
        Set monitor rotation to 180 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_90 or \
                self.config.DisplayOrientation == win32con.DMDO_270:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_180
        self.apply_config()

    def rotation_270(self):
        """
        Set monitor rotation to 270 degrees
        """
        if self.config.DisplayOrientation == win32con.DMDO_180 or \
                self.config.DisplayOrientation == win32con.DMDO_DEFAULT:
            self.swap_pels()
        self.config.DisplayOrientation = win32con.DMDO_270
        self.apply_config()

    def rotate_cw(self):
        """
        Rotate the monitor clock wise for 90 degrees
        """
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.rotation_270()
        elif current == win32con.DMDO_90:
            self.rotation_default()
        elif current == win32con.DMDO_180:
            self.rotation_90()
        elif current == win32con.DMDO_270:
            self.rotation_180()

    def rotate_ccw(self):
        """
        Rotate the monitor counter-clock wise for 90 degrees
        """
        current = self.config.DisplayOrientation
        if current == win32con.DMDO_DEFAULT:
            self.rotation_90()
        elif current == win32con.DMDO_90:
            self.rotation_180()
        elif current == win32con.DMDO_180:
            self.rotation_270()
        elif current == win32con.DMDO_270:
            self.rotation_default()


def get_monitors() -> list:
    """
    return a list of monitors recognize by the computer
    :return: A list of Monitor objects
    """
    displays = []
    i = 0
    while True:
        try:
            display = win32api.EnumDisplayDevices(None, i)
            displays.append(display)
        except pywintypes.error:  # run out of displays
            break
        i += 1

    monitors = []
    for display in displays:
        try:
            win32api.EnumDisplayDevices(display.DeviceName, 0)
            monitors.append(Monitor(display))
        except pywintypes.error:
            continue

    return monitors


class Monitors:
    """
    A class to represent all the monitors(adapters to be exact) that are detectable by windows.
    """

    def __init__(self):
        self.monitors = get_monitors()

    def __getitem__(self, item) -> Monitor:
        return self.monitors[item]

    def __len__(self):
        return len(self.monitors)

    def get_monitor_from_key(self, DeviceKey: str) -> Monitor:
        """
        find the monitor with the provided DeviceKey NOTE: DeviceKey Would Change!
        :param DeviceKey: a string matching DeviceKey of a Monitor object in this object
        :return: the first Monitor object with the provided DeviceKey
        """
        for monitor in self.monitors:
            if monitor.get_device_key() == DeviceKey:
                return monitor
        raise LookupError("%s Monitor does not exist" % DeviceKey)

    def get_monitor_from_id(self, DeviceID: str) -> Monitor:
        """
        find the monitor with the provided DeviceID
        :param DeviceID: a string matching DeviceID of a Monitor object in this object
        :return: the first monitor with the provided DeviceID
        """
        for monitor in self.monitors:
            if monitor.get_device_id() == DeviceID:
                return monitor
        raise LookupError("%s Monitor does not exist" % DeviceID)

    def to_dict(self) -> dict:
        monitors = {}
        for monitor in self.monitors:
            monitors[monitor.get_device_id()] = monitor.get_device_string()
        return monitors


def main():
    """
    it's just for testing purposes
    """
    print("Launch main.py plz")


if __name__ == "__main__":
    main()
