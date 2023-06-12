## The problem 
the linux kernel needs to know the hardware topology and the configuration
to initiate the device drivers and manage the memory.

For some architectures it is not a problem, because the motherboard firmware like UEFI and BIOS describe the hardware to the Linux kernel.
And buses like the USB, PCI etc help the Linux kernel to describe the hardware to the Linux kernel at runtime.

But in other architectures Like in ARM, PPC the hardware cannot describe itself.
So for a long time the solution for this by describing the hardware inside the source code.
```
arch/arm/mach-imx/*
```
## Disadvantages of the method
1. Change hardware change the kernel
2. no standard 
3. Too much duplicated code

## Device Tree
Hardware is described in another file which looks simillar to json or xml
The text file is compiled to dtb.

Use of device tree on ARM became compulsory after 3.7

device tree location
1. arch/arm/boot/dts

dtsi file - include file for the dts

## Compiling the DTS 
There is a tool called as dtc which can be used to compile the dts files 
the command for the kernel compilation is 
```sh
make dtbs 
```
## Passing the DTB to the kernel 
During the boot process the bootloader is responsible for passing the dtb to the kernel.

You can even ask the kernel to find the dtb by itself by using the option called CONFIG_ARM_DTB_APPENDED.


## Device Tree Syntax 
```yml
root node @ address of the device (optional)
        property 
        child node 


        node1 : node@address 

node1 is the label
```
Properties are data structures used to store a value.

Different types of properties 
1. String 
2. list of string
3. byte-string 
4. cell-property 

Main property of the DT 
1. compatible - Shows which device driver is the node compatible with 
2. status - enables or disables the node in the device tree
default status is enabled.

Address and memory mapping 
1. address cells - defines the format of the reg cells 
2. size-cells - defines the size of the the reg cells
3. reg -

Ranges are used to define the hardware which have their own address spaces and don't use the CPU's address space 

Hence we need a mapping of the parent address space and the child address space

The driver uses the of_match_table to match the compatible property 
and once it matches the probe function is called.

* model = describes the h/w model
* compatible = identifies the device driver of the 
* aliases - another name for the same node.
* chosen - is used to pass to the kernel command line 
* phandle - So that the node can be referenced from the property 

Device trees are split into multiple files to make it more modular
the dtsi files are the include files which contains the dts which is split.


The mechanism is overlay mechanism, that means the properties can be changed by changing them in another file and including that file later in the file. 


The compatible string and the properties are documented in the file called as the device tree bindings.

Documentation/devicetree/bindings
