#include "Arduino.h"

#define USB_MANUFACTURER "Trinity3D"
#define USB_PRODUCT "Trinity3D Technologies Macro Touch Keyboard"
#define USB_SERIAL "T3D-MTKB-001"

#define JOY_X_PIN GPIO_NUM_17
#define JOY_Y_PIN GPIO_NUM_18

#include "USB.cpp"
#include "USBHIDKeyboard.h"
#include "Nextion.h"

USBHIDKeyboard Keyboard;

// Nextion read buffer
char buffer[100] = {0};

/*
* Declare Nextion instance
*/
Nextion *next = Nextion::GetInstance(Serial1); // HW serial

/*
 * Declare a main page object [nextion instance, page id:0, page name: "page0"]. 
 */
NexPage p0(next, 0, "boot");
NexPage p1(next, 1, "solidworks");

/*
* Declare key readout var
*/
NexVariable keyId(next, 1, 0, "va0", &p1);

/*
* Declare Nextion page 1 buttons
*/
NexHotspot hs00(next, 1, 1, "m0", &p1);
NexHotspot hs01(next, 1, 2, "m1", &p1);
NexHotspot hs02(next, 1, 3, "m2", &p1);
NexHotspot hs03(next, 1, 4, "m3", &p1);
NexHotspot hs04(next, 1, 5, "m4", &p1);
NexHotspot hs05(next, 1, 6, "m5", &p1);
NexHotspot hs06(next, 1, 7, "m6", &p1);
NexHotspot hs07(next, 1, 8, "m7", &p1);
NexHotspot hs08(next, 1, 9, "m8", &p1);
NexHotspot hs09(next, 1, 10, "m9", &p1);
NexHotspot hs10(next, 1, 11, "m10", &p1);
NexHotspot hs11(next, 1, 12, "m11", &p1);
NexHotspot hs12(next, 1, 13, "m12", &p1);
NexHotspot hs13(next, 1, 14, "m13", &p1);
NexHotspot hs14(next, 1, 15, "m14", &p1);
NexHotspot hs15(next, 1, 16, "m15", &p1);
NexHotspot hs16(next, 1, 17, "m16", &p1);
NexHotspot hs17(next, 1, 18, "m17", &p1);
NexHotspot hs18(next, 1, 19, "m18", &p1);
NexHotspot hs19(next, 1, 20, "m19", &p1);
NexHotspot hs20(next, 1, 21, "m20", &p1);
NexHotspot hs21(next, 1, 22, "m21", &p1);
NexHotspot hs22(next, 1, 23, "m22", &p1);
NexHotspot hs23(next, 1, 24, "m23", &p1);
NexHotspot hs24(next, 1, 25, "m24", &p1);
NexHotspot hs25(next, 1, 26, "m25", &p1);
NexHotspot hs26(next, 1, 27, "m26", &p1);
NexHotspot hs27(next, 1, 28, "m27", &p1);
NexHotspot hs28(next, 1, 29, "m28", &p1);
NexHotspot hs29(next, 1, 30, "m29", &p1);
NexHotspot hs30(next, 1, 31, "m30", &p1);
NexHotspot hs31(next, 1, 32, "m31", &p1);

NexTouch *nex_listen_list[] = {
    &hs00, &hs01, &hs02, &hs03, &hs04, &hs05, &hs06, &hs07,
    &hs08, &hs09, &hs10, &hs11, &hs12, &hs13, &hs14, &hs15,
    &hs16, &hs17, &hs18, &hs19, &hs20, &hs21, &hs22, &hs23,
    &hs24, &hs25, &hs26, &hs27, &hs28, &hs29, &hs30, &hs31,
    nullptr
};

uint8_t buttonToChar[32] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '1', '2', '3', '4', '5', '6'
};

void hsPopCallback(void *ptr) {
    int32_t button;
    buffer[0]= 0;

    keyId.getValue(&button);
    keyId.setValue(-1);

    Serial.print("Screen button pressed: ");
    Serial.print(button);
    Serial.print(" sending: CTRL+SHIFT+ALt+");
    Serial.print(buttonToChar[button]);
    Serial.println();

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(buttonToChar[button]);
    delay(50);
    Keyboard.releaseAll();
    delay(100);
}

uint8_t adc_pins[] = {JOY_X_PIN, JOY_Y_PIN};

void setup(void) {   
    Serial.begin(115200);
    Keyboard.begin();
    USB.PID(0x3105);
    USB.begin();

    next->nexInit();

    buffer[0]= 0;

    hs00.attachPop(hsPopCallback);
    hs01.attachPop(hsPopCallback);
    hs02.attachPop(hsPopCallback);
    hs03.attachPop(hsPopCallback);
    hs04.attachPop(hsPopCallback);
    hs05.attachPop(hsPopCallback);
    hs06.attachPop(hsPopCallback);
    hs07.attachPop(hsPopCallback);
    hs08.attachPop(hsPopCallback);
    hs09.attachPop(hsPopCallback);
    hs10.attachPop(hsPopCallback);
    hs11.attachPop(hsPopCallback);
    hs12.attachPop(hsPopCallback);
    hs13.attachPop(hsPopCallback);
    hs14.attachPop(hsPopCallback);
    hs15.attachPop(hsPopCallback);
    hs16.attachPop(hsPopCallback);
    hs17.attachPop(hsPopCallback);
    hs18.attachPop(hsPopCallback);
    hs19.attachPop(hsPopCallback);
    hs20.attachPop(hsPopCallback);
    hs21.attachPop(hsPopCallback);
    hs22.attachPop(hsPopCallback);
    hs23.attachPop(hsPopCallback);
    hs24.attachPop(hsPopCallback);
    hs25.attachPop(hsPopCallback);
    hs26.attachPop(hsPopCallback);
    hs27.attachPop(hsPopCallback);
    hs28.attachPop(hsPopCallback);
    hs29.attachPop(hsPopCallback);
    hs30.attachPop(hsPopCallback);
    hs31.attachPop(hsPopCallback);

    delay(500);
    p0.show();
    delay(5000);
    p1.show();
}

int16_t x_adc_val, y_adc_val; 
float x_volt, y_volt;
int8_t xDelta, yDelta = 0;
int16_t xDeltaSum, yDeltaSum = 0;

void loop(void) {
    next->nexLoop(nex_listen_list);
}