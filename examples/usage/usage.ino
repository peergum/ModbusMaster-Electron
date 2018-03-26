// Test code
SYSTEM_MODE(MANUAL);

#include "ModbusMaster-Particle.h"

SerialLogHandler logHandler(9600,LOG_LEVEL_WARN, {
    {"app", LOG_LEVEL_TRACE},
    {"system", LOG_LEVEL_INFO}
});

ModbusMaster slave;

void preTransmission() {
    // set interface to TX
}

void postTransmission() {
    // set interface to RX
}

void idle() {
    delay(10); // in case slave only replies after 10ms
    Particle.process(); // avoids letting the connection close if open
}

void setup() {
    slave.begin(1,Serial1); // slaveID=1, serial=Serial1
    slave.setSpeed(9600,SERIAL_8N1);
    // slave.setSpeed(9600); // same as above
    slave.enableDebug(); // to catch the logs
    slave.preTransmission(preTransmission);
    slave.postTransmission(postTransmission);
    slave.idle(idle);

    uint8_t result = slave.readHoldingRegisters(8000,1);

    if (!result) {
        uint16_t value = slave.getResponseBuffer(0);
        Log.info("Received: %0x",value);
    } else {
        Log.warn("Read error");
    }
}

void loop() {
    // do nothing :P
}
