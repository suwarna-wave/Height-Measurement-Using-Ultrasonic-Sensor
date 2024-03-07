# Height-Measurement-Using-Ultrasonic-Sensor
Based on the provided code, here are the pinouts for the components used:

1. **Ultrasonic Sensor (HC-SR04)**:
   - TRIG_PIN: Connected to pin 9 on the Arduino (Trigger pin)
   - ECHO_PIN: Connected to pin 10 on the Arduino (Echo pin)

2. **I2C LCD Display**:
   - SDA: Connected to the SDA pin on the Arduino (A4 on most Arduino boards)
   - SCL: Connected to the SCL pin on the Arduino (A5 on most Arduino boards)
   - VCC: Connected to the 5V pin on the Arduino
   - GND: Connected to any GND pin on the Arduino

Make sure to connect the components according to these pinouts to ensure proper communication and functionality of your Arduino project.

Here are the steps to set up and run the provided Arduino code:

1. **Set Up Hardware**:
   - Connect the components to your Arduino board according to the pinouts provided:
     - Ultrasonic Sensor (HC-SR04) should be connected to pins 9 (TRIG_PIN) and 10 (ECHO_PIN).
     - I2C LCD Display should be connected to the SDA and SCL pins for I2C communication, and VCC and GND for power.

2. **Install Libraries**:
   - Make sure you have installed the required libraries for the DHT sensor and the LiquidCrystal_I2C library for the LCD display. You can install these libraries using the Arduino Library Manager.

3. **Upload the Code**:
   - Copy the provided code into your Arduino Integrated Development Environment (IDE).
   - Connect your Arduino board to your computer via USB.
   - Select the correct board and port from the Tools menu in the Arduino IDE.
   - Click the "Upload" button to upload the code to your Arduino board.

4. **Monitor Serial Output**:
   - Open the Serial Monitor in the Arduino IDE (Tools > Serial Monitor).
   - Make sure the baud rate is set to 9600 baud.
   - You should see the output from the Arduino, including temperature, humidity, object height, and ground level measurements.
