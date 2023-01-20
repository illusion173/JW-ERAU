print("Beginning Mousecontrol!")
import pyautogui
import time

pyautogui.FAILSAFE = True
correct_button_location_x = 856
correct_button_location_y = 1042

flipcard_button_location_x = 682
flipcard_button_location_y = 426

# print(pyautogui.position())
while True:
    pyautogui.click(
        x=flipcard_button_location_x,
        y=flipcard_button_location_y,
        clicks=1,
        interval=1,
        button="left",
    )
    pyautogui.click(
        x=correct_button_location_x,
        y=correct_button_location_y,
        clicks=1,
        interval=1,
        button="left",
    )
    time.sleep(2)
# pyautogui.moveTo()
