# NC SRP FC024 System
#### This repo contains the firmware for the project and instructions on how to upload it to the hardware

## Requirements
1) Install Visual Studio Code (VScode) on your machine. [Download](https://code.visualstudio.com/download) if you haven't yet.
2) Open VScode and go to Extensions tab.
3) Search for PlatformIO IDE and install it.

Refer to the following tutorials to learn how to use PlatformIO with VScode :link: [Link](https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/) or [Link](https://vbsmandi.medium.com/getting-started-with-the-esp32-board-in-vs-code-and-platform-io-92621641c985)

#### Download the files 
4)  Download all the files on the `Code`:arrow_down_small: on this platform. In your downloads, extract the zip file and you will get the folder :file_folder:**NC SRP FC024 System**. This folder should have a *platformio.ini* file and other source code files inside it.

5) In Visual Studio Studio Code, ensure you have the **PIO Home** tab open. Select :file_folder:`Open Project` and open the downloaded :file_folder:**NC SRP FC024 System** folder from step 4. This will begin a process to download important missing project files and might take a while.

## Uploading the code
1) Ensure you have a good quality usb Micro-B cable capable of data transfer.
2) Plug in your board to your computer using the usb cable.
3) Open **main.cpp**.
4) Select the :arrow_right: icon (**PlatformIO: Upload**) on the VScode status bar and wait for the code to compile and upload. A success message will be shown in the upload terminal if the upload has completed successfully.

## Debugging 
To see the serial data printed by the board, open the **PlatformIO: Serial Monitor** by selecting the icon that looks like an electrical plug on the VScode status bar.

<!-- ## Code Operation -->

 