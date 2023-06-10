# Arduino_BLE_LED_Controller
A simple project that uses the Arduino Nano 33 sense with the LightBlue app to control an LED strip via ble 5.0.
There is a simple list of commands that can be sent as strings via the LightBlue app.
##Commands 
###Solid Colours
There are 8 solid colour options consisting of: red, blue, green, pink, purple, cyan, orange, yellow
Please note that the colours may look different on different LED strips so you may need to tweak these solid colours in the code to get the desired colour.
###Dynamic Modes
There are 3 dynamic modes: rave, miami and pulse. Rave slowly transitions through the whole colour range, pulse pulses all the solid colours, and miami just cycles through cyan, pink, purple and blue.

