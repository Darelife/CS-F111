# import sys
# from datetime import datetime

# # GMT time
# time_tuple = (2024,  # Year
#               2,  # Month
#               20,  # Day
#               15,  # Hour
#               43,  # Minute
#               40,  # Second
#               0,  # Millisecond
#               )


# def _win_set_time(time_tuple):
#     import win32api
#     dayOfWeek = datetime(*time_tuple).isocalendar()[2]
#     t = time_tuple[:2] + (dayOfWeek,) + time_tuple[2:]
#     win32api.SetSystemTime(*t)


# def _linux_set_time(time_tuple):
#     import subprocess
#     import shlex

#     time_string = datetime(*time_tuple).isoformat()

#     subprocess.call(shlex.split("timedatectl set-ntp false"))  # May be necessary
#     subprocess.call(shlex.split("sudo date -s '%s'" % time_string))
#     subprocess.call(shlex.split("sudo hwclock -w"))


# if sys.platform == 'linux2' or sys.platform == 'linux':
#     _linux_set_time(time_tuple)

# elif sys.platform == 'win32':
#     _win_set_time(time_tuple)