#include "devices.hpp"
#include "packet.hpp"

int main(){
    groundControl gc;
    FlightController fc(100);

    Packet altitudeRequest;
    std::vector<uint8_t> requestBytes = gc.requestAlt(altitudeRequest);

    uint8_t fcCommand = fc.decode(requestBytes);
    fc.handleCommand(fcCommand);

    if (fcCommand == ALTITUDE){
        Packet altitudeResponse;
        altitudeResponse.header = 0xAA;
        altitudeResponse.deviceID = 0x01;
        altitudeResponse.cmd = ALTITUDE;

        std::vector<uint8_t> responseBytes = fc.sendAlt(altitudeResponse);
        int altitude = gc.groundDecode(responseBytes);
        gc.groundHandle(altitude);
    }

    return 0;
}
