# 42piscCpp
Everything is awesome, everything is cool when you're part of a team

# RUSH_01

## Step 1
* [~~Implement ncurse display using the ShellDisplay.[cpp/hpp] class~~](rush01/srcs/ShellDisplay.cpp)
* ~~Implement std container to contain a non finite list of modules to display~~ **std::list**
* [~~Define a method of selection for type of display to use and how we make this work USING the mandatory interface~~](rush01/includes/Options.hpp)
* Implement configuration file creation/save "on the fly"

## Step 2
* Define content of each module derived from the interface *i.e. the member functions and abstract methods that NEED defining* **such as update_values(void) maybe?**
* Implement each mandatory module: **use shell commands with `exec *` and `fork` please**
  * ~~Hostname.cpp/hpp~~
  * OS.cpp/hpp
  * [Time.cpp/hpp](http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c/997988#997988)
  * CPU.cpp/hpp - Model - Clock Speed - Number of Cores - Activity
  * [RAM.cpp/hpp](http://nadeausoftware.com/articles/2012/09/c_c_tip_how_get_physical_memory_size_system)
  * Network.cpp/hpp

## Step 3
* Define which graphical library to use for the windowed display
* Implement said display in the WindowedDisplay.[cpp/hpp]
* Implement configuration file for this display with creation/save "on the fly"

Decouvrons les cles du mystere au chocolat

# Class Usage
## IMonitorDisplay
* Derived classes are constructed without parameters for the moment (config file needs implementation)
* Draw method call the draw method of every module in it's list
### ShellDisplay
* Has a Window representing the working window
* Has a list of Module class instance pointers representing each modules

## IMonitorModule
* Derives classes are constructed without parameters for the moment (maybe a configuration file ?)
* Derived classes have a `std::vector<std::string>` representing each line to be displayed in the output returned in a `getData(void)` method
* Derived classes **should** have an update function to update the data displayed
* Derived classes have a `initWindow` method which returns a pointer to a correctly sized window in the right place

## Module
* Constructor takes a IMonitorModule reference + a pointer on the last added Module's `WINDOW` (can be NULL) + a pointer to the `WINDOW` belonging to the full display
* `draw(void)` draws the module in it's designated place
* Has a `getWindow(void)` function to get the window representing this module
