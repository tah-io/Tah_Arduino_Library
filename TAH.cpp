#include "Arduino.h"
#include "HardwareSerial.h"
#include "TAH.h"
#include "Stream.h";

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#define Delay_Between_Commands 50   // Delay between executation of each command in milliseconds




////////

void TAH::enterCommandMode() // Enters Command Mode
{
    _serial = &Serial1;
    _serial->print("AT");
    delay(Delay_Between_Commands);
}


void TAH::exitCommandMode()  // Resets and exit command mode
{
    _serial = &Serial1;
    _serial->print("AT+RESET");
    

}


void TAH::begin(long baud)// begins TAH ble serial port at specified baud rate
{
	_serial = &Serial1;
    _serial->begin(baud);

    
}


bool TAH::available() // retun bool if anything available on BLE RX Pin
{
	_serial = &Serial1;
    return _serial->available(); // retun bool if anything available on BLE RX Pin
    
}

int TAH::parseInt() // returns parsed integer from TAH Rx pin
{
    
    _serial = &Serial1;
    return _serial->parseInt();
    
}


int TAH::read() // Reads data from TAH ble RX Pin
{
    _serial = &Serial1;
    return _serial->read();
}

size_t TAH::write(uint8_t byte) // Writes data to TAH ble TX pin
{
    _serial = &Serial1;
    return _serial->write(byte);
}



///////////// Print and Println Functions //////////////////////////////


// Print
size_t TAH::print(const char str[])
{
    return _serial->write(str);
}

size_t TAH::print(char c)
{
    return _serial->write(c);
}

size_t TAH::print(unsigned char b, int base)
{
    return _serial->print((unsigned long) b, base);
}

size_t TAH::print(int n, int base)
{
    return _serial->print((long) n, base);
}

size_t TAH::print(unsigned int n, int base)
{
    return _serial->print((unsigned long) n, base);
}

size_t TAH::print(long num)
{
    size_t n = _serial->print(num);
    
    return n;
}

size_t TAH::print(unsigned long n, int base)
{
    return _serial->print((unsigned long) n, base);
}




// Println


size_t TAH::println(const char c[])
{
    size_t n = _serial->print(c);
    n += _serial->println();
    return n;
}

size_t TAH::println(char c)
{
    size_t n = _serial->print(c);
    n += _serial->println();
    return n;
}

size_t TAH::println(unsigned char b, int base)
{
    size_t n = _serial->print(b, base);
    n += _serial->println();
    return n;
}

size_t TAH::println(int num, int base)
{
    size_t n = _serial->print(num, base);
    n += _serial->println();
    return n;
}

size_t TAH::println(unsigned int num, int base)
{
    size_t n = _serial->print(num, base);
    n += _serial->println();
    return n;
}

size_t TAH::println(long num)
{
    size_t n = _serial->println(num);
    
    return n;
}

size_t TAH::println(unsigned long n, int base)
{
    return _serial->println((unsigned long) n, base);
}


///////////////////// TAH Configurate Parameters //////////////////////

// Name

void TAH::setName(char name[]) // Changes TAH Device name to desired
{
    
    _serial = &Serial1;
    _serial->print("AT+NAME");
    _serial->print(name);
    
    delay(Delay_Between_Commands);
}


// Advertising Interval

void TAH::setAdvertisingInterval(int interval)  // Chnages Advertising Interval
{
     _serial = &Serial1;
     _serial->print("AT+ADVI");
    
    switch (interval)
    {
        case 100:
            _serial->print("0");
            break;
            
        case 1285:
            _serial->print("1");
            break;
            
        case 2000:
            _serial->print("2");
            break;
            
        case 3000:
            _serial->print("3");
            break;
            
        case 4000:
            _serial->print("4");
            break;
            
        case 5000:
            _serial->print("5");
            break;
            
        case 6000:
            _serial->print("6");
            break;
            
        case 7000:
            _serial->print("7");
            break;
            
        case 8000:
            _serial->print("8");
            break;
            
        case 9000:
            _serial->print("9");
            break;
     }
    
    delay(Delay_Between_Commands);
    
}


// Battery Monitor Switch

void TAH::setBatteryMonitorSwitch(bool status) // Set Battery Monitor Switch

