# MSI-GT7x-VGA-SWITCH
Selects VGA from LINUX or EFI!

These programs or batch scripts will let you swtch the VGA from INTEL to NVIDIA (or the opposite)

This is possible at the moment only from Windows (bad choice MSI!).

Now it will also be possible from Linux or directly from an EFI SHELL!

intel.nsh and nvidia.nsh are two EFI Shell scripts that can be run directly from EFI shell.

Just "make intel"  and "make nvidia" to compile the 2 C sources.

A reboot is needed afterwards because the VGA is switched by BIOS at boot time.

***UPDATE***

msi_vga utility added!

MSI VGA Select V0.2 by Zibri
http://www.zibri.org

Usage: ./msi_vga -s/-i/-n/-t

-s Gets the name of the actual VGA

-t Toggles between nvidia and intel VGA

-n Sets nvidia VGA

-i Sets intel VGA

**WARNING**
This program has been tested and works ONLY on the latest BIOS version (Version 11D)

DO NOT USE IT on a different model unless you contact me first.

Enjoy!
(and write me a line if you use these)
