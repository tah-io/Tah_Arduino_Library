#ifndef TAH_h
#define TAH_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif



#include <inttypes.h>
#include <stdio.h> // for size_t


#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2



// TAH Device Role
#define MASTER 1
#define SLAVE 0

// iBeacon Deployment mode
#define BROADCAST_AND_SCAN 1
#define BROADCAST 2


// Device Scan result Filter
#define ALL_BLE 0
#define ONLY_TAH 1


// TAH's ble modules work type in Master Role
#define IMMEDIATELY 0
#define ATmode 1

// TAH iBeacon On Off State
#define ON 1
#define OFF 0

// TAH ble Module Work Mode

#define TRANSMISSION 0
#define IO_COLLECTION 1
#define REMOTE_CONTROL 2

// Transmission power of TAH's BLE module

#define Minus_Twenty_Three 0
#define Minus_Six 1
#define Zero 2
#define Six 3


// device authentication type

#define OPEN 0
#define SECURED 2



class TAH
{
public:
    
    void begin(long baud);
    bool available();
    int parseInt();

    int read(); // Reads data from TAH ble RX Pin
    
    virtual size_t write(uint8_t byte);  // Writes data to TAH ble TX pin
    
    void enterCommandMode(); // Enters Command Mode
    void exitCommandMode(); // Resets and exit command mode
    
    ///////////// Print and Println Functions //////////////////////////////
    
    
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long);
    size_t print(unsigned long, int = DEC);
    
    
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long);
    size_t println(unsigned long, int = DEC);
    
    
    ///////////////////// TAH Configurate Parameters //////////////////////
    
    void setName(char name[]); // Changes TAH Device name to desired
    
    void setAdvertisingInterval(int interval); // Chnages Advertising Interval
    
    void setBatteryMonitorSwitch(bool status); // Set Battery Monitor Switch

    void clearLastConnectedDevice(); // Clears address of Last Connected Device Address
    void connectLastSuccededDevice(); // Connect to last Device which was successfully connected
    void connectToMacAddress(char mac[]); // Connect to Specific Device by its MAC Address
    
    char scan(); // Start Scanning for BLE devices
    
    void connectToScannedDevice(int index); // Connect to device from from discovered device list
    
    void setiBeaconDeployMode(int mode); // Set TAH iBeacon Deployment mode
    
    void setDeviceScanFilter(int filter); // Set Device Scan result Filter
    
    void setWorkType(int type); // Sets TAH's ble modules work type in Master Role
    
    void setiBeaconMode(int mode); // Sets TAH iBeacon On Off State
    
    void setiBeaconUUIDstring1(char UUID1[]); // Sets first part of iBeacon UUID String
    
    void setiBeaconUUIDstring2(char UUID2[]); // Sets second part of iBeacon UUID String
    
    void setiBeaconUUIDstring3(char UUID3[]); // Sets third part of iBeacon UUID String
    
    void setiBeaconUUIDstring4(char UUID4[]); // Sets forth part of iBeacon UUID String
    
    void setiBeaconMajorValue(char major[]); // Sets TAH iBeacons Major Parameter Value
    
    void setiBeaconMinorValue(char minor[]); // Sets TAH iBeacons Minor Parameter Value
    
    void setWorkMode(int mode); // Sets TAH ble modules Work Mode
    
    void setUARTNotification(int notify); // Sets TAH connection notification service on uart
    
    void setPassword(char password[]); // Sets TAH device password
    
    void setAuth(int authtype);  // Sets device authentication type
    
    void setTransmissionPower(int power);  // Sets Transmission power of TAH's BLE module
    void setAutoSleepMode(int mode); // Sets Autosleep mode of TAH's ble module
    
    void WakeUp(); // Wakes up TAH from sleep
    
    void Reset(); // Restore to factory default settings
    
    void Refresh(); // Saves current changed settings and restarts ble module
    
    void setWorkRole(int role);  // Sets TAH's work role
    
    


    
    
private:
    
    HardwareSerial *_serial; // Defines Serial Port

    
 
    
};



#endif