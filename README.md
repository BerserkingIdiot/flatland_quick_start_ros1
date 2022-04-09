# ROS1 Robot Control Crash Course, with Flatland

## Installation and Environment Setup

Note: This guide assumes you are using an Ubuntu 20.04 operating system, and can be followed using either a computer running on this OS, WSL, or a Virtual Machine.

### ROS Installation

Follow the instructions in the official [ROS installation guide](http://wiki.ros.org/noetic/Installation/Ubuntu). It is recommended to at least install the desktop version, as some tools that will be used here are already contained within.

Note: From this point on, it is assumed that every terminal has sourced the _setup.bash_ script as indicated in section 1.5 of the installation guide. Without this, you will not be able to use ROS or any of its tools.

### Workspace Setup

Create your own workspace. Pick where you would like your workspace to be placed (usually in the home directory, a.k.a. _~/_) and create a folder with a name of your choice, for example _ros\_workspace_, and within it create a folder named _src_. Finally, from within the workspace folder, in this case the ros_workspace folder, run the _catkin\_make_ command. You can use the following commands in a terminal for this process, assuming you place your workspace in your home directory:

```
mkdir -p ~/ros_workspace/src
cd ~/ros_workspace/
catkin_make
```

Two new folders should have appeared in your workspace, _build/_ and _devel/_. Within the _devel/_ folder, you'll find multiple shell scripts. One of these, _devel/setup.bash_ will be used to allow you to run code from packages within your workspace. Every time you open a new terminal to run ROS code from within your workspace and after you run _catkin\_make_, don't forget to execute the following command:

```
source devel/setup.bash
```

### Flatland Setup

First, clone the flatland repository into the _src_ folder of your workspace. Then, from within your workspace, build the package with _catkin\_make_ (and source devel/setup.bash), and launch the default server to test whether everything is working. You can do this process with the following commands:

```
cd src/
git clone https://github.com/avidbots/flatland.git
cd ..
catkin_make
source devel/setup.bash
roslaunch flatland_server server.launch
```

If all went well, you should see a map of an office and a few models placed around, one of them moving back and forth on a cycle.

## First Run

- clone this repo
- run rqt robot steering mode launch

## Write your own code

Pick your poison:

- C++

- Python

run custom code launch