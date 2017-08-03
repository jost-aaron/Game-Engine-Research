clear

COMPILE_MODE=0
NUM_CORES=4

# Get the input arguments
for i in "$@"
do
case $i in
    # Compile changes with debug symbols
    -d|--debug)
    COMPILE_MODE=1
    ;;
    # Compile Entire source with debug symbols
    -dr|--debugRecompile)
    COMPILE_MODE=1
    make cleanAll
    ;;
    # Compile changes with full compiler optimization
    -r|--release)
    COMPILE_MODE=2
    ;;
    # Compile Entire source with compiler optimization
    -rr|--releaseRecompile)
    COMPILE_MODE=2
    make cleanAll
    ;;
    # Set the number of cores to utalize
    -c=*|--cores=*)
    NUM_CORES="${i#*=}"
    make cleanAll
    ;;
    # Do just run make with no extra flags
    --default)COMPILE_MODE
    COMPILE_MODE = 0
    ;;
    *)
            # unknown option
    ;;
  esac
  done

# Set the compile mode and number of cores
if [ $COMPILE_MODE -eq 0 ]; then
  make -j $NUM_CORES
elif [[ $COMPILE_MODE -eq 1 ]]; then
  make -e COMPILER_FLAGS=-g -j $NUM_CORES
elif [[ $COMPILE_MODE -eq 2 ]]; then
  make -e COMPILER_FLAGS=-O3 -j $NUM_CORES
else
  make -j $NUM_CORES
fi

# if Compilation was sucessfull execute the program
if [ $? -eq 0 ]; then
  # Run the executable
  ./out
fi
