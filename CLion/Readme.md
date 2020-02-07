# CSCI 366: CLion

1. Get a free version of CLion from https://www.jetbrains.com/student/

2. Set up vim keybindings
    * Install the IdeaVIM plugin in File &rarr; Settings &rarr; Plugins 
    * Several plugins come bundled with CLion, for example git support
    * Some useful unbundled plugins (https://www.jetbrains.com/help/clion/valuable-unbundled-plugins.html)

3. Set up a project
    * Use https://github.com/msu-netlab/CSCI_366_examples/tree/master/CLion as starting code
    * Right-click on top level CMakeLists.txt and click on Reload CMake Project
    * Run the "main" executable
    
4. Set up an environment
    * Go to File &rarr; Settings &rarr; Build, Execution, Deployment &rarr; Toolchains 
    * Set up WSL based on https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-clion.html

5. Debug your code
    * Run your code in debug mode
    * Play with stepping through functions, watching variables, set up watches, evaluate expressions 

6. Refactor your code
    * Change variable or function name
    * Change function signatures
    * Go to function definition
    * Go to usages
    
7. Work with git
    * Look at git and local histories
    * Commit your work