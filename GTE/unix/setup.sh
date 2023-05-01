# This setup script is used to set up the GTE environment and dependencies in linux/Ubutnu

# Check if the script is being run as root
if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

# Check if the script is being run from the GTE/unix directory
if [ ! -f "setup.sh" ]
  then echo "Please run from the GTE/unix directory"
  exit
fi

# Check if cmake is installed, otherwise, install it
if ! [ -x "$(command -v cmake)" ]; then
  echo 'Installing cmake.' >&2
  apt-get install cmake
fi

# Check if SDL2 is installed, otherwise, install it
if ! [ -x "$(command -v sdl2-config)" ]; then
  echo 'Installing SDL2.' >&2
  apt-get install libsdl2-dev
fi

# Run dpkg to check if the required packages (glm, glew) are installed
# If not, install them
dpkg -s libglm-dev &> /dev/null
if [ $? -ne 0 ]; then
  echo 'Installing glm.' >&2
  apt-get install libglm-dev
fi

dpkg -s libglew-dev &> /dev/null
if [ $? -ne 0 ]; then
  echo 'Installing glew.' >&2
  apt-get install libglew-dev
fi

# exit after it's done
exit
