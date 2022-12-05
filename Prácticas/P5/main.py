# Grabacion de funciones sobre un actualidor lineal

# Implementar un sistema de teleoperación para permitir grabar tareas.
# Una tecla del PC debe servir para activar y desactivar el modo grabación
# y la otra para reproducir de forma automática la última tarea grabada.

import serial
import time

arduino = serial.Serial(port='/dev/cu.usbmodem101', baudrate=9600, timeout=.1)


def write_read(value):
    # Escribimos como bytes (1 solo dígito) usando UTF-8
    arduino.write(bytes(value, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data


def main():
    while True:
        num = input("Envía un número desde a Python a Arduino: ")
        # Taking input from user
        input_value = write_read(num)
        print("Python dice:" + str(input_value))  # printing the value

main()