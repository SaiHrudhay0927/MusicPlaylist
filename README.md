This repository contains a Music Playlist application developed in C using Linked Lists and the SDL2 and SDL2_mixer libraries. The project showcases the integration of basic data structures with multimedia capabilities to create a music player.

Features
Static Playlist: Songs are predefined in the playlist and managed using linked lists.
Audio Playback: Utilizes SDL2 and SDL2_mixer libraries to play audio files.

Prerequisites
To run this application, you need:
A virtual machine running a Linux-based operating system.
The following libraries and packages installed:
libsdl2-dev
libsdl2-mixer-dev
Installation and Execution
Follow these steps to set up and run the program:
Install the required libraries and packages using the below command:
sudo apt-get install libsdl2-dev libsdl2-mixer-dev  
Compile the source code using the below command:
gcc dsassign.c -o dsassign -lSDL2 -lSDL2_mixer  
Run the application using the below command:
./dsassign  

Notes
Ensure you are running the application on a virtual machine to avoid compatibility issues.
Modify the code as needed to include additional features or adapt it for dynamic playlist management.

Contributing
Feel free to fork the repository and submit pull requests for improvements or additional features.

