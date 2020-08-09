# Hajime
A versatile, high-performance Minecraft server startup script written in C++.

# The Problem
Starting a Minecraft server can be simple but limited. Until now, more advanced scripts were made with unintelligible systemd services or Bash scripts. Hajime changes all this. It is programmed enntirely in C++ and can actively monitor a server.

# Requirements
Hajime has several prerequisites as of this writing. A Linux system is required. To use a precompiled binary, an ARM device such as a Raspberry Pi is needed. Hajime was designed to be used with servers that have all server info on an external mass storage device such as a USB flash drive.

# Instructions
If you are using a precompiled binary, stay in this section. If you are compiling, skip this section. Download the one appropriate for your platform. Next, place it in a simple, memorable location. In my own server, I use /media. Now, run 

    sudo ./hajime -I
to install the initial configuration file. If you would like to make a systemd service, now run

    sudo ./hajime -S
to make a systemd service file. By default, the file created is called **start.service**. If you would like a different name (for example, if you are running multiple servers) change the setting in the file **hajime.conf**. Now enable it using

    sudo systemctl enable start
to run Hajime on startup. Before rebooting, you must change the settings in **start.conf** and **hajime.conf**. Start.conf is the settings file for an individual server object. This is done for future-proofing for future versions that may implement multithreading. Hajime.conf is the settings file for the main program.

# Instructions: Compiling Your Own
It's easy to compile Hajime. First, download the files in the **source** section. Then, run this command:

    sudo g++ -O3 -o hajime hajime.cpp -lstdc++fs
The "-lstdc++fs" is required if you are running a version of GCC that treats the filesystem library as an experimental one. Now, follow the main Instructions area to finish.
   
