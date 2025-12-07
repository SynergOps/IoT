/**
 * @file serial_io.h
 * @brief Library for simplified reading and writing of data from/to the Serial Port.
 *
 * This header-only library provides a set of utility functions and templates
 * to streamline Serial communication in Arduino projects. It supports
 * variadic-like printing of up to 5 arguments and type-safe input reading.
 *
 * @author Aristides S. Bouras (Original Version)
 * @author Salih Emin (Documentation Update - 2025)
 * @license Public Domain
 */
#ifndef DECIMAL_PLACES
/**
 * @brief Default number of decimal places for floating-point output.
 *
 * Can be overridden by defining DECIMAL_PLACES before including this header.
 */
#define DECIMAL_PLACES 2
#endif

#ifndef serial_io_h
#define serial_io_h
#include "Arduino.h"

/**
 * @brief Prints a single argument to the Serial port.
 * @tparam TYPE1 Type of the argument.
 * @param arg1 The value to print.
 */
template <typename TYPE1>
void print(TYPE1 arg1)
{
	Serial.print(arg1);
}

template <typename TYPE1>
void println(TYPE1 arg1)
{
	print(arg1);
	print("\n");
}

void println()
{
	print("\n");
}

/**
 * @brief Specialization for printing float values with defined precision.
 * @param value The float value to print.
 */
void print(float value)
{
	Serial.print(value, DECIMAL_PLACES);
}

void println(float value)
{
	Serial.println(value, DECIMAL_PLACES);
}

/**
 * @brief Specialization for printing double values with defined precision.
 * @param value The double value to print.
 */
void print(double value)
{
	Serial.print(value, DECIMAL_PLACES);
}

void println(double value)
{
	Serial.println(value, DECIMAL_PLACES);
}

/**
 * @brief Variadic-like templates for printing multiple arguments.
 *
 * The following templates support printing 2 to 5 arguments of any type.
 * Arguments are automatically separated by a space character.
 */

template <typename TYPE1, typename TYPE2>
void print(TYPE1 arg1, TYPE2 arg2)
{
	print(arg1);
	print(" ");
	print(arg2);
}

template <typename TYPE1, typename TYPE2>
void println(TYPE1 arg1, TYPE2 arg2)
{
	print(arg1, arg2);
	println();
}

template <typename TYPE1, typename TYPE2, typename TYPE3>
void print(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3)
{
	print(arg1);
	print(" ");
	print(arg2);
	print(" ");
	print(arg3);
}

template <typename TYPE1, typename TYPE2, typename TYPE3>
void println(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3)
{
	print(arg1, arg2, arg3);
	println();
}

template <typename TYPE1, typename TYPE2, typename TYPE3, typename TYPE4>
void print(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3, TYPE4 arg4)
{
	print(arg1);
	print(" ");
	print(arg2);
	print(" ");
	print(arg3);
	print(" ");
	print(arg4);
}

template <typename TYPE1, typename TYPE2, typename TYPE3, typename TYPE4>
void println(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3, TYPE4 arg4)
{
	print(arg1, arg2, arg3, arg4);
	println();
}

template <typename TYPE1, typename TYPE2, typename TYPE3, typename TYPE4, typename TYPE5>
void print(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3, TYPE4 arg4, TYPE5 arg5)
{
	print(arg1);
	print(" ");
	print(arg2);
	print(" ");
	print(arg3);
	print(" ");
	print(arg4);
	print(" ");
	print(arg5);
}

template <typename TYPE1, typename TYPE2, typename TYPE3, typename TYPE4, typename TYPE5>
void println(TYPE1 arg1, TYPE2 arg2, TYPE3 arg3, TYPE4 arg4, TYPE5 arg5)
{
	print(arg1, arg2, arg3, arg4, arg5);
	println();
}

/**
 * @brief Reads a string from Serial input.
 *
 * Blocks execution until data is available and a newline is received.
 *
 * @param prompt Optional text to display before waiting for input.
 * @param echo If true, prints the received string back to Serial (default: true).
 * @return String The received string (trimmed of the newline).
 */
String inputString(String prompt = "", bool echo = true)
{
	print(prompt);
	while (Serial.available() <= 0)
	{
	}
	String s = Serial.readStringUntil('\n');
	if (echo)
		println(s);
	return s;
}

/**
 * @brief Reads a single character from Serial input.
 * @param prompt Optional prompt text.
 * @return char The first character of the input string.
 */
char inputCharacter(String prompt = "")
{
	return inputString(prompt)[0];
}

/**
 * @brief Reads an integer from Serial input.
 * @param prompt Optional prompt text.
 * @return long The parsed integer value.
 */
long inputInteger(String prompt = "")
{
	return inputString(prompt).toInt();
}

/**
 * @brief Reads a float from Serial input.
 * @param prompt Optional prompt text.
 * @return float The parsed float value.
 */
float inputFloat(String prompt = "")
{
	return inputString(prompt).toFloat();
}

/**
 * @brief Halts program execution.
 *
 * Prints a termination message and enters an infinite loop.
 * Useful for stopping the `loop()` function in Arduino sketches.
 */
void stop()
{
	print("\n*************** ΤΕΛΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ ***************\n*** ΠΑΤΗΣΤΕ RESET ΣΤΟ ARDUINO ΓΙΑ ΕΠΑΝΕΚΤΕΛΕΣΗ ***\n\n");
	while (true)
	{
	};
}

#endif