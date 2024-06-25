
#ifndef __PN532_HSU_H__
#define __PN532_HSU_H__

#include "PN532Interface.h"
#include "Ihardware_serial.hpp"

#define PN532_HSU_DEBUG

#define PN532_HSU_READ_TIMEOUT						(30)

class PN532_HSU : public PN532Interface {
public:
    explicit PN532_HSU(IHardwareSerial &serial);
    
    void begin() override;
    void wakeup() override;
    bool modifyHsuBaudrate(int baudrate) override;
    void sendAckFrame(void) override;
    int8_t writeCommand(const uint8_t *header, uint8_t hlen, const uint8_t *body = 0, uint8_t blen = 0) override;
    int16_t readResponse(uint8_t buf[], uint8_t len) override;
    int16_t readResponse(uint8_t buf[], uint8_t len, uint16_t timeout) override;
    
private:
    IHardwareSerial* _serial;
    uint8_t command;
    
    int8_t readAckFrame();
    
    int8_t receive(uint8_t *buf, int len, uint16_t timeout=PN532_HSU_READ_TIMEOUT);
};

#endif
