// --------------------------------------------------
//
//
//
// --------------------------------------------------

// this header is needed for Bluetooth Serial -> works ONLY on ESP32
#include "BluetoothSerial.h" 

// init Class:
BluetoothSerial ESP_BT; 

bool set_slider = false;

// Parameters for Bluetooth interface
int incoming;

void setup() {
  Serial.begin(19200);
  ESP_BT.begin("ESP32_Control"); //Name of your Bluetooth interface -> will show up on your phone
  Serial.println("Bluetooth ready to pair");
}

void loop() {
  
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); //Read what we receive 

    if (set_slider) {
      Serial.print("Set slider value: "); Serial.println(incoming);
      set_slider = false;
    }
    else {
      switch (incoming) {
        case 0:  
          Serial.print("Button 1:"); Serial.println(incoming);
          break;
        case 1:  
          Serial.print("Button 2:"); Serial.println(incoming);
          break;
        case 2:  
          Serial.print("Button 3:"); Serial.println(incoming);
          break;
        case 8:
          // in MIT app inventor we add 2048 to the slider -> this represents "8" in the most significant byte. Thus if 8 is received, the second byte represents the slider
          set_slider = true;
          break;
      }
    }
  }
}
