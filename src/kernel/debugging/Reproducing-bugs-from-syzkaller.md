# How to reproduce bugs from syzkaller 

1.  Navigate to the syzkaller bug link and download 
    -   disk image 
    -   kernel image 
    -   C repro, save as `.c` file 

    ![download-images](assets/syzkaller-download-images.png) 

2.  Extract the disk image and kernel image 
    ```sh 
    $ xz --decompress <disk-image> 
    $ xz --decompress <kernel-image> 
    ```
3.  Start VM, by running commands 
    ```sh
    $ export KERNEL_IMG=<full-path-to-kernel-image>
    $ export RFS_IMG=<full-path-to-disk-image>

    $ qemu-system-x86_64 \
	    -m 2G \ 
	    -smp 2 \
	    -kernel ${KERNEL_IMG} \
	    -append "console=ttyS0 root=/dev/sda1 earlyprintk=serial net.ifnames=0" \
	    -drive file=${RFS_IMG},format=raw \
	    -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
	    -net nic,model=e1000 \
	    -enable-kvm \
	    -nographic \
	    -pidfile vm.pid \
	    2>&1 | tee vm.log
    ```
4.  Compile the C repro file  
    ```sh
    $ gcc -o repro1 repro1.c 
    ```
    **Note**: Cross compile for arch other than x86_64

5.  Copy the compiled executable file into vm 
    ```sh 
    $ scp -P 10021 -r ./repro1 root@localhost:~/  
    ```

6.  SSH into the VM and run the compiled program 
    ```sh 
    $ ssh root@localhost -p 10021 
    # ./repro1 
    ```

7.  If the bug is not fixed then it will give a kernel panic. 

    ![syzkaller-panic](assets/syzkaller-panic.png) 

8.  If there is no panic then the bug has been fixed. 