{
    _serial = &Serial1;
    _serial->print("AT+BATC");
    
    switch (status)
    {
        case LOW:
            _serial->print("0");
            break;
        
        case HIGH:
            _serial->print("1");
            break;
            
    }
    
    delay(Delay_Between_Commands);
}


// Clear Last Connected Device Address

void TAH::clearLastConnectedDevice() // Clears address of Last Connected Device Address
{
    _serial = &Serial1;
    _serial->print("AT+CLEAR");
    delay(Delay_Between_Commands);
}



// Connect to last Device which was successfully connected

void TAH::connectLastSuccededDevice()  // Connect to last Device which was successfully connected
{
    _serial = &Serial1;
    _serial->print("AT+CONNL");
    delay(Delay_Between_Commands);
}


// Connect to Specific Device by its MAC Address

void TAH::connectToMacAddress(char mac[])
{
    _serial = &Serial1;
    _serial->print("AT+CON");
    _serial->print(mac);
    
    delay(Delay_Between_Commands);
}


// Start Scanning for BLE devices

char TAH::scan()
{
    _serial = &Serial1;
    _serial->print("AT+DISC?");
     delay(Delay_Between_Commands);
    
    return _serial->read();
}


// Connect to device from from discovered device list

void TAH::connectToScannedDevice(int index)
{
    _serial = &Serial1;
    _serial->print("AT+CONN");
    _serial->print(index);
    delay(Delay_Between_Commands);

}


// Set TAH iBeacon Deployment mode

void TAH::setiBeaconDeployMode(int mode)
{
    _serial = &Serial1;
    _serial->print("AT+DELO");
    
    switch (mode)
    {
        case BROADCAST_AND_SCAN :
            _serial->print(BROADCAST_AND_SCAN);
            break;
            
        case BROADCAST :
            _serial->print(BROADCAST);
            break;
            
       
    }
    
    delay(Delay_Between_Commands);
}


// Set Device Scan result Filter

void TAH::setDeviceScanFilter(int filter)
{
    _serial = &Serial1;
    _serial->print("AT+FILT");
    
    switch (filter)
    {
        case ALL_BLE :
            _serial->print(ALL_BLE);
            break;
            
        case ONLY_TAH :
            _serial->print(ONLY_TAH);
            break;
            
            
    }
    
    delay(Delay_Between_Commands);
}


// Sets TAH's ble modules work type in Master Role

void TAH::setWorkType(int type)
{
    _serial = &Serial1;
    _serial->print("AT+IMME");
    
    switch (type)
    {
        case IMMEDIATELY :
            _serial->print(IMMEDIATELY);
            break;
            
        case ATmode :
            _serial->print(ATmode);
            break;
            
            
    }
    
    delay(Delay_Between_Commands);
    
}


// Sets TAH iBeacon On Off State

void TAH::setiBeaconMode(int mode)
{
    _serial = &Serial1;
    _serial->print("AT+IBEA");
    
    switch (mode)
    {
        case ON :
            _serial->print(ON);
            break;
            
        case OFF :
            _serial->print(OFF);
            break;
            
            
    }
    delay(Delay_Between_Commands);
}


// Sets first part of iBeacon UUID String

void TAH::setiBeaconUUIDstring1(char UUID1[])
{
    _serial = &Serial1;
    _serial->print("AT+IBE0");
    _serial->print(UUID1);
    delay(Delay_Between_Commands);
    
}


// Sets second part of iBeacon UUID String

void TAH::setiBeaconUUIDstring2(char UUID2[])
{
    _serial = &Serial1;
    _serial->print("AT+IBE1");
    _serial->print(UUID2);
    delay(Delay_Between_Commands);
    
}


// Sets third part of iBeacon UUID String

void TAH::setiBeaconUUIDstring3(char UUID3[])
{
    _serial = &Serial1;
    _serial->print("AT+IBE2");
    _serial->print(UUID3);
    delay(Delay_Between_Commands);
    
}


// Sets forth part of iBeacon UUID String

void TAH::setiBeaconUUIDstring4(char UUID4[])
{
    _serial = &Serial1;
    _serial->print("AT+IBE3");
    _serial->print(UUID4);
    delay(Delay_Between_Commands);
    
}


// Sets TAH iBeacons Major Parameter Value

