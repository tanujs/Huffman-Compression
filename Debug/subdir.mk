################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Huffman.cpp \
../InputFileReader.cpp \
../Node.cpp \
../main.cpp 

OBJS += \
./Huffman.o \
./InputFileReader.o \
./Node.o \
./main.o 

CPP_DEPS += \
./Huffman.d \
./InputFileReader.d \
./Node.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


