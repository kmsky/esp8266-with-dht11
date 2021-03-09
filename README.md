# ESP8266-01S with DHT11 and communication via HTTP

Project is based on __ESP8266-01S__ module which is responsible for WiFi communication and works as an independent, programmed controller. Data collected from __DHT11__ (temperature and humidity) is sent via HTTP and stored in database. Communication between ESP module and database is handled by dedicated API.

Updated work results of the system are available here (in JSON format): http://arduino.gaway.pl/api/measurement/

## Used in the project

- ESP8266-01S
- DHT11
- Arduino (_to program the ESP8266 module_)

## Libraries
- ESP8266 WiFi
- ESP8266 HTTPClient
- DHT

[Installation of ESP library for Arduino IDE](https://github.com/esp8266/Arduino#installing-with-boards-manager)

## Diagram

![](https://i.ibb.co/c8McyWX/po-programowaniu.png)
_ESP8266 wiring diagram for programming via Arduino_

__After programming ESP8266 is an independent controller, Arduino is only used to power module and sensor.__

![](https://i.ibb.co/QDpqQXz/po-programowaniu.png)
_Wiring diagram of programmed ESP8266 with DHT_

## Sending JSON data via HTTP POST
The easiest way to send data in JSON using ESP8266 is adding header with content-type and next pass data formatted like JSON:
```cpp
http.addHeader("Content-Type", "application/json");
http.POST("{\"param1\":" + String(data1) + ",\"param2\":" + String(data2)+"}");
```

Doing it this way allows us to avoid including _ArduinoJson_ library.

## Contribute the project!
#### If you want to join and contribute to the project with us, create and program your own module. Then contact us, we will provide you with API access.

Contact: _arduino@gaway.pl_

### License
MIT