void TAH::setiBeaconMajorValue(char major[])
{
   
    
    _serial = &Serial1;
    _serial->print("AT+MARJ");
    _serial->print("0x");
    _serial->print(major);
    delay(Delay_Between_Commands);
}


// Sets TAH iBeacons Minor Parameter Value

void TAH::setiBeaconMinorValue(char minor[])
{
    _serial = &Serial1;
    _serial->print("AT+MINO");
    _serial->print("0x");
    _serial->print(minor);
    delay(Delay_Between_Commands);
}


// Sets TAH ble modules Work Mode

void TAH::setWorkMode(int mode)
{
    _serial = &Serial1;
    _serial->print("AT+MODE");
    
    switch (mode)
    {
        case TRANSMISSION:
            _serial->print(TRANSMISSION);
            break;
            
        case IO_COLLECTION:
            _serial->print(IO_COLLECTION);
            break;
        
        case REMOTE_CONTROL:
            _serial->print(REMOTE_CONTROL);
            break;
            
        
    }
      delay(Delay_Between_Commands);
}

// Sets TAH connection notification service on uart

void TAH::setUARTNotification(int notify)
{
    _serial = &Serial1;
    _serial->print("AT+NOTI");
    
    switch (notify)
    {
        case ON:
            _serial->print(ON);
            break;
            
        case OFF:
            _serial->print(OFF);
            break;

            
    }
    delay(Delay_Between_Commands);
}


// Sets TAH device password

void TAH::setPassword(char password[])
{
    _serial = &Serial1;
    _serial->print("AT+PASS");
    _serial->print(password);
    delay(Delay_Between_Commands);

}


// Sets device authentication type

void TAH::setAuth(int authtype)
{
    _serial = &Serial1;
    _serial->print("AT+TYPE");
    
    switch (authtype)
    {
        case OPEN:
            _serial->print(OPEN);
            break;
            
        case SECURED:
            _serial->print(SECURED);
            break;
            
            
    }

    delay(Delay_Between_Commands);
}




// Sets Transmission power of TAH's BLE module

void TAH::setTransmissionPower(int power)
{
    _serial = &Serial1;
    _serial->print("AT+POWE");
    switch (power)
    {
        case Minus_Twenty_Three:
            _serial->print(Minus_Twenty_Three);
            break;
            
        case Minus_Six:
            _serial->print(Minus_Six);
            break;
            
        case Zero:
            _serial->print(Zero);
            break;
            
        case Six:
            _serial->print(Six);
            break;
            
            
    }
    delay(Delay_Between_Commands);

}


// Sets Autosleep mode of TAH's ble module

void TAH::setAutoSleepMode(int mode)
{
    _serial = &Serial1;
    _serial->print("AT+PWRM");
    switch (mode)
    {
        case ON:
            _serial->print(OFF);
            break;
            
        case OFF:
            _serial->print(ON);
            break;

            
    }
    delay(Delay_Between_Commands);
}


// Wakes up TAH from sleep

void TAH::WakeUp()
{
    _serial = &Serial1;
    _serial->print("WakeFromSleepWakeFromSleepWakeFromSleepWakeFromSleep");
    delay(Delay_Between_Commands);
}


// Restore to factory default settings

void TAH::Reset()
{
    _serial = &Serial1;
    
    // Name
    _serial->print("AT+NAMETAH");
    delay(Delay_Between_Commands);
    
    // Password
    _serial->print("AT+PASS000000");
    delay(Delay_Between_Commands);
    
    // Role: Peripheral
    _serial->print("AT+ROLE0");
    delay(Delay_Between_Commands);
    
     // Baud
     _serial->print("AT+BAUD0");
     delay(Delay_Between_Commands);

}

// Saves current changed settings and restarts ble module

void TAH::Refresh()
{
    _serial = &Serial1;
    _serial->print("AT+RESET");
    delay(Delay_Between_Commands);
}


// Sets TAH's work role

void TAH::setWorkRole(int role)
{
    _serial = &Serial1;
    _serial->print("AT+ROLE");
    
    switch (role)
    {
        case MASTER:
            _serial->print(MASTER);
            break;
            
        case SLAVE:
            _serial->print(SLAVE);
            break;
        
    }
    delay(Delay_Between_Commands);
}









