# Macro Screen HID
## Basic information
This is the firmware repository for the Macro Screen HID found on Printables, which was designed primarily for use with Solidworks, but can just as easily be adapted to work with Fusion 360 or any other software that has the capability of binding custom keycombinations to functions/features of the software. In theory it could even be used perfectly fine for quick access to all sorts of commands used in RTS or MMO games.

The main content of this repository consists of the firmware for the ESP32 S3 microcontroller. In the __\_HMI FIRMWARE\___ folder you can find the firmware source as well as a precompiled binary for use with the TJC4024K032_011R HMI display I used with my version of the project. The project can however as easily be build using the Nextion NX4024K032_011R or the nearly identical T versions of the panels available from Nextion or TJC.
In order to use the T versions of the Nextion or TJC panels you will have to open the HMI file in the corresponding editor and adjust the targeted model number of the panel. Firmware source for Nextion and TJC are supplied and both setup to work with the K versions of the panels.

__NOTE:__ Nextion and TJC despite being the same panel essentially are NOT interchangable for the firmware. Nextion firmware can only be edited using the Nextion editor (English only) and TJC firmware can only be edited using the TJC editor (Chinese only)

__NOTE2:__ The screens can be sensitive to which version of the editor is used to generate the firmware binary, for the project v1.67.1 (Nextion AND TJC) were used. This version works with older and newer revisions of the HMI panels. Some of the new batches of at least the TJC panels will not work with firmware binaries compiled with some of the older versions of the editor.

## Customization
The screen can be customized by generating a custom background image for the button panel of the screen firmware. And flashing the new version of the panel firmware to the device. The ESP32 side of things shouldn't need to change in order to reconfigure for using the panel to a different panel.

The default Solidworks button layout in this firmware:
[[_HMI FIRMWARE_/images/solidworks.png]]