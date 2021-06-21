# Esp32BluetoothSliderApp
As per request of Rob I upload here a variant of the code to connect an ESP32 with Bluetooth to a Phone with a slider. For the original code and explanation, please refer to:
https://github.com/mo-thunderz/Esp32BluetoothApp
https://www.youtube.com/watch?v=aM2ktMKAunw

Bluetooth is a simple connection that sends bytes over from the phone to the ESP32 (1 byte = 8 bits = 256 values). The buttons are implemented in a straightforward fashion in this version where 0 is the first button, 1, the second, etc. Whenever the slider is changed, two bytes are send instead of one. The first byte is the most significant byte (MSB) and this indicates the slider ID. I gave the slider the ID of 2048, which is equal of an MSB of 8. Thus, whenever the Arduino receives 8, it will wait for a second byte to be received which is the value of the slider. 

This quick hack works for one single slider, but this concept can be easily expanded to support many sliders by adding more IDs. 
