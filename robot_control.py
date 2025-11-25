import tkinter as tk
import serial
import time

# -------------------------
# Auto-connect to Arduino
# -------------------------
try:
    arduino = serial.Serial('/dev/tty.usbmodem1101', 9600, timeout=1)
    time.sleep(2)  # Wait for Arduino to reset
except serial.SerialException:
    print("Could not connect to Arduino. Make sure the port is correct.")
    arduino = None

# -------------------------
# Function to send servo commands
# -------------------------
def send_servo(servo_name, angle):
    if arduino:
        command = f"{servo_name}:{angle}\n"
        arduino.write(command.encode())

# -------------------------
# GUI setup
# -------------------------
root = tk.Tk()
root.title("Robotic Arm Controller")

# Make everything a bit bigger
LABEL_FONT = ("Arial", 16)
BUTTON_FONT = ("Arial", 14)
SLIDER_LENGTH = 400  # pixels

# Arm slider
tk.Label(root, text="Arm", font=LABEL_FONT).pack(pady=5)
arm_slider = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, length=SLIDER_LENGTH,
                      command=lambda val: send_servo("arm", val))
arm_slider.pack(pady=5)

# Gripper assembly slider
tk.Label(root, text="Gripper Assembly", font=LABEL_FONT).pack(pady=5)
assembly_slider = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, length=SLIDER_LENGTH,
                           command=lambda val: send_servo("assembly", val))
assembly_slider.pack(pady=5)

# Gripper slider
tk.Label(root, text="Gripper", font=LABEL_FONT).pack(pady=5)
gripper_slider = tk.Scale(root, from_=0, to=180, orient=tk.HORIZONTAL, length=SLIDER_LENGTH,
                          command=lambda val: send_servo("gripper", val))
gripper_slider.pack(pady=5)

# Quit button
tk.Button(root, text="Quit", font=BUTTON_FONT, bg="red", fg="white", width=15,
          command=root.destroy).pack(pady=10)

# Start GUI
root.mainloop()
