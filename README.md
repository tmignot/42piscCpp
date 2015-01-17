# 42piscCpp
Everything is awesome, everything is cool when you're part of a team

# RUSH_01

## Step 1
* Implement ncurse display using the ShellDisplay.[cpp/hpp] class
* Implement std container to contain a non finite list of modules to display
* [~~Define a method of selection for type of display to use and how we make this work USING the mandatory interface~~](rush01/includes/Options.hpp)
* Implement configuration file creation/save "on the fly"

## Step 2
* Define content of each module derived from the interface *i.e. the member functions and abstract methods that NEED defining* **such as update_values(void) maybe?**
* Implement each mandatory module: **use shell commands with `exec *` and `fork` please**
  * Hostname.cpp/hpp
  * OS.cpp/hpp
  * Time.cpp/hpp
  * CPU.cpp/hpp
  * [RAM.cpp/hpp](http://nadeausoftware.com/articles/2012/09/c_c_tip_how_get_physical_memory_size_system)
  * Network.cpp/hpp

## Step 3
* Define which graphical library to use for the windowed display
* Implement said display in the WindowedDisplay.[cpp/hpp]
* Implement configuration file for this display with creation/save "on the fly"

Decouvrons les cles du mystere au chocolat
